#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    char str1[20], str2[20];
    
    // Initialize str1 with "CSE002"
    strcpy(str1, "CSE002");
    
    // Copy "Programming" to str2
    strcpy(str2, "Programming");
    
    // Concatenate strings with space in between
    strcat(str1, " ");
    strcat(str1, strcat(str2, " II"));
    
    // Print result
    printf("%s\n", str1);  // Will print: "CSE002 Programming II"
    
    return 0;
}
