#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define SIZE 10 //Size declared as 10 for the array
#define S 5 //Size declared as 5 for the array using macros

/*
	Author: Keerthana K M
	Date: 08/08/2023
*/

int main() {
	int i=0;
	//Dynamic allocation of memory using malloc
	int* n = (int*)malloc(SIZE * sizeof(SIZE));
	assert(linear_search(n,5)==1);
	max_min(n);
	printf("Sum of all elements of the array = %d\n",sum(n));
	//Dynamic allocation of memory using malloc
	int* arr = (int*)malloc(S * sizeof(S));
	for(i=0;i<S;i++){
		*(arr+i) = 2;
	}
	palindrome(arr);
	//Dynamic allocation of memory using malloc
	int* set = (int*)malloc(S * sizeof(S));
	for(i=0;i<S;i++){
		*(set+i) = i+1;
	}
	sum_of_elements(set);
	deallocate(n);
	printf("%d\n",n);
	return 0;
}

//Linear Search
int linear_search(int* lin, int key){
	int i=0;
	for(i=0;i<SIZE;i++){
		*(lin+i) = i+1;
	}
	for(i=0;i<SIZE;i++){
		if(*(lin+i)==key){
			printf("Key is found\n");
			return 1;
			break;
		}
	}
	return 0;
}

//Finding maximum and minimum numbers of an array
void max_min(int* arr){
	int max = *(arr+0);
	int min = *(arr+0);
	int i=0;
	for(i=1;i<SIZE;i++){
		if(max < *(arr+i)) max = *(arr+i);
		if(min > *(arr+i)) min = *(arr+i);
	}
	printf("Maximum = %d\n",max);
	printf("Minimum = %d\n",min);
}

//Sum of all numbers of an array
int sum(int* arr){
	int i=0, sum=0;
	for(i=0;i<SIZE;i++){
		sum+=*(arr+i);
	}
	return sum;
}

//To find if an array is palindrome or not
void palindrome(int* arr){
	int i=0, j=0, count=0;
	for(i=0,j=S-1;i<S;i++){
		if(*(arr+i)==*(arr+j)) {
			count++;
			j--;
		}
	}
	if(count==S) printf("The numbers in array is a palindrome\n");
	else printf("The numbers in array is not a palindrome\n");
}

//To check if sum of subsets is a whole number or not
void sum_of_elements(int* arr){
	int i=0, j=0, k=1;
	for(i=0;i<S-1;i++){
		for(j=i+1;j<S;j++){
			if(*(arr+i) + *(arr+j) >=0){
				printf("Subset %d = {%d,%d}, Sum = %d, which is a whole number\n",k,*(arr+i),*(arr+j),(*(arr+i) + *(arr+j)));
				k++;
			}
		}
	}
}

//To deallocate memory using free()
void deallocate(int* ptr){
	int i=0;
	for(i=0;i<SIZE;i++){
		free(ptr+i);
	}
	free(ptr);
}
