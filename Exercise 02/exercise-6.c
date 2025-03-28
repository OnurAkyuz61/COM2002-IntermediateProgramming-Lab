#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Function prototype
int* find_largest(int *a, int n);

int main() {
    int values[] = { 0, 3, 28, 1, 30, 41, 20, 14, 301 };
    
    // Call find_largest to find maximum value from elements 2 through 7
    int* result = find_largest(&values[2], 6);  // Start from index 2, length 6 (up to index 7)
    
    printf("Maximum value between elements 2-7: %d\n", *result);
    printf("Original array: ");
    for(int i = 0; i < 9; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
    
    return 0;
}

// Function implementation
int* find_largest(int *a, int n) {
    int* largest = a;  // Start with first element
    
    for(int i = 1; i < n; i++) {
        if(a[i] > *largest) {
            largest = &a[i];
        }
    }
    
    return largest;
}
