#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// Simple macro for file information
#define FILE_INFO "File information is given below."

// Parameterized macro to add two numbers
#define ADD(x, y) ((x) + (y))

// Parameterized macro to subtract two numbers
#define SUB(x, y) ((x) - (y))

// Parameterized macro for welcome message using # operator
#define message_for(name, surname) "Hello " #name " " #surname ". Welcome to COM2002 Intermediate Programming Lab!"

// Conditional compilation to ensure bigger number is first
#ifdef SWAP_NUMBERS
    #define FIRST_NUM 8
    #define SECOND_NUM 9
#else
    #define FIRST_NUM 9
    #define SECOND_NUM 8
#endif

int main() {
    // Print file information using predefined macro
    printf("%s\n", FILE_INFO);
    printf("File\t: %s\n", __FILE__);
    printf("Date\t: %s\n", __DATE__);
    printf("Time\t: %s\n", __TIME__);
    printf("Line\t: %d\n", __LINE__);
    printf("ANSI\t: %d\n\n", __STDC__);

    // Using message_for macro with # operator
    printf("%s\n", message_for(John, Doe));

    // Using ADD macro
    int num1 = 5, num2 = 6;
    printf("Enter first number:%d\n", num1);
    printf("Enter second number:%d\n", num2);
    printf("The summation of %d and %d is %d\n", num1, num2, ADD(num1, num2));

    // Using SUB macro with conditional compilation
    printf("The subtraction of %d and %d is calculated.\n", FIRST_NUM, SECOND_NUM);
    printf("%d - %d = %d\n", FIRST_NUM, SECOND_NUM, SUB(FIRST_NUM, SECOND_NUM));

    return 0;
}
