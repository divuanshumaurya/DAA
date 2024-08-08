#include <stdio.h>

// Function to perform insertion sort on the array
void insertionSort(int arr[], int n, int ascending) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        if (ascending) {
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
        } else {
            while (j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
        }
        arr[j + 1] = key;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Test Case 1
    int arr1[] = {250, 150, 400, 320};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Original prices (Test Case 1): ");
    printArray(arr1, n1);
    insertionSort(arr1, n1, 0); // Sort in descending order
    printf("Sorted prices (Test Case 1): ");
    printArray(arr1, n1);

    // Test Case 2
    int arr2[] = {100, 900, 700, 150};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Original prices (Test Case 2): ");
    printArray(arr2, n2);
    insertionSort(arr2, n2, 1); // Sort in ascending order
    printf("Sorted prices (Test Case 2): ");
    printArray(arr2, n2);

    return 0;
}

