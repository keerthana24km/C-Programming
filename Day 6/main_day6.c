#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 10 //Size defined for Student array length
#define SIZE1 30 //Size defined for Student name
#define SIZE2 7 //For validation
#define LADDER 6 //Number of ladders used
#define SNAKE 7 //Number of snakes used

/*
	Author: Keerthana K M
	Date: 08/08/2023
*/

//Structure declaration for student
struct Student{
    int roll_no;
    char name[SIZE1];
    int age;
    float marks;
};
typedef struct Student Student;

//Structure declaration for a complex number
struct Complex{
    double re1, im1, re2, im2;
    char i;
};
typedef struct Complex Complex_Number;

//Structure declaration for item
struct Item{
	double price;
	int quantity;
};
typedef struct Item Item;

//Structure declaration for a snake in snake and ladder
struct snake{
	int start, end;
};
typedef struct snake Snake;

//Structure declaration for a ladder in snake and ladder
struct ladder{
	int start, end;
};
typedef struct ladder Ladder;

int main()
{
    Student stud1[SIZE];
    Student* ptr = &stud1;
    view_students(stud1,ptr);
    
    Complex_Number cn = {cn.re1, cn.im1, cn.re2, cn.im2, cn.i};
    Complex_Number* ptr1 = &cn;
    printf("Enter the value of first real number\n");
    scanf("%lf",&cn.re1);
    printf("Enter the value of first imaginary number\n");
    scanf("%lf",&cn.im1);
    printf("Enter the value of second real number\n");
    scanf("%lf",&cn.re2);
    printf("Enter the value of second imaginary number\n");
    scanf("%lf",&cn.im2);
    complex_num(cn, ptr1);
    printf("\n");
    
    Item item[5] = {{200,1},{400,1},{200,3},{10,5},{50,2}};
    list_of_items(item,5);
    
    Ladder lad[LADDER] = {{3,21},{6,15},{23,46},{30,54},{58,86},{84,95}};
    Snake sn[SNAKE] = {{27,6},{32,15},{40,21},{46,18},{66,34},{88,54},{97,22}};
    snake_ladder(sn, lad);
    return 0;
}

//Function to insert data in Student str array, and viewing of those records
void view_students(Student s[],Student* ptr){
    int i,j=0;
    char arr[7] = "Student";
    for(i=0;i<SIZE;i++){
        (*(ptr+i)).roll_no = 1001+i;
        j=0;
        while(arr[j]!='\0'){
            (*(ptr+i)).name[j] = arr[j];
            j++;
            if(j==SIZE2) break;
        }
        (*(ptr+i)).age = 23;
        (*(ptr+i)).marks = rand() % 20 + 80;
        printf("%d, %s, %d, %f\n",(*(ptr+i)).roll_no,(*(ptr+i)).name,(*(ptr+i)).age,(*(ptr+i)).marks);
    }
}

//Function to perform addition, subtraction and multiplication on complex numbers
void complex_num(Complex_Number cn, Complex_Number* ptr){
    int choice = 0;
    printf("Menu\n1.To add two complex numbers\n2.To subtract two complex numbers\n3.To multiply two complex numbers\nEnter your choice\n");
    scanf("%d",&choice);
    switch(choice){
        case 1: if(choice==1){
            printf("The sum of two complex numbers %lfi+(%lf) and %lfi+(%lf) = %lfi+(%lf)\n",(*ptr).re1,(*ptr).im1,(*ptr).re2,(*ptr).im2,(*ptr).re1+(*ptr).re2,(*ptr).im1+(*ptr).im2);
            break;
        }
        case 2: if(choice==2){
            printf("The sum of two complex numbers %lfi+(%lf) and %lfi+(%lf) = %lfi+(%lf)\n",cn.re1,cn.im1,cn.re2,cn.im2,cn.re1-cn.re2,cn.im1-cn.im2);
            break;
        }
        case 3: if(choice==3){
            printf("The sum of two complex numbers %lfi+(%lf) and %lfi+(%lf) = %lfi+(%lf)\n",cn.re1,cn.im1,cn.re2,cn.im2,(*ptr).re1*(*ptr).re2,(*ptr).im1*(*ptr).im2);
            break;
        }
    }
}

//Function to print a bill of items, it's total and the grand total
void list_of_items(Item item[], int size){
	int i=0;
	float total=0, gtotal=0;
	for(i=0;i<size;i++){
		printf("Item%d\t%f\t%d\t%f\n",i+1,item[i].price,item[i].quantity,item[i].price*item[i].quantity);
		total += item[i].price*item[i].quantity;
	}
	printf("---------------------------------------\n");
	if(total<=1000) {
		printf("TOTAL %f\n",total);
		printf("Discount 5%% - %f\n",(total*0.05));
		printf("---------------------------------------\n");
		gtotal = total - total*0.05;
		printf("GRAND TOTAL %f\n",gtotal);
	}
	else if(total>1000 && total<=5000) {
		printf("TOTAL %f\n",total);
		printf("Discount 10%% - %f\n",(total*0.1));
		printf("---------------------------------------\n");
		gtotal = total - total*0.1;
		printf("GRAND TOTAL %f\n",gtotal);
	}
	else {
		printf("TOTAL %f\n",total);
		printf("Discount 15%% - %f\n",(total*0.15));
		printf("---------------------------------------\n");
		gtotal = total - total*0.15;
		printf("GRAND TOTAL %f\n",gtotal);
	}
}

//Function to play snake and ladder with 2 players - Player1 being user and Player2 being computer
void snake_ladder(Snake snake[SNAKE], Ladder ladder[LADDER]){
	int player1 = 0, player2 = 0, dice1 = 0, dice2 = 0, i = 0, j = 0;
	while(player1!=100 || player2!=100){
		i = SNAKE;
		j = LADDER;
		printf("Player 1, roll the dice ");
		scanf("%d",&dice1);
		if(dice1==1 || dice1==2 || dice1==3 || dice1==4 || dice1==5 || dice1==6){
			printf("You rolled %d\n",dice1);
			player1 += dice1;
			while(j!=0){
				if(ladder[j].start==player1){
					printf("You got a ladder to climb!\n");
					player1 = ladder[j].end;
				//	printf("Current score = %d\n",player1);
				}
				j--;
			}
			while(i!=0){
				if(snake[i].start==player1){
					printf("You got bitten by a snake...\n");
					player1 = snake[i].end;
				//	printf("Current score = %d\n",player1);
				}
				i--;
			}
			printf("Current score = %d\n",player1);
		}
		i = SNAKE;
		j = LADDER;
		printf("Player 2 (computer) rolling the dice...\n");
		dice2 = (rand()%5+1);
		printf("Rolled %d on dice\n",dice2);
		player2 += dice2;
		while(j!=0){
			if(ladder[j].start==player2){
				printf("You got a ladder to climb!\n");
				player2 = ladder[j].end;
			//	printf("Current score = %d\n",player2);
			}
			j--;
		}
		while(i!=0){
			if(snake[i].start==player2){
				printf("You got bitten by a snake...\n");
				player2 = snake[i].end;
			//	printf("Current score = %d\n",player2);
			}
			i--;
		}
		printf("Current score = %d\n",player2);
		if(player1==100 || player2==100) break;
	}
	if(player1==100) printf("Player 1 wins!!");
	else printf("Player 2 wins!!");
}
