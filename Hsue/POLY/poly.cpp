#include<stdio.h>
#define MAX 10000000

int total=0;

void makepoly(int left, int n1, int n2, int acc)
{
	// accumulate total
	if(n1==-1)
		acc=1;
	else if(n1==0)
		acc = acc*1;
	else
	{
		acc = (n1+n2-1)*acc;
		acc = acc % MAX;
	}

	// check finished
	if(left == 0)
	{
		total += acc;
		total = total %MAX;
	}
	else
	{
		for(int i=left; i>=1; i--)
			makepoly(left-i,n2,i,acc);
	}
}

int main()
{
	int testcase;
	scanf("%d",&testcase);

	for(int i=0; i<testcase; i++)
	{
		int numOfsquare;
		scanf("%d",&numOfsquare);

		total=0;
		makepoly(numOfsquare,-1,0,1);
		printf("%d",total);

	}
}
