//. Implement a Binary search tree (BST) library (btree.h) with operations – create, insert, 
//preorder. Write a menu driven program that performs the above operations
#include<stdio.h>
#include<stdlib.h>
#include"binary tree.h"
int main()
{
	int num,ch;
	NODE *root=NULL;
	do
	{
		printf("\n1-Create :  \n2-Insert :  \n3-Preorder :  ");
		printf("\nEnter Choice :: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:root=create(root);
			       break;
			case 2:root=insert(root);
			       break;
			case 3:printf("\nPreorder Display::");
				   preorder(root);          
		}
	}while(ch<4);
}

