//Drew Mares
//10-11-17
//Homework #4
//Problem # (Monte Carlo simulation, average length of polymer)
//average length = 56.5554
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
int TRIALS=0;

cout<<"This program will take an average of the distance between \n"
	<<"the start point and end point of a number of polymers. \n"
	<<"Please enter the number of polymers you would like to create. \n";
	
cin>>TRIALS;
double trials[TRIALS]={0};
double x_value=0, y_value=0, direction=0, distance=0;

//loop to creat multiple polymers in order to take the average distance
for(int polymers=0;polymers<TRIALS;polymers++)
{
	//loop to create the polymer
	for(int monomers=0;monomers<4000;monomers++)
		{
			//random direction of monomer being added
			direction=rand()/(32767/6.283185);
		
			//x_value of polymer
			x_value=x_value+cos(direction);
		
			//y_value of polymer
			y_value=y_value+sin(direction);
		}
	
	//storing distance from begginning to end in array
	distance = sqrt((pow(x_value,2)+pow(y_value,2)));
	trials[polymers]=distance;
	
	//clearing variables
	distance=0;
	x_value=0;
	y_value=0;
}

//declaring variables to use to find the average
double total=0,average=0;

//Finding average distance using values stored in array
for(int count=0;count<TRIALS;count++)
	total=trials[count]+total;
		
average=total/TRIALS;

//Final output with answer
cout<<"The average distance between the start point and end point of a polymer is "
	<<average<<" units";
return 0;
}

