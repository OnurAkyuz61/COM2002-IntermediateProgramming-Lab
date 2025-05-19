#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[50], birlesik[150];
    
    printf("String İşlemleri (string.h)\n");
    printf("===========================\n\n");
    
    /* Kullanıcıdan iki string al */
    printf("İlk string'i giriniz: ");
    fgets(str1, sizeof(str1), stdin);
    
    /* fgets() fonksiyonu satır sonu karakterini (newline) de alır, bunu kaldıralım */
    str1[strcspn(str1, "\n")] = '\0';
    
    printf("İkinci string'i giriniz: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';
    
    /* 1. String uzunluklarını ölçme (strlen) */
    printf("\n1. String Uzunlukları:\n");
    printf("İlk string'in uzunluğu: %lu karakter\n", strlen(str1));
    printf("İkinci string'in uzunluğu: %lu karakter\n", strlen(str2));
    
    /* 2. Stringleri alfabetik olarak karşılaştırma (strcmp) */
    printf("\n2. Alfabetik Karşılaştırma:\n");
    int karsilastirma = strcmp(str1, str2);
    
    if (karsilastirma < 0) {
        printf("'%s' alfabetik olarak '%s' kelimesinden ÖNCE gelir.\n", str1, str2);
    } else if (karsilastirma > 0) {
        printf("'%s' alfabetik olarak '%s' kelimesinden SONRA gelir.\n", str1, str2);
    } else {
        printf("'%s' ve '%s' alfabetik olarak AYNIDIR.\n", str1, str2);
    }
    
    /* 3. Stringleri birleştirme (strcpy ve strcat) */
    printf("\n3. String Birleştirme:\n");
    
    /* Önce birlesik dizisine ilk string'i kopyala */
    strcpy(birlesik, str1);
    
    /* Sonra ikinci string'i birlesik dizisinin sonuna ekle */
    strcat(birlesik, " ");  /* İki string arasına boşluk ekle */
    strcat(birlesik, str2);
    
    printf("Birleştirilmiş string: '%s'\n", birlesik);
    printf("Birleştirilmiş string'in uzunluğu: %lu karakter\n", strlen(birlesik));
    
    /* 4. String içinde arama yapma (strstr) */
    printf("\n4. String İçinde Arama:\n");
    printf("İkinci string, birinci string içinde aranıyor...\n");
    
    char *arama_sonucu = strstr(str1, str2);
    if (arama_sonucu != NULL) {
        printf("'%s' ifadesi, '%s' içinde BULUNDU.\n", str2, str1);
        printf("Bulunan pozisyon: %ld\n", arama_sonucu - str1);
    } else {
        printf("'%s' ifadesi, '%s' içinde BULUNAMADI.\n", str2, str1);
    }
    
    return 0;
}
