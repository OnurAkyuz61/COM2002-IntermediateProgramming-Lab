/* veri_modulu.h - Veri modülü header dosyası */
#ifndef VERI_MODULU_H
#define VERI_MODULU_H

/* Modül içindeki fonksiyonların prototipleri */
void veri_yazdir();
void veri_guncelle(int indeks, int yeni_deger);

/* Modül dışından erişilebilen fonksiyonlar */
int veri_oku(int indeks);

#endif /* VERI_MODULU_H */
