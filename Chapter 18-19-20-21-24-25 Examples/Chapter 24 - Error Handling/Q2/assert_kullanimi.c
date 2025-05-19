#include <stdio.h>
#include <assert.h>

/* Güvenli dizi erişimi için fonksiyon */
int dizi_eleman_al(int dizi[], int boyut, int indeks) {
    /* assert() ile dizinin sınırlarını kontrol et */
    assert(indeks >= 0 && "İndeks negatif olamaz!");
    assert(indeks < boyut && "Dizi sınırları dışına çıkıldı!");
    
    return dizi[indeks];
}

/* Diziye güvenli eleman ekleme fonksiyonu */
void dizi_eleman_ekle(int dizi[], int boyut, int indeks, int deger) {
    /* assert() ile dizinin sınırlarını kontrol et */
    assert(indeks >= 0 && "İndeks negatif olamaz!");
    assert(indeks < boyut && "Dizi sınırları dışına çıkıldı!");
    
    dizi[indeks] = deger;
}

int main() {
    int dizi[5] = {10, 20, 30, 40, 50};
    int boyut = 5;
    int indeks, deger;
    
    printf("Assert Kullanımı - Dizi Sınır Kontrolü\n");
    printf("======================================\n\n");
    
    printf("Dizi elemanları:\n");
    for (int i = 0; i < boyut; i++) {
        printf("dizi[%d] = %d\n", i, dizi[i]);
    }
    
    /* Geçerli bir indeks için dizi erişimi */
    printf("\nGeçerli bir indeks için dizi erişimi:\n");
    indeks = 2;
    printf("dizi[%d] = %d\n", indeks, dizi_eleman_al(dizi, boyut, indeks));
    
    /* Geçerli bir indekse eleman ekleme */
    printf("\nGeçerli bir indekse eleman ekleme:\n");
    indeks = 3;
    deger = 999;
    dizi_eleman_ekle(dizi, boyut, indeks, deger);
    printf("dizi[%d] = %d olarak güncellendi\n", indeks, dizi[indeks]);
    
    printf("\nGüncellenmiş dizi elemanları:\n");
    for (int i = 0; i < boyut; i++) {
        printf("dizi[%d] = %d\n", i, dizi[i]);
    }
    
    /* 
     * Aşağıdaki kodlar, dizi sınırları dışına çıkıldığında assert() ile hata verecektir.
     * Program çalışırken bu noktada duracak ve hata mesajı gösterecektir.
     * 
     * NOT: Bu kodların çalıştırılması programın sonlanmasına neden olacaktır.
     * Bu nedenle, bu kodlar yorum satırı olarak bırakılmıştır.
     * Test etmek için yorum satırlarını kaldırın.
     */
    
    printf("\nDizi sınırları dışına çıkma denemeleri:\n");
    printf("(Aşağıdaki kodlar yorum satırı olarak bırakılmıştır)\n");
    
    /* Negatif indeks için dizi erişimi */
    // printf("\nNegatif indeks için dizi erişimi:\n");
    // indeks = -1;
    // printf("dizi[%d] = %d\n", indeks, dizi_eleman_al(dizi, boyut, indeks));
    
    /* Dizi boyutundan büyük indeks için dizi erişimi */
    // printf("\nDizi boyutundan büyük indeks için dizi erişimi:\n");
    // indeks = 10;
    // printf("dizi[%d] = %d\n", indeks, dizi_eleman_al(dizi, boyut, indeks));
    
    printf("\nProgram başarıyla tamamlandı.\n");
    
    return 0;
}
