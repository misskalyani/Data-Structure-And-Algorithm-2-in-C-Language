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
int Count_total_nodes(NODE *root)
{
	static int count=0;
	NODE *temp=root;
	if(temp!=NULL)
	{
		count++;
		Count_total_nodes(temp->left);
		Count_total_nodes(temp->right);
	}
    return count;
}
int Count_leaf_nodes(NODE *root)
{
	static int count=0;
	NODE *temp=root;
	if(temp!=NULL)
	{
		if((temp->left==NULL)&&(temp->right==NULL))
			count++;
		Count_total_nodes(temp->left);
		Count_total_nodes(temp->right);
	}
	return count;
}
int main()
{
	NODE*root=NULL;
	root=create(root);
	printf("\nCount Total node = %d",Count_total_nodes(root));
	printf("\nCount Leaf Node = %d",Count_leaf_nodes(root));
}
