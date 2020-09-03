/**
* @file 		AVLTree.hpp
* @description 	AVL agaci icin; ekleme, silme, yuksekligini bulma, tekli sola ve saga donus,
*				ciftli sola ve saga donus, seviye alma ve guncelleme, Stack'e ekleme, postorder siralama
*				ve kok durumunu donme gibi islemleri yapan metotlarin tanimlanmasi
* @course 		1. Ogretim - A Grubu
* @assignment 	Final Odevi
* @date 		28.08.2020
* @author 		Oguzhan Tohumcu / oguzhan.tohumcu@ogr.sakarya.edu.tr
*/

#include <cmath>
#include "Person.hpp"
#include "Stack.hpp"

struct Node
{   
    Stack* stack;
    Person* person;
    Node* left;
    Node* right;
    int height;
    int level;
    int prevLevel;
};

class AVLTree
{
	public:
		AVLTree();
		void updateLevel(Node*, Node*);
		void addToStack(Node*, Person*);
		void postorder(Node* t);
		Node* getRoot();
		void insert(Person* person);
		~AVLTree();
		
	private:
		Node* root;
		int Max(int a, int b);
		void makeEmpty(Node* t);
		Node* insert(Person* newPerson, Node* t);
		Node* singleRightRotate(Node* &t);
		Node* singleLeftRotate(Node* &t);
		Node* doubleRightRotate(Node* &t);
		Node* doubleLeftRotate(Node* &t);
		int height(Node* t);
		int getLevel(Node*, Person*, int);
		
};