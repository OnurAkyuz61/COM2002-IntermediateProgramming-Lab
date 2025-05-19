#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // sleep fonksiyonu için

int main() {
    FILE *fp;
    int i;
    
    // Dosyayı yazma modunda aç
    fp = fopen("flush_test.txt", "w");
    if (fp == NULL) {
        printf("Dosya oluşturulamadı!\n");
        return 1;
    }
    
    printf("Dosyaya veri yazılıyor ve flush ediliyor...\n");
    
    // 5 kez veri yaz ve her seferinde flush et
    for (i = 1; i <= 5; i++) {
        fprintf(fp, "Veri %d: Bu veri yazıldı ve hemen flush edilecek.\n", i);
        printf("Veri %d yazıldı", i);
        
        // Buffer'ı manuel olarak flush et
        if (fflush(fp) == 0) {
            printf(" ve flush edildi.\n");
        } else {
            printf(" ama flush edilemedi!\n");
        }
        
        // Flush işlemini göstermek için kısa bir bekleme
        sleep(1);
    }
    
    // Dosyayı kapat
    fclose(fp);
    
    printf("\nİşlem tamamlandı. flush_test.txt dosyasını kontrol edebilirsiniz.\n");
    
    return 0;
}
