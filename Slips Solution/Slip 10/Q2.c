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

int main()
{
	int num,ch;
	NODE *root=NULL;
	do
	{
		printf("\n1-Create :  \n2-Insert :  \n3-Postorder :  ");
		printf("\nEnter Choice :: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:root=create(root);
			       break;
			case 2:root=insert(root);
			       break;
			case 3:printf("\nInorder Display::");
				   inorder(root);          
		}
	}while(ch<4);
}

