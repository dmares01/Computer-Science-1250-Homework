//Student name:Drew Mares
//Date:10-3-2017
//Homework # 4b
//Problem # distributions of coin flips

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;
int a[1000000];
 
int main()
{
int count=0;
double heads=0, perchantage=0;
	
cout<<"Please enter the perchantage (as a decimal) for how often \n"
	<<"heads will appear on a coin. For a fair coin you would \n"
	<<"enter .5 into the program. Unfair coins are represented \n"
	<<"by any other perchantage. The program will then output the\n"
	<<"number of times heads appears out of 100 for 1 million trials\n"
	<<"Enter your perchantage below \n";
		
cin>>perchantage;
	
for(int trials=0; trials<1000000; trials++)
{
	for(int flips=0;flips<100;flips++)
	{
		heads=rand()/32767.0;
		
		if((heads>=0)&&(heads<=perchantage))
			count++;
	}
	
	a[trials]=count;
	count=0;
}
	
int number=0,result=0,total=0;
		
while(result<=100)
{	
	while(number<1000000)
	{
	
		if (a[number]==result)
			total++;
			
		number++;
	}
	number=0;
	
	cout<<result<<'\t'<<total<<'\t';
	
	if(total>0)
	{
		total=total/1500;
		
		for(int asteriks=0;asteriks<total;asteriks++)
			cout<<'*';
	}
	
	cout<<endl;
	result++;
	total=0;
	
}

return 0;
}
