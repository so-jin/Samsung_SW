#include <iostream>
using namespace std;
const int TREE_SIZE = 50;

int tree[TREE_SIZE] = { 0, };
int V, E;

int findNode(int node) {
	for (int i = 1; i < TREE_SIZE; i++) {
		if (tree[i] == node) return i;
	}
	return -1;
}

void preorder(int node) {
	if (node < 1 || node >= TREE_SIZE) return;
	if (tree[node] == 0) return;
	cout << tree[node] << " ";	//V
	preorder(node << 1);		//L
	preorder(node << 1 | 1);	//R
}
void inorder(int node) {
	if (node < 1 || node >= TREE_SIZE) return;
	if (tree[node] == 0) return;
	inorder(node << 1);		//L
	cout << tree[node] << " ";	//V
	inorder(node << 1 | 1);	//R
}

void postorder(int node) {
	if (node < 1 || node >= TREE_SIZE) return;
	if (tree[node] == 0) return;
	postorder(node << 1);		//L
	postorder(node << 1 | 1);	//R
	cout << tree[node] << " ";	//V

}
void levelorder(int node) {
	int pow2[] = { 1,2,4,8,16,32,64 };
	int nextLevel = 1;
	for (int i = 1; i < TREE_SIZE; i++) {
		//한 줄마다 개행 찍기
		if (i == pow2[nextLevel]) {
			cout << endl;
			nextLevel++;
		}
		//완전 이진트리가 아님
		if (tree[i]) {
			cout << tree[i] << " ";
		}

	}
	cout << endl;
}


int main() {
	freopen("tree.txt", "r", stdin);
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int parent, child;
		cin >> parent >> child;

		int pIdx = findNode(parent);
		if (pIdx < 1) {
			pIdx = 1;	//root
			tree[pIdx] = parent;
		}
		//no left child
		if (tree[2 * pIdx] == 0) {
			tree[2 * pIdx] = child;
		}
		else
			tree[2 * pIdx + 1] = child;
	}
	cout << "전위순회 : ";
	preorder(1);
	cout << endl;
	cout << "중위순회 : ";
	inorder(1);
	cout << endl;
	cout << "후위순회 : ";
	postorder(1);
	cout << endl;

	cout << "Level 순회 : \n";
	levelorder(1);
	cout << endl;
	return 0;

}
