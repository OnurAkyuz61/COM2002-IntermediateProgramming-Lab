#ifndef LINE_H
#define LINE_H

/* Writes line buffer without justification */
void flush_line(char *line, FILE *fp);

/* Calculates remaining space in the line buffer */
int space_remaining(const char *line, int line_len);

/* Writes line buffer with justification */
void write_line(char *line, int line_len, FILE *fp);

/* Clears the line buffer */
void clear_line(char *line);

/* Adds a word to the line buffer */
void add_word(char *line, const char *word);

#endif /* LINE_H */
