#include <math.h>
#include <stdio.h>
#define I 1 //I defined as constant one throughout the program

//To convert a binary number to a decimal number
int binary_to_decimal(int num){
	int count = 0,n = num,i = 0,var = 0,dec = 0;
	while(n!=0){
		n/=10;
		count++;
	}
	for(i=0;i<count;i++){
		var = num%10;
		dec += var*pow(2,i);
		num/=10;
	}
	return dec;
}

//To convert a decimal number to binary number
int decimal_to_binary(int num){
	int i = 0,var = 0,bin = 0,j = 0;
	while(num!=0){
		var = num%2;
		bin += var*pow(10,i);
		num/=2;
		i++;
	}
	bin += num*pow(10,i);
	return bin;
}

//To generate a series of numbers resulting in sum of three previous numbers
int series_generate(int length, int n1, int n2, int n3){
	int i = 0, n4 = 0;
	printf("Series = %d,%d,%d,",n1,n2,n3);
	for(i=4;i<=length;i++){
		printf("%d,",(n1+n2+n3));
		n4 = n1+n2+n3;
		n1 = n2;
		n2 = n3;
		n3 = n4;
	}
	printf("\n");
	return 1;
}

//stars displayed based on number of rows in downward right angled triangle format
int star1(int num_rows){
	int i=0;
	for(i=num_rows;i>=1;i--){
		if(i==1) printf("   *\n");
		else if(i==2) printf("  **\n");
		else if(i==3) printf(" ***\n");
		else if(i==4) printf("****\n");
	}
	return 1;
}

//stars displayed based on number of rows in upward left-sided right angled triangle format
int star2(int num_rows){
	int i = 0;
	for(i=1;i<=num_rows;i++){
		if(i==1) printf("*\n");
		else if(i==2) printf("*\t*\n");
		else if(i==3) printf("*\t*\t*\n");
		else if(i==4) printf("*\t*\t*\t*\n");
	}
	return 1;
}

//To find numbers whose sum of digits is nine
int sum_is_nine(int length){
	int i = 0, var1 = 0, var2 = 0;
	while(length!=0){
		for(i=1;i>0;i++){
			var1 = i%10;
			var2 = i/10;
			if(9 == var1+var2 && var2!=0){
				printf("%d,",i);
				length--;
			}
			if(length==0) break;
		}
	}
	return 1;
}

//Recursive function to find exponential forms of a base number
int exponential_form(int base, int exp){
	if(0==exp) return 1;
	else if(1==exp) return base;
	else return (base * exponential_form(base,exp-1));
}

//Recursive funtion to find factorial of a number
int recursive_func(int num){
	if(0==num) return 0;
	else if(1==num) return 1;
	else return num*recursive_func(num-1);
}

//Recursive function to find sum of series of a number
int recursive_function(int x){
	int i = I+2;
	return x + ((pow(x,i))/(i)*recursive_func(i-1));
}

//Concatenating numbers using macros
#define X 3
#define Y 4
#define Z X*10+Y
void concatenate(){
	printf("Concatenated numbers %d and %d = %d\n",X,Y,Z);
}

//Finding square of a number using macros
#define A 5
#define SQUARE A*A
void square_of_num(){
	printf("Square of the number %d is %d\n",A,SQUARE);
}

//A menu driven function that introduces some of the math.h functionalities
double math_menu(double num){
	int choice = 0, n = 0;
	printf("Menu\n1.Square root of a number\n2.Natural log of a number\n3.Log to the base 10 of x\n4.Power of x to n\n5.Cos of x\nEnter your choice ");
	scanf("%d",&choice);
	switch(choice){
		case 1: if(choice==1){
			return sqrt(num);
			break;
		}
		case 2: if(choice==2){
			return log(num);
			break;
		}
		case 3: if(choice==3){
			return log10(num);
			break;
		}
		case 4: if(choice==4){
			printf("Enter the power ");
			scanf("%d",&n);
			return pow(num,n);
			break;
		}
		case 5: if(choice==5){
			return cos(num);
			break;
		}
	}
}
