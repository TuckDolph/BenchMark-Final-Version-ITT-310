/*Point of Sale System V3*/
/*Vape Shop Juice Menu*/

//inports stdio header file and errno header file
#include<stdio.h>
#include<errno.h>
#include <stdlib.h>
#include <string.h>

extern int errno;

//start of main function
void main(void) {
	int code, qty, errnum;
	float price, amt, cash, change, totalAmt;
	double tax_rate, tax;
	char addAnother;
	//do loop allowing for more than 1 order
	do {
		//visual menu printed out with item code number and price
		system("cls");
		printf("===============\n");
		printf("Vape Juice Menu\n");
		printf("===============\n\n");
		printf("[1] House Juice 30ml\tUSD $10.00\n");
		printf("[2] House Juice 60ml\tUSD $15.00\n");
		printf("[3] House Juice 120ml\tUSD $20.00\n");
		printf("[4] Premium Juice 60ml\tUSD $20.00\n");
		printf("[5] Premium Juice 120ml\tUSD $25.00\n");

		//input prompt for item code and quantity
		printf("\nEnter Item Code: ");
		scanf_s("%d", &code);
		printf("\nEnter Quantity\t: ");
		scanf_s("%d", &qty);

		//Error handling

		if (code > 5 || code < 1)
		{
			fwrite("[ERROR} : Enter 1-5 only for Item code!!!", 39, 1, stderr);
			exit(EXIT_FAILURE);
		}

		//while loop for when code > 0
		while (code > 0 || code <= 5) {
			//switch function changing variable code into a new varible price for future function
			switch (code) {
			case 1: price = 10.00;
				break;
			case 2: price = 15.00;
				break;
			case 3: price = 20.00;
				break;
			case 4: price = 20.00;
				break;
			case 5: price = 25.00;
				break;

			}
			break;
		}

		//function to determing amount owed after user input
		amt = price * qty;
		printf("\nAmount owed is: %.2f", amt);
		tax_rate = 9.18;
		tax = amt * (tax_rate / 100);
		totalAmt = 0 + amt + tax;
		printf("\nTotal amount\t: %.2f", totalAmt);
		printf("\nAdd another order (y/n)? ");
		addAnother = getch();//This is get character for the print prompt above
	} while (addAnother == 'y' || addAnother == 'Y');

	printf("\nCash Tendered: ");
	scanf_s("%f", &cash);

	change = cash - totalAmt;
	printf("\nChange\t\t: %.2f", change);
}