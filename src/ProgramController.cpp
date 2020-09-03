/**
* @file 		ProgramController.cpp
* @description 	AVL Agaci objesi uzerinde, stringstream ile kisinin ad, 
*				dogum tarihi, kilo bilgilerinin okunarak gerekli islemlerin 
*				yapilmasiyla programi calistiracak metodun implement edilmesi
* @course 		1. Ogretim - A Grubu
* @assignment 	Final Odevi
* @date 		30.08.2020
* @author 		Oguzhan Tohumcu / oguzhan.tohumcu@ogr.sakarya.edu.tr
*/

#include "ProgramController.hpp"

void ProgramController::run() {
	tree = new AVLTree();

	readFile.open("Kisiler2.txt");
	
	while (getline(readFile, line))
	{
		stringstream ss(line);
		getline(ss, name, '#');
		getline(ss, tmp, '#');
		date = stoi(tmp);
		getline(ss, tmp, '#');
		weight = stoi(tmp);
		
		Person* newOne = new Person(name, date, weight);
		
		tree->insert(newOne);
		tree->updateLevel(tree->getRoot(), tree->getRoot());
		tree->addToStack(tree->getRoot(), newOne);
	}
	
	readFile.close();
	tree->postorder(tree->getRoot());
}