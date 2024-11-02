#ifndef DICT_H
#define DICT_H

typedef struct {
    char *number;
    char *text;
} DictEntry;

typedef struct {
    DictEntry *entries;
    int size;
} Dict;

Dict *parse_dict(const char *path);
char *convert_number_to_text(Dict *dict, const char *number);
void free_dict(Dict *dict);

#endif
