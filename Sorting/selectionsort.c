//selection sort
#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min;

    for (i = 0; i < n - 1; i++) {
        min = arr[i];
        int loc = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j] < min) {
                min = arr[j];
                loc = j;
            }
        }
       arr[loc] = arr[i];
       arr[i]  = min;

    }
}


int main() {
    int arr[50], n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("enter the array");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    selectionSort(arr, n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
