#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main() {
    int gun, ay, yil;
    struct tm tarih = {0};
    char tarih_str[100];
    
    printf("Tarih Formatlama (Uluslararasılaştırma)\n");
    printf("=======================================\n\n");
    
    /* Kullanıcıdan tarihi al */
    printf("Tarih giriniz (gün/ay/yıl): ");
    if (scanf("%d/%d/%d", &gun, &ay, &yil) != 3) {
        printf("Hata: Geçersiz tarih formatı! Örnek: 19/5/2025\n");
        return 1;
    }
    
    /* Girilen tarihi tm yapısına dönüştür */
    tarih.tm_mday = gun;
    tarih.tm_mon = ay - 1;  /* ay 0-11 arası değer alır */
    tarih.tm_year = yil - 1900;  /* yıl 1900'den itibaren */
    
    /* Tarihin geçerliliğini kontrol et */
    time_t t = mktime(&tarih);
    if (t == -1) {
        printf("Hata: Geçersiz tarih!\n");
        return 2;
    }
    
    printf("\nFarklı locale ayarlarına göre tarih formatları:\n");
    printf("==============================================\n");
    
    /* 1. C locale (varsayılan) */
    setlocale(LC_TIME, "C");
    strftime(tarih_str, sizeof(tarih_str), "%x", &tarih);
    printf("1. C locale (varsayılan):\n");
    printf("   Locale: %s\n", setlocale(LC_TIME, NULL));
    printf("   Kısa tarih formatı (%%x): %s\n", tarih_str);
    strftime(tarih_str, sizeof(tarih_str), "%A, %B %d, %Y", &tarih);
    printf("   Uzun tarih formatı: %s\n\n", tarih_str);
    
    /* 2. Sistem locale */
    setlocale(LC_TIME, "");
    strftime(tarih_str, sizeof(tarih_str), "%x", &tarih);
    printf("2. Sistem locale:\n");
    printf("   Locale: %s\n", setlocale(LC_TIME, NULL));
    printf("   Kısa tarih formatı (%%x): %s\n", tarih_str);
    strftime(tarih_str, sizeof(tarih_str), "%A, %B %d, %Y", &tarih);
    printf("   Uzun tarih formatı: %s\n\n", tarih_str);
    
    /* 3. Türkçe locale */
    if (setlocale(LC_TIME, "tr_TR.UTF-8") != NULL) {
        strftime(tarih_str, sizeof(tarih_str), "%x", &tarih);
        printf("3. Türkçe locale (tr_TR.UTF-8):\n");
        printf("   Locale: %s\n", setlocale(LC_TIME, NULL));
        printf("   Kısa tarih formatı (%%x): %s\n", tarih_str);
        strftime(tarih_str, sizeof(tarih_str), "%A, %d %B %Y", &tarih);
        printf("   Uzun tarih formatı: %s\n\n", tarih_str);
    } else {
        printf("3. Türkçe locale (tr_TR.UTF-8) ayarlanamadı.\n\n");
    }
    
    /* 4. İngilizce (ABD) locale */
    if (setlocale(LC_TIME, "en_US.UTF-8") != NULL) {
        strftime(tarih_str, sizeof(tarih_str), "%x", &tarih);
        printf("4. İngilizce (ABD) locale (en_US.UTF-8):\n");
        printf("   Locale: %s\n", setlocale(LC_TIME, NULL));
        printf("   Kısa tarih formatı (%%x): %s\n", tarih_str);
        strftime(tarih_str, sizeof(tarih_str), "%A, %B %d, %Y", &tarih);
        printf("   Uzun tarih formatı: %s\n\n", tarih_str);
    } else {
        printf("4. İngilizce (ABD) locale (en_US.UTF-8) ayarlanamadı.\n\n");
    }
    
    /* 5. Almanca locale */
    if (setlocale(LC_TIME, "de_DE.UTF-8") != NULL) {
        strftime(tarih_str, sizeof(tarih_str), "%x", &tarih);
        printf("5. Almanca locale (de_DE.UTF-8):\n");
        printf("   Locale: %s\n", setlocale(LC_TIME, NULL));
        printf("   Kısa tarih formatı (%%x): %s\n", tarih_str);
        strftime(tarih_str, sizeof(tarih_str), "%A, %d. %B %Y", &tarih);
        printf("   Uzun tarih formatı: %s\n\n", tarih_str);
    } else {
        printf("5. Almanca locale (de_DE.UTF-8) ayarlanamadı.\n\n");
    }
    
    /* 6. Fransızca locale */
    if (setlocale(LC_TIME, "fr_FR.UTF-8") != NULL) {
        strftime(tarih_str, sizeof(tarih_str), "%x", &tarih);
        printf("6. Fransızca locale (fr_FR.UTF-8):\n");
        printf("   Locale: %s\n", setlocale(LC_TIME, NULL));
        printf("   Kısa tarih formatı (%%x): %s\n", tarih_str);
        strftime(tarih_str, sizeof(tarih_str), "%A %d %B %Y", &tarih);
        printf("   Uzun tarih formatı: %s\n\n", tarih_str);
    } else {
        printf("6. Fransızca locale (fr_FR.UTF-8) ayarlanamadı.\n\n");
    }
    
    printf("Not: Bazı locale'ler sistemde yüklü olmayabilir.\n");
    printf("Bu durumda locale değişikliği başarısız olabilir.\n");
    
    return 0;
}
