#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    FILE *fp;
    
    // Önce gecici.txt dosyasını oluşturalım
    fp = fopen("gecici.txt", "w");
    if (fp == NULL) {
        printf("Dosya oluşturulamadı!\n");
        return 1;
    }
    
    // Dosyaya örnek veri yazalım
    fprintf(fp, "Bu bir geçici dosyadır.");
    fclose(fp);
    printf("gecici.txt dosyası oluşturuldu.\n");
    
    // Dosyayı yeniden adlandır
    if (rename("gecici.txt", "yedek.txt") == 0) {
        printf("Dosya başarıyla 'yedek.txt' olarak yeniden adlandırıldı.\n");
    } else {
        printf("Dosya yeniden adlandırılamadı!\n");
        return 1;
    }
    
    // Yeniden adlandırılan dosyayı sil
    if (remove("yedek.txt") == 0) {
        printf("'yedek.txt' dosyası başarıyla silindi.\n");
    } else {
        printf("Dosya silinemedi!\n");
        return 1;
    }
    
    printf("\nİşlem tamamlandı.\n");
    
    return 0;
}
