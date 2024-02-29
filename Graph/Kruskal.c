#include<stdio.h>
#include<stdlib.h>
int i, j, k, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];
 
int find(int);
int check(int, int);
 
void main()
{
	  printf("Enter Number Of Vertex :: ");
	  scanf("%d", &n);
	 
	  printf("\nEnter edges:\n");
	  for (i = 1; i <= n; i++)
	  {
	    for (j = 1; j <= n; j++)
	    {
	      scanf("%d", &cost[i][j]);
	      if (cost[i][j] == 0)
	        cost[i][j] = 999;
	    }
	  }
	  printf("\nAdjacency Matrix :: \n");
	  for(i=1;i<=n;i++)
	  {
	  	for(j=1;j<=n;j++)
	  	{
	  		printf("%d\t",cost[i][j]);
		  }
		  printf("\n");
	  }
	  printf("\n MST // Minimum Spanning Tree :: \n");
	  while(ne<n)
	  {
	    for (i = 1, min = 999; i <= n; i++)
	    {
	      for (j = 1; j <= n; j++)
	      {
	        if (cost[i][j] < min)
	        {
	          min = cost[i][j];
	          a = u = i;
	          b = v = j;
	        }
	      }
	    }
	 
	    u = find(u);
	    v = find(v);
	 
	    if (check(u, v)==1)
	    {
	      printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
	      mincost += min;
	    }
	 
	    cost[a][b] = cost[b][a] = 999;
	  }
	 
	  printf("\nMinimum cost = %d\n", mincost);
	  
}
 
int find(int i)
{
  while (parent[i])
    i = parent[i];
  return i;
}
 
int check(int i, int j)
{
  if (u != v)
  {
    parent[v] = u;
    return 1;
  }
 
  return 0;
}
