#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50

/* Part structure with next pointer for linked list */
struct Part {
    int number;
    char name[MAX_NAME_LENGTH];
    int quantity;
    struct Part *next;
};

/* Global pointer to the first node in the list */
struct Part *inventory = NULL;

void read_line(char *str, int n) {
    int ch, i = 0;
    
    // Skip leading whitespace including newline
    while ((ch = getchar()) != EOF && isspace(ch))
        ;
        
    if (ch == EOF) {
        str[0] = '\0';
        return;
    }
    
    // Store first non-whitespace character
    str[i++] = ch;
    
    // Read remaining characters
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
}

/* Find a part in the list - returns pointer to node or NULL if not found */
struct Part *find_part(int number) {
    struct Part *p;
    
    for (p = inventory; p != NULL && p->number <= number; p = p->next)
        if (p->number == number)
            return p;
    return NULL;
}

void insert(void) {
    struct Part *cur, *prev, *new_node;
    
    /* Create new node */
    new_node = malloc(sizeof(struct Part));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    
    printf("Enter part number: ");
    scanf("%d", &new_node->number);
    
    /* Check if part already exists */
    if (find_part(new_node->number) != NULL) {
        printf("Part already exists.\n");
        free(new_node);
        while (getchar() != '\n'); // Clear input buffer
        return;
    }
    
    printf("Enter part name: ");
    while (getchar() != '\n'); // Clear input buffer
    read_line(new_node->name, MAX_NAME_LENGTH);
    
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->quantity);
    while (getchar() != '\n'); // Clear input buffer
    
    /* Find position to insert new node (keeping list sorted) */
    prev = NULL;
    cur = inventory;
    while (cur != NULL && cur->number < new_node->number) {
        prev = cur;
        cur = cur->next;
    }
    
    /* Insert new node */
    new_node->next = cur;
    if (prev == NULL)
        inventory = new_node;  /* Insert at beginning */
    else
        prev->next = new_node; /* Insert after prev */
}

void search(void) {
    int number;
    struct Part *p;
    
    printf("Enter part number: ");
    scanf("%d", &number);
    while (getchar() != '\n'); // Clear input buffer
    
    p = find_part(number);
    if (p != NULL) {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->quantity);
    } else
        printf("Part not found.\n");
}

void update(void) {
    int number, change;
    struct Part *p;
    
    printf("Enter part number: ");
    scanf("%d", &number);
    
    p = find_part(number);
    if (p != NULL) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        while (getchar() != '\n'); // Clear input buffer
        p->quantity += change;
    } else {
        printf("Part not found.\n");
        while (getchar() != '\n'); // Clear input buffer
    }
}

void erase(void) {
    int number;
    struct Part *cur, *prev;
    
    printf("Enter part number: ");
    scanf("%d", &number);
    while (getchar() != '\n'); // Clear input buffer
    
    /* Find part to delete */
    prev = NULL;
    cur = inventory;
    
    while (cur != NULL && cur->number < number) {
        prev = cur;
        cur = cur->next;
    }
    
    if (cur == NULL || cur->number != number) {
        printf("Part not found.\n");
        return;
    }
    
    /* Remove the node */
    if (prev == NULL)
        inventory = cur->next;  /* Remove first node */
    else
        prev->next = cur->next; /* Remove after prev */
    
    free(cur);
    printf("Part deleted.\n");
}

void print(void) {
    struct Part *p;
    
    printf("Part Number   Part Name                      Quantity on Hand\n");
    for (p = inventory; p != NULL; p = p->next)
        printf("%-12d %-30s %d\n", p->number, p->name, p->quantity);
}

/* Free all allocated memory before exiting */
void cleanup(void) {
    struct Part *cur, *next;
    
    cur = inventory;
    while (cur != NULL) {
        next = cur->next;
        free(cur);
        cur = next;
    }
}

int main(void) {
    char code;
    
    for (;;) {
        printf("\nEnter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n'); // Clear input buffer
        
        switch (tolower(code)) {
            case 'i':
                insert();
                break;
            case 's':
                search();
                break;
            case 'u':
                update();
                break;
            case 'p':
                print();
                break;
            case 'e':
                erase();
                break;
            case 'q':
                cleanup();
                return 0;
            default:
                printf("Illegal code\n");
        }
    }
}
