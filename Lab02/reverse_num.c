#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 10  // Okunacak sayı miktarı

int main() {
    int numbers[SIZE];    // Sayıları saklamak için dizi
    int *ptr = numbers;   // Diziyi işaret eden pointer
    
    // Kullanıcıdan 10 sayı okuma
    printf("Enter 10 numbers: ");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", ptr + i);  // Pointer aritmetiği kullanarak sayıları okuma
    }
    
    // Sayıları tersten yazdırma
    printf("In reverse order: ");
    for (ptr = numbers + SIZE - 1; ptr >= numbers; ptr--) {
        printf("%d ", *ptr);  // Pointer aritmetiği kullanarak sayıları yazdırma
    }
    printf("\n");
    
    return 0;
}
