#include <stdio.h>

/* Bit alanları (bit-fields) kullanarak file_date yapısını tanımlama
   day için 5 bit (0-31 arası değerler için yeterli)
   month için 4 bit (0-15 arası değerler için yeterli)
   year için 7 bit (0-127 arası değerler için yeterli, 2000 + year şeklinde kullanılacak) */
struct file_date {
    unsigned int day   : 5;  /* 5 bit için 0-31 arası değerler */
    unsigned int month : 4;  /* 4 bit için 0-15 arası değerler */
    unsigned int year  : 7;  /* 7 bit için 0-127 arası değerler */
};

void tarih_yazdir(struct file_date tarih) {
    printf("Tarih: %02d/%02d/%d\n", 
           tarih.day, 
           tarih.month, 
           2000 + tarih.year); /* 2000 yılından itibaren */
}

int main() {
    struct file_date tarih1, tarih2;
    
    printf("Bit Alanları (Bit-Fields) Örneği\n");
    printf("================================\n\n");
    
    /* struct file_date boyutunu yazdır */
    printf("struct file_date'in boyutu: %lu byte\n\n", sizeof(struct file_date));
    
    /* İlk tarih örneği */
    tarih1.day = 15;    /* 15 = 01111 (binary, 5 bit) */
    tarih1.month = 6;   /* 6 = 0110 (binary, 4 bit) */
    tarih1.year = 23;   /* 23 = 0010111 (binary, 7 bit) -> 2023 yılı */
    
    printf("Tarih 1:\n");
    printf("day = %d (5 bit kullanılıyor, 0-31 arası değerler)\n", tarih1.day);
    printf("month = %d (4 bit kullanılıyor, 0-15 arası değerler)\n", tarih1.month);
    printf("year = %d (7 bit kullanılıyor, 0-127 arası değerler)\n", tarih1.year);
    tarih_yazdir(tarih1);
    
    /* İkinci tarih örneği */
    tarih2.day = 31;    /* 31 = 11111 (binary, 5 bit) */
    tarih2.month = 12;  /* 12 = 1100 (binary, 4 bit) */
    tarih2.year = 25;   /* 25 = 0011001 (binary, 7 bit) -> 2025 yılı */
    
    printf("\nTarih 2:\n");
    printf("day = %d (5 bit kullanılıyor, 0-31 arası değerler)\n", tarih2.day);
    printf("month = %d (4 bit kullanılıyor, 0-15 arası değerler)\n", tarih2.month);
    printf("year = %d (7 bit kullanılıyor, 0-127 arası değerler)\n", tarih2.year);
    tarih_yazdir(tarih2);
    
    /* Bit sınırlarını aşan değerlerin nasıl davrandığını göster */
    printf("\nBit sınırlarını aşan değerler:\n");
    
    struct file_date tarih3;
    tarih3.day = 40;    /* 5 bit için maksimum değer 31, taşma olacak */
    tarih3.month = 20;  /* 4 bit için maksimum değer 15, taşma olacak */
    tarih3.year = 200;  /* 7 bit için maksimum değer 127, taşma olacak */
    
    printf("Sınırları aşan değerler atandıktan sonra:\n");
    printf("day = %d (5 bit sınırı aşıldı, 40 -> %d)\n", tarih3.day, tarih3.day);
    printf("month = %d (4 bit sınırı aşıldı, 20 -> %d)\n", tarih3.month, tarih3.month);
    printf("year = %d (7 bit sınırı aşıldı, 200 -> %d)\n", tarih3.year, tarih3.year);
    tarih_yazdir(tarih3);
    
    return 0;
}
