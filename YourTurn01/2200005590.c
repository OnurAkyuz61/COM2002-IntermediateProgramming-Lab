//2200005590, Onur Akyüz

#define _CRT_SECURE_NO_WARNINGS // To suppress warnings about using insecure functions like scanf()

#define NUM_SUITS 4 // Number of suits (hearts, diamonds, clubs, spades)
#define NUM_RANKS 13 // Number of ranks (2-10, Jack, Queen, King, Ace)

#include <stdio.h>    // Include standard input/output library for printf and scanf functions
#include <stdlib.h>   // Include standard library for memory allocation functions

int main() {
    int original[3][5] = {    // Define and initialize the original 2D array with given values
        {4, 4, 82, 34, 56},
        {5, 34, 76, 90, 76},
        {2, 6, 1, 2, 45}
    };
    
    int rows = 3;    // Define number of rows in the original array
    int cols = 5;    // Define number of columns in the original array
    char choice = 'c';    // Variable to store user's choice to continue or quit
    
    while(choice != 'q' && choice != 'Q') {    // Continue loop until user enters 'q' or 'Q'
        printf("\nTranspose of the array\n");    // Print header for transpose display
        
        for(int i = 0; i < cols; i++) {    // Loop through each row of transpose (original columns)
            for(int j = 0; j < rows; j++) {    // Loop through each column of transpose (original rows)
                printf("%-4d", original[j][i]);    // Print each element with left alignment and width of 4
            }
            printf("\n");    // Move to next line after printing each row
        }
        
        int column;    // Variable to store user's column choice
        printf("\nEnter column number: ");    // Prompt user for column number
        scanf("%d", &column);    // Read column number from user
        while(getchar() != '\n');    // Clear input buffer
        
        double sum = 0;    // Variable to store sum for arithmetic mean
        double harmonicSum = 0;    // Variable to store sum for harmonic mean
        
        for(int i = 0; i < rows; i++) {    // Loop through each element in selected column
            sum += original[i][column-1];    // Add each element to sum for arithmetic mean
            harmonicSum += 1.0/original[i][column-1];    // Add reciprocal of each element for harmonic mean
        }
        
        double arithmeticMean = sum / rows;    // Calculate arithmetic mean
        double harmonicMean = rows / harmonicSum;    // Calculate harmonic mean
        
        printf("The arithmetic mean of column is %.3f\n", arithmeticMean);    // Print arithmetic mean with 3 decimal places
        printf("The harmonic mean of column is %.2f\n", harmonicMean);    // Print harmonic mean with 2 decimal places
        
        printf("\nPress 'q' to quit or any other key to continue: ");    // Prompt user for continuation choice
        scanf(" %c", &choice);    // Read user's choice
        while(getchar() != '\n');    // Clear input buffer
    }
    
    return 0;    // End program with success status
}