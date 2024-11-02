#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dict.h"

Dict *parse_dict(const char *path) {
    FILE *file = fopen(path, "r");
    if (!file) return NULL;

    Dict *dictionary = malloc(sizeof(Dict));
    dictionary->entries = malloc(sizeof(DictEntry) * 100);
    dictionary->size = 0;

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *number = strtok(line, ":");
        char *text = strtok(NULL, "\n");

        if (number && text) {
            dictionary->entries[dictionary->size].number = strdup(number);
            dictionary->entries[dictionary->size].text = strdup(text);
            dictionary->size++;
        }
    }

    fclose(file);
    return dictionary;
}

char *convert_number_to_text(Dict *dict, const char *number) {
    char *result = malloc(1024);
    result[0] = '\0';

    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->entries[i].number, number) == 0) {
            strcat(result, dict->entries[i].text);
            return result;
        }
    }

    free(result);
    return NULL;
}

void free_dict(Dict *dict) {
    for (int i = 0; i < dict->size; i++) {
        free(dict->entries[i].number);
        free(dict->entries[i].text);
    }
    free(dict->entries);
    free(dict);
}
