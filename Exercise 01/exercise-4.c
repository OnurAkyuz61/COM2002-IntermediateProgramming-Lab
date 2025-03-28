#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Corrected version of the pay_amount function
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
    // Calculate number of $20 bills
    *twenties = dollars / 20;
    dollars = dollars % 20;  // Use modulo instead of subtraction
    
    // Calculate number of $10 bills
    *tens = dollars / 10;
    dollars = dollars % 10;  // Use modulo instead of subtraction
    
    // Calculate number of $5 bills
    *fives = dollars / 5;
    
    // Calculate number of $1 bills
    *ones = dollars % 5;
}

int main() {
    int dollars = 67;  // Example amount
    int twenties, tens, fives, ones;
    
    pay_amount(dollars, &twenties, &tens, &fives, &ones);
    
    printf("For $%d:\n", dollars);
    printf("$20 bills: %d\n", twenties);
    printf("$10 bills: %d\n", tens);
    printf("$5 bills: %d\n", fives);
    printf("$1 bills: %d\n", ones);
    
    return 0;
}
