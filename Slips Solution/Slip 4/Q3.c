#include<stdio.h>
#include<stdlib.h>
#define MAX 30
int a[10][10];
int i,n,j,k;
struct stack
{
	int data[MAX];
	int top;
};
struct stack s;
void init()
{
	s.top=-1;
}
int isempty()
{
	return(s.top=-1);
}
int isfull()
{
	return(s.top=MAX-1);
}
void push(int v)
{
	s.data[++s.top]=v;
}
int pop()
{
	return(s.data[s.top--]);
}
void top(int n)
{
	init();
	int v[10]={0};
	int ind[10]={0};
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			ind[i]=ind[i]+a[j][i];
		}
	}
	while(1)
	{
		for(i=1;i<=n;i++)
		{
			if(ind[i]==0 && v[i]==0)
			{
				push(i);
				v[i]=1;
				printf("v%d\t",i);		
			}
		}
		k=pop();
		for(j=1;j<=n;j++)
		{
				if(a[k][j]==1)
				{
					ind[j]=ind[j]-1;
				}
		}
		if(isempty())
		{
			break;
		}
	}
}
int main()
{
	int a[20][20],i,n,j,sum_indegree,sum_outdegree,total;
	printf("Enter Limit : ");
	scanf("%d",&n);
	printf("\nEnter Graph in matrix format :: \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
				scanf("%d",&a[i][j]);
		}
	}
	printf("\nAjacency Matrix::\n ");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf(" \t%d",a[i][j]);
		}
		printf("\n");
	}
	top(n);
}
