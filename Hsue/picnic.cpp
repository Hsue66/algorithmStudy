#include<string.h>
#include<stdio.h>

int numOfstudent;
int sizeOfpairs;
int	numOfpairs;
int total;
int *pairs;
//int *check;

void findPairs(int check[], int p1, int p2)
{
	int TorF = 0;
	int smallIdx =0;
	int *copyCheck = new int[numOfstudent];

	// copy 
	memcpy(copyCheck,check,sizeof(int)*numOfstudent);

	// mark
	if(!(p1 == 0 && p2 == 0))
	{
		copyCheck[p1]=1;
		copyCheck[p2]=1;
	}

//		printf("list :");
	// finish check
	for(int i=0; i<numOfstudent; i++)
	{
		if(copyCheck[i]==1)
			TorF++;
//		printf("%d ",copyCheck[i]);
	}
//	printf("\n");

	if(TorF == numOfstudent)
	{
		total++;
//		printf("one more group %d\n",total);
	}	
	else
	{
		for(int i=0; i<numOfstudent; i++)
		{
			if(copyCheck[i]==0)
			{
				smallIdx = i;
//				printf("smallIdx : %d\n",smallIdx);
				break;
			}
		}

		for(int i=0; i<numOfpairs; i++)
		{
//			printf("------ %d : %d ------",smallIdx,i);
//			printf("pairs: %d %d\n",pairs[i*2],pairs[i*2+1]);
//			printf("before checks: %d %d\n",copyCheck[pairs[i*2]],copyCheck[pairs[i*2+1]]);

			if( (pairs[i*2]==smallIdx||pairs[i*2+1]==smallIdx) 
					&& copyCheck[pairs[i*2]] !=1 && copyCheck[pairs[i*2+1]] !=1)
			{
//				printf("will checked: %d %d\n\n",pairs[i*2],pairs[i*2+1]);
				findPairs(copyCheck,pairs[i*2],pairs[i*2+1]);
			}
		}

	}
}

int main()
{
	int testcase;
	scanf("%d",&testcase);
	for(int i=0; i<testcase; i++)
	{
		scanf("%d %d",&numOfstudent,&numOfpairs);
		sizeOfpairs = numOfpairs*2;
		pairs = new int[sizeOfpairs];
		
		for(int j=0; j<sizeOfpairs; j++)
		{
			int temp;
			scanf("%d",&temp);
			pairs[j]=temp;
		}

		total = 0;
		int *check = new int[numOfstudent];
		memset(check,0,numOfstudent);
		
		findPairs(check,0,0);

		printf("%d\n",total);
	}
}
