#include "table.h"

char* read_str() {
    int sz = 16;
    int len = 0;
    char* s = (char*)malloc(sz);
    if (!s) return NULL;
    
    int c;
    while ((c = getchar()) != EOF && isspace(c));
    if (c == EOF) {
        free(s);
        return NULL;
    }
    ungetc(c, stdin);

    while ((c = getchar()) != EOF && c != '\n') {
        if (len + 1 >= sz) {
            sz *= 2;
            char* tmp = (char*)realloc(s, sz);
            if (!tmp) {
                free(s);
                return NULL;
            }
            s = tmp;
        }
        s[len++] = c;
    }
    s[len] = '\0';
    return s;
}

Table* create_table(int n) {
    Table* t = (Table*)malloc(sizeof(Table));
    if (!t) return NULL;
    t->a = (Item*)malloc(n * sizeof(Item));
    if (!t->a) {
        free(t);
        return NULL;
    }
    t->n = n;
    return t;
}

void free_table(Table* t) {
    if (!t) return;
    for (int i = 0; i < t->n; i++) {
        free(t->a[i].k);
        free(t->a[i].v);
    }
    free(t->a);
    free(t);
}

void sort_table(Table* t) {
    for (int i = 1; i < t->n; i++) {
        Item x = t->a[i];
        int l = 0;
        int r = i - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (strcmp(x.k, t->a[m].k) < 0) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        for (int j = i - 1; j >= l; j--) {
            t->a[j + 1] = t->a[j];
        }
        t->a[l] = x;
    }
}

int find_item(Table* t, char* k) {
    int l = 0;
    int r = t->n - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        int res = strcmp(k, t->a[m].k);
        if (res == 0) return m;
        if (res < 0) r = m - 1;
        else l = m + 1;
    }
    return -1;
}

void print_table(Table* t) {
    for (int i = 0; i < t->n; i++) {
        printf("%s\n%s\n", t->a[i].k, t->a[i].v);
    }
}
