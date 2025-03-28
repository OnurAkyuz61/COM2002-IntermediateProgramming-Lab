#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    // Exercise 3: Demonstrating pointer operations and output
    int value = 6, *p = &value, *q;
    
    printf("The output will be:\n");
    printf("%d\n", p);      // Prints address stored in p
    printf("%d\n", *p);     // Prints 6 (value at address p)
    printf("%d\n", &p);     // Prints address of p
    printf("%d\n", value);  // Prints 6
    printf("%d\n", &value); // Prints address of value
    printf("%d\n", *value); // This will cause error - can't dereference int
    printf("%d\n", &*value);// This will cause error - can't take address of dereferenced int
    printf("%d\n", q);      // Prints undefined value (uninitialized pointer)
    printf("%d\n", *q);     // This will cause error - dereferencing uninitialized pointer
    printf("%d\n", &q);     // Prints address of q
    
    return 0;
}
