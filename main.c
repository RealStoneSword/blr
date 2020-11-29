#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <sys/stat.h>
#include "config.h"

const long int num_of_langs = sizeof(supported_langs)/sizeof(*supported_langs);
const long int num_of_temps = sizeof(templates)/sizeof(*templates);

void write(FILE **pntr, char *lang) {
    for (int i = 0; i < num_of_langs; i++){
        if (strcasecmp(lang, supported_langs[i]) == 0)
            fprintf(*pntr, "%s", templates[i]);
    }
}

int string_in_array(char *value, const char *array[], int array_length);
int char_in_string(char value, char *string, int string_length);

int main(int argc, char *argv[]) {
    char *short_args;
    FILE *fp;

    short_args = "weh";

    /* Usage checking */
    if (argc < 3) {
        printf("Not enough arguments.\n");
        return 1; }
    if (num_of_langs != num_of_temps){
        printf("Invalid config.\n");
        return 1; }
    if (argv[1][0] != '-') {
        printf("Invalid argument.\n");
        return 1; }
    if (char_in_string(argv[1][1], short_args, 3) == 1) {
        printf("Invalid argument.\n");
        return 1; }
    if (string_in_array(argv[2], supported_langs, num_of_langs) == 1) {
        printf("Invalid or unsupported language.\n");
        return 1; }

    /* Open file pointer */
    fp = fopen(argv[3], "w");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return 1; }

    /* Parsing of command */
    switch (argv[1][1]) {
        case 'w':
            write(&fp, argv[2]);
            break;
        case 'e':
            write(&fp, argv[2]);
            chmod(argv[3], 0775);
            break;
        case 'h':
            break;
    }

    /* Close file pointer */
    fclose(fp);

    return 0;
}

int string_in_array(char *value, const char *array[], int array_length) {
    for (int i = 0; i < array_length; i++) {
        if (strcasecmp(value, array[i]) == 0)
            return 0;
    }
    return 1;
}

int char_in_string(char value, char *string, int string_length) {
    for (int i = 0; i < string_length; i++) {
        if (value == string[i])
            return 0;
    }
    return 1;
}
