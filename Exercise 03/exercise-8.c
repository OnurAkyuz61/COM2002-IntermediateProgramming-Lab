#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char str[50];  // Make sure buffer is large enough
    
    printf("Enter a line: ");
    gets(str);  // Will read entire line "Welcome to course"
    
    printf("You entered: %s\n", str);
    printf("Note: gets reads the entire line including spaces\n");
    printf("Warning: gets is unsafe and deprecated, better to use fgets\n");
    
    return 0;
}
