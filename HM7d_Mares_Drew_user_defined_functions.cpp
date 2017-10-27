//Drew Mares
//Date:10/25/17
//Homework # 7d
//Problem # user-defined functions 

#include <iostream>
#include <cstdlib>

unsigned int mod(unsigned int a, unsigned int b); //function declaration, like table of contents
/*
Precondition: a and b are non-negative integers
Postcondition: function calculates and returns a mod b
*/
double mod_like_func(double a, double b);
/*
Precondition: a and b are doubles
Postcondition: function generalizes notion of "mod" and returns a "mod" b
*/
void print_histogram(int a[], int array_size);
/*
Precondition: a is an array of ints
Postcondition: function prints out 
1) value of a[i]
2) tab
3) a bar graph that displays a[i] visually and "efficiently" uses 
the width of the screen
*/
int random(int begin, int end);
/*
Precondition: we have an interval [begin, end] whose size is at most RAND_MAX
(You can assume that (end - begin) + 1 is <=  32768.)
Postcondition: returns an integer in the interval with uniform distribution.  
*/
double random_decimal(double begin, double end);
/*
Precondition: we have an interval [begin, end] in which begin and end are decimal fractions.
Postcondition: returns a decimal fraction in the interval with uniform distribution. 
*/
int logarithm_lower_bound(double x, double base);
/*
Precondition: input consists of two decimal fractions, x and the base for our logarithm
Postcondition: function calculates the greatest integer that is less than log_base(x)
Example: 3 < log_2(10) < 4.  Thus, given the function call, logarithm_lower_bound(10, 2),
the function will return 3.
Directions: you cannot use cmath
*/
double power(double x, int n);
/*
Precondition: x is a decimal fraction and n is an integer
Postcondition: function calculates x^n
*/
double root(double x, int n);
/*
Precondition: x is a decimal fraction and n is an integer
Postcondition: function calculates x^(1/n)
*/
double logarithm(double x, double base);
/*
This problem is extra credit.
Precondition: input consists of two decimal fractions, x and the base for our logarithm
Postcondition: function calculates log_base(x) to two decimal places.
Example:  Given the function call, logarithm(12, 2),
the function will return 3.58.
If you cannot solve this problem, have the function return -1.
Directions: you cannot use cmath
*/
int main()
{
	//std::cout << 5.5 % 6.28 << std::endl; //Note: % requires two ints
	//std::cout << mod(5,3) << std::endl;
	char dummy;
	std::cout << "Here we call mod."<<std::endl;
	for (int i = 0 ; i < 20; i++)
	{
		double approx = i;
		int j = 3;
		std::cout << mod(i,j) <<'\t' << mod_like_func(i, 3.14)<< std::endl;
	}
	std::cin >> dummy;	
	std::cout<<"Now we print a histogram"<<std::endl;
	int SIZE = 100;
	int histogram[SIZE]={0};
	histogram[0]=0;
	histogram[1]=1;
	for (int i = 2; i < SIZE; i++)
		histogram[i] = (histogram[i-1]+histogram[i-2]) % (INT_MAX/2);
		print_histogram(histogram, SIZE);
	std::cin >> dummy;
	std::cout << "Now we print out 10 rolls of a die"<<std::endl;
	for (int i=0; i<10; i++)
		std::cout<<random(1,6)<<std::endl;
	std::cin >> dummy;
	std::cout << "Now we print out 10 decimal fractions in the interval [0,1]"<<std::endl;	
	for (int i = 0; i < 10; i++)
		std::cout<<random_decimal(0,1)<<std::endl;
	std::cin >> dummy;
	std::cout << "Now we print out a lower bound on log_2(12)"<<std::endl;
	std::cout << logarithm_lower_bound(12,2)<<std::endl;
	std::cin >> dummy;
	std::cout << "Now we print out 10^2"<<std::endl;	
	std::cout << power(10,2)<<std::endl;
	std::cin >> dummy;
	std::cout << "Now we print out the 10th root of 2"<<std::endl;	
	std::cout << root(2,10)<<std::endl;
	std::cin >> dummy;
	std::cout<<"Enter a positive decimal fraction greater than 1 for x."<<std::endl;
	double x;
	std::cin >> x ; 
	std::cout << "Now we print out log_2(x)"<<std::endl;
	std::cout << logarithm(x,2)<<std::endl;
	return 0;

}

unsigned int mod(unsigned int a, unsigned int b)
{
	while (a>=b)
		a=a-b;
	return a;
}

double mod_like_func(double a, double b)
{
	while(a>=b)
		a=a-b;
	return a;
}

void print_histogram(int a[], int array_size)
{
	for (int count=0;count<=100;count++)
	{
		std::cout<<a[count]<<'\t';
	
		double total =0;
		total=a[count]/10000000;
	
		while(total>0)
		{
			std::cout<<'*';
			total--;
		}
		std::cout<<std::endl;
	}
}
int random(int begin, int end)
{
	int x=0,y=0;
	x=rand()/(RAND_MAX/end);
	if((x>=begin)&&(x<=end))
		y=x;
	return y+1;
}

double random_decimal(double begin, double end)
{
	double x=0,y=0;
	x=rand()/((RAND_MAX-.000001)/end);
	{
		y=x;
	}
	return y;
}

int logarithm_lower_bound(double x, double base)
{
	double exponent=0,original_base=base;
	while(base<x)
	{
		base=base*original_base;
		exponent++;
	}
	return exponent;
}

double power(double x, int n)
{
	
	double y=x;
	while (n>1)
	{
		x=x*y;
		n--;
	}
	return x;
}

double root(double x, int n)
{
	double y=0, lower_bound =0,lower_bound_initial=0;
	double upper_bound =x,upper_bound_initial=x, distance =0;
	int n_initial=0;
	n_initial=n;
	while ((y>(x+.0000001))||(y<(x-.0000001)))
	{
		while(n>1)
		{
			lower_bound=lower_bound*lower_bound_initial;
			upper_bound=upper_bound*upper_bound_initial;
			n--;
		}
		y=upper_bound;
		
		if((lower_bound<=x)&&(upper_bound>x))
		{
			distance=(upper_bound_initial+lower_bound_initial)/2;
			upper_bound_initial=distance;
		}	
		else
		{
			upper_bound_initial=(distance*2)-lower_bound_initial;
			distance=(lower_bound_initial+upper_bound_initial)/2;
			lower_bound_initial=distance;
			
		}
		upper_bound=upper_bound_initial;
		lower_bound=lower_bound_initial;
		n=n_initial;
	}
return upper_bound_initial;
}

double logarithm(double x, double base)
{
return (-1);	
}
