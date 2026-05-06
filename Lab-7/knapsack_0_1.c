#include <stdio.h>

int knapsack(int W, int w[], int v[], int n) {
    int K[n+1][W+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {

            if (i == 0 || j == 0) {
                K[i][j] = 0;
            }
            else if (w[i-1] <= j) {
                int take = v[i-1] + K[i-1][j - w[i-1]];
                int not_take = K[i-1][j];
                K[i][j] = (take > not_take) ? take : not_take;
            }
            else {
                K[i][j] = K[i-1][j];
            }
        }
    }

    return K[n][W];
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int w[n], v[n];

    printf("Enter weights:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    int result = knapsack(W, w, v, n);

    printf("Maximum value = %d\n", result);

    return 0;
}
