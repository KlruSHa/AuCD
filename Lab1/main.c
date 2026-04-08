#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
	int x, val, type;
	b_node* b_root = NULL;

	while(1) {
		printf("\n1. Добавить узел\n");
		printf("2. Вывести дерево\n");
		printf("3. Удалить узел\n");
		printf("4. Определить степень дерева\n");
		printf("0. Выход\n\n");
		printf("===> ");
		scanf("%d", &x);

		switch (x) {
			case 1:
				printf("Тип (1-двоичное, 2-общее): ");
				scanf("%d", &type);
				printf("Значение: ");
				scanf("%d", &val);

				if (type == 1) {
					b_root = add_b_node(b_root, val);
				} else {
					printf("Для общего дерева пока не реализовано\n");
				}
				break;

			case 2:
				printf("Тип (1-двоичное, 2-общее): ");
				scanf("%d", &type);
				if (type == 1) {
					printf("\nДвоичное дерево:\n");
					print_b_tree(b_root, 0);
				} else {
					printf("\nОбщее дерево:\n");
					//print_c_tree(c_root, 0);
				}
				break;

			case 3:
				printf("Тип (1-двоичное, 2-общее): ");
				scanf("%d", &type);
				printf("Что удалить: ");
				scanf("%d", &val);

				if (type == 1) {
					b_root = del_b_node(b_root, val);
				} else {
					printf("Для общего дерева пока не реализовано\n");
				}
				break;

			case 4:
				printf("Тип (1-двоичное, 2-общее): ");
				scanf("%d", &type);
				if (type == 1) {
					printf("Степень двоичного дерева: %d\n", get_deg(b_root));
				} else {
					printf("Для общего дерева пока не реализовано\n");
				}
				break;

			case 0:
				clear_b(b_root);
				printf("\nВы успешно вышли!\n");
				return 0;

			default:
				printf("\nТакой опции нет!\n\n");
		}
	}
	return 0;
}