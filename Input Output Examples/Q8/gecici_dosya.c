#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    FILE *fp;
    char buffer[100];
    
    // Geçici dosya oluştur
    fp = tmpfile();
    if (fp == NULL) {
        printf("Geçici dosya oluşturulamadı!\n");
        return 1;
    }
    
    printf("Geçici dosya oluşturuldu.\n");
    
    // Dosyaya veri yaz
    fprintf(fp, "Geçici Veri");
    printf("Dosyaya \"Geçici Veri\" yazıldı.\n");
    
    // Dosya göstericisini başa al
    rewind(fp);
    printf("Dosya göstericisi başa alındı.\n");
    
    // Dosyadan veriyi oku
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("\nDosyadan okunan veri: %s\n", buffer);
    } else {
        printf("\nDosyadan veri okunamadı!\n");
    }
    
    // Dosyayı kapat (geçici dosya otomatik olarak silinecek)
    fclose(fp);
    printf("\nGeçici dosya kapatıldı ve otomatik olarak silindi.\n");
    
    return 0;
}
