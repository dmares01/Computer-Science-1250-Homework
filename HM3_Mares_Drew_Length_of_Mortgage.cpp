
//Drew Mares
//9-20-17
//Homework #3
//Problem: Length of Mortgage
//Number of Months = 244,Last Payment = 603.61

#include <iostream>
using namespace std;
int main()

{
	int time = 0; //number of months
	double balance = 240000; //Price of House
	
	cout<< "If you purchase a $240,000 home this program \n"
		<< "will tell you how many months it will take to pay off your mortgage.\n"
		<< "This program assumes three things.\n"
		<< "First, that the down payment is equal to $40,000\n"
		<< "Second, the interest for the first three years is eqaul to 6%.\n"
		<< "Third, the interest moves to 7% after those first three years\n\n\n";
	
	balance = balance - 40000; //subtracting down payment
	
	{
	
		while (time < 36)
		{
			time = time + 1;
			balance = balance * (1+ (.06/12));
			balance = balance - 1500;
			cout.setf(ios::fixed);
			cout.precision(2);
			if (time % 24 == 0)
			cout<<"For month "<< time <<" your balance is $"<<balance<< endl;
		}
	
		while (time >= 36 && balance > 1500)
	
		{
			time = time + 1;
			balance = balance * (1 + (.07/12));
			balance = balance - 1500;
			cout.setf(ios::fixed);
			cout.precision(2);
			if (time % 24 == 0)
			cout<<"For month "<< time <<" your balance is "<<balance<< endl;
		}
		
		while (balance < 1500 && balance > 0)
		{
			time = time + 1;
			cout.setf(ios::fixed);
			cout.setf(ios::showpoint);
			cout.precision(2);
			cout << "Your final payment will be in month "<<time<< " for $"<<balance<<endl;
			balance = balance - balance;
		}
	}
	cout<<"\nYour home will be completly paid off in approximately "<<time/12<<" years.\n";
	
	return (0);
}
