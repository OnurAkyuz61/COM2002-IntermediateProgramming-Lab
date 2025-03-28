#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Function prototype
char* find_middle(char a[], int n);

int main() {
    char planets[][10] = {
        "Mercury",
        "Venus",
        "Earth",
        "Mars",
        "Jupiter",
        "Saturn",
        "Uranus",
        "Pluto"
    };
    
    // Find middle element in row 5 (Saturn)
    char* middle = find_middle(planets[5], strlen(planets[5]));
    
    printf("Planet in row 5: %s\n", planets[5]);
    printf("Middle character: %c\n", *middle);
    
    return 0;
}

// Function implementation
char* find_middle(char a[], int n) {
    return &a[n / 2];
}
