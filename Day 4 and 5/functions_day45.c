#include <stdio.h>
#define SIZE 20

//To find ascending and descending order of elements
int asc_desc(int arr[8], int size){
	int i = 0, j = 0, temp = 0;
	for(i=0;i<size-1;i++){
		for(j=i+1;j<size;j++){
			if(arr[i]>=arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}else{
				//Do nothing
			}
		}
	}
	printf("Array in ascending order = ");
	for(i=0;i<size;i++) printf("%d ",arr[i]);
	printf("\n");
	for(i=0;i<size;i++){
		for(j=i+1;j<size;j++){
			if(arr[i]<=arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}else{
				//Do nothing
			}
		}
	}
	printf("Array in descending order = ");
	for(i=0;i<size;i++) printf("%d ",arr[i]);
	printf("\n");
	return 1;
}

//Swapping two integers
int swap(int x, int y){
    int temp = 0;
    printf("Before swapping, x = %d and y = %d\n",x,y);
    temp = x;
    x = y;
    y = temp;
    printf("After swapping, x = %d and y = %d\n",x,y);
    return 1;
}

//Finding the maximum and minimum numbers
int find_max_min(int array[], int size, int *max, int *min){
    *max = array[0];
	*min = array[0];
    int i = 0;
    for(i=1;i<size;i++){
        if(*max<array[i]){
            *max = array[i];
        }
        if(*min>array[i]){
            *min = array[i];
        }
    }
    printf("Max = %d and Min = %d\n",*max,*min);
    return 1;
}

//Finding union of two sets
int set_union(int A[], int B[], int size_a, int size_b){
    int C[10] = {0};
    int i = 0, j = 0, k = 0, count = 0;
    for(i=0;i<size_a;i++){
        C[k] = A[i];
        k++;
        count++;
    }
    for(j=0;j<size_b;j++){
        C[k] = B[j];
        k++;
        count++;
    }
    for(i=0;i<count-1;i++){
        for(j=i+1;j<count;j++){
            if(C[i]==C[j]){
                for(k=j;k<count;k++){
                    C[k] = C[k+1];
                }
                count--;
            }
        }
    }
    printf("Union of two sets A and B is given by ");
    for(k=0;k<count;k++){
        printf("%d,",C[k]);
    }
    printf("\n");
    return 1;
}

//Finding intersection of two sets
int set_intersection(int A[], int B[], int size_a, int size_b){
    int C[10] = {0};
    int i = 0, j = 0, k = 0, count = 0;
    for(i=0;i<size_a;i++){
        for(j=0;j<size_b;j++){
            if(A[i]==B[j]){
                C[k] = A[i];
                k++;
                count++;
            }
        }
    }
    for(i=0;i<count-1;i++){
        for(j=i+1;j<count;j++){
            if(C[i]==C[j]){
                for(k=j;k<count;k++){
                    C[j] = C[j+1];
                    count--;
                }
            }
        }
    }
    printf("Intersection of two sets A and B is given by ");
    for(k=0;k<count;k++){
        printf("%d,",C[k]);
    }
    printf("\n");
    return 1;
}

//Finding difference between two sets
int set_difference(int A[], int B[], int size_a, int size_b){
    int C[10] = {0},D[10] = {0};
    int i = 0, j = 0, k1 = 0, count1 = 0, k2 = 0, count2 = 0;
    for(i=0;i<size_a;i++){
        for(j=0;j<size_b;j++){
            if(A[i]==B[j]){
                C[k1] = A[i];
                D[k2] = B[j];
                k1++;
                k2++;
                count1++;
                count2++;
            }
        }
    }
    k1 = k2 = 0;
    for(i=0;i<size_a;){
        if(C[k1]==A[i]){
            for(j=i;j<size_a;j++){
                A[j] = A[j+1];
            }
            size_a--;
            k1++;
        }else i++;
    }
    for(j=0;j<size_b;){
        if(D[k2]==B[j]){
            for(i=j;i<size_b;i++){
                B[i] = B[i+1];
            }
            size_b--;
            k2++;
        }else j++;
    }
    printf("Difference of two sets A and B as A-B is given by = ");
    for(k1=0;k1<size_a;k1++){
        printf("%d,",A[k1]);
    }
    printf("\n");
    printf("Difference of two sets A and B as B-A is given by = ");
    for(k2=0;k2<size_b;k2++){
        printf("%d,",B[k2]);
    }
    printf("\n");
    return 1;
}

//Removing the duplicates of an array
int rem_duplicates(int arr[], int size){
	int i=0, temp=0, j=0;
	for(i=0;i<size-1;i++){
		for(j=i+1;j<size;j++){
			if(arr[i]>=arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for(i=0;i<size;i++){
		if(arr[i]==arr[i+1]){
			for(j=i;j<size;j++) arr[j] = arr[j+1];
			size--;
		}
	}
	printf("Array without duplicates = ");
	for(i=0;i<size;i++) printf("%d,",arr[i]);
	printf("\n");
	return 1;
}

//Searching an element in an array using linear search
int linear_search(int arr[], int size, int key){
	int i = 0, j = 0, res = 0;
	for(i=0;i<size;i++){
		if(key==arr[i]){
			j = i;
			res = 1;
			break;
		}
	}
	if(res==1) printf("Key %d is found in the array at index %d\n",key,j);
	else printf("Key is not found!");
	return 1;
}

//Searching an element in an array using binear search
int binary_search(int arr[], int size, int key){
	int i = 0, j = 0, res = 0, min = 0, max = size-1, mid = (min+max)/2; //2,3,5,1,7,2,9,3
	for(i=0;i<size;i++){
		if(key==arr[mid]){
			j = mid;
			res = 1;
			break;
		}
		if(key==arr[min]){
			j = min;
			res = 1;
			break;
		}
		else{
			min++;
			mid = (max + min)/2;
		}
		if(key==arr[max]){
			j = max;
			res = 1;
			break;
		}
		else{
			max--;
			mid = (max + min)/2;
		}
	}
	if(res==1) printf("Key %d is found in the array at index %d\n",key,j);
	else printf("Key is not found!\n");
	return 1;
}

//To find sum of product of consecutive numbers of an array
int sum_of_products(int arr[], int size){
	int i = 0, sum = 0, prod = 0, num1 = 0, num2 = 0;
	for(i=0;i<size-1;i++){
		num1 = arr[i];
		num2 = arr[i+1];
		prod = num1*num2;
		sum+=prod;
	}
	return sum;
}

//To find length of a string without using string.h
int string_leng(const char str[]){
    int i = 0, length = 0;
    while(str[i]!='\0'){
        length++;
        i++;
    }
    return length;
}

//Print the given day, month and year in a date format
int date_word_format(int d, int m, int y){
    if((d<=31 && m==1 || m==3 || m==5 || m==7 || m==8 || m==10 | m==12 && y<2023) || (d<=30 && m==4 || m==6 || m==9 || m==11 && y<2023) || ((d<=28 && m==2 && y<2023) || (d<=29 && m==2 && y<2023))){
        if(d%10==1 && d!=11) printf("%dst ",d);
        else if(d%10==2 && d!=12) printf("%dnd ",d);
        else if(d%10==3 && d!=13) printf("%drd ",d);
        else printf("%dth ",d);
        switch(m){
            case 1: if(m==1){
                printf("%s, %d\n","January",y);
                break;
            }
            case 2: if(m==2){
                printf("%s, %d\n","February",y);
                break;
            }
            case 3: if(m==3){
                printf("%s, %d\n","March",y);
                break;
            }
            case 4: if(m==4){
                printf("%s, %d\n","April",y);
                break;
            }
            case 5: if(m==5){
                printf("%s, %d\n","May",y);
                break;
            }
            case 6: if(m==6){
                printf("%s, %d\n","June",y);
                break;
            }
            case 7: if(m==7){
                printf("%s, %d\n","July",y);
                break;
            }case 8: if(m==8){
                printf("%s, %d\n","August",y);
                break;
            }case 9: if(m==9){
                printf("%s, %d\n","September",y);
                break;
            }case 10: if(m==10){
                printf("%s, %d\n","October",y);
                break;
            }case 11: if(m==11){
                printf("%s, %d\n","November",y);
                break;
            }case 12: if(m==12){
                printf("%s, %d\n","December",y);
                break;
            }
        }
    }else printf("Incorrect Date format\n");
    return 1;
}

//Converting a string from lower case to upper case
void lower_to_upperr(const char str[]){
    int i = 0;
    printf("Lower to upper = ");
    while(str[i]!='\0'){
        if(islower(str[i])==1) printf("%c",toupper(str[i]));
		else printf("%c",str[i]);
		i++;
    }
}

//To find a reverse of a string without string.h
void reverse_stringg(const char str[]){
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
	printf("Reversed string is given by %s\n",arr);
}

//Diplaying a matrix in row x column format
void display_matrix(int row, int col, int arr[row][col]){
	int m = 0, n = 0;
	int size = row * col;
	printf("Matrix is given by...\n");
	for(m=0;m<row;m++){
		for(n=0;n<col;n++){
			printf("%d\t",arr[m][n]);
			size--;
		}
		printf("\n");
		if(size==0) break;
	}
}

//Finding transpose of a matrix
void transpose(int row, int col, int arr[row][col]){
	int m = 0, n = 0;
	int size = row * col;
	if(row==col){
		printf("Matrix before transpose\n");
		for(m=0;m<row;m++){
			for(n=0;n<col;n++){
				printf("%d\t",arr[m][n]);
				size--;
			}
			printf("\n");
			if(size==0) break;
		}
		printf("Matrix after transpose\n");
		for(m=0;m<row;m++){
			for(n=0;n<col;n++){
				if(m==n){
					printf("%d\t",arr[m][n]);
					size--;
				}else{
					printf("%d\t",arr[n][m]);
					size--;
				}
			}
			printf("\n");
			if(size==0) break;
		}
	}else printf("Given matrix cannot have a transpose\n");
}

//Finding the sum of all columns of a matrix
void sum_of_column(int row, int col, int arr[row][col]){
	int m = 0, n = 0, i = 1;
	int sum = 0;
	int size = row * col;
	if(col>=row){
		for(m=0;m<col;m++){
			sum = 0;
			for(n=0;n<row;n++){
				sum+=arr[n][m];
				size--;
			}
			printf("Sum of %d column = %d\n",m+1,sum);
			if(size==0) break;
		}
	}else{
		for(m=0;m<row;m++){
			sum = 0;
			for(n=0;n<col;n++){
				sum+=arr[n][m];
				size--;
			}
			printf("Sum of %d column = %d\n",m+1,sum);
			if(size==0) break;
		}
	}
}

//Finding out if a matrix is sparse or not
void sparse(int row, int col, int arr[row][col]){
	int m = 0, n = 0, count = 0;
	int size = row * col;
	for(m=0;m<row;m++){
		for(n=0;n<col;n++){
			if(0==arr[m][n]) count++;
			size--;
		}
		if(size==0) break;
	}
	size = row * col;
	if(count>(size/2)) printf("The given matrix is a sparse matrix\n");
	else if(count<(size/2)) printf("The given matrix is not a sparse matrix\n");
	else printf("The given matrix has equal number of zero and non-zero elements\n");
}
