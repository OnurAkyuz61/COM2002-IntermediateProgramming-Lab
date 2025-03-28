#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char str[50];  // Make sure buffer is large enough
    
    printf("Enter a line: ");
    scanf("%s", str);  // Will read "Welcome" only (stops at space)
    
    printf("You entered: %s\n", str);
    printf("Note: scanf only reads until the first whitespace\n");
    
    return 0;
}
