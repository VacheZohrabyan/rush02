#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "dict.h"

void print_error(const char *msg) {
    write(1, msg, strlen(msg));
}

int is_valid_number(const char *str) {
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        print_error("Error\n");
        return 1;
    }

    char *dict_path = (argc == 3) ? argv[1] : "numbers.dict";
    char *number_str = (argc == 3) ? argv[2] : argv[1];

    if (!is_valid_number(number_str)) {
        print_error("Error\n");
        return 1;
    }

    Dict *dictionary = parse_dict(dict_path);
    if (!dictionary) {
        print_error("Dict Error\n");
        return 1;
    }


    char *text = convert_number_to_text(dictionary, number_str);
    if (text) {
        printf("%s\n", text);
        free(text);
    } else {
        print_error("Dict Error\n");
    }

    free_dict(dictionary);

    return 0;
}
