#include <stdio.h>

int main() {
    unsigned int veri, anahtar, sifreli, cozulmus;
    
    printf("XOR Şifreleme ve Çözümleme\n");
    printf("==========================\n\n");
    
    /* Kullanıcıdan veriyi al */
    printf("Şifrelenecek veriyi giriniz (pozitif tam sayı): ");
    scanf("%u", &veri);
    
    /* Kullanıcıdan anahtarı al */
    printf("Şifreleme anahtarını giriniz (pozitif tam sayı): ");
    scanf("%u", &anahtar);
    
    /* XOR ile şifreleme */
    sifreli = veri ^ anahtar;
    
    /* XOR ile çözümleme (aynı anahtarla tekrar XOR işlemi) */
    cozulmus = sifreli ^ anahtar;
    
    /* Sonuçları ekrana yazdır */
    printf("\nOrijinal veri: %u\n", veri);
    printf("Anahtar: %u\n", anahtar);
    printf("Şifrelenmiş veri: %u\n", sifreli);
    printf("Çözümlenmiş veri: %u\n", cozulmus);
    
    /* Binary gösterimlerini yazdır */
    printf("\nBinary gösterimler:\n");
    
    printf("Orijinal veri (binary): ");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (veri >> i) & 1);
        if (i % 8 == 0) printf(" ");
    }
    
    printf("\nAnahtar (binary): ");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (anahtar >> i) & 1);
        if (i % 8 == 0) printf(" ");
    }
    
    printf("\nŞifrelenmiş veri (binary): ");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (sifreli >> i) & 1);
        if (i % 8 == 0) printf(" ");
    }
    
    printf("\nÇözümlenmiş veri (binary): ");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (cozulmus >> i) & 1);
        if (i % 8 == 0) printf(" ");
    }
    
    printf("\n\nNot: XOR şifrelemenin özelliği, aynı anahtarla iki kez XOR işlemi yapıldığında\n");
    printf("orijinal verinin elde edilmesidir. Yani (A XOR B) XOR B = A\n");
    
    return 0;
}
