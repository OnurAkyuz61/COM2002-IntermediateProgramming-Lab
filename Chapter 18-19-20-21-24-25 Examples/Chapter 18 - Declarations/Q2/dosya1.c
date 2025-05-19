#include <stdio.h>
#include "paylas.h"

/* Paylaşılan değişkenin tanımı (definition) */
int paylasilan_deger = 100;

void deger_goster() {
    printf("dosya1.c: Paylaşılan değer = %d\n", paylasilan_deger);
}

/* Bu fonksiyon dosya2.c'den çağrılacak */
void deger_degistir(int yeni_deger) {
    paylasilan_deger = yeni_deger;
    printf("dosya1.c: Değer %d olarak güncellendi\n", paylasilan_deger);
}
