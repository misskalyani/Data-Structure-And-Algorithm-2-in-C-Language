#include<stdio.h>
#include<stdlib.h>
#include"Binary tree.h"
int main()
{
	int num;
	NODE *root=NULL;
	root=create(root);
	printf("\nInorder Display::");
	inorder(root);
	printf("\nPreorder Display::");
	preorder(root);
	printf("\nPostorder Display::");
	postorder(root);
}
