#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#define NSIZE 30 //Length of the name
#define SSIZE 5 //Number of students considered
#define FOUND 1 //Found defined to be returned when element is found
#define NOP 6 //Number of Points in the plane

/*
	Author: Keerthana K M
	Date: 08/08/2023
*/

//Structure defined for student
struct Student{
	int rollno;
	char* name;
	int age;
	int marks;
};
typedef struct Student Student;

//Structure defined for point
struct Point{
	int x,y;
};
typedef struct Point Point;

//Structure defined for plane
struct Plane{
	Point points[NOP];
	int weights[NOP];
};
typedef struct Plane Plane;

int main() {
	Student* stud = (Student*)malloc(SSIZE*sizeof(SSIZE));
	insert_data(stud);
	assert(search_by_rollno(stud,1003)==FOUND);
	assert(search_by_name(stud,"Ansha")==FOUND);
	printf("Maximum marks scored = %d\n",max_marks(stud));
	name_starting_with_A(stud);
	
	Plane plane;
	xy_plane(plane);
	
	deallocate(stud);
	printf("%d\n",stud);
	return 0;
}

//Inserting student data
void insert_data(Student* stud){
	int i=0,k=0;
	char* names[SSIZE] = {"Aaron","Ansha","Imaad","Disha","Nitin"};
	for(i=0;i<SSIZE;i++){
		(*(stud+i)).rollno = 1001 + i;
		(*(stud+i)).name = names[k];
		k++;
		(*(stud+i)).age = rand()%25;
		(*(stud+i)).marks = rand()%19+80;
		printf("%d, %s, %d, %d\n",(*(stud+i)).rollno,(*(stud+i)).name,(*(stud+i)).age,(*(stud+i)).marks);
	}
}

//Finding a student using rollno
int search_by_rollno(Student* stud, int rollno){
	int i=0;
	for(i=0;i<SSIZE;i++){
		if((*(stud+i)).rollno==rollno){
			printf("Student is found!\n");
			return FOUND;
		}
	}
	return 0;
}

//Finding a student using name
int search_by_name(Student* stud, char* name){
	int i=0;
	for(i=0;i<SSIZE;i++){
		if(strcmp((*(stud+i)).name,name)){ //usage of strcmp to compare if the two names are same or not
			printf("Student is found!\n");
			return FOUND;
		}
	}
	return 0;
}

//To find the highest marks scored
int max_marks(Student* stud){
	int i=0, max = (*(stud+0)).marks;
	for(i=1;i<SSIZE;i++){
		if(max < (*(stud+i)).marks){
			max = (*(stud+i)).marks;
		}
	}
	return max;
}

//To find all names that start with 'A'
void name_starting_with_A(Student* stud){
	int i=0;
	for(i=0;i<SSIZE;i++){
		if((*(stud+i)).name[0]=='A'){
			printf("Name starting with A = %s\n",(*(stud+i)).name);
		}
	}
}

//To deallocate the allocated memory
void deallocate(Student* stud){
	int i=0;
	for(i=0;i<SSIZE;i++){
		free((*(stud+i)).name);
		free(stud+i);
	}
	free(stud);
}

//To find maximum weighted point and number of horizontal and vertical lines on a plane
void xy_plane(Plane plane){
	int x=0,y=0,i=0,max=0,hlines=0,vlines=0;
	Point point;
	for(i=0;i<NOP/2;i++){
		plane.points[i].x = x;
		plane.points[i].y = y;
		plane.weights[i] = rand()%14+1;
		x++;
		printf("(%d,%d) = %d\n",plane.points[i].x,plane.points[i].y,plane.weights[i]);
	}
	for(i=NOP/2;i<NOP;i++){
		plane.points[i].x = x-1;
		plane.points[i].y = y;
		plane.weights[i] = rand()%14+1;
		y++;
		printf("(%d,%d) = %d\n",plane.points[i].x,plane.points[i].y,plane.weights[i]);
	}
	max = plane.weights[0];
	point = plane.points[0];
	for(i=1;i<NOP;i++){
		if(max < plane.weights[i]){
			max = plane.weights[i];
			point = plane.points[i];
		}
	}
	printf("Point with maximum weights of %d = (%d,%d)\n",max,point.x,point.y);
	for(i=0;i<NOP;i++){
		if(plane.points[i].x < plane.points[i+1].x && plane.points[i].y == plane.points[i+1].y) hlines++;
		else if(plane.points[i].x == plane.points[i+1].x && plane.points[i].y < plane.points[i+1].y) vlines++;
		else if(plane.points[i].x < plane.points[i+1].x && plane.points[i].y < plane.points[i+1].y){
			hlines++;
			vlines++;
		}
	}
	printf("Number of horizontal lines = %d\n",hlines);
	printf("Number of vertical lines = %d\n",vlines);
}
