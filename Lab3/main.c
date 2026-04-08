#include "func.h"

int main() {
    char expr[512];
    printf("Введите выражение: ");
    if (!fgets(expr, sizeof(expr), stdin)) return 0;
    expr[strcspn(expr, "\n")] = 0;

    Node* root = build_tree_from_expr(expr);
    if (!root) {
        printf("Parse error\n");
        return 1;
    }

    printf("\nДерево выражения:\n");
    print_tree(root, 0);

    printf("\nВыражение: ");
    print_expr(root);
    printf("\nРезультат: %d\n", evaluate(root));

    printf("\nПрименение трансформации\n");
    root = transform_fractions(root);
    print_tree(root, 0);

    printf("\nВыражение после трансформации: ");
    print_expr(root);
    printf("\nРезультат после трансформации: %d\n", evaluate(root));

    free_tree(root);
    return 0;
}
