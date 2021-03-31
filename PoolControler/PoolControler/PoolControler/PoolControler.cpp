// PoolControler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

bool flag = false; //flag interrupt, global variable

//#include "pool_controler_windowns.cpp"

#include "List.cpp"

//-- Uncomment bellow for Atmega Interface: 
//#include "pool_controler_atmega.cpp"

int main(void)
{
	//PoolControlerWindowns Controler;
	////-- Uncomment bellow for Atmega Interface:
	////PoolControlerAtmega Controler;

	//Controler.inputSW();

	//while (1)
	//{
	//	Controler.Inputs();
	//	Controler.Outputs();
	//	Controler.FSM();
	//	if (flag)
	//	{
	//		Controler.setEstate(1);  //If interrupt occur the next estate is INIT to reset the timer
	//		flag = false;
	//	}
	//}

	List lista1;

	lista1.insertBeforeFirst("helllo");
	lista1.insertAfterLast("world");

	cout << "Primeiro nodo contem: " << lista1.readFirst() << endl;

	lista1.listAll();



	return 0;
}


