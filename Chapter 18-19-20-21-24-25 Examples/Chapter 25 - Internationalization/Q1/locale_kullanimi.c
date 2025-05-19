#include <stdio.h>
#include <locale.h>

int main() {
    char *locale;
    double sayi = 1234.56;
    
    printf("Locale Kullanımı (Uluslararasılaştırma)\n");
    printf("=======================================\n\n");
    
    /* Varsayılan locale bilgisini göster */
    printf("1. Varsayılan locale ayarları:\n");
    locale = setlocale(LC_ALL, NULL);
    printf("   Mevcut locale: %s\n", locale);
    printf("   Sayı gösterimi: %.2f\n\n", sayi);
    
    /* LC_NUMERIC locale'ini sistem ayarına göre değiştir */
    printf("2. LC_NUMERIC locale'ini sistem ayarına göre değiştirme:\n");
    locale = setlocale(LC_NUMERIC, "");
    printf("   Yeni locale (LC_NUMERIC): %s\n", locale);
    printf("   Sayı gösterimi: %.2f\n\n", sayi);
    
    /* Tüm locale ayarlarını sistem ayarına göre değiştir */
    printf("3. Tüm locale ayarlarını sistem ayarına göre değiştirme:\n");
    locale = setlocale(LC_ALL, "");
    printf("   Yeni locale (LC_ALL): %s\n", locale);
    printf("   Sayı gösterimi: %.2f\n\n", sayi);
    
    /* Farklı locale örnekleri */
    printf("4. Farklı locale örnekleri:\n");
    
    /* Türkçe locale */
    printf("   a) Türkçe locale (tr_TR.UTF-8):\n");
    locale = setlocale(LC_NUMERIC, "tr_TR.UTF-8");
    if (locale != NULL) {
        printf("      Locale ayarlandı: %s\n", locale);
        printf("      Sayı gösterimi: %.2f\n\n", sayi);
    } else {
        printf("      Türkçe locale ayarlanamadı.\n\n");
    }
    
    /* İngilizce (ABD) locale */
    printf("   b) İngilizce (ABD) locale (en_US.UTF-8):\n");
    locale = setlocale(LC_NUMERIC, "en_US.UTF-8");
    if (locale != NULL) {
        printf("      Locale ayarlandı: %s\n", locale);
        printf("      Sayı gösterimi: %.2f\n\n", sayi);
    } else {
        printf("      İngilizce locale ayarlanamadı.\n\n");
    }
    
    /* Almanca locale */
    printf("   c) Almanca locale (de_DE.UTF-8):\n");
    locale = setlocale(LC_NUMERIC, "de_DE.UTF-8");
    if (locale != NULL) {
        printf("      Locale ayarlandı: %s\n", locale);
        printf("      Sayı gösterimi: %.2f\n\n", sayi);
    } else {
        printf("      Almanca locale ayarlanamadı.\n\n");
    }
    
    /* C locale (varsayılan) */
    printf("   d) C locale (varsayılan):\n");
    locale = setlocale(LC_NUMERIC, "C");
    printf("      Locale ayarlandı: %s\n", locale);
    printf("      Sayı gösterimi: %.2f\n\n", sayi);
    
    printf("Not: Bazı locale'ler sistemde yüklü olmayabilir.\n");
    printf("Bu durumda locale değişikliği başarısız olabilir.\n");
    
    return 0;
}
