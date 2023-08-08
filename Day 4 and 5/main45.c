#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#include "header_day45.h" //included header file for calling the necessary functions

/* Author: Keerthana K M
   Date: 03/08/2023 */

int main() {
	int arr[8] = {2,3,5,1,7,2,9,3};
	asc_desc(arr,8);
	
	//assert function used to check if the function is returning 1 or not
	assert(swap(10,20)==1);
	
    int a[8] = {7,4,2,21,9,11,2,8};
    int min = 0, max = 0;
    assert(find_max_min(a,8,&max,&min));
    
    //Set operations
    int A[4] = {2,3,4,6};
    int B[5] = {1,2,3,4,5};
    assert(set_union(A, B, 4, 5));
    assert(set_intersection(A, B, 4, 5));
    assert(set_difference(A, B, 4, 5));
    
	rem_duplicates(arr,8);
	linear_search(arr,8,5);
	binary_search(arr,8,5);
	
	int array[8] = {2,3,5,1,7,2,9,3};
	printf("Sum of product of consecutive numbers = %d\n",sum_of_products(array,8));
	
    assert(date_word_format(15,9,1999));
    
    //Matrix applications
    int mat[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    display_matrix(3,4,mat);
    sum_of_column(3,4,mat);
    
    int arr1[3][3] = {1,2,3,4,5,6,7,8,9};
    transpose(3,3,arr1);
    
    int matrix[4][4] = {0,0,3,0,2,4,0,0,5,0,1,0,0,3,0,1};
    sparse(4,4,matrix);
    
    //String applications
    char str[30] = "Welcome to World";
    printf("Length of the given string is %d\n",string_len(str));
    
    char strr[10] = "KeeRthanA";
    lower_to_upper(strr);
    reverse_string(strr);
    printf("Upper to lower case is = %c\n",utol(74));
    
    char pal[5] = "kanak";
    palindrome(pal);
    
    char src[9] = "Keerthana";
    char tgt[5] = "@MSIS";
    concatenate(src,tgt);
    return 0;
}

//To find the length of a string
int string_len(const char str[]){
    int length = 0;
    while(str[length]!='\0'){
        length++;
    }
    return length;
}

//To convert lower case to upper case
void lower_to_upper(const char str[]){
    int i = 0;
    printf("Lower to upper = ");
    while(str[i]!='\0'){
        if(islower(str[i])) printf("%c",toupper(str[i]));
		else printf("%c",str[i]);
		i++;
    }
    printf("\n");
}

//To find if given string is a palindrome or not
void palindrome(const char str[]){
    int i = 0, count = 0, j = 0;
	char arr[30];
	while(str[i]!='\0'){
		count++;
		i++;
	}
	for(i=count-1,j=0;i>=0;i--){
		arr[i] = str[j];
		j++;
	}
	j = 0;
	for(i=0;i<count;i++){
        if(arr[i]==str[i]) j++;
	}
	if(count==j) printf("The given string %s is a palindrome\n",str);
	else printf("The given string %s is not a palindrome\n",str);
}

//To find reverse of a string
void reverse_string(const char str[]){
	int i = 0, count = 0, j = 0;
	char arr[30];
	while(str[i]!='\0'){
		count++;
		i++;
	}
	for(i=count,j=0;i>=0;i--){
		arr[i] = str[j];
		j++;
	}
	printf("Reversed string is given by ");
	for(i=0;i<=count;i++){
        printf("%c",arr[i]);
	}
	printf("\n");
}

//upper to lower
int utol(int num){
    if(isupper(num)){
        printf("Uppercase letter = %c\n",num);
        return tolower(num);
    }
}

//To concatenate two strings
int concatenate(const char src[], char tgt[]){
	int i = 0, j = 0, count_src = 0, count_tgt = 0, tcount = 0;
	char res[50];
	while(src[i]!='\0'){
		count_src++;
		i++;
	}
	i = 0;
	while(tgt[i]!='\0'){
		count_tgt++;
		i++;
	}
	printf("Concatenated strings %s and %s = ",src,tgt);
	tcount = count_src + count_tgt;
	for(i=count_src,j=0;i<tcount;i++){
		tgt[i] = tgt[j];
		j++;
		count_tgt--;
		if(count_tgt==0) break;
	}
	for(i=0;i<count_src;i++){
		tgt[i] = src[i];
	}
	for(i=0;i<tcount;i++){
		printf("%c",tgt[i]);
	}
	printf("\n");
	return 1;
}
