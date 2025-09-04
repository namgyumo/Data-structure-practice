#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct BST {
	long long data;
	long long count;
	struct BST* left;
	struct BST* right;
}BST;

BST* make_BST(long long data) {
	BST* node = (BST*)malloc(sizeof(BST));
	node->data = data;
	node->count = 1;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void insert_node(long long data, BST** head) {
	if ((*head) == NULL) {
		*head = make_BST(data);
		return;
	}
	BST* temp = *head;
	BST* last = NULL;
	while (temp) {
		last = temp;
		if (temp->data > data) {
			temp = temp->left;
		}
		else if (temp->data < data) {
			temp = temp->right;
		}
		else {
			temp->count++;
			return;
		}
	}
	BST* insert = make_BST(data);
	if (last->data > data) {
		last->left = insert;
	}
	else {
		last->right = insert;
	}
}

BST* find_BST(BST* temp, long long data) {
	while (temp) {
		if (temp->data > data) {
			temp = temp->left;
		}
		else if (temp->data < data) {
			temp = temp->right;
		}
		else {
			return temp;
		}
	}
	return NULL;
}

int main() {
	BST* head = NULL;
	long long input;
	srand((unsigned)time(NULL));
	scanf("%lld", &input);

	clock_t start = clock();
	for (long long i = 0; i < input; i++) {
		insert_node(rand() % (input * 2), &head);
	}

	BST* resert = find_BST(head, rand() % (input * 2));
	if (resert == NULL) {
		printf("Not found it...\n");
	}
	else {
		printf("Data : %lld \t Count : %lld\n", resert->data, resert->count);
	}

	double TIME = (double)(clock() - start) * 1000.0 / CLOCKS_PER_SEC;
	printf("TIME : %.2f ms\n", TIME);

	return 0;
}
