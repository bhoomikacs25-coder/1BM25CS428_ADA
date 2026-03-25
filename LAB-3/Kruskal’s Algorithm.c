#include <stdio.h>
#define MAX 10
#define INF 9999

int parent[MAX];

// Find function
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Union function
void union_set(int i, int j) {
    parent[i] = j;
}

int main() {
    int n, i, j, a, b, u, v;
    int cost[MAX][MAX];
    int min, mincost = 0;
    int edges = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    // Initialize parent array
    for(i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges in MST:\n");

    while(edges < n - 1) {
        min = INF;

        // Find minimum edge
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(u != v) {
            printf("%d - %d : %d\n", a, b, min);
            mincost += min;
            union_set(u, v);
            edges++;
        }

        // Remove selected edge
        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum Cost = %d\n", mincost);

    return 0;
}
