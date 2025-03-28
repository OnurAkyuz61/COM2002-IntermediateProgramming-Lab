#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int values[] = { 0, 3, 28, 1, 30, 41, 20, 14, 301 }, *ptr;
    
    // Store pointer to first element
    ptr = values;
    
    // Store 35 as the first element using pointer ptr
    *ptr = 35;
    
    // Print the array to verify the change
    printf("First element is now: %d\n", values[0]);
    printf("Array contents: ");
    for(int i = 0; i < 9; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
    
    return 0;
}
