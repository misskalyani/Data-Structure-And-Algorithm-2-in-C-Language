#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void swap(int*a,int*b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
void build_heap(int a[],int n,int i)
{
	int large_index=i;
	int left=2*i+1;
	int right=left+1;
	if(left<n && a[left]>a[large_index])
	{
		large_index=left;
	}
	if(right<n && a[right]>a[large_index])
	{
		large_index=right;
	}
	if(large_index!=i)
	{
		swap(&a[i],&a[large_index]);
		build_heap(a,n,large_index);
	}
}
void heap_sort(int a[],int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
	{
		build_heap(a,n,i);
	}
	for(i=n-1;i>=0;i--)
	{
	    swap(&a[0],&a[i]);
		build_heap(a,i,0);
	}
}
int main()
{
	int a[50],n,i;
	printf("Enter Limit : ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		a[i]=rand()%100;
	}
	printf("\nRandom Number Are : ");
	for(i=0;i<n;i++)
	{
	     printf("%d\t",a[i]);
	}
	heap_sort(a,n);
	
	printf("\nSorted Number Are : ");
	for(i=0;i<n;i++)
	{
     	printf("%d\t",a[i]);
	}
}
