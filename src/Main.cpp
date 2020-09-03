/**
* @file 		Main.cpp
* @description 	ProgramController instance'i uzerinden programin calismasinin saglanmasi
* @course 		1. Ogretim - A Grubu
* @assignment 	Final Odevi
* @date 		31.08.2020
* @author 		Oguzhan Tohumcu / oguzhan.tohumcu@ogr.sakarya.edu.tr
*/ 

#include "ProgramController.hpp" 

int main()
{
	ProgramController *program = new ProgramController();
	cout << endl;
	program->run(); 	//Program calistirilir
	cout << endl;
	return 0;
}
