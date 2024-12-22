//CS2211b 2023
//Assignment 2
//Ricardo Veras
//Student #: 250692934
//rveras@uwo.ca
//Sunday, February 5, 2023

#include <stdio.h>
double power(double base,int exp);

//The main function receives user input for a base number and its exponent and then calls a function to calculate the value
//It then displays the result and terminates if the exponent was zero, otherwise it recursively calls itself to produce another result
int main()
{
	double base, result;
	int exp;

	//Requests user input and stores the value in the variable "base"
	printf("Please enter a base number to calculate an exponential for: ");
	scanf("%lf", &base);

	//Requests user input and stores the value in the variable "exp"
	printf("Please enter the exponent you would like to calculate for that base(Enter 0 to quit the program): ");
	scanf("%d", &exp);

	result = power(base, exp);	//Calls the function power() to calculate the result of the base to its exponent

	if (exp == 0)	//If the exponent is zero, the result is displayed and the program terminated
	{
		printf("The value of %lf^%d = %lf \n", base, exp, result);
		return 0;
	}

	else	//If the exponent is not zero, the result is displayed and main() calls itself to provide another result for the user
	{
		printf("The value of %lf^%d = %lf \n", base, exp, result);
		main();
	}

	return 0;
}

//This function calculates the value of a base number to its exponent
double power(double base, int exp)
{
	
	if (exp == 0)	
		return 1;

	else if (exp > 0)
		return base*power(base, exp-1);	//If the exponent is positive the result is calculated recursively and returned

	else
		return 1/power(base, -exp);	//Recursively calculates the result if the exponent is negative
}



