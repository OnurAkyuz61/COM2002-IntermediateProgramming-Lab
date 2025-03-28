#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void function2(int* ptr, int y);
void function(int* x, int* y);

int main(void) {
    int x, y;
    function(&x, &y);
    printf("x = %d, y = %d\n", x, y);  // Will print: x = 13, y = 7
    return 0;
}

void function2(int* ptr, int y) {
    int x;
    x = 10;
    *ptr = 2 * x - y;  // *ptr = 2 * 10 - y
}

void function(int* x, int* y) {
    function2(x, 7);   // Sets *x to 13 (2 * 10 - 7)
    function2(y, *x);  // Sets *y to 7 (2 * 10 - 13)
}