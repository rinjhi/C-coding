//array insertion deletion and traversal
#include <stdio.h>
#define MAX_SIZE 100 // Define the maximum size of the array
// Function to insert an element at a given position in an array
void insert(int arr[], int *n, int pos, int x) {
    // Check if the position is valid
    if (pos < 0 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }

    // Check if the array has reached its maximum capacity
    if (*n >= MAX_SIZE) {
        printf("Array is full! Cannot insert a new element.\n");
        return;
    }

    // Shift elements to the right to create space for the new element
    for (int i = *n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }

    // Insert the new element at the specified position
    arr[pos] = x;
    (*n)++; // Increase the size of the array
}

// Function to delete an element at a given position in an array
void deleteelement(int arr[], int *n, int pos) {
    // Check if the position is valid
    if (pos < 0 || pos >= *n) {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements to the left to fill the gap
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--; // Decrease the size of the array
}

// Function to traverse and print the elements of an array
void traverse(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE], n, x, pos;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Ensure the initial size does not exceed MAX_SIZE
    if (n > MAX_SIZE) {
        printf("Number of elements exceeds the maximum size (%d).\n", MAX_SIZE);
        return 1;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Insert an element
    printf("Enter the position and element to insert: ");
    scanf("%d %d", &pos, &x);
    insert(arr, &n, pos, x);
    printf("Array after insertion: ");
    traverse(arr, n);

    // Delete an element
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    deleteelement(arr, &n, pos);
    printf("Array after deletion: ");
    traverse(arr, n);

    return 0;
}

