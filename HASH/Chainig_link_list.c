#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;
}*ht[10];
void init()
{
   int i;
   for(i=0;i<10;i++)
   {
   	ht[i]=NULL;
   }
}
int hash(int num)
{
   return num%10;
}
void insert(int num)
{
   struct node*temp,*newnode;
   int i;
   newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=num;
   newnode->next=NULL;
   i=hash(num);
   if(ht[i]==NULL)
   {
      ht[i]=newnode;
   }
   else
   {
      for(temp=ht[i];temp->next!=NULL;temp=temp->next);
      temp->next=newnode;
   }
}
void disp()
{
    struct node *temp;
    int i;
    for(i=0;i<10;i++)
    {
       printf("\n ht[%d] = ",i);
       for(temp=ht[i];temp!=NULL;temp=temp->next)
       {
          printf("%d\t",temp->data);
       }
    
    }
}
void search(int num)
{
   int i;
   struct node*temp;
   i=hash(num);
   for(temp=ht[i];temp!=NULL;temp=temp->next)
   {
       if(temp->data==num)
       {
          printf("Number is present in the Hash Table");
          break;
       }
   }
   if(temp==NULL)
      printf("Number Not Found");
}
void del(int num) 
{
	int i;
	struct node *temp ,*temp1;
	i=hash(num); 
	temp=temp1=ht[i] ; 
	if(temp->data==num && temp!=NULL) /* first node */ 
	{
		ht[i]=temp->next;
		free(temp);
		return;
	}
	while(temp!=NULL)  /* find identifier and delete node */
	{
		if(temp->data==num) 
		{
			temp1->next=temp->next;
			free(temp);
			return;
		}
		temp1=temp;
		temp=temp->next;
		
	 }
	printf("\n Identifier not found \n"); 
}
int main()
{
   int num,ch;
   do
   {
      printf("\n1-Insert : \n2-Display : \n3-Search : \n4-Delete : ");
      printf("\nEnter Choice :: ");
      scanf("%d",&ch);
      switch(ch)
      {
         case 1	:  printf("Enter Number :: ");
                  scanf("%d",&num);
                  insert(num);
                  break;
         case 2	:  disp();
                  break;  
         case 3	:  printf("Enter Number :: ");
                  scanf("%d",&num);
                  search(num);
                  break;    
         case 4	:   printf("Enter number:");
                  scanf("%d",&num);
                  del(num);   
				  break;  
      }
   }while(ch<5);
}
