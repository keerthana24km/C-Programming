#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//header file extension used to provide usability of the defined functions
#include "header_file.h"

/* Author : Keerthana K M
   Date : 25/07/2023 */

int main(){
	
	//Program 1 : Uppercase to Lowercase
	assert(upper_to_lower('H'));
	
	//Program 2 : Area of Circle
	printf("Area of Circle is %lf\n", area_of_circle(9.34));
	
	//Program 3 : Count of Number of characters between given two characters
	printf("The number of characters between given two characters is %d\n", in_between_characters('A','J'));
	
	//Program 4 : Celsius to Fahrenheit Conversion
	printf("Celsius to Fahrenheit = %f degrees\n", celsius_to_fahrenheit(25.16));
	
	//Program 5 : Check if a number is even or odd
	assert(even_or_odd(23));	//Usage of assert() for testing
	
	//Program 6 : Check if the given year is a leap year or not
	assert(leap_year_or_not(2012));
	
	//Program 7 : Powers of two using left shift
	printf("Exponential value of two is %d\n",power_of_two(8));
	
	//Program 8 : Given input is an integer or a character
	assert(char_or_int(74));
	
	//Program 9 : Sum of two random integer numbers
	printf("Sum of Two Random Numbers = %d\n", sum_of_two_numbers(rand(), rand()));
	
	return 0;
}
