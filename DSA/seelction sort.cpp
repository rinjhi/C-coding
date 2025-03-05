#include <stdio.h>

void selection(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])  // Removed extraneous semicolon
                min = j;
        }
        // Swap arr[i] and arr[min]
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d \t", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 5, 4, 9, 7, 66, 77, 10};
    int n = 10;
    printf("Unsorted array:\n");
    print(arr, n);

    printf("Sorted array:\n");
    selection(arr, n);
    print(arr, n);

    return 0;
}

