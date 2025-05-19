#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    FILE *fp;
    int num, sum = 0;
    
    // Dosyayı okuma modunda aç
    fp = fopen("sayilar.txt", "r");
    
    // Dosya açılma kontrolü
    if (fp == NULL) {
        printf("Dosya açılamadı!\n");
        return 1;
    }
    
    // Dosyadaki tüm sayıları oku ve topla
    while (fscanf(fp, "%d", &num) == 1) {
        sum += num;
    }
    
    // Dosyayı kapat
    fclose(fp);
    
    // Toplamı ekrana yazdır
    printf("Dosyadaki sayıların toplamı: %d\n", sum);
    
    return 0;
}