#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    // Declare array arr with 10 elements as float
    float arr[10];
    
    // Declare pointer p and make it point to element 5 of arr
    float* p = &arr[5];
    
    // Demonstration
    printf("Array address: %p\n", (void*)arr);
    printf("Pointer p points to element 5 at address: %p\n", (void*)p);
    
    return 0;
}
