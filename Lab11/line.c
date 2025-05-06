#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

/* Writes line buffer without justification */
void flush_line(char *line, FILE *fp) {
    fputs(line, fp);    /* Write line to file */
    fputc('\n', fp);    /* Add newline character */
}

/* Calculates remaining space in the line buffer */
int space_remaining(const char *line, int line_len) {
    return line_len - strlen(line);    /* Subtract current length from maximum length */
}

/* Writes line buffer with justification */
void write_line(char *line, int line_len, FILE *fp) {
    int extra_spaces, spaces_to_insert, i, j;
    int line_len_without_spaces = 0;  /* Length of line without spaces */
    int num_words = 0;               /* Number of words in line */
    int num_spaces = 0;              /* Number of spaces in line */
    
    /* Count the number of words and spaces in the line */
    for (i = 0; i < strlen(line); i++) {
        if (line[i] != ' ')
            line_len_without_spaces++;  /* Count non-space characters */
        else
            num_spaces++;              /* Count spaces */
    }
    
    num_words = num_spaces + 1;      /* Number of words = number of spaces + 1 */
    
    /* If there's only one word, write without justification */
    if (num_words == 1) {
        fputs(line, fp);              /* Write line as is */
        fputc('\n', fp);              /* Add newline */
        return;
    }
    
    /* Calculate extra spaces needed for justification */
    extra_spaces = line_len - line_len_without_spaces;
    
    /* Calculate spaces to insert between each word */
    spaces_to_insert = extra_spaces / (num_words - 1);
    
    /* Write the justified line */
    for (i = 0; i < strlen(line); i++) {
        fputc(line[i], fp);           /* Write current character */
        
        if (line[i] == ' ') {         /* When space character is encountered */
            /* Add extra spaces for justification */
            for (j = 0; j < spaces_to_insert; j++) {
                fputc(' ', fp);
            }
            
            /* Distribute remaining spaces evenly */
            if (extra_spaces % (num_words - 1) > 0) {
                fputc(' ', fp);       /* Add one more space */
                extra_spaces -= (num_words - 1);
            }
        }
    }
    
    fputc('\n', fp);                  /* Add newline at end of line */
}

/* Clears the line buffer */
void clear_line(char *line) {
    line[0] = '\0';    /* Create empty string */
}

/* Adds a word to the line buffer */
void add_word(char *line, const char *word) {
    if (strlen(line) > 0) {
        /* If line is not empty, add a space before the word */
        strcat(line, " ");
    }
    strcat(line, word);    /* Add word to line buffer */
}
