#include <stdio.h>

// Static değişken kullanarak sayaç fonksiyonu
void sayacFonksiyonu() {
    // static anahtar kelimesi ile tanımlanan değişken
    // fonksiyon çağrıları arasında değerini korur
    static int sayac = 0;
    
    // Her çağrıda sayacı 1 arttır
    sayac++;
    
    // Güncel değeri ekrana yazdır
    printf("Fonksiyon %d kez çağrıldı.\n", sayac);
}

int main() {
    printf("İlk çağrı:\n");
    sayacFonksiyonu();
    
    printf("\nİkinci çağrı:\n");
    sayacFonksiyonu();
    
    printf("\nÜçüncü çağrı:\n");
    sayacFonksiyonu();
    
    printf("\nDördüncü çağrı:\n");
    sayacFonksiyonu();
    
    printf("\nBeşinci çağrı:\n");
    sayacFonksiyonu();
    
    return 0;
}
