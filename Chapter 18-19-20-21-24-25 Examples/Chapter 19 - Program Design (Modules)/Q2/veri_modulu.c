#include <stdio.h>
#include "veri_modulu.h"

/* Modül içinde static olarak tanımlanan dizi
   Bu diziye sadece bu dosya içinden erişilebilir */
static int veri_dizisi[5] = {10, 20, 30, 40, 50};

/* Diziyi ekrana yazdıran fonksiyon */
void veri_yazdir() {
    int i;
    printf("Veri dizisinin içeriği:\n");
    for (i = 0; i < 5; i++) {
        printf("veri_dizisi[%d] = %d\n", i, veri_dizisi[i]);
    }
}

/* Dizinin belirli bir elemanını güncelleyen fonksiyon */
void veri_guncelle(int indeks, int yeni_deger) {
    if (indeks >= 0 && indeks < 5) {
        veri_dizisi[indeks] = yeni_deger;
        printf("veri_dizisi[%d] = %d olarak güncellendi\n", indeks, yeni_deger);
    } else {
        printf("Hata: Geçersiz indeks!\n");
    }
}

/* Dizinin belirli bir elemanını döndüren fonksiyon 
   Bu fonksiyon, static diziye dolaylı erişim sağlar */
int veri_oku(int indeks) {
    if (indeks >= 0 && indeks < 5) {
        return veri_dizisi[indeks];
    } else {
        printf("Hata: Geçersiz indeks!\n");
        return -1;
    }
}
