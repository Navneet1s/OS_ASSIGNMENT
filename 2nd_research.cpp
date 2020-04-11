/*Researchers designed one system that classified interactive and noninteractive processes automatically by looking at the amount of terminal I/O.
 If a process did not input or output to the terminal in a 1-second interval, the process was classified as noninteractive and was moved to a 
lower-priority queue. In response to this policy, one programmer modified his programs to write an arbitrary character to the terminal at regular 
intervals of less than 1 second. 
The system gave his programs a high priority, even though the terminal output was completely meaningless.*/
#include<stdio.h>
int main()
{
	int b, type[20],i;
	int resptime[20];
	printf(" The Number of process= ");
	scanf("%d",&b);
	printf("Enter the data \n");
	for(i=0;i<b;i++)
	{
		printf("Response time of P%d (ms)= ",i);
		scanf("%d",&resptime[i]);
		if(resptime[i]<1000)        //condition for interacive or non interactive
		{
			type[i]=1;
		}
		else
		{ 
			type[i]=0;
		}
	}
	printf("Process Number\tResponse Time\tType\t\tPriority");
	for(i=0;i<b;i++)
	{
		printf("\nP%d\t\t%dms\t\t",i,resptime[i]);
		if(type[i]==1)
		{
			printf("INTERACTIVE \tHigh");
		}
		else
		{
			printf("NON-INTERACTIVE \tLow");
		}
	}
}



