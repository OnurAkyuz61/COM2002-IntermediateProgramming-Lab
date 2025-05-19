#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char buffer[21]; // 20 karakter + null terminator
    long pozisyon;
    
    // Dosyayı okuma ve yazma modunda aç (r+)
    fp = fopen("metin.txt", "w+");
    if (fp == NULL) {
        printf("Dosya oluşturulamadı!\n");
        return 1;
    }
    
    // Örnek metin yaz
    fprintf(fp, "Bu bir örnek metindir. Bu metin dosya konum işlemleri için kullanılacaktır.");
    
    // Dosya göstericisini başa al
    rewind(fp);
    
    // İlk 20 karakteri oku
    fread(buffer, sizeof(char), 20, fp);
    buffer[20] = '\0'; // Null terminator ekle
    printf("İlk 20 karakter: %s\n", buffer);
    
    // Mevcut konumu kaydet
    pozisyon = ftell(fp);
    printf("Kaydedilen konum: %ld\n", pozisyon);
    
    // Dosyanın sonuna git
    fseek(fp, 0, SEEK_END);
    
    // Sona "SON" yaz
    fprintf(fp, "SON");
    printf("Dosyanın sonuna 'SON' yazıldı.\n");
    
    // Kaydedilen konuma geri dön
    fseek(fp, pozisyon, SEEK_SET);
    
    // "BAŞ" yaz
    fprintf(fp, "BAŞ");
    printf("Kaydedilen konuma 'BAŞ' yazıldı.\n");
    
    // Dosyayı kapat
    fclose(fp);
    
    // Dosyayı tekrar aç ve içeriğini oku
    fp = fopen("metin.txt", "r");
    if (fp == NULL) {
        printf("Dosya açılamadı!\n");
        return 1;
    }
    
    // Dosya içeriğini oku ve ekrana yazdır
    printf("\nDosyanın son hali:\n");
    printf("----------------\n");
    
    char c;
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }
    
    // Dosyayı kapat
    fclose(fp);
    
    return 0;
}
