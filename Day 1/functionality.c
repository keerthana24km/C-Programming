#include <stdio.h>
#include <ctype.h>

//Functionality to convert uppercase to lowercase
int upper_to_lower(char c){
	if(isupper(c)){
		printf("Character is in uppercase\n");
		char uptolow = tolower(c);
		printf("Converted lowercase character : %c\n",uptolow);
	}else printf("Character already in lowercase\n");
	return 1;
}

//To find the area of circle
double area_of_circle(double radius){
	return 3.14*radius*radius;	//area = pi_value x radius^2
}

//To find the number of characters between given two characters
int in_between_characters(char c1, char c2){
	int numOfChars = 0;
	if(isalpha(c1) && isalpha(c2)){
		if(toascii(c1)>toascii(c2)) numOfChars = toascii(c1) - toascii(c2) - 1;
		else numOfChars = toascii(c2) - toascii(c1) - 1;
	}
	return numOfChars;
}

//Conversion of Celsius to Fahrenheit
float celsius_to_fahrenheit(float degrees){
	return (degrees * 9/5) + 32;	//value of degrees in celsius
}

//To find if a number is even or odd
int even_or_odd(int num){
	if(0 == num%2) printf("%d is an even number\n", num);
	else printf("%d is an odd number\n", num);
	return 1;
}

//To find if the year is a leap year or not
int leap_year_or_not(int year){
	if(0 == year%4){
		if(0 == year%100){
			if(0 == year%400) printf("%d is a leap year\n",year);
			printf("%d is a leap year\n",year);
		}
		printf("%d is a leap year\n",year);
	}else printf("%d is not a leap year\n",year);
	return 1;
}

//To find powers of two using left shift operator
int power_of_two(int exponent){
	return 2<<(exponent-1);
}

//To check if the given input is an integer or a character
int char_or_int(int c){
	if(c==0 || c==1 || c==2 || c==3 || c==4 || c==5 || c==6 || c==7 || c==8 || c==9) printf("%d is an integer number\n",c);
	else if(isascii(c)){
		if(isupper(c)) printf("%c is a character\n",toupper(c));
		else if(islower(c)) printf("%c is a character\n",tolower(c));
	}
	else printf("Invalid Input\n");
	return 1;
}

//To find out the sum of two random integer numbers
int sum_of_two_numbers(int val1, int val2){
	return val1 + val2;
}

