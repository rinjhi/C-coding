//array insertion deletion and traversal
#include <stdio.h>
#define MAX_SIZE 100 
void insert(int arr[], int n, int pos, int x) {
    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return;
    }
    if (n >= MAX_SIZE) {
        printf("Array is full! Cannot insert a new element.\n");
        return;
    }
    for (int i = n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = x;
    (n)++;
}
void deleteelement(int arr[], int n, int pos) {
    if (pos < 0 || pos >=n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (n)--;
}
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
    if (n > MAX_SIZE) {
        printf("Number of elements exceeds the maximum size (%d).\n", MAX_SIZE);
        return 1;
    }
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the position and element to insert: ");
    scanf("%d %d", &pos, &x);
    insert(arr, &n, pos, x);
    printf("Array after insertion: ");
    traverse(arr, n);
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    deleteelement(arr, &n, pos);
    printf("Array after deletion: ");
    traverse(arr, n);
    return 0;
}

