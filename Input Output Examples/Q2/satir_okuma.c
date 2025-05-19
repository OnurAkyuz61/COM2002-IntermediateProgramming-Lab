#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    FILE *fp;
    char buffer[100]; // Satır için buffer tanımlama
    
    // Dosyayı okuma modunda aç
    fp = fopen("metin.txt", "r");
    
    // Dosya açılma kontrolü
    if (fp == NULL) {
        printf("Dosya açılamadı!\n");
        return 1;
    }
    
    // Dosyayı satır satır oku ve ekrana yazdır
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer); // Okunan satırı ekrana yazdır
    }
    
    // Dosyayı kapat
    fclose(fp);
    
    return 0;
}
