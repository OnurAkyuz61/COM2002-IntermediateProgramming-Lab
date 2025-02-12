#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int value4 = 1;

int function(int* param1, int param2, int* param3);

int main(void) {
    int value1 = 7, value2 = 3, value3 = 2;
    printf("Print in main: %d %d %d %d\n", value1, value2, value3, value4);
    value4 = function(&value1, value2, &value3);
    printf("Print in main: %d %d %d %d\n", value1, value2, value3, value4);
    return 0;
}

int function (int* param1, int param2, int* param3) {
    int static value6 = 11;
    
    *param1 = *param1 +2;
    param2 = param2 + 5;
    ++*param3;
    param3 = param1;
    value6 = value6 + *param3;;
    printf("Print in function: %d %d %d %d\n", value4, param2, *param3, value6);
    param3 = &param2;
    return *param3;
}