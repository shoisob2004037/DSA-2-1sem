#include <stdio.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}
int findFinalPosition(int arr[], int n, int element) {
    quicksort(arr, 0, n - 1);
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == element)
            return mid;
        else if (arr[mid] < element)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}
int main() {
    int arr[] = {2, 3, 1, 17, 3, 7, 2, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int element = 5;

    int position = findFinalPosition(arr, n, element);
    if (position != -1)
        printf("The final position of %d in the sequence is %d.\n", element, position);
    else
        printf("Element %d was not found in the sequence.\n", element);
        return 0;
}

