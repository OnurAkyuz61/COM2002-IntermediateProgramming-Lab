#include <stdio.h>

int main() {
    int sayi;
    int sola_kaydir, saga_kaydir;
    
    printf("Bit Kaydırma İşlemi\n");
    printf("===================\n\n");
    
    /* Kullanıcıdan sayı al */
    printf("Bir tam sayı giriniz: ");
    scanf("%d", &sayi);
    
    /* 1 bit sola kaydır (2 ile çarpma işlemine eşdeğer) */
    sola_kaydir = sayi << 1;
    
    /* 2 bit sağa kaydır (4'e bölme işlemine eşdeğer) */
    saga_kaydir = sayi >> 2;
    
    /* Sonuçları ekrana yazdır */
    printf("\nGirilen sayı: %d\n", sayi);
    printf("Sayının ikili (binary) gösterimi: ");
    
    /* Sayının binary gösterimini yazdır (32-bit için) */
    for (int i = 31; i >= 0; i--) {
        printf("%d", (sayi >> i) & 1);
        if (i % 8 == 0) printf(" "); /* 8 bit aralıklarla boşluk bırak */
    }
    
    printf("\n\n1 bit sola kaydırılmış hali: %d\n", sola_kaydir);
    printf("Sola kaydırılmış sayının ikili gösterimi: ");
    
    for (int i = 31; i >= 0; i--) {
        printf("%d", (sola_kaydir >> i) & 1);
        if (i % 8 == 0) printf(" ");
    }
    
    printf("\n\n2 bit sağa kaydırılmış hali: %d\n", saga_kaydir);
    printf("Sağa kaydırılmış sayının ikili gösterimi: ");
    
    for (int i = 31; i >= 0; i--) {
        printf("%d", (saga_kaydir >> i) & 1);
        if (i % 8 == 0) printf(" ");
    }
    
    printf("\n\nNot:\n");
    printf("- 1 bit sola kaydırma, sayıyı 2 ile çarpmaya eşdeğerdir.\n");
    printf("- 2 bit sağa kaydırma, sayıyı 4'e bölmeye eşdeğerdir (tam sayı bölmesi).\n");
    
    return 0;
}
