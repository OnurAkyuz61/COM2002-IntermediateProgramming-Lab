#include <stdio.h>
#include <stdlib.h>

int main() {
    int sayi_adedi;
    double *sayilar;
    double toplam = 0.0, ortalama;
    
    printf("Dinamik Bellek Yönetimi (stdlib.h)\n");
    printf("==================================\n\n");
    
    /* Kullanıcıdan kaç sayı gireceğini al */
    printf("Kaç adet sayı gireceksiniz? ");
    scanf("%d", &sayi_adedi);
    
    /* Geçerli bir sayı adedi kontrolü */
    if (sayi_adedi <= 0) {
        printf("Hata: Geçerli bir sayı adedi giriniz (1 veya daha büyük).\n");
        return 1;
    }
    
    /* Girilen sayı adedi kadar bellek ayır */
    sayilar = (double *)malloc(sayi_adedi * sizeof(double));
    
    /* Bellek ayırma başarısız olursa */
    if (sayilar == NULL) {
        printf("Hata: Bellek ayırma başarısız oldu!\n");
        return 2;
    }
    
    /* Kullanıcıdan sayıları al */
    printf("\n%d adet sayı giriniz:\n", sayi_adedi);
    for (int i = 0; i < sayi_adedi; i++) {
        printf("Sayı %d: ", i + 1);
        scanf("%lf", &sayilar[i]);
        toplam += sayilar[i];  /* Her sayıyı toplama ekle */
    }
    
    /* Ortalamayı hesapla */
    ortalama = toplam / sayi_adedi;
    
    /* Sonuçları ekrana yazdır */
    printf("\nGirilen sayılar:\n");
    for (int i = 0; i < sayi_adedi; i++) {
        printf("Sayı %d: %.2f\n", i + 1, sayilar[i]);
    }
    
    printf("\nToplam: %.2f\n", toplam);
    printf("Ortalama: %.2f\n", ortalama);
    
    /* Ayrılan belleği serbest bırak */
    free(sayilar);
    printf("\nAyrılan bellek serbest bırakıldı.\n");
    
    return 0;
}
