#include <stdio.h>
#include "paylas.h"

/* dosya1.c'deki fonksiyonu kullanabilmek için bildirim */
extern void deger_degistir(int yeni_deger);
extern void deger_goster();

void dosya2_islemleri() {
    /* Paylaşılan değişkene erişim */
    printf("dosya2.c: Paylaşılan değer = %d\n", paylasilan_deger);
    
    /* Paylaşılan değişkeni değiştirme */
    paylasilan_deger += 50;
    printf("dosya2.c: Değer %d olarak güncellendi\n", paylasilan_deger);
    
    /* dosya1.c'deki fonksiyonu çağırma */
    deger_degistir(200);
}

int main() {
    printf("Program başladı\n\n");
    
    /* İlk değeri göster */
    deger_goster();
    
    printf("\n");
    
    /* dosya2.c'deki işlemleri yap */
    dosya2_islemleri();
    
    printf("\n");
    
    /* Son değeri göster */
    deger_goster();
    
    printf("\nProgram sonlandı\n");
    return 0;
}
