#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int A[50], int L, int R) {
    int x = A[R];
    int i = L;
    for (int j = L; j <= R - 1; j++) {
        if (A[j] <= x) {
            swap(&A[i], &A[j]);
            i++;
        }
    }
    swap(&A[i], &A[R]);
    return i;
}

void QuickSort(int A[50], int L, int R) {
    if (L < R) {
        int Q = partition(A, L, R);
        QuickSort(A, L, Q - 1);
        QuickSort(A, Q + 1, R);
    }
}

int main() {
    int n, A[50];
    printf("Enter the size of array: \n");
    scanf("%d", &n);
    printf("Enter the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    QuickSort(A, 0, n - 1);
    printf("Sorted Array\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
   
}
