/**
* @file 		Person.hpp
* @description 	Kisinin isim, dogum tarihi, kilo, yas gibi ozellikleri ile bunlara ait
*				getter/setter metodlari ve 2 farkli constructor metodunun tanimlanmasi
* @course 		1. Ogretim - A Grubu
* @assignment 	Final Odevi
* @date 		27.08.2020
* @author 		Oguzhan Tohumcu / oguzhan.tohumcu@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <string>

#define CURRENT_YEAR 2020

using namespace std;

class Person
{
	public:
		Person(string, int, int);
		Person(const Person&);
		string getName();
		int getDateOfBirth();
		int getWeight();
		int getAge();
		void setName(string);
		void setDateOfBirth(int);
		void setWeight(int);
		
	private:
		string name;
		int dateOfBirth;
		int weight;
		int age;
		
};

