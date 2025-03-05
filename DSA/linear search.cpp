//linera
#include <stdio.h>
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; }
    }
    return -1; 
}
int main() {
    int arr[] = {5, 8, 12, 3, 7, 10, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);
    int result = linearSearch(arr, size, key);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }
    return 0;
}

