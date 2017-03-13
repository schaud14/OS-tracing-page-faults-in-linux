#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 10000
#define COUNT_MAX_SIZE 100
#define ANIMATION_SIZE 16
int globali=1;

void animate(int input[],int input_size)
{
	int iterator,inner_i;
	for (iterator=0; iterator < input_size; iterator++)
	{
		for(inner_i=0;inner_i<input[iterator];inner_i++)
		{
			fprintf(stderr, "*" );
		}
		fprintf(stderr, "\n" );
	}
	fprintf(stderr, "\n" );
}

void animate2(int input[],int count[],int input_size,int iteration)
{
	int i,j,iterator=1;
	fprintf(stderr, "\n \t Next Iteration : %d\n",iteration);	
	for (i=1;i<ANIMATION_SIZE;i++)
	{
		fprintf(stderr, "\t#%2d.------ ",i);
		for (j=0;j<count[i];j++)
		{
			fprintf(stderr, "*");
		}
	fprintf(stderr, "\n");
	}
}

void generateRandom(int input_size,int input[],int choice)
{
	int iterator;
	for (iterator = 0; iterator < input_size; iterator++)
	{	
		if (choice == 2)
		{
			if (input_size < 21)
			{
				do
				{
					input[iterator] = rand()%16;
				}while (input[iterator] == 0);
			}
			else
			{
				do
				{
					input[iterator] = rand()%100;
				}while (input[iterator] == 0);
			}
		}
		else if (choice != 2)
		{
			if (input_size < 21)
			{
				do
				{
					input[iterator] = rand()%16;
				}while (input[iterator] == 0);
			}
			else
			{
				do
				{
					input[iterator] = rand();		
				}while (input[iterator] == 0);
			}
		}
	}
}

void print_input(int input[],int input_size)
{
	int iterator;
	for (iterator=0;iterator<input_size;iterator++)
	{
		fprintf(stderr, "%12d\t",input[iterator]);
	}	
	fprintf(stderr, "\n" );
}

void countingSort(int input[],int count[],int input_size,int choice)
{

	int temp,i,inner_i,iterator;
	int iteration = 1;
	int j = 0;
		
	/*
	Generating Random Number
	*/
	generateRandom(input_size,input,choice);
	fprintf(stderr, "\n\t Input Array is : \n\n");
	print_input(input,input_size);

	/* 
	Algorithm Start
	*/

	for (iterator = 0; iterator < input_size; iterator++ )
	{
		temp = input[iterator];
		count[temp] = count[temp] + 1;
		if (input_size < 21)
		{
			animate2(input,count,input_size,iteration);
			iteration++;
		}	
	}
	
	if (input_size > 20)
	{
		for (iterator = 0;iterator < COUNT_MAX_SIZE;iterator++)
		{
			for (inner_i=0;inner_i<count[iterator];inner_i++)
			{
				input[j]=iterator;
				j++;
			}		
		}	
	fprintf(stderr, "\n");
	}
	else 
	{
		for (iterator = 0;iterator < 16 ;iterator++)
		{
			for (inner_i=0;inner_i<count[iterator];inner_i++)
			{
				input[j]=iterator;				
				j++;
			}		
		}
		fprintf(stderr, "\n");
	}		
	fprintf(stderr, "\n\t Sorted Array is : \n\n");
	print_input(input,input_size);
}

void insertion_sort(int input[], int input_size,int choice)
{
	int temp,ii=1,iterator,inner_i,size;
	generateRandom(input_size,input,choice);
	fprintf(stderr, "\n\t Input Array is : \n\n");
	print_input(input,input_size);
	/*
	Insertion Algorithm.. Outer loop for N iterations.
	*/
	for (iterator=0; iterator < input_size; iterator++)
	{
		inner_i = iterator;
		/*
		inner loop for i times. Max N-1 in worst case.
		*/
		while (inner_i > 0 && input[inner_i-1] > input[inner_i])
		{
			temp = input[inner_i];
			input[inner_i] = input[inner_i-1];
			input[inner_i-1] = temp;
			inner_i--;
		}
		/*
		Animation for small input
		*/
		if (input_size < 21)
		{
			fprintf(stderr, "\n\tIteration: %d\n",iterator+1);
			animate(input,input_size);
		}
	}
	if (input_size < 21)
	{
		fprintf(stderr, "\n%s\n","Final View of Sorted Array " );
		animate(input,input_size);
	}
	fprintf(stderr, "\n\n\t Sorted Array is : \n\n" );
	print_input(input,input_size);
}

void merge(int input[], int low, int mid, int high,int input_size)
{
    int temp[MAX_SIZE];
    int i = low, j = mid + 1, k = 0;
  
    while (i <= mid && j <= high) 
    {
        if (input[i] <= input[j])
            temp[k++] = input[i++];
        else
            temp[k++] = input[j++];
    }
    while (i <= mid)
        temp[k++] = input[i++];
  
    while (j <= high)
        temp[k++] = input[j++];
    k--;
    while (k >= 0) 
    {
        input[low + k] = temp[k];
        k--;
    }
    if(input_size < 21)
    	{
    		fprintf(stderr, "Iteration: %d\n",globali );
    		animate(input,high);
			globali++;
		}
}  
void merge_sort(int input[], int low, int high,int input_size)
{
	int i,k;
    if (low < high) {
        int mid = (high + low)/2;
        merge_sort(input, low, mid,input_size);
        //animate(input,mid);
        merge_sort(input, mid + 1, high,input_size);
        //animate(input,high);
        merge(input, low, mid, high,input_size);
    }
}
int generateRandomPivot(int min,int max)
{
	int random = min + rand()%(max - min + 1);
	return random;
}

animate3(int input[],int input_size)
{
	int i,j;
	for (i=0;i<input_size;i++)
	{
		for (j = 0; j < input[i]; j++)
		{
			fprintf(stderr, "*");
		}
	fprintf(stderr, "\n" );
	}
}


void RandomizedQuickSort(int input[],int left,int right,int input_size)
{
  if (left < right)
  {
    int q = RandomizedPartition(input,left,right,input_size);
    RandomizedQuickSort(input,left,q-1,input_size);
    RandomizedQuickSort(input,q+1,right,input_size);
  }

} 
int RandomizedPartition(int input[],int left, int right,int input_size)
{
  int i = generateRandomPivot(left,right);
  int pivot = input[i];
  input[i] = input[right];
  input[right] = pivot;
 i = partition(input, left, right);
 	if (input_size < 21)
 	{
 		fprintf(stderr, "Interation : %d\n",globali++);
 		animate(input,input_size);
 		fprintf(stderr, "\n" );
 	}
 return i;
}

int partition(int input[], int left, int right)
{
    int pivot = input[right];
    int temp;
    int j;
    int i = left;
    for (j = left; j < right; j++)
    {
        if (input[j] <= pivot)
        {
            temp = input[j];
            input[j] = input[i];
            input[i] = temp;
            i++;
        }
    }
 
    input[right] = input[i];
    input[i] = pivot;
 
    return i;
}	

int main()
{
	int input[MAX_SIZE];
	int count[COUNT_MAX_SIZE]={0};
	srand (time(NULL));
	int choice=0,input_size=0;
	while (1)//(choice != 5);
	{
	fprintf(stdout,"PID: %d\n",getpid());		
	choice=0;
		globali=1;
		char c;
		fprintf(stdout, "\n" );
		memset(input,0,MAX_SIZE);
		memset(count,0,COUNT_MAX_SIZE);
	//	do
	//	{
			fprintf(stdout, "\n\t\t\tSORTING ALGORITHMS\n" );
		    fprintf(stdout, "\t1.Insertion Sort\n\t2.Counting Sort\n\t3.Merge Sort\n\t4.Randomized Quick Sort\n\t5.Exit\n\n");
		 	fprintf(stdout, "Enter choice between 1 to 5 : " );
			//printf("%s\n", "Enter choice");
			scanf(" %c",&c);
			//gets(&c);
			choice = atoi(&c);
			c='\0';
	//	}while(choice < 1 || choice > 5)
		// if(choice > 5 || choice < 1)
		// 	continue;
		switch (choice)
		{
			case 1:
			{
				do
				{
					fprintf(stderr, "Enter the Input Size between 1 to 1000 : ");
					scanf("%d",&input_size);
				}while(input_size < 0  | input_size >= MAX_SIZE );
				insertion_sort(input,input_size,choice);

				break;
			}
			case 2:
			{
				do
				{
					fprintf(stderr, "Enter the Input Size between 1 to 1000 : ");
					scanf("%d",&input_size);
				}while(input_size < 0  | input_size >= MAX_SIZE );
				
				countingSort(input,count,input_size,choice);

				break;
			}
			case 3:
			{
				do
				{
					fprintf(stderr, "Enter the Input Size between 1 to 1000 : ");
					scanf("%d",&input_size);
				}while(input_size < 0  | input_size >= MAX_SIZE );
				
				generateRandom(input_size,input,choice);
				
				fprintf(stderr, "\n\n\t Input Array is : \n\n" );
				print_input(input,input_size);		
				if (input_size < 21)
				{
					fprintf(stderr, "%s\n","Initial Array: " );
					animate3(input,input_size);
				}
				merge_sort(input,0,input_size-1,input_size);
				
				if (input_size < 21)
				{
					fprintf(stderr, "%s\n","Sorted Array: " );
					animate3(input,input_size);
				}

				fprintf(stderr, "\n\n\t Sorted Array is : \n\n" );
				print_input(input,input_size);		
				
				break;	
			}
			case 4:
			{
				do
				{
					fprintf(stderr, "Enter the Input Size between 1 to 1000 : ");
					scanf("%d",&input_size);
				}while(input_size < 0  | input_size >= MAX_SIZE );
				generateRandom(input_size,input,choice);
				
				fprintf(stderr, "\n\n\t Input Array is : \n\n" );
				print_input(input,input_size);		
				
				if (input_size < 21)
				{
					fprintf(stderr, "%s\n","Initial Array: " );
					animate3(input,input_size);
				}

				RandomizedQuickSort(input,0,input_size-1,input_size);
				
				if (input_size < 21)	
				{
					fprintf(stderr, "%s\n","Sorted Array: " );
					animate3(input,input_size);
				}
				fprintf(stderr, "\n\n\t Sorted Array is : \n\n" );
				print_input(input,input_size);
				break;
			}
			case 5:
			{
				exit(0);
			}
			default: 
			{
				//fprintf(stderr, "Enter choice: " );
				//scanf("%d",&choice);
				break;
			}		
			//break;	
		}
		//fflush(stdout);
	//break;
	}
}
