#include "tree.h"

void test1() {
	b_node* root = createNode(10);
	if (root->key == 10) printf("Test 1 passed\n");
	else printf("Test 1 failed\n");
	clear_b(root);
}

void test2() {
	b_node* root = NULL;
	root = add_b_node(root, 10);
	root = add_b_node(root, 5);
	root = add_b_node(root, 15);
	if (get_deg(root) == 2) printf("Test 2 passed\n");
	else printf("Test 2 failed\n");
	clear_b(root);
}

void test3() {
	b_node* root = createNode(10);
	root = add_b_node(root, 5);
	root = del_b_node(root, 5);
	if (root->l_ptr == NULL) printf("Test 3 passed\n");
	else printf("Test 3 failed\n");
	clear_b(root);
}

void test4() {
	b_node* root = NULL;
	root = add_b_node(root, 10);
	if (get_deg(root) == 0) printf("Test 4 passed\n");
	else printf("Test 4 failed\n");
	clear_b(root);
}

void test5() {
	b_node* root = NULL;
	root = add_b_node(root, 10);
	root = add_b_node(root, 5);
	root = add_b_node(root, 3);
	if (get_deg(root) == 1) printf("Test 5 passed\n");
	else printf("Test 5 failed\n");
	clear_b(root);
}

int main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	return 0;
}