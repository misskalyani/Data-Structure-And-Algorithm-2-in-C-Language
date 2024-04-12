#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int data;
	struct node*next;
};
struct node *head[10];
void createlist(int a[10][10],int n)
{
	struct node *newnode,*temp;	
	int i,j;
	for(i=1;i<=n;i++)
	{
		head[i]=NULL;
		for(j=1;j<=n;j++)
		{
			if(a[i][j]==1)
			{
				newnode=(struct node*)malloc(sizeof(struct node));
				newnode->data=j;
				newnode->next=NULL;
			
				if(head[i]==NULL)
				{
					head[i]=temp=newnode;
				}
				else
				{
					temp->next=newnode;
					temp=newnode;
				}
		   }
		}
	}
}
void disp(int n)
{
	struct node*temp;
		int i;
	for(i=1;i<=n;i++)
	{
		printf("\n Head%d->=",i);
		for(temp=head[i];temp!=NULL;temp=temp->next)
		{
			printf("%d->",temp->data);
		}
		printf("NULL");
	}
}
int main()
{
	int a[10][10],i,j,n;
	printf("Enter Limit : ");
	scanf("%d",&n);
	printf("Enter graph in matrix format:\n ");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			
				scanf("%d",&a[i][j]);
			
		}
	}
	printf("graph in matrix format :\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			
				printf("%d\t",a[i][j]);
			
		}
		printf(" \n");
	}
	createlist(a,n);
	disp(n);
}

