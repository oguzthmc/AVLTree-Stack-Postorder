/**
* @file 		ProgramController.hpp
* @description 	Programi calistiracak metot ile AVL agaci, file stream ve kisinin ad, dogum tarihi,
*				kilo bilgilerinin okunmasi icin gerekli degiskenlerin tanimlanmasi
* @course 		1. Ogretim - A Grubu
* @assignment 	Final Odevi
* @date 		30.08.2020
* @author 		Oguzhan Tohumcu / oguzhan.tohumcu@ogr.sakarya.edu.tr
*/

#include <fstream>
#include <sstream>
#include <windows.h>
#include "AVLTree.hpp"

class ProgramController {
	public:
		void run();
		
	private:
		int date;
		int weight;
		string name, line, tmp;
		ifstream readFile;
		AVLTree* tree;
};