#include <stdio.h>
#include "veri_modulu.h"

int main() {
    int i, deger;
    
    printf("Static Dizi Erişim Testi\n");
    printf("========================\n\n");
    
    /* Modül içindeki veri_yazdir fonksiyonunu çağırarak diziyi görüntüle */
    printf("1. Dizinin başlangıç değerleri:\n");
    veri_yazdir();
    
    printf("\n2. Dizi elemanlarını modül fonksiyonları aracılığıyla okuma:\n");
    for (i = 0; i < 5; i++) {
        deger = veri_oku(i);
        printf("veri_oku(%d) = %d\n", i, deger);
    }
    
    printf("\n3. Dizi elemanlarını modül fonksiyonları aracılığıyla güncelleme:\n");
    veri_guncelle(2, 300);
    veri_guncelle(4, 500);
    
    printf("\n4. Güncellenmiş dizi:\n");
    veri_yazdir();
    
    /* Aşağıdaki satır derleme hatası verecektir çünkü veri_dizisi static olarak tanımlanmıştır
       ve sadece veri_modulu.c dosyası içinden erişilebilir */
    
    /* Bu satırı açarsanız derleme hatası alırsınız:
       printf("\nDoğrudan erişim denemesi (çalışmayacak):\n");
       printf("veri_dizisi[0] = %d\n", veri_dizisi[0]);
    */
    
    printf("\nNOT: Bu programda veri_dizisi'ne doğrudan erişim denemesi yorum satırı olarak bırakılmıştır.\n");
    printf("Eğer bu yorum satırını kaldırırsanız, derleme sırasında aşağıdaki gibi bir hata alırsınız:\n");
    printf("'veri_dizisi' undeclared (first use in this function)\n");
    
    return 0;
}
