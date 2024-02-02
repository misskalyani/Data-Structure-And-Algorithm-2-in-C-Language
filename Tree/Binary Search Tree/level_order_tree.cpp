#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct node
{
	int data;
	struct node *left,*right;
}NODE;
typedef struct
{
	NODE *data[MAX];
	int front,rear;
}QUEUE;
QUEUE *q;
void initq()
{
    q=(NODE*)malloc(sizeof(NODE));
	q->front=q->rear=-1;	
}
void addq(NODE*root)
{
	q->data[++q->rear]=root;
}
NODE*delq()
{
	return (q->data[++q->front]);
}
int isempty()
{
	return(q->front==q->rear);
}
int isfull()
{
	return(q->rear==MAX-1);
}
NODE *create(NODE *root)
{
	NODE *temp,*parent,*newnode;
	int i,n;
	printf("Enter Limit::");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(NODE*)malloc(sizeof(NODE));
		printf("\nEnter Value::");
		scanf("%d",&newnode->data);
		newnode->left=NULL;
		newnode->right=NULL;
		if(root==NULL)
		{
			root=newnode;
			continue;
		}
		temp=root;
		while(temp!=NULL)
		{
			parent=temp;
			if(newnode->data<=temp->data)
				temp=temp->left;
			else
				temp=temp->right;
		}
		if(newnode->data<=parent->data)
			parent->left=newnode;
		else
			parent->right=newnode;
	}
	return root;
}
void inorder(NODE *root)
{
	NODE *temp=root;
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%d\t",temp->data);
		inorder(temp->right);
	}
}
void preorder(NODE *root)
{
	NODE *temp=root;
	if(temp!=NULL)
	{
		printf("%d\t",temp->data);
	    preorder(temp->left);
		preorder(temp->right);
	}
}
void postorder(NODE *root)
{
	NODE *temp=root;
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d\t",temp->data);
	}
}

void levelorder(NODE *root)
{
	int level=0;
	NODE *temp;
	initq();
	addq(root);
	addq(NULL);
	printf("\nLevel = %d ",level);
	while(!isempty())
	{
		temp=delq();
		if(temp==NULL)
		{
			level++;
			if(!isempty())
			{
				addq(NULL);
				printf("\nLevel = %d ",level);
			}
		}
		else 
		{
			printf("\n %d \t",temp->data);
			if(temp->left!=NULL)
				addq(temp->left);
			if(temp->right!=NULL)
				addq(temp->right);	
		}
	}
}

int main()
{
	NODE*root=NULL;
	root=create(root);
	printf("\nPreorder::");
	preorder(root);
	printf("\nInorder::");
	inorder(root);
	printf("\nPostorder::");
	postorder(root);
	printf("\n\nLEVEL ORDER ::");
	levelorder(root);
	
}
