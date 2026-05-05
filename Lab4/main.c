#include "func.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printInOrder(Node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%s (%d) ", root->key, root->height);
        printInOrder(root->right);
    }
}

int main() {
    Node* root = NULL;
    char command;
    char key[100];
    printf("Commands: i <key> (insert), d <key> (delete), s <key> (search), p (print), q (quit)\n");

    while (1) {
        printf("> ");
        if (scanf(" %c", &command) != 1) break;

        if (command == 'q') break;

        switch (command) {
            case 'i':
                scanf("%s", key);
                if (strlen(key) > 6) {
                    printf("Error: Key too long (max 6 chars)\n");
                } else {
                    root = insert(root, key);
                }
                break;
            case 'd':
                scanf("%s", key);
                root = deleteNode(root, key);
                break;
            case 's':
                scanf("%s", key);
                if (search(root, key)) {
                    printf("Key '%s' found\n", key);
                } else {
                    printf("Key '%s' not found\n", key);
                }
                break;
            case 'p':
                printf("Tree: ");
                printInOrder(root);
                printf("\nHeight: %d\n", height(root));
                break;
            default:
                printf("Unknown command\n");
        }
    }

    freeTree(root);
    return 0;
}
