#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    char line[100];
    int yil, ay, gun;
    
    // Kullanıcıdan doğum tarihi al
    printf("Doğum tarihinizi 'YYYY/AA/GG' formatında giriniz: ");
    fgets(line, sizeof(line), stdin);
    
    // Girilen veriyi ayrıştır
    if (sscanf(line, "%d/%d/%d", &yil, &ay, &gun) == 3) {
        // Başarıyla ayrıştırıldı
        printf("\nGirilen tarih ayrıştırıldı:\n");
        printf("Yıl: %d\n", yil);
        printf("Ay: %d\n", ay);
        printf("Gün: %d\n", gun);
        
        // Basit bir doğrulama kontrolü
        if (ay < 1 || ay > 12) {
            printf("\nUyarı: Geçersiz ay değeri!\n");
        }
        
        if (gun < 1 || gun > 31) {
            printf("\nUyarı: Geçersiz gün değeri!\n");
        }
    } else {
        printf("\nHata: Geçersiz tarih formatı. Lütfen 'YYYY/AA/GG' formatında giriniz.\n");
    }
    
    return 0;
}
