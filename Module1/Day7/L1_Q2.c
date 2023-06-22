#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void changeToUpperCase(char* str);
void changeToLowerCase(char* str);
void changeToSentenceCase(char* str);

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: ./cp <option> <source_file> <destination_file>\n");
        printf("Options:\n");
        printf("  -u: Change file content to Upper Case\n");
        printf("  -l: Change file content to Lower Case\n");
        printf("  -s: Change file content to Sentence Case\n");
        return 1;
    }

    char* option = argv[1];
    char* sourceFileName = argv[2];
    char* destinationFileName = argv[3];

    FILE* sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Failed to open the source file.\n");
        return 1;
    }

    FILE* destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("Failed to create the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    char line[1000];
    while (fgets(line, sizeof(line), sourceFile) != NULL) {
        if (strcmp(option, "-u") == 0) {
            changeToUpperCase(line);
        } else if (strcmp(option, "-l") == 0) {
            changeToLowerCase(line);
        } else if (strcmp(option, "-s") == 0) {
            changeToSentenceCase(line);
        }

        fputs(line, destinationFile);
    }

    printf("File copied successfully.\n");

    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}

void changeToUpperCase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void changeToLowerCase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

void changeToSentenceCase(char* str) {
    int i = 0;

    // Convert the first character of the string to uppercase
    if (str[i] != '\0') {
        str[i] = toupper(str[i]);
        i++;
    }

    while (str[i] != '\0') {
        // Convert alphabets to lowercase
        if (isalpha(str[i])) {
            str[i] = tolower(str[i]);
        }

        // Convert the first character after a period (.) to uppercase
        if (str[i] == '.') {
            i++;
            while (str[i] == ' ') {
                i++;
            }

            if (isalpha(str[i])) {
                str[i] = toupper(str[i]);
            }
        }

        i++;
    }
}