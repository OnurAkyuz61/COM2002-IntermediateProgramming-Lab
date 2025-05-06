#ifndef WORD_H
#define WORD_H

/* Reads the next word from file and stores it in the specified buffer */
int read_word(char *word, int len, FILE *fp);

/* Reads a character from file and converts newline or tab characters to space */
int read_char(FILE *fp);

#endif /* WORD_H */
