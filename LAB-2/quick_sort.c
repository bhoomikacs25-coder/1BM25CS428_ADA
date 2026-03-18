#include <stdio.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose last element as pivot
    int i = low - 1;
    int j;

    for (j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi;

        pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1); // Left subarray
        quickSort(arr, pi + 1, high); // Right subarray
    }
}

// Main function
int main() {
    int n, i;
    int arr[10000];
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

        // Start time
    start = clock();

    quickSort(arr, 0, n - 1);

    // End time
    end = clock();



    // Calculate time taken
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nTime taken = %f seconds\n", time_taken);

    return 0;
}
