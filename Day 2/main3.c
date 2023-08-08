#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "header.h"

/* Author: Keerthana K M
   Date: 26/07/2023 */

int main() {
	//Calling the functions with necessary inputs
	printf("Sum of five digits = %d\n", sum_of_5_digits(55555));
	printf("Reverse of five digits = %d\n", reverse_of_5_digits(42462));
	printf("Occurences of digit in a number = %d\n", occurences_of_digit(873961962));
	assert(palindrome_or_not(12121));
	first_n_primes(10);
	sum_of_series(4);
	assert(armstrong_or_not(153));
	assert(amicable_numbers(220,284));
	
	//User inputs taken to calculate sum/ difference/ product of two numbers based on menu choices
	int num1, num2;
	printf("Enter the first input integer ");
	scanf("%d",&num1);
	printf("Enter the second input integer ");
	scanf("%d",&num2);
	printf("Result = %d\n",menu(num1, num2));
	
	//Menu written to take inputs based on the shape whose volume is to be calculated
	double edge, radius, length, width, height;
	int choice;
	printf("Menu\n1.Volume of Cube\n2.Volume of Cuboid\n3.Volume of Sphere\n4.Volume of Cylinder\n5.Volume of Cone\nEnter your choice ");
	scanf("%d",&choice);
	switch(choice){
		case 1: if(choice==1){
			printf("Enter the edge of the cube "); //Taking only edge as input as volume of cube = (edge * edge * egde)
			scanf("%lf",&edge);
			printf("Volume = %lf\n",volume_cube(edge)); //Calling function to calculate volume of cube
			break;
		}
		case 2: if(choice==2){
			printf("Enter the length of the cuboid ");
			scanf("%lf",&length);
			printf("Enter the width of the cuboid ");
			scanf("%lf",&width);
			printf("Enter the height of the cuboid ");
			scanf("%lf",&height);
			printf("Volume = %lf\n",volume_cuboid(length,width,height));
			break;
		}
		case 3: if(choice==3){
			printf("Enter the radius of the sphere ");
			scanf("%lf",&radius);
			printf("Volume = %lf\n",volume_sphere(radius));
			break;
		}
		case 4: if(choice==4){
			printf("Enter the radius of the cylinder ");
			scanf("%lf",&radius);
			printf("Enter the height of the cylinder ");
			scanf("%lf",&height);
			printf("Volume = %lf\n",volume_cylinder(radius,height));
			break;
		}
		case 5: if(choice==5){
			printf("Enter the radius of the cone ");
			scanf("%lf",&radius);
			printf("Enter the height of the cone ");
			scanf("%lf",&height);
			printf("Volume = %lf\n",volume_cone(radius,height));
			break;
		}
	}
	
	//User input to define the number of units
	int units;
	printf("Enter the number of units ");
	scanf("%d",&units);
	printf("Total charges in Rs. = %lf\n",total_charge(units));
	
	//A and B are two arrays used as sets
	int A[8] = {1,2,3,4,1,6,9,8};
	int B[9] = {9,3,5,7,1,4,2,3,1};
	assert(intersection(A, B, 8, 9));
	return 0;
}


