// 2200005590, Onur Akyuz

#define _CRT_SECURE_NO_WARNINGS // Disable security warnings

#include <stdio.h> // Standard input-output library
#include <stdlib.h> // Standard library

// Define the Stack structure
typedef struct {
    int top;        // Index of the top element in the stack
    int array[32];  // Array to store binary digits (for 32-bit numbers)
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;  // Set top to -1 to indicate empty stack
}

// Function to push an element onto the stack
void push(Stack *s, int value) {
    s->array[++(s->top)] = value;  // Increment top and add new value
}

// Function to pop an element from the stack
int pop(Stack *s) {
    return s->array[(s->top)--];  // Return top value and decrement top
}

// Main function
int main() {
    Stack s;
    int decimal;
    
    // Initialize the stack
    initStack(&s);
    
    // Get decimal number from user
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    
    // If number is 0, print 0 directly
    if (decimal == 0) {
        printf("Binary equivalent is: 0\n");
        return 0;
    }
    
    // Convert decimal to binary
    while (decimal > 0) {
        push(&s, decimal % 2);  // Push remainder of division by 2
        decimal = decimal / 2;   // Divide number by 2
    }
    
    // Print the result
    printf("Binary equivalent is: ");
    while (s.top >= 0) {
        printf("%d", pop(&s));  // Pop and print each digit
    }
    printf("\n");
    
    return 0; // Return success
}