#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60     /* max length of reminder message */

int read_line(char str[], int n);

int main(void) {
    char *reminders[MAX_REMIND];  /* Array of pointers to dynamically allocated strings */
    char day_str[3], msg_str[MSG_LEN+1];
    char *temp_str;
    int day, i, j, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter day and reminder: ");
        scanf("%2d", &day);
        if (day == 0)
            break;
        if (day < 0 || day > 31) {
            printf("Invalid day\n");
            while (getchar() != '\n')   /* clear rest of line */
                ;
            continue;
        }

        sprintf(day_str, "%2d", day);
        read_line(msg_str, MSG_LEN);

        /* Allocate memory for the new reminder string */
        temp_str = (char *)malloc(strlen(day_str) + strlen(msg_str) + 1);
        if (temp_str == NULL) {
            printf("Error: Memory allocation failed\n");
            break;
        }

        /* Combine day and message */
        strcpy(temp_str, day_str);
        strcat(temp_str, msg_str);

        /* Find position to insert the new reminder */
        for (i = 0; i < num_remind; i++)
            if (strcmp(day_str, reminders[i]) < 0)
                break;

        /* Move existing reminders to make room */
        for (j = num_remind; j > i; j--)
            reminders[j] = reminders[j-1];

        reminders[i] = temp_str;
        num_remind++;
    }

    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);

    /* Free allocated memory */
    for (i = 0; i < num_remind; i++)
        free(reminders[i]);

    return 0;
}

int read_line(char str[], int n) {
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}
