#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	fprintf(stderr,"%d",getpid());	
	sleep(10);
	size_t n;	
	int pid;
	char data[100];
	unsigned long array[10];
	memset(array,-1,10*sizeof(unsigned long));
	memset(data,0,100);
	int fd = open("/proc/myprocfile", O_RDONLY);
	if(fd == -1){
		printf("Error in opening /proc/myprocfile.. %s\n",strerror(errno));
		return 0;
	}			
			int * memoryLoc;
			int i;		
			for(i=0;i<25;i++)		
			{	
				memoryLoc = malloc(10 * sizeof(int));
				sleep(1);}
			for(i=0;i<25;i++)	
				{n = read(fd, data, 100);			
				//fprintf(stderr,"value of N= %d",n);			
				//if(n ==1000000)
				//{
				//printf("Waiting\n");					
				//waiting 
				//}
				//else 
				if (n>0)
				{
					//printf("Data in array:\n");
					//int k = 0;
					//while (k<100)
					//{
						fprintf(stderr,"%s",data);
					//	k = k + 1;
					}
					fprintf(stderr,"\n");
					//while(k<16)
					//{
				//		fprintf(stderr,"%c",data[k]);
				//		k = k + 1;
				//	}
					//k = 0;
				}
				 if(n<0){
					printf("Error in reading from device buffer\n");
					exit(1);
				}

			//}
//		}
	//else
	//{
	//waitpid(pid);	
	//}

return 0;
}
