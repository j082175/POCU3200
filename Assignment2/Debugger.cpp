#include "Debugger.h"
#include <iostream>
#include <cstring>
using namespace std;

void Debugger::Debug(const char* name)
{

	if (!strcmp(name, "Airplane"))
	{
		cout << "Airplane ";
	}
	else if (!strcmp(name, "Boat"))
	{
		cout << "Boat ";
	}
	else if (!strcmp(name, "Boatplane"))
	{
		cout << "Boatplane ";
	}
	else if (!strcmp(name, "Motorcycle"))
	{
		cout << "Motorcycle ";
	}
	else if (!strcmp(name, "Sedan"))
	{
		cout << "Sedan ";
	}
	else if (!strcmp(name, "UBoat"))
	{
		cout << "UBoat ";
	}
	else
	{
		return;
	}
}
