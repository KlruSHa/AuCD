#include "tree.h"

b_node* createNode(int key) {
	b_node* n = (b_node*)malloc(sizeof(b_node));
	n->l_ptr = NULL;
	n->r_ptr = NULL;
	n->key = key;
	return n;
}

void print_b_tree(b_node* t, int d) {
	if (t == NULL) return;
	print_b_tree(t->r_ptr, d + 1);
	for (int i = 0; i < d; i++) printf("    ");
	printf("%d\n", t->key);
	print_b_tree(t->l_ptr, d + 1);
}

b_node* add_b_node(b_node* t, int v) {
	if (t == NULL) return createNode(v);
	if (v < t->key) t->l_ptr = add_b_node(t->l_ptr, v);
	else t->r_ptr = add_b_node(t->r_ptr, v);
	return t;
}

b_node* find_min(b_node* t) {
	b_node* cur = t;
	while (cur && cur->l_ptr != NULL) cur = cur->l_ptr;
	return cur;
}

b_node* del_b_node(b_node* t, int v) {
	if (t == NULL) return NULL;
	if (v < t->key) t->l_ptr = del_b_node(t->l_ptr, v);
	else if (v > t->key) t->r_ptr = del_b_node(t->r_ptr, v);
	else {
		if (t->l_ptr == NULL) {
			b_node* tmp = t->r_ptr;
			free(t);
			return tmp;
		} else if (t->r_ptr == NULL) {
			b_node* tmp = t->l_ptr;
			free(t);
			return tmp;
		}
		b_node* tmp = find_min(t->r_ptr);
		t->key = tmp->key;
		t->r_ptr = del_b_node(t->r_ptr, tmp->key);
	}
	return t;
}

int get_deg(b_node* t) {
	if (t == NULL) return 0;
	int cur = 0;
	if (t->l_ptr) cur++;
	if (t->r_ptr) cur++;
	int l = get_deg(t->l_ptr);
	int r = get_deg(t->r_ptr);
	int max = cur;
	if (l > max) max = l;
	if (r > max) max = r;
	return max;
}

void clear_b(b_node* t) {
	if (t == NULL) return;
	clear_b(t->l_ptr);
	clear_b(t->r_ptr);
	free(t);
}

c_node* add_c_node(c_node* tree, c_node* parent, int v);
c_node* del_c_node(c_node* tree, c_node* node);