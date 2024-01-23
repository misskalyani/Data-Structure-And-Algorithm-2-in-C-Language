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
int search(NODE *root)
{
	int num;
	printf("Enter Number::");
	scanf("%d",&num);
	NODE *temp=root;
	while(temp!=NULL)
	{
		if(num==temp->data)
		{
			return num;
		}
		else if(num<temp->data)
		{
			temp=temp->left;
		}
		else
		{
			temp=temp->right;
		}
	}
	return -1;
}
NODE *recursive_insert(NODE *root,int num)
{
	NODE *newnode,*temp,*parent;
	int n,i;
	newnode=(NODE*)malloc(sizeof(NODE));
	newnode->data=num;
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL)
	{
			root=newnode;
			return root;
	}
	temp=root;
	if(newnode->data<temp->data)
		temp->left=recursive_insert(temp->left,num);
	else
		temp->right=recursive_insert(temp->right,num);
	return root;
}
NODE *del(NODE* root,int key)
{
	NODE *temp;
	if(root==NULL)
	{
		return root;
	}
	if(key<root->data)
		root->left=del(root->left,key);
	else if(key>root->data)
		root->right=del(root->right,key);
	else
	{
		if(root->left==NULL)
		{
			temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			temp=root->left;
			free(root);
			return temp;
		}
		temp=root->right;
		while(temp && temp->left!=NULL)
		{
			temp=temp->left;
		}
		root->data=temp->data;
		root->right=del(root->right,temp->data);
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
int Count_NON_leaf_nodes(NODE *root)
{
	static int count=0;
	NODE *temp=root;
	if(temp!=NULL)
	{
		if((temp->left==NULL)||(temp->right==NULL))
			count++;
		Count_total_nodes(temp->left);
		Count_total_nodes(temp->right);
	}
	return count;
}
int main()
{
	int ch,ans,num,key;
	NODE *root=NULL;
	do
	{
		printf("\n\n1-create\n2-preorder\n3-inorder\n4-postorder\n5-insert\n6-search\n7-recursive insert\n8-delete\n9-count total nodes\n10-count leaf node\n11-count non leaf node\nEnter choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :root=create(root);
					break;
			case 2 :preorder(root);
					break;
			case 3 :inorder(root);
					break;
			case 4 :postorder(root);
					break;	
			case 5 :root=insert(root);
					break;
			case 6 :ans=search(root);
					if(ans==-1)
						printf("Not Found");
					else
						printf("Found");
					break;
		    case 7 :printf("\nEnter Value::");
					scanf("%d",&num);
					root=recursive_insert(root,num);
					break;	
			case 8 :printf("\nEnter Value::");
					scanf("%d",&key);
					root=del(root,key);
					break;
			case 9 :
			        printf("\nCount Total node = %d",Count_total_nodes(root));
			        break;
			case 10 :printf("\nCount Leaf Node = %d",Count_leaf_nodes(root));
			        break;
			case 11:printf("\nCount Non Leaf Node = %d",Count_NON_leaf_nodes(root));
			        break;		 																						
		}
	}while(ch<15);
}
