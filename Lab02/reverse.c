#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 100 // Maksimum mesaj uzunluğu

int main() {
    char message[MAX_SIZE];  // Mesajı saklamak için dizi
    char ch;                 // Her karakteri okumak için değişken
    int i = 0;              // Dizideki pozisyonu takip etmek için sayaç
    
    // Kullanıcıdan mesaj isteme
    printf("Enter a message: ");
    
    // Karakterleri tek tek okuma
    while ((ch = getchar()) != '\n' && i < MAX_SIZE - 1) {
        message[i] = ch;    // Karakteri diziye kaydet
        i++;                // Pozisyonu güncelle
    }
    message[i] = '\0';      // Dizinin sonuna null karakter ekle
    
    // Mesajı tersten yazdırma
    printf("Reversal is: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", message[j]);
    }
    printf("\n");
    
    return 0;
}
