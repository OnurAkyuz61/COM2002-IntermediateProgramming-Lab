#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// Ürün yapısı
struct urun {
    int id;
    char ad[20];
    float fiyat;
};

int main() {
    struct urun urunler[3];
    FILE *fp;
    int i;
    
    // Kullanıcıdan 3 ürün bilgisi al
    printf("3 ürün bilgisi giriniz:\n");
    for (i = 0; i < 3; i++) {
        printf("\n%d. ürün ID: ", i+1);
        scanf("%d", &urunler[i].id);
        
        printf("%d. ürün adı: ", i+1);
        scanf("%s", urunler[i].ad);
        
        printf("%d. ürün fiyatı: ", i+1);
        scanf("%f", &urunler[i].fiyat);
    }
    
    // Binary dosyaya yazma
    fp = fopen("urunler.dat", "wb");
    if (fp == NULL) {
        printf("Dosya oluşturulamadı!\n");
        return 1;
    }
    
    // Tüm ürün dizisini tek seferde yaz
    fwrite(urunler, sizeof(struct urun), 3, fp);
    
    // Dosyayı kapat
    fclose(fp);
    printf("\nÜrünler binary dosyaya kaydedildi.\n");
    
    // Dosyadan okuma
    fp = fopen("urunler.dat", "rb");
    if (fp == NULL) {
        printf("Dosya açılamadı!\n");
        return 1;
    }
    
    // Ürünleri oku
    struct urun okunan_urunler[3];
    fread(okunan_urunler, sizeof(struct urun), 3, fp);
    
    // Dosyayı kapat
    fclose(fp);
    
    // Okunan ürünleri ekrana yazdır
    printf("\nDosyadan okunan ürünler:\n");
    printf("------------------------\n");
    for (i = 0; i < 3; i++) {
        printf("ID: %d, Ürün: %s, Fiyat: %.2f TL\n", 
               okunan_urunler[i].id, 
               okunan_urunler[i].ad, 
               okunan_urunler[i].fiyat);
    }
    
    return 0;
}
