/**
* @file 		Stack.cpp
* @description 	Stack'e ait constructor ve destructor ile push, pop, ekrana yazdirma 
*				ve bos olup olmadiginin kontrolunu yapan metotlarin implement edilmesi
* @course 		1. Ogretim - A Grubu
* @assignment 	Final Odevi
* @date 		26.08.2020
* @author 		Oguzhan Tohumcu / oguzhan.tohumcu@ogr.sakarya.edu.tr
*/

#include "Stack.hpp"

//No parameter constructor
Stack::Stack()
{
    top = NULL;
}

//Stack bos mu diye check eden metot
bool Stack::isEmpty() {
    return (top == NULL);
}

//Stack'e dugum push eden metot
void Stack::push(char s)
{
    Dugum* temp;
    temp = new Dugum;
    temp->data = s;
    temp->next = top;
    top = temp;
}

//Stack'ten dugumu pop eden metot
void Stack::pop()
{
    if (top != NULL)
    {
        Dugum* temp = top;
        top = top->next;
        cout << temp->data<<" ";
        delete temp;

    }
    else
        cout << "Stack empty!";
}

//Stack'i ekrana basan metot
void Stack::display()
{
    Dugum* temp = top;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

//Destructor
Stack::~Stack()
{
    while (top != NULL)
    {
        Dugum* temp = top;
        top = top->next;
        delete temp;
    }
}