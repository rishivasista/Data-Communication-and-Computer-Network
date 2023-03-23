

#include <stdio.h>
#define INFINITY 9999


void dijikstra(int cost[10][10], int n, int startnode)
{
	int distance[10], path[10];
	int visited[10], count, mindistance, nextnode, i,j;
	
	for(i=0;i< n;i++)
	{
		distance[i]=cost[startnode][i];
		path[i]=startnode;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count < n-1){
		mindistance=INFINITY;
		for(i=0;i < n;i++)
			if(distance[i] < mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
		visited[nextnode]=1;
		for(i=0;i < n;i++)
			if(!visited[i])
				if(mindistance+cost[nextnode][i] < distance[i])
				{
					distance[i]=mindistance+cost[nextnode][i];
					path[i]=nextnode;
				}
			count++;
	}
 
	for(i=0;i < n;i++)
		if(i!=startnode)
		{
			printf("Distance of %d = %d\n", i+1, distance[i]);
			printf("Path = %d", i+1);
			j=i;
			do
			{
				j=path[j];
				printf(" <-%d", j+1);
			}
			while(j!=startnode);
      printf("\n");
		}
}
 
int main() {
  int Cost[10][10], i, j, n, start;
  printf("Enter number of nodes\n");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
        printf("\nEnter cost for %d -> %d :", i+1, j+1);
        scanf("%d", &Cost[i][j]);
        if(Cost[i][j] == 0)
        Cost[i][j] = INFINITY;
    }
  }
  dijikstra(Cost, n, start);

  return 0;
}