/* stack.h - Stack modülü header dosyası */
#ifndef STACK_H
#define STACK_H

/* Stack'in maksimum boyutu */
#define MAX_STACK_SIZE 100

/* Stack veri yapısı */
typedef struct {
    int items[MAX_STACK_SIZE];
    int top;
} Stack;

/* Stack işlemleri için fonksiyon prototipleri */
void stack_init(Stack *s);
int stack_push(Stack *s, int item);
int stack_pop(Stack *s, int *item);
int stack_is_empty(Stack *s);
int stack_is_full(Stack *s);

#endif /* STACK_H */
