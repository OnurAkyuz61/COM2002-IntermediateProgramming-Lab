#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int values[] = { 0, 3, 28, 1, 30, 41, 20, 14, 301 };
    
    // Store 10 in element 5 using array name as a pointer
    *(values + 5) = 10;  // Equivalent to values[5] = 10
    
    // Print array to verify the change
    printf("Element at index 5 is now: %d\n", values[5]);
    printf("Array contents: ");
    for(int i = 0; i < 9; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
    
    return 0;
}
