/*
Author: Anthony Tortola
Date: Fall 2018
Description: This program will run a personal ATM for the user. It will ask for the users starting balance. 
Next it will display a menu giving the user the option to credit, debit, show current balance, or exit.
*/
#include<stdio.h>
#include<stdbool.h>

float balance;


//Gets the amount the user starts with as his balance
float getAmount()
{

	float amount;

	while(1){

		printf("Enter the amount currently in your bank: ");
		scanf("%f",&amount);
		if(amount > 0)break;
		printf("The amount should be greater than 0!\n");
	}

return amount;

}

void initBalance(float amount)
{

balance = amount;

}

//Will display the choices for the user and if a numer is entered that is not between 1 and 4 it will have an invalid input.
int displayMenu()
{

	int choice;

	while(1){

		printf("1: credit money to the account \n2: debit money from the account\n3: display the current balance\n4: exit\n");
		scanf("%d",&choice);
		if(choice >= 1 && choice <= 4)return choice;
			printf("Invalid choice\n\n");

		}

	}

//Adds money to the balance
void creditMoney(float credit)
{

	if(credit <= 0)return;
	balance += credit;

}
//Takes money from the balance, if there isn't enough money it will display an error message
bool debitMoney(float debit)
{

	if(debit > balance){
		printf("You don't have enough credit\n");
		return false;
	}
	
	balance -= debit;
	return true;

}
//counts the number of transactions
int countTransaction()
{
static int count = 0;
return ++count;

}

int main(void)
{

    int cmd;    
	printf("Please enter initial balance.\n");
	initBalance(getAmount());
    float credit,debit;

	while(1){   

		cmd = displayMenu();

		switch(cmd){

			case 1:{								
				printf("Enter credit amount: ");
				scanf("%f",&credit);
				creditMoney(credit);
				break;
			}

			case 2:{
				printf("Enter debit amount: ");
				scanf("%f",&debit);
				debitMoney(debit);
				break;
			}

			case 3:{
				printf("Current balance: $%.2f\n\n",balance);
				break;
			}

			case 4:{
				printf("Thank you for visit \n");
				break;
			}

		}
		if(countTransaction() > 4 || cmd == 5){		//Will end the program if the number of transactions is greater than 5
			break;
		}										
	}

	return 0; 
}
