#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

struct Node {
	int data;
	char *origin;
	Node *left;
	Node *right;
};

Node *root = nullptr;
Node *makeNode(int value, char * origin) {
	Node *newNode = new Node;
	if (newNode != nullptr) {
		newNode->data = value;
		newNode->left = nullptr;
		newNode->right = nullptr;
		newNode->origin = origin;
	}
	return newNode;
}

Node * searchBST(Node *node, int key) {
	if (node == nullptr) return nullptr;

	if (node->data == key) {
		return node;
	}
	else if (node->data > key) {
		return searchBST(node->left, key);
	}
	else
		return searchBST(node->right, key);
	return node;
}

Node *insertBST(Node *node, int value, char * origin)
{
	//삽입하고자 하는 노드로 탐색하고 탐색 실패 위치에 추가한다.
	if (node == nullptr) {
		Node *newNode = makeNode(value, origin);
		return newNode;
	}
	if (node->data < value) {
		node->right = insertBST(node->right, value, origin);
	}
	else if (node->data > value) {
		node->left = insertBST(node->left, value,origin);
	}
	//중복되는 경우.. 중복 허용 X
	else {
		//cout << "Duplicate Key\n";
	}
	return node;
}



unsigned hash_fun(char a[]) {
	int i = 0, k = 1;
	int hashcode = 0;

	for (int j = 0; j < strlen(a); j++) {
		int tmp = (a[j]);
		tmp *= k;
		k *= 3;
		hashcode += tmp;
		
	}
	return hashcode;
}

int size_, a_size, b_size;
char* pointer[100000];
unsigned hashA[100000] = { 0, };
unsigned hashB[100000] = { 0, };
char a[100000][50];
char b[100000][50];

int main() {
	freopen("sample.txt", "r", stdin);
	scanf("%d", &size_);
	//printf("%d\n", size_);
	for (int i = 0; i < size_; i++) {
		int same_count = 0;
		Node *root = nullptr;
		scanf("%d %d ", &a_size, &b_size);

//		char a[50] = { 0, };
	//	char b[50] = { 0, };

		for (int j = 0; j < a_size; j++) {
			scanf(" %s", a[j]);
			//printf("hashA: %d\n", hash_fun(a));
			hashA[j] = hash_fun(a[j]);
			root = insertBST(root, hashA[j], a[j]);
			//원본 데이터 넣어주기

		}

		for (int j = 0; j < b_size; j++) {
			scanf(" %s", b[j]);
			//printf(" %s", b);
			//printf("hashB: %d\n", hash_fun(b));
			hashB[j] = hash_fun(b[j]);
			Node * found = searchBST(root, hashB[j]);
			if (found != nullptr && strcmp(found->origin, b[j])==0) {
				same_count++;
			}
		}


		printf("#%d %d\n", i + 1, same_count);
	}



	return 0;
}
