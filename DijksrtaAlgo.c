#include<stdio.h>
#define INFINITY 999

void dijkstra(int n, int source, int cost[10][10])
{
    
}
int main()
{
    int cost[10][10], i, j, n, source;
    printf("Enter the number of nodes to be entered\n");
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("\nEnter cost for %d -> %d : ", i, j);
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
            cost[i][j] = INFINITY;
        }
    }
    printf("Enter source node : \n");
    scanf("%d", &source);
    dijkstra(n, source, cost);
}