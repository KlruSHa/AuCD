#include "func.h"

void run_test(int id, const char* expr) {
    printf("--- Test %d: %s ---\n", id, expr);
    Node* root = build_tree_from_expr(expr);
    if (!root) {
        printf("Parse error\n\n");
        return;
    }

    printf("Выражение: ");
    print_expr(root);
    int res1 = evaluate(root);
    printf(" = %d\n", res1);

    root = transform_fractions(root);
    
    printf("Выражение после трансформации: ");
    print_expr(root);
    int res2 = evaluate(root);
    printf(" = %d\n", res2);

    if (res1 == res2) {
        printf("Тест пройден\n");
    } else {
        printf("Значения отличаются! %d и %d\n", res1, res2);
    }
    printf("\nДерево\n");
    print_tree(root, 0);
    printf("\n");

    free_tree(root);
}

int main() {
    run_test(1, "1 + 2 * 3");
    run_test(2, "1/2 + 1/3");
    run_test(3, "5/2 - 1/4");
    run_test(4, "(1/2 + 1/3) * (2/5 + 1/10)");
    run_test(5, "10 + (3/4 - 1/2) / 2");
    return 0;
}
