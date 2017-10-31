//Drew Mares
//Date:11-2-17
//Homework # 9b
//Problem # convert from XY to polar coord
#include <iostream>
#include <cmath>

void convert_XY_to_polar(double& x, double& y, double& r, double& theta);
//Precondition: x and y are the (x,y) coordinates of a point in the XY plane.
//Postcondition: r and theta are the polar coordinates (r,theta) that correspond to (x,y)
void convert_polar_to_XY(double& x, double& y, double& r, double& theta);
//Precondition: r and theta are the (r,theta) coordinates of a point in the polar plane.
//Postcondition; x and y are the cartesian coordinates that correspond to (r,theta)
int main()
{
int selection=0;
double x=0,y=0,r=0,theta=0;

std::cout<<"Would you like to convert from cartesian to polar,\n"
		 <<"or from polar to cartesian?\n";
do
{
	std::cout<<"Enter 1 for cartesian to polar\n"
			 <<"Enter 2 for polar to cartesian\n";
	std::cin>>selection;
	switch (selection)
	{
		case 1:
			std::cout<<"Please enter in an x and y coordinate pressing enter after each coordinate\n";
			std::cin>>x>>y;
			convert_XY_to_polar(x,y,r,theta);
			std::cout<<"r is equal to "<<r<<'\t'<<"theta is equal to "<<theta;
			break;
		
		case 2:
			std::cout<<"Please enter in 'r' and 'theta' pressing return after each\n";
			std::cin>>r>>theta;
			convert_polar_to_XY(x,y,r,theta);
			std::cout<<"x is equal to "<<x<<'\t'<<"y is equal to "<<y;
			break;
		default:
			std::cout<<"That is not a possible option.\n\n";
	}
}while((selection !=1)&&(selection!=2));

return 0;
}


void convert_XY_to_polar(double& x, double& y, double& r, double& theta)
{
	r=sqrt(pow(x,2)+pow(y,2));
	//inverse tan can be created by cos over sin
	theta=atan(y/x);
}

void convert_polar_to_XY(double& x, double& y, double& r, double& theta)
{
	x=r*cos(theta);
	y=r*sin(theta);
	x=round(x);
	y=round(y);
}

