#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 1024

/**
 * char *fgets(char *str, int n, FILE *stream);
 *
 * This function reads a line from the specified stream and stores it
 * into the string pointer by str. It stops when either (n-1) chars are
 * read, the newline character is read, or the EOF is reached, whichever
 * comes first.
 */

/**
 * int puts(const char *str);
 *
 * writes a string to stdout up to but not including the full character.
 * A newline char is appended to the output.
 */

void read_from_file (char const *filename)
{
    FILE *fp;
    char str[BUF_SIZE];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error openning file");
        exit(1);
    }
    while (fgets(str, BUF_SIZE, fp) != NULL) {
        printf("%s",str);
    }

    fclose(fp);
}

/**
 * Main execution. ARGC stands for arguments counter and ARGV is
 * arguments vector.
 */
int main(int argc, char const *argv[])
{
    // if (argc > 1) {
    //     char *args[] = strtok(argv[1], "=");
    //     if (args[0] != "--file") return 1;
    //     read_from_file(args[1]);

    //     return 0;
    // }

    // printf("Enter a fucking argument, mf");

    //

    char* token;
    char* string;
    char* tofree;

    if (argc > 1) {
        string = strdup(argv[1]);

        if (!string) return 1;

        tofree = string;

        while ((token = strsep(&string, ",")) != NULL) {
            printf("%s\n", token);
        }

        free(tofree);
    }

    return 0;
}
