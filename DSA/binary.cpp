//binary
#include<stdio.h>
int binary(int arr[], int size, int element){
    int low=0;
    int high=size-1;
    int mid;

    while(low<=high){
        mid = (low + high) / 2;
        if(arr[mid] == element)
            return mid;
        else if(arr[mid] < element)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(){
    int arr[] = {1, 2, 3, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(int);
    int element = 7;
    int searchindex = binary(arr, size, element);
    if (searchindex != -1)
        printf("The element %d is found at index %d\n", element, searchindex);
    else
        printf("Element not found\n");
    return 0;
}

