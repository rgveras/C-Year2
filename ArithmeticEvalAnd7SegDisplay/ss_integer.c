//CS2211b 2023
//Assignment 3
//Ricardo Veras
//250692934
//rveras
//Monday, February 27, 2023

#include <stdio.h>
#include <stdbool.h>

//This program receives a single user inputted integer digit and displays it in seven-segment display format
int main() {
	const char segments[10][3][3] = { { {' ', '_', ' '}, {'|', ' ', '|'}, {'|', '_', '|'} }, { {' ', ' ', ' ',}, {' ', ' ', '|'}, {' ', ' ', '|'} }, { {' ', '_', ' '}, {' ', '_', '|'}, {'|', '_', ' '} }, { {' ', '_', ' '}, {' ', '_', '|'}, {' ', '_', '|'} }, { {' ', ' ', ' '}, {'|', '_', '|'}, {' ', ' ', '|'} }, { {' ', '_', ' '}, {'|', '_', ' '}, {' ', '_', '|'} }, { {' ', '_', ' '}, {'|', '_', ' '}, {'|', '_', '|'} }, { {' ', '_', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'} }, { {' ', '_', ' '}, {'|', '_', '|'}, {'|', '_', '|'} }, { {' ', '_', ' '}, {'|', '_', '|'}, {' ', '_', '|'} } };
	char decision;			//User inputted decision to continue or end the program
	int input;
	bool negative=false;		//Set to true if the user input is negative


	printf("Please enter an integer: ");
	scanf(" %d", &input);		//Store users integer in variable "input"

	printf("You inputted: %d \n", input);


	//Print the characters that make up the digit in the seven-segment display format, in 3 lines each consisting of 3 characters
	for(int i=0; i<3; i++) {

		//If the input was negative it is converted to positive to continue printing the characters and boolean variable negative is set to true
		if(input<0) {
			negative = true;
			input *= -1;
		}

		//If the input was negative, a negative sign is printed before the middle segment of the number is printed
		if(negative==true && i==1) printf(" - ");
		
		else printf("   ");		//Spaces are set before printing the characters that make up the number in order to fit a negative sign if necessary

		for(int j=0; j<3; j++) {
			printf("%c", segments[input][i][j]);		//Print 3 characters per line to display the digit in seven-segment display format
		}
		printf("\n");						//Create a new line to print the next 3 characters
	}

	printf("Would you like to continue? (Y/N): ");
	scanf(" %c", &decision);

	if(decision == 'Y') main();					//If the user enters "Y" to continue, the program is recursively called
	else if(decision == 'N') return 0;				//If user enters "N" the progran is terminated
	else printf("Invalid response. Program terminating. \n");	//If any other character is inputted by the user, a response is printed and program terminated
	
return 0;
}
