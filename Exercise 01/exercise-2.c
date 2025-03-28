#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    // Exercise 2: Testing which expressions are aliases for i
    int i = 10;  // Example value
    int *p = &i;
    
    printf("Given that i is an int variable and p points to i:\n\n");
    printf("a. int value = *p;    // This IS an alias (gets the value i points to)\n");
    printf("b. float value = *p;   // This is NOT an alias (different type)\n");
    printf("c. int value = p;     // This is NOT an alias (p is an address)\n");
    printf("d. float value = p;    // This is NOT an alias (wrong type and p is an address)\n");
    printf("e. int value = *&i;    // This IS an alias (gets the value at address of i)\n");
    printf("f. float value = *&i;  // This is NOT an alias (different type)\n");
    printf("g. int value = &p;     // This is NOT an alias (address of pointer)\n");
    
    return 0;
}
