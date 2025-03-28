#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Corrected function that modifies an array by storing zero into each element
void store_zeros(int a[], int n) {  // Removed const as we need to modify the array
    int i;
    for (i = 0; i < n; i++) {
        a[i] = 0;
    }
}

int main() {
    int test_array[] = {1, 2, 3, 4, 5};
    int n = sizeof(test_array) / sizeof(test_array[0]);
    
    printf("Array before store_zeros: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", test_array[i]);
    }
    printf("\n");
    
    store_zeros(test_array, n);
    
    printf("Array after store_zeros: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", test_array[i]);
    }
    printf("\n");
    
    return 0;
}

/* The original function had these errors:
   1. const int a[] prevented modifying the array elements
   2. The function should modify the array, so const qualifier should be removed
   
   The corrected version:
   - Removed const qualifier to allow array modification
   - Function now works as intended, setting all elements to zero
*/
