#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    // Original statement
    float values[] = { 0.5, 3.0, 28.7, 1.1, 30.9, 41.2, 20.9, 14.5 };
    float *ptr = &values[0];
    
    // Rewritten using compound literal
    float *ptr2 = (float[]){ 0.5, 3.0, 28.7, 1.1, 30.9, 41.2, 20.9, 14.5 };
    
    // Verify both methods work the same
    printf("Original array first element: %f\n", *ptr);
    printf("Compound literal first element: %f\n", *ptr2);
    
    return 0;
}
