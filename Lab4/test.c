#include "func.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int isBalanced(Node* root) {
    if (root == NULL) return 1;
    int balance = getBalance(root);
    if (balance < -1 || balance > 1) return 0;
    return isBalanced(root->left) && isBalanced(root->right);
}

void test_insertion_and_balancing() {
    Node* root = NULL;
    root = insert(root, "bbbb");
    root = insert(root, "aaaa");
    root = insert(root, "cccc");
    assert(isBalanced(root));
    assert(strcmp(root->key, "bbbb") == 0);
    
    root = insert(root, "dddd");
    root = insert(root, "eeee");
    assert(isBalanced(root));
    freeTree(root);
    printf("test_insertion_and_balancing passed!\n");
}

void test_search_functionality() {
    Node* root = NULL;
    root = insert(root, "apple");
    root = insert(root, "banana");
    root = insert(root, "cherry");
    assert(search(root, "apple") != NULL);
    assert(search(root, "banana") != NULL);
    assert(search(root, "cherry") != NULL);
    assert(search(root, "date") == NULL);
    freeTree(root);
    printf("test_search_functionality passed!\n");
}

void test_deletion_leaf() {
    Node* root = NULL;
    root = insert(root, "m");
    root = insert(root, "a");
    root = insert(root, "z");
    root = deleteNode(root, "a");
    assert(search(root, "a") == NULL);
    assert(isBalanced(root));
    freeTree(root);
    printf("test_deletion_leaf passed!\n");
}

void test_deletion_single_child() {
    Node* root = NULL;
    root = insert(root, "m");
    root = insert(root, "f");
    root = insert(root, "p");
    root = insert(root, "c");
    root = deleteNode(root, "f");
    assert(search(root, "f") == NULL);
    assert(strcmp(root->left->key, "c") == 0);
    assert(isBalanced(root));
    freeTree(root);
    printf("test_deletion_single_child passed!\n");
}

void test_deletion_two_children() {
    Node* root = NULL;
    root = insert(root, "m");
    root = insert(root, "f");
    root = insert(root, "p");
    root = insert(root, "c");
    root = insert(root, "h");
    root = deleteNode(root, "f");
    assert(search(root, "f") == NULL);
    assert(isBalanced(root));
    freeTree(root);
    printf("test_deletion_two_children passed!\n");
}

int main() {
    test_insertion_and_balancing();
    test_search_functionality();
    test_deletion_leaf();
    test_deletion_single_child();
    test_deletion_two_children();
    printf("\nAll tests passed!\n");
    return 0;
}
