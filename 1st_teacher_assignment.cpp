/*
There are 3 student processes and 1 teacher process. Students are supposed to do their assignments and they need 3 things for that pen, paper and question paper.
The teacher has an infinite supply of all the three things. One students has pen,an other has paper and another has question paper. 
The teacher places two things on a shared table and the student having the third complementary thing makes the assignment and tells the teacher on completion.
The teacher then places another two things out of the three and again the student having the third thing makes the assignment and tells the teacher on completion.
This cycle continues. Write a programme to synchronize the teacher and the students.
*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h> 
#include<stdbool.h>
int student[3][4]={0};    //creating a 2d array
void *teacher();
void *student1();         //3 student processes  in three different functions 
void *student2();
void *student3();
pthread_mutex_t lck;
int ch1,ch2;
int r1,r2;

int main()
{	
printf("\t\t\t---Welcome---\n");
	pthread_mutex_init(&lck,NULL);\
student[1][1]=1;
	student[2][2]=2;student[3][3]=1;
	pthread_t t_thread;
	pthread_t s_thread;
printf("Resources Menu: \n\t\tPress '1' for pen\n\t\tPress '2' for paper \n\t\tPress '3' for   question_paper \n"); 	
	while(1)
{
if(student[1][4]==1 && student[2][4]==1 && student[3][4]==1){break;}
pthread_create(&t_thread, NULL, teacher, NULL);
pthread_join(t_thread,NULL);
	    
if((ch1==1 && ch2==2 || ch2==1 && ch1==2 ) && student[3][4]==0)
{
	pthread_create(&s_thread, NULL, student3, NULL);
	pthread_join(s_thread,NULL);
}
else if((ch1==1 && ch2==3 || ch2==1 && ch1==3 ) && student[2][4]==0)
{
pthread_create(&s_thread, NULL, student2, NULL);
	pthread_join(s_thread,NULL);
}
else if((ch1==2 && ch2==3 || ch2==2 && ch1==3 ) && student[1][4]==0)
{
	pthread_create(&s_thread, NULL, student1, NULL);
pthread_join(s_thread,NULL);
}
else
{
	printf("\n\tError please try again.. with different choices.\n");
}
}
printf("\n\tDone\n");
}


void *teacher()
{
pthread_mutex_lock(&lck);
	printf("\nFirst Resource on shared tabel:-\t");
	scanf("%d",&ch1);
	printf("Second Resource on shared tabel:-\t");
	scanf("%d",&ch2);
	pthread_mutex_unlock(&lck);
}

void *student2()
{	
	pthread_mutex_lock(&lck);
	printf("\nChoices Made = 'pen', 'question_paper'\n");
	student[2][4]=1;
	printf("\n\tStudent 2 has Completed the assignment. \n");
	pthread_mutex_unlock(&lck);
}

void *student3()
{	
	pthread_mutex_lock(&lck);
	printf("\nChoices Made = 'pen', 'paper'\n");
	student[3][4]=1;
	printf("\n\tStudent 3 has Completed the assignment.\n");
	pthread_mutex_unlock(&lck);
}

void *student1()
{	
	pthread_mutex_lock(&lck);
	printf("\nChoices Made = 'paper', 'question_paper'\n");
	student[1][4]=1;
	printf("\n\tStudent 1 has Completed the assignment.\n");	
	pthread_mutex_unlock(&lck);
}
