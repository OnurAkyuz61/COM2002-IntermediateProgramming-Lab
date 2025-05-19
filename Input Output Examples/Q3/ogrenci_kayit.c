#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    FILE *fp;
    char ad[50];
    int not;
    int i;
    
    // Dosyayı yazma modunda aç
    fp = fopen("ogrenciler.txt", "w");
    
    // Dosya açılma kontrolü
    if (fp == NULL) {
        printf("Dosya oluşturulamadı!\n");
        return 1;
    }
    
    printf("5 öğrencinin adını ve notunu giriniz:\n");
    
    // 5 öğrenci için veri al ve dosyaya yaz
    for (i = 0; i < 5; i++) {
        printf("%d. öğrenci adı: ", i+1);
        scanf("%s", ad);
        
        printf("%d. öğrenci notu: ", i+1);
        scanf("%d", &not);
        
        // Öğrenci bilgilerini dosyaya yaz
        fprintf(fp, "%s %d\n", ad, not);
    }
    
    // Dosyayı kapat
    fclose(fp);
    
    printf("Öğrenci bilgileri başarıyla kaydedildi.\n");
    
    return 0;
}
