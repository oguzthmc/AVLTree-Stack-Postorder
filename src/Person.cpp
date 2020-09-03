/**
* @file 		Person.cpp
* @description 	Kisinin isim, dogum tarihi, kilo, yas gibi ozellikleri ile bunlara ait
*				getter/setter metodlari ve 2 farkli constructor metodunun implement edilmesi
* @course 		1. Ogretim - A Grubu
* @assignment 	Final Odevi
* @date 		27.08.2020
* @author 		Oguzhan Tohumcu / oguzhan.tohumcu@ogr.sakarya.edu.tr
*/

#include "Person.hpp"

Person::Person(string name, int dateOfBirth, int weight) {
	this->name = name;
	this->dateOfBirth = dateOfBirth;
	this->weight = weight;
	this->age = CURRENT_YEAR - dateOfBirth;
}

Person::Person(const Person& person) {
	this->name = new char[50];
	this->name = person.name;
	this->weight = person.weight;
	this->age = person.age;
	this->dateOfBirth = person.dateOfBirth;
}

string Person:: getName() {
	return name;
}

int Person::getDateOfBirth() {
	return dateOfBirth;
}

int Person::getWeight() {
	return weight;
}

int Person::getAge() {
	return this->age;
}

void Person::setName(string name) {
	this->name = name;
}

void Person::setDateOfBirth(int dateOfBirth) {
	this->dateOfBirth = dateOfBirth;
}

void Person::setWeight(int weight) {
	this->weight = weight;
}
