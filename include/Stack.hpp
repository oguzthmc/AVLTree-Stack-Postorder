/**
* @file 		Stack.hpp
* @description 	Stack'e ait constructor, destructor ile push, pop, ekrana yazdirma 
*				ve bos olup olmadiginin kontrolunu yapan metotlarin tanimlanmasi
* @course 		1. Ogretim - A Grubu
* @assignment 	Final Odevi
* @date 		25.08.2020
* @author 		Oguzhan Tohumcu / oguzhan.tohumcu@ogr.sakarya.edu.tr
*/

#include <iostream>

using namespace std;

struct Dugum
{
    char data;
    Dugum* next;
};

class Stack
{
	public:
		Stack();
		bool isEmpty();
		void push(char);
		void pop();
		void display();
		~Stack();
		
	private:
		Dugum* top;
		
};





