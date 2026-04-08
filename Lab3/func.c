#include "func.h"

int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

Node* create_val_node(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = NODE_VAL;
    node->value = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* create_op_node(char op, Node* left, Node* right) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = NODE_OP;
    node->op = op;
    node->left = left;
    node->right = right;
    return node;
}

void free_tree(Node* root) {
    if (!root) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

Node* copy_tree(Node* root) {
    if (!root) return NULL;
    if (root->type == NODE_VAL) return create_val_node(root->value);
    return create_op_node(root->op, copy_tree(root->left), copy_tree(root->right));
}

Node* build_tree_from_expr(const char* expr) {
    Node* tree_stack[256];
    int t_top = -1;
    char op_stack[256];
    int o_top = -1;

    for (int i = 0; expr[i]; i++) {
        if (isspace(expr[i])) continue;

        if (isdigit(expr[i])) {
            int val = 0;
            while (isdigit(expr[i])) {
                val = val * 10 + (expr[i] - '0');
                i++;
            }
            i--;
            tree_stack[++t_top] = create_val_node(val);
        } else if (expr[i] == '(') {
            op_stack[++o_top] = '(';
        } else if (expr[i] == ')') {
            while (o_top >= 0 && op_stack[o_top] != '(') {
                Node* r = tree_stack[t_top--];
                Node* l = tree_stack[t_top--];
                tree_stack[++t_top] = create_op_node(op_stack[o_top--], l, r);
            }
            if (o_top >= 0) o_top--;
        } else {
            while (o_top >= 0 && op_stack[o_top] != '(' && priority(op_stack[o_top]) >= priority(expr[i])) {
                Node* r = tree_stack[t_top--];
                Node* l = tree_stack[t_top--];
                tree_stack[++t_top] = create_op_node(op_stack[o_top--], l, r);
            }
            op_stack[++o_top] = expr[i];
        }
    }

    while (o_top >= 0) {
        Node* r = tree_stack[t_top--];
        Node* l = tree_stack[t_top--];
        tree_stack[++t_top] = create_op_node(op_stack[o_top--], l, r);
    }

    return (t_top >= 0) ? tree_stack[0] : NULL;
}

Node* transform_fractions(Node* root) {
    if (!root || root->type == NODE_VAL) return root;

    root->left = transform_fractions(root->left);
    root->right = transform_fractions(root->right);

    if (root->type == NODE_OP && (root->op == '+' || root->op == '-')) {
        Node* L = root->left;
        Node* R = root->right;

        if (L && R && L->type == NODE_OP && L->op == '/' && R->type == NODE_OP && R->op == '/') {
            Node* a = L->left;
            Node* b = L->right;
            Node* c = R->left;
            Node* d = R->right;

            Node* ad = create_op_node('*', copy_tree(a), copy_tree(d));
            Node* bc = create_op_node('*', copy_tree(b), copy_tree(c));
            Node* new_num = create_op_node(root->op, ad, bc);

            Node* new_den = create_op_node('*', copy_tree(b), copy_tree(d));

            root->op = '/';
            free_tree(L);
            free_tree(R);
            root->left = new_num;
            root->right = new_den;
        }
    }
    return root;
}

int evaluate(Node* root) {
    if (!root) return 0;
    if (root->type == NODE_VAL) return root->value;
    int l = evaluate(root->left);
    int r = evaluate(root->right);
    switch (root->op) {
        case '+': return l + r;
        case '-': return l - r;
        case '*': return l * r;
        case '/': return (r != 0) ? l / r : 0;
        case '^': return (int)pow(l, r);
        default: return 0;
    }
}

void print_tree(Node* t, int d) {
    if (t == NULL) return;
    print_tree(t->right, d + 1);
    for (int i = 0; i < d; i++) printf("    ");
    if (t->type == NODE_VAL) printf("%d\n", t->value);
    else printf("%c\n", t->op);
    print_tree(t->left, d + 1);
}

void print_expr_r(Node* root, int parent_priority, int is_right) {
    if (!root) return;
    if (root->type == NODE_VAL) {
        printf("%d", root->value);
        return;
    }

    int my_priority = priority(root->op);
    int need_parens = 0;

    if (my_priority < parent_priority) {
        need_parens = 1;
    } 
    
    else if (my_priority == parent_priority && is_right) {
        if (root->op == '+' || root->op == '-' || root->op == '*' || root->op == '/') {
            need_parens = 1;
        }
    }

    if (need_parens) printf("(");
    print_expr_r(root->left, my_priority, 0);
    printf("%c", root->op);
    print_expr_r(root->right, my_priority, 1);
    if (need_parens) printf(")");
}

void print_expr(Node* root) {
    print_expr_r(root, 0, 0);
}
