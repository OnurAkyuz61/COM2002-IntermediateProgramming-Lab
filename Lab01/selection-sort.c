#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define LENGTH 10

// Function prototypes
void selection_sort(int array[], char s_order);
void swap(int *first, int *second);
void display_array(int array[]);

// Function to swap two elements
void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

// Function to display the array
void display_array(int array[]) {
    for (int i = 0; i < LENGTH; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to perform selection sort
void selection_sort(int array[], char s_order) {
    int i, j, index;
    
    for (i = 0; i < LENGTH - 1; i++) {
        index = i;
        
        for (j = i + 1; j < LENGTH; j++) {
            if (s_order == 'A' || s_order == 'a') {
                // For ascending order
                if (array[j] < array[index]) {
                    index = j;
                }
            } else if (s_order == 'D' || s_order == 'd') {
                // For descending order
                if (array[j] > array[index]) {
                    index = j;
                }
            }
        }
        
        if (index != i) {
            swap(&array[i], &array[index]);
        }
    }
}

int main() {
    int my_array[LENGTH] = {12, 36, 27, 8, 77, 43, 22, 58, 60, 85};
    char sort_order;
    
    printf("The array before sort:\n");
    display_array(my_array);
    
    printf("Choose the sorting order (either ascending or descending) (A/D) : ");
    scanf(" %c", &sort_order);
    
    selection_sort(my_array, sort_order);
    
    printf("The array after selection sort:\n");
    display_array(my_array);
    
    return 0;
}