#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};

Node *root = nullptr;
Node *makeNode(int value) {
	Node *newNode = new Node;
	if (newNode != nullptr) {
		newNode->data = value;
		newNode->left = nullptr;
		newNode->right = nullptr;
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

void printTree(Node *node, int level, int depth) {
	if (node == nullptr) {
		return;
	}
	if (level < depth) return;
	printTree(node->left, level, depth + 1);
	printTree(node->right, level, depth + 1);
	if (level == depth) printf("%d ", node->data);

	return;
}
void printBST(Node *node) {
	const int depth = 5;
	for (int i = 0; i < depth; i++) {
		printTree(node, i, 0);
		cout << endl;

	}
	cout << endl;
}

Node *insertBST(Node *node, int value)
{
	//삽입하고자 하는 노드로 탐색하고 탐색 실패 위치에 추가한다.
	if (node == nullptr) {
		Node *newNode = makeNode(value);
		return newNode;
	}
	if (node->data < value) {
		node->right = insertBST(node->right, value);
	}
	else if(node->data > value){
		node->left = insertBST(node->left, value);
	}
	//중복되는 경우.. 중복 허용 X
	else {
		cout << "Duplicate Key\n";
	}
	return node;
}

Node *findMostBiggestNode(Node *node) {
	while (node->right != nullptr) {
		node = node->right;
	}
	return node;
}

Node *deleteBST(Node *node, int value) {
	if (node == nullptr) return nullptr;
	if (node->data < value) {
		node->right = deleteBST(node->right, value);
	}
	else if (node->data > value) {
		node->left = deleteBST(node->left, value);
	}
	else if (node->data == value) {
		//삭제 대상 노드 찾음
		//degree가 2
		if (node->left != nullptr && node->right != nullptr) {
			Node * replaceNode = findMostBiggestNode(node->left);
			node->data = replaceNode->data;
			node->left = deleteBST(node->left, replaceNode->data);

		}
		//Degree 1 or 0
		else {
			// node backup
			Node *delNode = node;

			node = node->left;

			//left가 없으면
			if (node == nullptr) {
				node = delNode->right;
			}

			delete delNode;
		}
		
	}
	return node;
}
int main() {
	root = insertBST(root, 9);
	root = insertBST(root, 4);
	root = insertBST(root, 12);
	root = insertBST(root, 15);
	root = insertBST(root, 6);
	root = insertBST(root, 3);
	root = insertBST(root, 13);
	root = insertBST(root, 17);

	Node *node = searchBST(root, 6);
	if (node != nullptr)
	{
		printf("0x%p = %d\n", node, node->data);
	}
	else {
		printf("Not found \n");
	}
	
	printBST(root);
	root = insertBST(root, 5);	//insert 다시보기
	printBST(root);				// 다시보기

	root = deleteBST(root, 13);
	printBST(root);

	root = deleteBST(root, 12);
	printBST(root);

	root = deleteBST(root, 9);
	printBST(root);
	return 0;
}
