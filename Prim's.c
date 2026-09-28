#include <stdio.h>

#define INF 999

int main()
{
    int n;
    int cost[10][10];
    int visited[10] = {0};
    int edges = 0;
    int min, u = 0, v = 0;
    int total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;

    while (edges < n - 1)
    {
        min = INF;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("Edge: %d - %d  Weight: %d\n", u, v, min);

        total = total + min;
        visited[v] = 1;
        edges++;
    }

    printf("Minimum cost = %d\n", total);

    return 0;
}