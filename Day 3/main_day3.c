#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "header_day3.h" //includes all the functions present in functions_day3.c file

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Main function that contains the necessary print and assert statements for the respective functions
int main() {
	printf("Binary to Decimal = %d\n",binary_to_decimal(1011));
	printf("Decimal to Binary = %d\n",decimal_to_binary(5));
	assert(series_generate(7,0,0,1));
	//constant input of 4 passed in the function to get the necessary output
	assert(star1(4));
	assert(star2(4));
	//Length passed as input upto which the series is generated
	assert(sum_is_nine(4));
	printf("\nThe exponential form is given by %d\n",exponential_form(2,9));
	printf("Recursive form of the given number = %d\n",recursive_func(5));
	printf("Recursive result of the series = %d\n",recursive_function(3));
	//Functions called to print the output using macros
	concatenate();
	square_of_num();
	printf("Result = %lf\n",math_menu(23));
	return 0;
}
