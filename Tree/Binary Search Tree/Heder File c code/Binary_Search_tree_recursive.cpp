#include<stdio.h>
#include<stdlib.h>
#include"Menu_Binary_Tree_recursive.h"
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
						printf("\nFOUND");
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
