#include "Resourceallocator.h"
#include <iostream>
#include <math.h>
#include <stdexcept>

Resourceallocator::Resourceallocator()
{
  
	for (int i = 0; i < 24; i++)
	{
		isrush.push_back(false);
	}
// Default values of resource object attribute
}

bool Resourceallocator::IsRushHour(float t)
{   
	try
	{
		int index = (int)t;
		return isrush.at(index); 
	}
	catch (std::out_of_range & oor)
	{
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
		

}

void Resourceallocator::AddTimeSpan(float start_time, float stop_time)
{
	//If the input is invalid(meaning T<0 or T >= 24.00), behvaiour is not defined.

	int sp = ceil(stop_time);
	int st = floor(start_time);
	
	std::cout << "\nQuery Interval "<< sp << "\t" << st <<"\n\n"<< std::endl;
	if ((0< st) & (sp <23))
	{
		bool status;
		status = true;
		float stime =1.0f;

		for (int i = st; i < sp; i++)
		{
			if (!isrush[i])
			{
				isrush[i] = (status);
			}
			else
			{
				stime = (float)i;
				std::cout << "Time Slot " << std::fixed << std::setprecision(2) << stime << "\thas been taken \n" << std::endl;
				
			}
		}

	}
	else
	{
		std::cout << "Invalid Time Input" << std::endl; //check statement
	}
}

Resourceallocator::~Resourceallocator()
{}


