#include <stdio.h>
#define MAX 10
#define INF 9999

int main() {
    int n, i, j;
    int cost[MAX][MAX];
    int visited[MAX] = {0};
    int min, mincost = 0;
    int a = 0, b = 0, u = 0, v = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = INF; // No edge
        }
    }

    visited[0] = 1; // Start from first vertex

    printf("\nEdges in MST:\n");

    for(int edge_count = 0; edge_count < n - 1; edge_count++) {
        min = INF;

        for(i = 0; i < n; i++) {
            if(visited[i]) {
                for(j = 0; j < n; j++) {
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        printf("%d - %d : %d\n", a, b, min);

        mincost += min;
        visited[b] = 1;
    }

    printf("\nMinimum Cost = %d\n", mincost);

    return 0;
}
