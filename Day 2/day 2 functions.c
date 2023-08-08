#include <math.h>
#include <stdio.h>

#define SIZE_C 10
//To find the sum of 5 digits of a number
int sum_of_5_digits(int num){
	int sum = 0;
	while(num!=0){
		sum+=num%10;
		num/=10;
	}
	return sum;
}

//To find the reverse of a 5 digit number
int reverse_of_5_digits(int num){
	int i = 0;
	int result = 0;
	int var = 0;
	for(i=4;i>=0;i--){
		var = num%10;
		result += (var*pow(10,i));
		num/=10;
	}
	return result;
}

//To find the number of occurences of a digit in a number
int occurences_of_digit(int num){
	int count = 0;
	while(num!=0){
		num/=10;
		count++;
	}
	return count;
}

//To find if a given number is palindrome or not
int palindrome_or_not(int num){
	int rev = 0, i = 0, var = 0, fnum = num;
	int number = occurences_of_digit(num);
	for(i=number-1;i>=0;i--){
		var = num%10;
		rev += (var*pow(10,i));
		num/=10;
	}
	if(fnum == rev) printf("The given number is a palindrome\n");
	else printf("The given number is not a palindrome\n");
	return 1;
}

//To find the number of first n prime numbers
int first_n_primes(int num){
	int i = 0, j = 0;
	printf("%d\t",2);
	printf("%d\t",3);
	printf("%d\t",5);
	printf("%d\t",7);
	printf("%d\t",11);
	printf("%d\t",13);
	printf("%d\t",17);
	num-=7;
	for(i=18;i!=0;i++){
		if(i%1==0 && i%i==0 && i%2!=0 && i%3!=0 && i%5!=0 && i%7!=0 && i%11!=0 && i%13!=0 && i%17!=0 && num>0){
			for(j=1;num!=0;j++){
				printf("%d\t",i);
				num--;
				break;
			}
		}
		if(num<=0) break;
	}
	return 1;	
}

//To find sum of series of numbers based on given input length
int sum_of_series(int num){
	int i = 0, var = 0, sum = 0;
	printf("\nSum of series ");
	for(i=0;i<num;i++){
		var += pow(10,i);
		printf("%d,",var);
		sum+=var;
	}
	printf(" is %d\n",sum);
	return 0;
}

//To find a given number is a armstrong number or not
int armstrong_or_not(int num){
	int i = 0, sum = 0, var = 0, n = num, count = 0;
	while(n!=0){
		n/=10;
		count++;
	}
	n = num;
	for(i=0;i<count;i++){
		var = n%10;
		sum += pow(var,3);
		n/=10;
	}
	if(num == sum) printf("The given number is a armstrong number\n");
	else printf("The given number is not a armstrong number\n");
	return 1;
}

//To find if the given two numbers are amicable or not
int amicable_numbers(int num1, int num2){
	int i = 1, j = 1, sum1 = 0, sum2 = 0;
	while(i<num1 && j<num2){
		if(num1%i==0) sum1+=i;
		if(num2%j==0) sum2+=j;
		i++; j++;
	}
	if(sum1==num2 && sum2==num1) printf("The given two numbers %d and %d are amicable\n",num1,num2);
	else printf("The given two numbers are not amicable\n");
	return 1;
}

//To create a menu for some basic arithmetic operations
int menu(int num1, int num2){
	int result = 0, choice = 0;
	printf("Menu\n1.Sum of two numbers\n2.Difference between two numbers\n3.Product of two numbers\nEnter your choice ");
	scanf("%d",&choice);
	switch(choice){
		case 1: if(choice==1) {
			result = num1 + num2;
			break;
		}
		case 2: if(choice==2){
			if(num1>num2) result = num1 - num2;
			else result = num2 - num1;
			break;
		}
		case 3: if(choice==3){
			result = num1 * num2;
			break;
		}
	//	default: printf("Invalid input\n");
	}
	return result;
}

//To find volume of a cube
double volume_cube(double edge){
	return pow(edge,3);
}

//To find volume of a cuboid
double volume_cuboid(double l, double w, double h){
	return l*w*h;
}

//To find volume of a sphere
double volume_sphere(double radius){
	return (4/3)*3.14*pow(radius,3);
}

//To find volume of a cylinder
double volume_cylinder(double r, double h){
	return 3.14*pow(r,2)*h;
}

//To find volume of a cone
double volume_cone(double r, double h){
	double v = 3.14*pow(r,2)*h;
	return (1/3)*v;
}

//To find the total electricity charge based on input units
double total_charge(int units){
	double total_cost = 0;
	if(units<=200) total_cost+=units*5;
	else if(units>200 && units<=300) total_cost+=units*7;
	else if(units>300) total_cost+=units*10;
	else printf("Invalid Input\n");
	return total_cost;
}

//To find the intersection between two sets A and B
int intersection(int A[], int B[], int size_a, int size_b){
	int C[SIZE_C] = {0};
	int i = 0, j = 0, k = 0;
	for(i=0;i<size_a;i++){
		for(j=0;j<size_b;j++){
			if(A[i] == B[j]){
				C[k] = A[i];
				k++;
			}
		}
	}
	#ifdef SIZE_C
	#undef SIZE_C
	#define SIZE_C k
	#endif
	printf("\n");
	for(i=0;i<SIZE_C;i++){
		printf("%d\t",C[i]);
	}
	return 1;
}
