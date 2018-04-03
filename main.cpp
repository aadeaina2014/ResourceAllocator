// main Application Driver File for time resource allocation class
#include "Resourceallocator.h"
#include <iostream>
using namespace std;

void queryServer(Resourceallocator *p)
{
	std::setprecision(2);
	bool rushStatus;
	float timeStamp;
	cout << "Time Stamp\t" << "\tServer Response:" << endl;
	cout << "------------------------------------------" << endl;
	for (int i = 0; i < 24; i++)
	{
		rushStatus = p->IsRushHour((float)i);
		timeStamp = (float)i ;
		if (rushStatus)
		{
			cout << fixed << setprecision(2)<< " "<<timeStamp << " \t\t\tRush Hour" << endl;
		}
		else
		{
			cout << fixed << setprecision(2)<< " "<<timeStamp<< " \t\t\tNot Rushour" << endl;
		}
	}
}

int main()
{
	Resourceallocator * timeServer = new Resourceallocator;// Instantiate a pointer to a dynamic resource allocator object
	cout << "\t**********************************************************************************" << endl;
	cout << "\t\tNetwork Resource Allocation" << endl;
	cout << "\t\tDeveloped by Ayokunle Ade-Aina (c) 2016 , All rights reserved" << endl;
	cout << "\t**********************************************************************************" << endl;
	timeServer->AddTimeSpan(1.30, 3.30); //allocate time resource on the server
	system("pause");

	queryServer(timeServer);  // Query server for all available time slots
	system("pause");
	timeServer->AddTimeSpan(1.30, 3.30); //simulate duplicate timespan allocation
	system("pause");
	queryServer(timeServer);  // Query server for all available time slots
	system("pause");
	timeServer->AddTimeSpan(11.30, 17.30); 
	system("pause");
	queryServer(timeServer);  // Query server for all available time slots
	delete timeServer;
	system("pause");
	return EXIT_SUCCESS;
}
