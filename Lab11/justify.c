#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "word.h"
#include "line.h"

#define MAX_WORD_LEN 20
#define MAX_LINE_LEN 60

int main(int argc, char *argv[]) {
    char word[MAX_WORD_LEN + 1];        /* Word buffer */
    char line[MAX_LINE_LEN + 1] = "";   /* Line buffer */
    FILE *input_file, *output_file;      /* File pointers */
    
    /* Check number of command line arguments */
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;                       /* Exit with error code */
    }
    
    /* Open input file */
    input_file = fopen(argv[1], "r");    /* Open in read mode */
    if (input_file == NULL) {
        printf("Error: Cannot open input file %s\n", argv[1]);
        return 1;                       /* Exit with error code */
    }
    
    /* Open output file */
    output_file = fopen(argv[2], "w");   /* Open in write mode */
    if (output_file == NULL) {
        printf("Error: Cannot open output file %s\n", argv[2]);
        fclose(input_file);             /* Close input file */
        return 1;                       /* Exit with error code */
    }
    
    clear_line(line);                    /* Clear line buffer */
    
    /* Process input file word by word */
    while (read_word(word, MAX_WORD_LEN, input_file)) {
        /* If adding the word would exceed the line length, write the current line and clear it */
        if (strlen(word) > space_remaining(line, MAX_LINE_LEN)) {
            write_line(line, MAX_LINE_LEN, output_file);  /* Write line with justification */
            clear_line(line);                             /* Clear line buffer */
        }
        
        /* Add word to line buffer */
        add_word(line, word);
    }
    
    /* Write the last line without justification */
    if (strlen(line) > 0) {
        flush_line(line, output_file);   /* Write last line without justification */
    }
    
    /* Close files */
    fclose(input_file);
    fclose(output_file);
    
    return 0;                           /* Successful exit */
}
