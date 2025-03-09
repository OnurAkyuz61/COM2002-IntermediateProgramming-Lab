#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX_PARTS 100
#define MAX_NAME_LENGTH 50

struct Part {
    int number;
    char name[MAX_NAME_LENGTH];
    int quantity;
};

struct Part inventory[MAX_PARTS];
int num_parts = 0;

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

void insert(void) {
    struct Part part;
    
    if (num_parts == MAX_PARTS) {
        printf("Database is full.\n");
        return;
    }
    
    printf("Enter part number: ");
    scanf("%d", &part.number);
    
    // Check if part already exists
    for (int i = 0; i < num_parts; i++) {
        if (inventory[i].number == part.number) {
            printf("Part already exists.\n");
            while (getchar() != '\n'); // Clear input buffer
            return;
        }
    }
    
    printf("Enter part name: ");
    while (getchar() != '\n'); // Clear input buffer
    read_line(part.name, MAX_NAME_LENGTH);
    
    printf("Enter quantity on hand: ");
    scanf("%d", &part.quantity);
    while (getchar() != '\n'); // Clear input buffer
    
    inventory[num_parts++] = part;
}

void search(void) {
    int number;
    
    printf("Enter part number: ");
    scanf("%d", &number);
    while (getchar() != '\n'); // Clear input buffer
    
    for (int i = 0; i < num_parts; i++) {
        if (inventory[i].number == number) {
            printf("Part name: %s\n", inventory[i].name);
            printf("Quantity on hand: %d\n", inventory[i].quantity);
            return;
        }
    }
    printf("Part not found.\n");
}

void update(void) {
    int number, change;
    
    printf("Enter part number: ");
    scanf("%d", &number);
    
    for (int i = 0; i < num_parts; i++) {
        if (inventory[i].number == number) {
            printf("Enter change in quantity on hand: ");
            scanf("%d", &change);
            while (getchar() != '\n'); // Clear input buffer
            inventory[i].quantity += change;
            return;
        }
    }
    printf("Part not found.\n");
    while (getchar() != '\n'); // Clear input buffer
}

void print(void) {
    printf("Part Number   Part Name                      Quantity on Hand\n");
    for (int i = 0; i < num_parts; i++) {
        printf("%-12d %-30s %d\n", inventory[i].number, inventory[i].name, inventory[i].quantity);
    }
}

int main(void) {
    char code;
    
    for (;;) {
        printf("\nEnter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n'); // Clear input buffer
        
        switch (code) {
            case 'i': case 'I':
                insert();
                break;
            case 's': case 'S':
                search();
                break;
            case 'u': case 'U':
                update();
                break;
            case 'p': case 'P':
                print();
                break;
            case 'q': case 'Q':
                return 0;
            default:
                printf("Illegal code\n");
        }
    }
}
