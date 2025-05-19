#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <string.h>

int main() {
    double sayi, sonuc;
    
    printf("Hata Yakalama (errno)\n");
    printf("=====================\n\n");
    
    /* Kullanıcıdan sayı al */
    printf("Karekökü hesaplanacak sayıyı giriniz: ");
    scanf("%lf", &sayi);
    
    /* Karekök hesapla */
    errno = 0;  /* errno'yu sıfırla */
    sonuc = sqrt(sayi);
    
    /* Hata kontrolü */
    if (errno != 0) {
        printf("\nHATA: ");
        perror("Karekök hesaplanırken bir hata oluştu");
        printf("Hata kodu (errno): %d\n", errno);
        printf("Hata açıklaması: %s\n", strerror(errno));
        printf("\nNegatif sayıların karekökü gerçel sayılar kümesinde tanımlı değildir.\n");
    } else {
        printf("\n%.2f sayısının karekökü: %.4f\n", sayi, sonuc);
    }
    
    /* Farklı hata durumlarını göster */
    printf("\nFarklı Hata Durumları:\n");
    printf("----------------------\n");
    
    /* 1. Negatif sayı için logaritma hesaplama */
    printf("\n1. Negatif sayının logaritması:\n");
    errno = 0;
    double log_sonuc = log(-5.0);
    
    if (errno != 0) {
        printf("   HATA: ");
        perror("   Logaritma hesaplanırken bir hata oluştu");
        printf("   Hata kodu (errno): %d\n", errno);
        printf("   Hata açıklaması: %s\n", strerror(errno));
    } else {
        printf("   log(-5.0) = %.4f\n", log_sonuc);
    }
    
    /* 2. Sıfıra bölme hatası */
    printf("\n2. Sıfıra bölme hatası (float):\n");
    errno = 0;
    double bolme_sonuc = 5.0 / 0.0;
    
    if (errno != 0) {
        printf("   HATA: ");
        perror("   Bölme işlemi sırasında bir hata oluştu");
        printf("   Hata kodu (errno): %d\n", errno);
        printf("   Hata açıklaması: %s\n", strerror(errno));
    } else {
        printf("   5.0 / 0.0 = %f (IEEE 754 standardına göre Infinity)\n", bolme_sonuc);
    }
    
    return 0;
}
