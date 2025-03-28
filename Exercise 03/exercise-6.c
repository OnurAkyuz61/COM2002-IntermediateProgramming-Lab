#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    // Given declaration
    char str[] = "Welcome to course";
    
    // Print with different format specifiers
    printf("%.3s\n", str);     // Prints first 3 characters: "Wel"
    printf("%.5s\n", str);     // Prints first 5 characters: "Welco"
    printf("%10s\n", str);     // Right-justifies in 10-char field
    printf("%-10s\n", str);    // Left-justifies in 10-char field
    printf("%10.3s\n", str);   // Right-justifies 3 chars in 10-char field
    printf("%-10.3s\n", str);  // Left-justifies 3 chars in 10-char field
    
    return 0;
}
