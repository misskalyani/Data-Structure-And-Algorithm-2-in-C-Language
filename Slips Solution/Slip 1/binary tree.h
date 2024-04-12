#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left,*right;
}NODE;
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
NODE *insert(NODE *root)
{
	NODE *newnode,*temp,*parent;
	int n,i;
	newnode=(NODE*)malloc(sizeof(NODE));
	printf("\nEnter Value::");
	scanf("%d",&newnode->data);
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL)
	{
			root=newnode;
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
		
	return root;
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


