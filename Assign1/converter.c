//CS2211b 2023
//Assignment 2
//Ricardo Veras
//Student #: 250692934
//rveras@uwo.ca
//Sunday, February 5, 2023


#include <stdio.h>
//This program converts units both ways for Celsius-Fahrenheit, Centimetre-Inch, Kilogram-Pound and Meter-Feet.
//The conversion is processed and displayed using a function for each conversion.
//The main function receives user input to identify which conversion function to call or whether to quit the program

int convertTemp();
int convertCmToInch();
int convertWeight();
int convertMeterToFeet();

int main()
{
	char convert;	//Stores user input to determine which action to take

	printf("Enter a character for the following actions:\n\t1 for conversion between Celsius and Fahrenheit\n\t2 for conversion between Centimetre and Inch\n\t3 for conversion between Kilogram and Pound\n\t4 for conversion between Meter and Feet\n\tq for quit\n\tQ for quit\n\t\t");

	scanf(" %c", &convert);	//Stores user input in variable "convert"

	//The following if statements call the conversion function the user requests based on their input value, or quits if "q" or "Q" is entered
	if (convert == '1')
		convertTemp();

	if (convert == '2')
		convertCmToInch();

	if (convert == '3')
		convertWeight();

	if (convert == '4')
		convertMeterToFeet();

	if (convert == 'q' || convert == 'Q')	//Quits if user input is "q" or "Q"
			return 0;
	
	main();	//Recursively calls main() if the user input does not match any specified value

}

//This function converts temperature both ways, between degrees Celsius and Fahrenheit
int convertTemp()
{
	char direction;	//User inputted value will specify direction to convert
	float num;	//Users number to be converted

	printf("To convert from Celsius to Fahrenheit, please type C\nTo convert from Fahrenheit to Celsius, please type F\n\t");

	scanf(" %c", &direction);

	//If the user inputs "C" they are asked to input a number in degrees Celsius which is then converted and displayed in Fahrenheit
	if (direction == 'C') {
		printf("Please input a number: ");
		scanf(" %f", &num);

		printf("%f degrees celsius is: %f degrees fahrenheit.\n\n", num, num*1.8 + 32.0);
		return 0;
	}

	//If the user inputs "F" they are asked to input a number in degrees Fahrenheit which is then converted and displayed in Celsius
	if (direction == 'F') {
		printf("Please input a number: ");
		scanf(" %f", &num);

		printf("%f degrees fahrenheit is: %f degrees celsius.\n\n", num, (num-32)/(5.0/9.0));
		return 0;
	}

	else convertTemp();	//If the user inputs anything other than "C" or "F" the convertTemp() function is recursively called to ask again

}

//This function converts between Centimetres and Inches in both directions 
int convertCmToInch()
{
	char direction;	//User inputted value will specify which direction to convert
	float num;	//Users number to be converted

	printf("To convert from Centimetres to Inches, please type C\nTo convert from Inches to Centimetres, please type I\n\t");

	scanf(" %c", &direction);
	
	//If the user inputs "C" they are asked to input a number in Centimetres which is then converted to Inches and displayed
	if (direction == 'C') {
                printf("Please input a number: ");
                scanf(" %f", &num);

                printf("%f centimetres in inches is: %f inches.\n\n", num, num*0.394);
		return 0;
        }

	//If the user inputs "I" they are asked to input a number in Inches which is then converted and displayed in Centimetres
        if (direction == 'I') {
                printf("Please input a number: ");
                scanf(" %f", &num);

                printf("%f inches in centimetres is: %f centimetres.\n\n", num, num*2.54);
		return 0;
        }

        else convertCmToInch();	//Recursively calls itself if user input does not match any specified value

}

//This function converts between Kilograms and Pounds in both directions
int convertWeight()
{
        char direction;	//User inputted value will specify which direction to convert
        float num;	//Users number to be converted

        printf("To convert from Kilograms to Pounds, please type K\nTo convert from Pounds to Kilograms, please type P\n\t");

        scanf(" %c", &direction);

	//If user input "K" they are asked to input a number in Kilograms which is then converted to Pounds and displayed
        if (direction == 'K') {
                printf("Please input a number: ");
                scanf(" %f", &num);

                printf("%f kilograms in pounds is: %f pounds.\n\n", num, num*2.205);
		return 0;
        }

	//If user inputs "P" they are asked to input a number in Pounds which is then converted and displayed in Kilograms
        if (direction == 'P') {
                printf("Please input a number: ");
                scanf(" %f", &num);

                printf("%f Pounds in Kilograms is: %f kilograms.\n\n", num, num*0.454);
		return 0;
        }

        else convertWeight();	//Function recursively calls itself if user input does not match any specified values

}

//This function converts both ways between Meters and Feet
int convertMeterToFeet()
{
        char direction;	//User inputted value will specify which direction to convert
        float num;	//Users number to be converted

        printf("To convert from Meters to Feet, please type M\nTo convert from Feet to Meters, please type F\n\t");

        scanf(" %c", &direction);

	//If the user inputs "M" they are asked to input a number in Meters which is then converted and displayed in Feet
        if (direction == 'M') {
                printf("Please input a number: ");
                scanf(" %f", &num);

                printf("%f metres in feet is: %f feet.\n\n", num, num*3.2808);
		return 0;
        }

	//If the user input "F" they are asked to input a number in Feet which is then converted and displayed in Meters
        if (direction == 'F') {
                printf("Please input a number: ");
                scanf(" %f", &num);

                printf("%f feet in metres is: %f metres.\n\n", num, num*0.30488888888);
		return 0;
        }

        else convertMeterToFeet();	//Function recursively calls itself if user input does not match any specified values

}
