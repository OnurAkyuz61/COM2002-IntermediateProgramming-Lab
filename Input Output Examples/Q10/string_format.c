#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main() {
    char ad[30];
    char soyad[30];
    char tam_ad[60];
    
    // Kullanıcıdan ad ve soyad bilgilerini al
    printf("Adınızı giriniz: ");
    scanf("%s", ad);
    
    printf("Soyadınızı giriniz: ");
    scanf("%s", soyad);
    
    // "Soyad, Ad" formatında string oluştur (sprintf kullanarak)
    sprintf(tam_ad, "%s, %s", soyad, ad);
    printf("\nsprintf ile oluşturulan string: %s\n", tam_ad);
    
    // Aynı işlemi snprintf ile yapalım (daha güvenli)
    char tam_ad2[60];
    snprintf(tam_ad2, sizeof(tam_ad2), "%s, %s", soyad, ad);
    printf("snprintf ile oluşturulan string: %s\n", tam_ad2);
    
    // sprintf ve snprintf arasındaki farkı gösterelim
    printf("\nFark: snprintf belirtilen boyutu aşmayacak şekilde güvenli bir şekilde çalışır.\n");
    
    return 0;
}
