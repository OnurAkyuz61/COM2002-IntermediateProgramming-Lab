#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert month number to month name
const char* get_month_name(int month) {
    static const char* month_names[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    
    if (month >= 1 && month <= 12) {
        return month_names[month - 1];
    } else {
        return "Invalid Month";
    }
}

int main(int argc, char *argv[]) {
    int month, day, year;
    
    // Check if date is provided as command line argument
    if (argc != 2) {
        printf("Usage: %s <date>\n", argv[0]);
        printf("Date format: m-d-yyyy or m/d/yyyy (no spaces)\n");
        return 1;
    }
    
    // Try to parse the date with different formats
    if (sscanf(argv[1], "%d-%d-%d", &month, &day, &year) == 3 ||
        sscanf(argv[1], "%d/%d/%d", &month, &day, &year) == 3) {
        
        // Validate date components
        if (month < 1 || month > 12) {
            printf("Error: Invalid month. Month must be between 1 and 12.\n");
            return 1;
        }
        
        if (day < 1 || day > 31) {
            printf("Error: Invalid day. Day must be between 1 and 31.\n");
            return 1;
        }
        
        // Display the date in the required format
        printf("%s %d, %d\n", get_month_name(month), day, year);
        
    } else {
        printf("Error: Invalid date format. Use m-d-yyyy or m/d/yyyy.\n");
        return 1;
    }
    
    return 0;
}
