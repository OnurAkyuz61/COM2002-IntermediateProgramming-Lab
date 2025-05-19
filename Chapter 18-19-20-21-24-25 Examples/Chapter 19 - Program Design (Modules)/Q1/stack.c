#include <stdio.h>
#include "stack.h"

/* Stack'i başlatma fonksiyonu */
void stack_init(Stack *s) {
    s->top = -1;  /* Boş stack için top değeri -1 */
}

/* Stack'e eleman ekleme fonksiyonu */
int stack_push(Stack *s, int item) {
    if (stack_is_full(s)) {
        printf("Hata: Stack dolu!\n");
        return 0;  /* Başarısız */
    }
    
    s->top++;
    s->items[s->top] = item;
    return 1;  /* Başarılı */
}

/* Stack'ten eleman çıkarma fonksiyonu */
int stack_pop(Stack *s, int *item) {
    if (stack_is_empty(s)) {
        printf("Hata: Stack boş!\n");
        return 0;  /* Başarısız */
    }
    
    *item = s->items[s->top];
    s->top--;
    return 1;  /* Başarılı */
}

/* Stack'in boş olup olmadığını kontrol eden fonksiyon */
int stack_is_empty(Stack *s) {
    return (s->top == -1);
}

/* Stack'in dolu olup olmadığını kontrol eden fonksiyon */
int stack_is_full(Stack *s) {
    return (s->top == MAX_STACK_SIZE - 1);
}
