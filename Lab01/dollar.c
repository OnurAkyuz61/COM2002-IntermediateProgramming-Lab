#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Function prototype
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main() {
    int amount;
    int twenties, tens, fives, ones;
    
    printf("Enter a dollar amount: ");
    scanf("%d", &amount);
    
    pay_amount(amount, &twenties, &tens, &fives, &ones);
    
    printf("$20 bills: %d\n", twenties);
    printf("$10 bills: %d\n", tens);
    printf("$5 bills: %d\n", fives);
    printf("$1 bills: %d\n", ones);
    
    return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
    // Calculate number of $20 bills
    *twenties = dollars / 20;
    dollars = dollars % 20;
    
    // Calculate number of $10 bills
    *tens = dollars / 10;
    dollars = dollars % 10;
    
    // Calculate number of $5 bills
    *fives = dollars / 5;
    dollars = dollars % 5;
    
    // Remaining amount is number of $1 bills
    *ones = dollars;
}