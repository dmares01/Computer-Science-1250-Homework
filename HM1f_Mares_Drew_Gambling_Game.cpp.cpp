//Drew Mares
//9-24-2017
//Homework #1f
//Problem #A gambling game
//Decision: No I don't want to play the game
/*	The program always ends up hitting $1 before it hits 1000 turns.
	This means that you would always win, and I would only lose money 
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(const char* cout, int cin)
{
int randomNumber=0,my_balance=100000000,your_balance=100000000,table_balance=0;
int turn;

cout<<"Enter in how much money you would like to start betting\n";
cin>>table_balance;
cout<<"There is "<<table_balance<<" dollars on the table.\n";
	
while (turn < 1000 && table_balance > 1) 
{

	if (table_balance % 2 == 1)
		{
			my_balance = my_balance-table_balance;
			your_balance = your_balance-table_balance;
			table_balance = table_balance * 3;
			turn++;
			
    		randomNumber = rand()% 2 ;
    		
			if (randomNumber=0)
			{
				your_balance = your_balance - 1;
				table_balance = table_balance + 1;
			}
			else
			{
				my_balance = my_balance - 1;
				table_balance = table_balance + 1;
			}
		}
	else
	{
		my_balance = my_balance + (table_balance/2);
		table_balance = table_balance/2;
		turn++;
	}
	cout<<table_balance<<"\t\t"<<turn<<endl;	
}
cout<<endl<<endl;

 if(turn==1000)
 {
 	cout<<"I won "<<table_balance + (my_balance-100000000)<<" dollars.";
 }
 else
 {
 	cout<<"You have swindled "<<table_balance +(my_balance-100000000);
	cout<<" dollars from me. Gongratulations! \n";
 }
 return(0);  
}
