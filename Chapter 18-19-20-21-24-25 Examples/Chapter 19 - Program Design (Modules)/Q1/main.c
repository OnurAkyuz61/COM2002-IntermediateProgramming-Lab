#include <stdio.h>
#include "stack.h"

int main() {
    Stack yigit;
    int deger;
    
    /* Stack'i başlat */
    stack_init(&yigit);
    
    printf("Stack modülü test programı\n");
    printf("==========================\n\n");
    
    /* 3 eleman ekle */
    printf("Elemanlari ekleme:\n");
    printf("1. eleman ekleniyor: 10\n");
    stack_push(&yigit, 10);
    
    printf("2. eleman ekleniyor: 20\n");
    stack_push(&yigit, 20);
    
    printf("3. eleman ekleniyor: 30\n");
    stack_push(&yigit, 30);
    
    printf("\nElemanları çıkarma:\n");
    
    /* Elemanları sırayla çıkar */
    if (stack_pop(&yigit, &deger)) {
        printf("Çıkarılan 1. eleman: %d\n", deger);
    }
    
    if (stack_pop(&yigit, &deger)) {
        printf("Çıkarılan 2. eleman: %d\n", deger);
    }
    
    if (stack_pop(&yigit, &deger)) {
        printf("Çıkarılan 3. eleman: %d\n", deger);
    }
    
    /* Stack'in boş olduğunu göstermek için bir eleman daha çıkarmayı dene */
    if (stack_pop(&yigit, &deger)) {
        printf("Çıkarılan eleman: %d\n", deger);
    }
    
    return 0;
}
