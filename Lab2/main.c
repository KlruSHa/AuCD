#include "table.h"

int main() {
    int n;
    scanf("%d", &n);

    Table* t = create_table(n);
    if (!t) return 1;

    for (int i = 0; i < n; i++) {
        t->a[i].k = read_str();
        t->a[i].v = read_str();
    }

    printf("Table:\n");
    print_table(t);
    sort_table(t);
    printf("\nSorted table:\n");
    print_table(t);

    char* s_key;
    while ((s_key = read_str()) != NULL) {
        if (strcmp(s_key, "exit") == 0) {
            free(s_key);
            break;
        }
        int idx = find_item(t, s_key);
        if (idx != -1) {
            printf("Found: %s\n", t->a[idx].v);
        } else {
            printf("Not found\n");
        }
        free(s_key);
    }

    free_table(t);
    return 0;
}
