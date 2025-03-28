#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int values[] = { 0, 3, 28, 1, 30, 41, 20, 14, 301 }, *ptr1, *ptr2;
    
    ptr1 = &values[4];  // ptr1 points to values[4] (30)
    printf("%d\n", ptr1);    // Prints address of values[4]
    printf("%d\n", *ptr1);   // Prints value at values[4] (30)
    printf("%d\n", &ptr1);   // Prints address of ptr1 variable
    
    ptr2 = ptr1 + 2;    // ptr2 points to values[6] (20)
    printf("%d\n", ptr2);    // Prints address of values[6]
    printf("%d\n", *ptr2);   // Prints value at values[6] (20)
    printf("%d\n", &ptr2);   // Prints address of ptr2 variable
    
    ptr1 = ptr2 - 4;    // ptr1 now points to values[2] (28)
    printf("%d\n", ptr1);    // Prints address of values[2]
    printf("%d\n", *ptr1);   // Prints value at values[2] (28)
    printf("%d\n", &ptr1);   // Prints address of ptr1 variable
    
    int value = ptr2 - ptr1; // Calculates number of elements between pointers
    printf("%d\n", value);   // Prints 4 (difference in positions)
    
    return 0;
}
