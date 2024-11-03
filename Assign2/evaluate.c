//CS2211b 2023
//Assignment 3
//Ricardo Veras
//250692934
//rveras
//Friday, March 3, 2023

#include <stdio.h>
#include <stdlib.h>

float sim_sub_exp(float sub_exp);
float md_sub_exp(float sub_exp);
float sim_exp();
float md_exp();
float get_num();
char get_op();


//This program takes a simple arithmetic expression and calculates the result.
//Two functions, sim_sub_exp() and md_sub_exp() are used to calculate expressions with + or - and * or /, respectively
//get_op() and get_num() are used within the functions to locate their values from stdin
//sim_exp and md_exp are used to do the calculations in the correct order of operations
//The final result of the calculation is printed once the end of the expression is reached, giving the resulting value 
int main(void) {

	char op;
	float result;			//Store final calculated value
	char decision;			//Store user's decision to continue or end the program 

	printf("Please input expression: ");

  do {
    result = sim_exp();			//Continue calculations until the end of the expression is reached
    op = get_op();
  }  while (op != '\n');

  printf("The calculated result is: %f\n", result);	//Print the resulting value after the entire simple arithmetic expression has been calculated

  printf("Enter Y to continue or N to exit: ");
  scanf(" %c", &decision);
 
  if (decision == 'Y') main();		//Recursively call main if the user would like to calculate another simple arithmetic expression
  
  else if (decision == 'N') {
	  printf("Exiting program.\n");
	  return 0;
  }
  else {
	  printf("Invalid decision.\n");	//If the decision entered is not 'Y' or 'N', a message is printed and the program terminated
	  exit(EXIT_FAILURE);
  }

  return 0;
}


//Find and return the next character in the simple arithmetic expression
char get_op() {
	char c;
	
	do scanf("%c", &c);
	while (c == ' ');		//Iterate through stdin until a non-whitespace character is found
	
	return c;			//Return the next character found in stdin
}


//Find and return the next number in the arithmetic expression
float get_num() {
	float f;
	scanf(" %f", &f);		//Locate next number in the arithmetic expression from stdin
	
	return f;			//Return the next number of the expression
}


//Calculate the sub-expressions consisting of '+' or '-' operators
float sim_sub_exp(float sub_exp) {
	float next_sub_exp;	
	char next_op = get_op();

	if (next_op == '\n') {
		ungetc(next_op, stdin);				//If the next operator is a newline character it is pushed back to stdin
		return sub_exp;
	}

	else if (next_op == '+' || next_op == '-') {
		float next_md_exp = md_exp();			//Any adjacent sub-expressions containing '*' or '/' are calculated and stored in next_md_exp
		
		if (next_op == '+') {
			next_sub_exp = sub_exp + next_md_exp;	//next_md_exp is added to the current sub_exp if operator is '+'
			
			return sim_sub_exp(next_sub_exp);	//Addition and subtraction expressions are calculated by recursively calling sim_sub_exp()
		}

		if (next_op == '-') {		
			next_sub_exp = sub_exp - next_md_exp;	//next_md_exp is subtracted from the current sub_exp if operator is '-'
			
			return sim_sub_exp(next_sub_exp);	//Addition and subtraction expressions are calculated by recursively calling sim_sub_exp()
		}
		else {
			printf("Invalid operator inputted.\n");	//If the next operator was not '-', '+', or the end of the expression '\n', a message is printed 
			exit(EXIT_FAILURE);			//Program exits if an invalid operator is entered
		}
	}
}


//Any sub expressions containing '*' or '/' are calculated by calling md_exp() and storing the value in m
//This value is then calculated with remaining sub expressions containing '+' or '-' by calling sim_sub_exp(m)
float sim_exp() {

	float m = md_exp();

	return sim_sub_exp(m);
}


//This function calculates sub expressions containing '*' or '/' 
float md_sub_exp(float sub_exp) {

	float next_num;
	float next_sub_exp;
	char next_op = get_op();
	
	//If the next operator is the end of the line, '+', or '-', it is pushed back to stdin and the current sub_exp is returned
	if (next_op == '+' || next_op == '-' || next_op == '\n') {
		
		ungetc(next_op, stdin);

		return sub_exp;

	} else if (next_op == '*') {
		
		next_num = get_num();
		next_sub_exp = sub_exp * next_num;	//If the next operator is '*', the current sub expression is multiplied by the next number
		
		return md_sub_exp(next_sub_exp);	//Recursively call md_sub_exp() with the calculated value to solve any remaining multiply/division sub expressions 

	} else if (next_op == '/') {
                
		next_num = get_num();

		//If the next number after a division is zero, a divide by zero message is printed, and the program terminated
		if (next_num == 0) {
			printf("Divide by zero error.\n");
			exit(EXIT_FAILURE);
		}

                next_sub_exp = sub_exp / next_num;	//If next_op is '/', the current sub expression is divided by the next number

                return md_sub_exp(next_sub_exp);	//Recursively call md_sub_exp() with the calculated value to solve remaining multiply/division sub expressions

	} else {
		
		printf("Incorrect operator inputted.\n");	//A message is printed if an invalid operator is entered and the program is terminated
		exit(EXIT_FAILURE);
	}

	return sub_exp;					//The final value after all multiply/division sub expressions are calculated is returned
}


//The next number is stored in m and md_sub_exp(m) is returned in order to return any values calculated from sub expressions with '*' or '/'
float md_exp() {

	float m = get_num();
	
	return md_sub_exp(m);
}
