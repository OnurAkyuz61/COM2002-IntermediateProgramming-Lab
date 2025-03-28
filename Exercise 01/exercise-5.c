#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Function prototype
int* find_largest(int a[], int n);

int main() {
    int values[] = { 0, 3, 28, 1, 30, 41, 20, 14, 301 };
    int n = sizeof(values) / sizeof(values[0]);
    
    int* result = find_largest(values, n);
    printf("The largest value is: %d\n", *result);
    printf("Located at address: %p\n", (void*)result);
    
    return 0;
}

// Function implementation
int* find_largest(int a[], int n) {
    int* largest = &a[0];  // Start with first element
    
    for(int i = 1; i < n; i++) {
        if(a[i] > *largest) {
            largest = &a[i];
        }
    }
    
    return largest;
}
