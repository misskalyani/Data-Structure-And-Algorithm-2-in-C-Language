#include<stdio.h>
int n=10;
int a[10];
void init()
{
   int i;
   for(i=0;i<n;i++)
     a[i]=-1;  
}
int hash(int num)
{
  return num%10;
}
void insert(int num)
{
   int key;
   key=hash(num);
   if(a[key]==-1)
   {
       a[key]=num;
       printf("\n Insert Succ..");
   } 
   else
   {
       printf("\n Collision Occurs...at %d position",key);
   }
}
void del(int num)
{
   int key=hash(num);
   if(a[key]==num)
   {
       a[key]=-1;
       printf("\n Deleted succ..");
   }
   else
   {
      printf("\n Number not present in the HAsh Table");
   }
}
void search(int num)
{
   int key=hash(num);
   if(a[key]==num)
       printf("Record Found");
   else
     printf("Record not found..");
}
void disp()
{
   int i;
   for(i=0;i<n;i++)
   {
      printf("%d\t",a[i]);
   }
}
int main()
{
   int ch,i,num;
  init();
   do
   {
       printf("\n Menu\n 1-insert \n 2-del \n 3-search:");
       printf("\n Enter choice:");
       scanf("%d",&ch);
       switch(ch)
       {
         case 1: printf("Enter number:");
                      scanf("%d",&num);
                      insert(num);
                      break;
         case 2: printf("Enter number:");
                      scanf("%d",&num);
                      del(num);
                      break;
         case 3: printf("Enter number:");
                      scanf("%d",&num);
                      search(num);
                      break;
         case 4: disp();
                      break;             
       }
   }while(ch<5);
}
