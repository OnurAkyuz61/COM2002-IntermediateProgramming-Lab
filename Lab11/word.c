#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include "word.h"

/* Reads a character from file and converts newline or tab characters to space */
int read_char(FILE *fp) {
    int ch = getc(fp);    /* Read a character from file */
    
    if (ch == '\n' || ch == '\t')
        return ' ';        /* Convert newline or tab characters to space */
    return ch;            /* Return normal characters as is */
}

/* Reads the next word from file and stores it in the specified buffer */
int read_word(char *word, int len, FILE *fp) {
    int ch, pos = 0;      /* ch: read character, pos: position in word */
    
    /* Skip spaces */
    while ((ch = read_char(fp)) == ' ')
        ;
    
    /* If end of file is reached, return empty word */
    if (ch == EOF) {
        word[0] = '\0';    /* Create empty string */
        return 0;          /* Indicate end of file reached */
    }
    
    /* Store first character of the word */
    word[pos++] = ch;
    
    /* Read the rest of the word */
    while ((ch = read_char(fp)) != EOF && ch != ' ') {
        if (pos < len - 1) {
            word[pos++] = ch;  /* Add character to word if within limit */
        } else if (pos == len - 1) {
            /* If word exceeds maximum length, add asterisk and stop reading */
            word[pos++] = '*';
        }
    }
    
    word[pos] = '\0';  /* Null-terminate the word */
    return 1;          /* Indicate a word was successfully read */
}
