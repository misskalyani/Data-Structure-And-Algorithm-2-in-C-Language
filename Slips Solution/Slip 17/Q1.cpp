#include<stdio.h>
int ht[10];
void init()
{
  int i;
  for(i=0;i<10;i++)
  {
    ht[i]=-1;
  }
}
int hash(int num,int i)
{
   return (num%10+i)%10;
}
void insert(int num)
{
   int i,index;
   for(i=0;i<10;i++)
   {
      index=hash(num,i);
      if(ht[index]==-1)
      {
        ht[index]=num;
        break;
      }
   }
}
void disp()
{
   int i;
   for(i=0;i<10;i++)
   {
      printf("%d\t",ht[i]);
   }
}
int search(int num)
{
   int i,index;
   for(i=0;i<10;i++)
   {
      index=hash(num,i);
      if(ht[index]==num)
      {
         return index;
      }
   }
  return -1;
}
void del(int num)
{
  int index=search(num);
  if(ht[index]==-1)
      printf("Not found");
  else
  {
     ht[index]=-1;
      printf("\n Del succ..");
  }
}
int main()
{
   int ch,num,index;
   init();
   do
   {
	     printf("\n 1-insert \n 2 disp \n 3-search \n 4-del :");
	     printf("\nEnter Choice :: ");
		 scanf("%d",&ch);
	     switch(ch)
	     {
		      case 1:printf("Enter number:");
				      scanf("%d",&num);
				      insert(num);
				      break;
		      case 2: disp();
				      break;
		      case 3: printf("Enter number:");
				      scanf("%d",&num);
				   	  index=search(num);
				  	  if(index==-1)
				            printf("Number not found");
				      else
				            printf("\n Number found position=%d",index);
				      break;
		      case 4: printf("Enter number:");
				      scanf("%d",&num);
				      del(num);
				      break;
	
	     }
	   }while(ch<5);
}
