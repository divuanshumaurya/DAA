#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the maximum length of item codes
int getMaxLength(char arr[][5], int n) {
    int maxLength = strlen(arr[0]);
    for (int i = 1; i < n; i++) {
        int length = strlen(arr[i]);
        if (length > maxLength) {
            maxLength = length;
        }
    }
    return maxLength;
}

// Function to do counting sort of arr[] according to the digit represented by exp
void countingSort(char arr[][5], int n, int exp) {
    char output[n][5]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++) {
        int digit = (strlen(arr[i]) > exp) ? (arr[i][strlen(arr[i]) - exp - 1] - '0') : 0;
        count[digit]++;
    }

    // Change count[i] so that count[i] now contains the actual position of this digit in output[]
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        int digit = (strlen(arr[i]) > exp) ? (arr[i][strlen(arr[i]) - exp - 1] - '0') : 0;
        strcpy(output[count[digit] - 1], arr[i]);
        count[digit]--;
    }

    // Copy the output array to arr[], so that arr now contains sorted numbers according to the current digit
    for (i = 0; i < n; i++) {
        strcpy(arr[i], output[i]);
    }
}

// The main function to that sorts arr[] of size n using Radix Sort
void radixSort(char arr[][5], int n) {
    // Find the maximum number of digits
    int maxLength = getMaxLength(arr, n);

    // Do counting sort for every digit starting from the least significant digit to the most significant digit
    for (int exp = 0; exp < maxLength; exp++) {
        countingSort(arr, n, exp);
    }
}

// Function to print an array of strings
void printArray(char arr[][5], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Test Case 1
    char arr1[][5] = {"5021", "3023", "8045", "6732"};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Original item codes (Test Case 1): ");
    printArray(arr1, n1);
    radixSort(arr1, n1);
    printf("Sorted item codes (Test Case 1): ");
    printArray(arr1, n1);

    // Test Case 2
    char arr2[][5] = {"1452", "3890", "5643", "2751"};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Original item codes (Test Case 2): ");
    printArray(arr2, n2);
    radixSort(arr2, n2);
    printf("Sorted item codes (Test Case 2): ");
    printArray(arr2, n2);

    return 0;
}

