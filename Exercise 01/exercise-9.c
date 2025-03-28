#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Function prototype
int* find_middle(int a[], int n);

int main() {
    int values[] = { 0, 3, 28, 1, 30, 41, 20, 14, 301 };
    int n = sizeof(values) / sizeof(values[0]);
    
    int* middle = find_middle(values, n);
    printf("The middle element is: %d\n", *middle);
    printf("Located at address: %p\n", (void*)middle);
    
    return 0;
}

// Function implementation
int* find_middle(int a[], int n) {
    return &a[n / 2];
}
