#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 8

void to_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main(int argc, char *argv[]) {
    const char *planets[] = {"mercury", "venus", "earth", "mars",
                            "jupiter", "saturn", "uranus", "neptune"};
    
    if (argc < 2) {
        printf("Usage: %s planet1 planet2 ...\n", argv[0]);
        return 1;
    }
    
    // For each command line argument (except the program name)
    for (int i = 1; i < argc; i++) {
        char arg[20];
        strcpy(arg, argv[i]);
        to_lower(arg);  // Convert to lowercase for comparison
        
        int is_planet = 0;
        // Check if the argument matches any planet name
        for (int j = 0; j < NUM_PLANETS; j++) {
            if (strcmp(arg, planets[j]) == 0) {
                printf("%s is planet %d\n", argv[i], j + 1);
                is_planet = 1;
                break;
            }
        }
        
        if (!is_planet) {
            printf("%s is not a planet\n", argv[i]);
        }
    }
    
    return 0;
}
