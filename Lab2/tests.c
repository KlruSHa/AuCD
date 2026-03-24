#include "table.h"
#include <assert.h>

char* my_dup(const char* s) {
    char* d = (char*)malloc(strlen(s) + 1);
    if (d) strcpy(d, s);
    return d;
}

void test_sort_up() {
    printf("test 1: sorted table - ");
    Table* t = create_table(3);
    t->a[0].k = my_dup("a"); t->a[0].v = my_dup("1");
    t->a[1].k = my_dup("b"); t->a[1].v = my_dup("2");
    t->a[2].k = my_dup("c"); t->a[2].v = my_dup("3");
    sort_table(t);
    assert(strcmp(t->a[0].k, "a") == 0);
    assert(strcmp(t->a[1].k, "b") == 0);
    assert(strcmp(t->a[2].k, "c") == 0);
    free_table(t);
    printf("passed\n\n");
}
    
void test_sort_down() {
    printf("test 2: reversed sorted table - ");
    Table* t = create_table(3);
    t->a[0].k = my_dup("c"); t->a[0].v = my_dup("3");
    t->a[1].k = my_dup("b"); t->a[1].v = my_dup("2");
    t->a[2].k = my_dup("a"); t->a[2].v = my_dup("1");
    sort_table(t);
    assert(strcmp(t->a[0].k, "a") == 0);
    assert(strcmp(t->a[1].k, "b") == 0);
    assert(strcmp(t->a[2].k, "c") == 0);
    free_table(t);
    printf("passed\n\n");
}

void test_sort_rand() {
    printf("test 3: unsorted table - ");
    Table* t = create_table(3);
    t->a[0].k = my_dup("b"); t->a[0].v = my_dup("2");
    t->a[1].k = my_dup("c"); t->a[1].v = my_dup("3");
    t->a[2].k = my_dup("a"); t->a[2].v = my_dup("1");
    sort_table(t);
    assert(strcmp(t->a[0].k, "a") == 0);
    assert(strcmp(t->a[1].k, "b") == 0);
    assert(strcmp(t->a[2].k, "c") == 0);
    free_table(t);
    printf("passed\n\n");
}

void test_find_found() {
    printf("test 4: find_item() that exists - ");
    Table* t = create_table(3);
    t->a[0].k = my_dup("apple"); t->a[0].v = my_dup("fruit");
    t->a[1].k = my_dup("banana"); t->a[1].v = my_dup("yellow");
    t->a[2].k = my_dup("cherry"); t->a[2].v = my_dup("red");
    int idx = find_item(t, "banana");
    assert(idx == 1);
    assert(strcmp(t->a[idx].v, "yellow") == 0);
    free_table(t);
    printf("passed\n\n");
}

void test_find_missing() {
    printf("test 5: find_item() that missing - ");
    Table* t = create_table(2);
    t->a[0].k = my_dup("a"); t->a[0].v = my_dup("1");
    t->a[1].k = my_dup("c"); t->a[1].v = my_dup("3");
    int idx = find_item(t, "b");
    assert(idx == -1);
    free_table(t);
    printf("passed\n\n");
}

void test_empty_table() {
    printf("test 6: empty table - ");
    Table* t = create_table(0);
    assert(t != NULL);
    assert(t->n == 0);
    sort_table(t);
    int idx = find_item(t, "anything");
    assert(idx == -1);
    free_table(t);
    printf("passed\n\n");
}

int main() {
    test_sort_up();
    test_sort_down();
    test_sort_rand();
    test_find_found();
    test_find_missing();
    test_empty_table();
    printf("All tests passed!\n");
    return 0;
}
