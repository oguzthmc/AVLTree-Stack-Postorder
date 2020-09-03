/**
* @file 		AVLTree.cpp
* @description 	AVL agaci olusturarak; ekleme, silme, yuksekligini bulma, tekli sola ve saga donus,
*				ciftli sola ve saga donus, seviye alma ve guncelleme, Stack'e ekleme, postorder siralama
*				ve kok durumunu donme gibi islemleri yapan metotlarin implement edilmesi
* @course 		1. Ogretim - A Grubu
* @assignment 	Final Odevi
* @date 		29.08.2020
* @author 		Oguzhan Tohumcu / oguzhan.tohumcu@ogr.sakarya.edu.tr
*/

#include "AVLTree.hpp"

//No parameter constructor
AVLTree::AVLTree()
{
	root = NULL;
}

//Dugum seviyesini saptayan metot
int AVLTree::Max(int a, int b) {
    if (a >= b)
        return a;
    return b;
}

//Agaci bos hale getiren metot
void AVLTree::makeEmpty(Node* t)
{
    if (t == NULL)
        return;
    makeEmpty(t->left);
    makeEmpty(t->right);
	delete t->person;
	delete t->stack;
    delete t;
}

//AVL Agaci icine ekleme metodu
Node* AVLTree::insert(Person* newPerson, Node* t)
{
    if (t == NULL)
    {
        t = new Node;
        t->stack = new Stack;
        t->stack->push('O'); 	//dugum ilk kez olusturuldugunda O harfi atanir
        t->person = newPerson;
        t->height = 0; 
        t->left = t->right = NULL;
        t->level = getLevel(t, newPerson, 1);
        t->prevLevel = t->level;
    }
    else if (newPerson->getAge() <= t->person->getAge())
    {
        t->left = insert(newPerson, t->left);
        if (t->left->person == newPerson)
            t->left->level = getLevel(t, newPerson, 1);
        if (height(t->left) - height(t->right) == 2)
        {
            if (newPerson->getAge() <= t->left->person->getAge())
                t = singleRightRotate(t);
            else
                t = doubleRightRotate(t);
        }
    }
    else if (newPerson->getAge() > t->person->getAge())
    {
        t->right = insert(newPerson, t->right);
        if (t->right->person == newPerson)
            t->right->level = getLevel(t, newPerson, 1);
        if (height(t->right) - height(t->left) == 2)
        {
            if (newPerson->getAge() > t->right->person->getAge())
                t = singleLeftRotate(t);
            else
                t = doubleLeftRotate(t);
        }
    }

    t->height = Max(height(t->left), height(t->right)) + 1;

    return t;
}

//Saga dogru tek donus metodu
Node* AVLTree::singleRightRotate(Node* &t)
{
    Node* u = t->left;
    t->left = u->right;
    u->right = t;
    t->height = Max(height(t->left), height(t->right)) + 1;
    u->height = Max(height(u->left), t->height) + 1;
    t->stack->push('A'); 			//dugum saga dogru giderse kok Node asagi 
    u->stack->push('Y');			//kokun sagi ise yukarı kayar
    if (t->left) {					
        t->left->stack->push('A'); 	//eger kokun solu bos degilse o da asagi kayar
    }
    return u;
}

//Sola dogru tek donus metodu
Node* AVLTree::singleLeftRotate(Node* &t)
{
    Node* u = t->right;
    t->right = u->left;
    u->left = t;
    t->height = Max(height(t->left), height(t->right)) + 1;
    u->height = Max(height(t->right), t->height) + 1;
    u->stack->push('Y');			//kokun sagi sola dogru dönerse Node'un sagi yukari 
    t->stack->push('A');			//kokun ise asagi kayar
    if (t->right)
    {
        t->right->stack->push('Y'); //eger kokun sagi bos degilse o da yukari kayar
    }
    return u;
}

//Saga dogru cift donus metodu
Node* AVLTree::doubleRightRotate(Node*& t)
{
    t->left = singleLeftRotate(t->left);
    return singleRightRotate(t);
}

//Sola dogru cift donus metodu
Node* AVLTree::doubleLeftRotate(Node*& t)
{
    t->right = singleRightRotate(t->right);
    return singleLeftRotate(t);
}

//Agacin yuksekligini donen metot
int AVLTree::height(Node* t)
{	
	if(t==NULL)
		return -1;
	return t->height;

}

//Her bir dugumun seviyelerini belirtmek icin kullanilan metot
int AVLTree:: getLevel(Node* nd, Person* newPerson, int level) 
{
    if (nd == NULL)
        return 0;

    if (nd->person == newPerson)
        return level;

    int downlevel = getLevel(nd->left, newPerson, level + 1);
    if (downlevel != 0)
        return downlevel;

    downlevel = getLevel(nd->right, newPerson, level + 1);
    return downlevel;
}

//Agacin mevcut seviyesini guncelleyen metot
void AVLTree::updateLevel(Node* root, Node* curr)
{
    if (curr && root)
    {
        curr->level = getLevel(root, curr->person, 1);
        updateLevel(root, curr->right);
        updateLevel(root, curr->left);
    }
}

//Degismeyen dugum seviyeleri icin cagrilan Stack'e ekleme metodu
void AVLTree:: addToStack(Node* root, Person* newPerson)
{
    if (root)
    {
        if (root->level == root->prevLevel && root->person != newPerson)
        {
            root->stack->push('D');
        }
        root->prevLevel = root->level;

        addToStack(root->left, newPerson);
        addToStack(root->right, newPerson);
    }
}

//Postorder seklinde siralama yapan metot
void AVLTree::postorder(Node* t)
{
    if (t == NULL)
        return;
    postorder(t->left);
    postorder(t->right);
    cout << t->person->getName() << "," << t->person->getDateOfBirth() << "," << t->person->getWeight()<<"  Yigit: ";
    while(!(t->stack->isEmpty()))
		t->stack->pop();
    cout << "\n";
}

//Agacin kok dugumunu donen metot
Node* AVLTree::getRoot() { 
	return root; 
}

//Insert metodunun basite indirgenmis hali
void AVLTree::insert(Person* person)
{
	root = insert(person, root);
}

//Destructor
AVLTree::~AVLTree(){
	makeEmpty(root);
}
