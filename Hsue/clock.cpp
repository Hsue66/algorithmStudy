#include<string.h>
#include<stdio.h>

int result = 987654321;

//					   0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5
int SWITCH[10][16] = {{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
					  {0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0},
					  {0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1},
					  {1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
					  {0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0},
					  {1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
					  {0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1},
					  {0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1},
					  {0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
					  {0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0}};

void pushSwitch(int CLOCK[], int sIdx, int pushCnt, int pushAcc)
{
	// copy
	int *subCLOCK = new int[16];
	memcpy(subCLOCK,CLOCK,sizeof(int)*16);

	// update
	if(sIdx-1 == -1)
	{}
	else if(pushCnt ==0)
	{}
	else
	{
		pushAcc = pushAcc + pushCnt;
		
		for(int i=0; i<16; i++)		
		{
			if(SWITCH[sIdx-1][i] == 1)
			{
				subCLOCK[i] = (subCLOCK[i]+(3*pushCnt))%12;
				if(subCLOCK[i]==0)
					subCLOCK[i]=12;
			}
		}
	}

	int TorF=0;
	// check finish
	for(int i=0; i<16; i++)
	{
		if(subCLOCK[i]!= 12)
		{	
			TorF=1;
			break;
		}
	}

	if(TorF==0)
	{
		if(pushAcc<result)
			result = pushAcc;
	}
	else
	{
		if(sIdx<10)
		{
			for(int i=0; i<4; i++)
				pushSwitch(subCLOCK,sIdx+1,i,pushAcc);
		}
		delete[] subCLOCK;
	}
}


int main()
{
	int testcase;
	scanf("%d",&testcase);

	for(int i=0; i<testcase; i++)
	{
		result = 987654321;

		// make clock
		int *CLOCK = new int[16];

		for(int j=0; j<16; j++)
			scanf("%d",&CLOCK[j]);

		// recursive
		pushSwitch(CLOCK,0,0,0);
		
		if(result == 987654321)
			result = -1;

		printf("%d\n",result);

/*
		for(int j=0; j<16; j++)
			printf("%d ",CLOCK[j]);
*/	
	}
}

