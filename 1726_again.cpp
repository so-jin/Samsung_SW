#include <stdio.h>
int node_num, query_num, start, end;
int node[500001] = { 0 ,};
struct Node {
	int max;
	int left;
	int right;
};

Node* tree[100002] = { nullptr, };

Node* postorder(int index) {
	//printf("postorder %d\n", index);
	if (index >= node_num && index < 2 * node_num) {
		tree[index]->max = node[index - node_num+1];
		printf("node %d %d\n", index, tree[index]);
		tree[index]->left = index;
		tree[index]->right = index;
		
		return tree[index];
	}
	else {
		Node* left = postorder(index<<1);
		Node* right = postorder((index << 1) | 1);
		tree[index]->max = left->max > right->max ? left->max : right->max;
		tree[index]->left = left->left;
		tree[index]->right = right->right;
		printf("%d \n", index);
		return tree[index];
	}

}


int getMax(int start, int end, int index) {
	int right = tree[index]->right;
	int left = tree[index]->left;
	if (right < start) return 0;
	//탐색 필요 x

}

int main() {
	printf("start");
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &node_num, &query_num);
	
	for (int i = 1; i <= node_num; i++) {
		scanf("%d", &node[i]);
		//printf("%d %d\n", i, node_num);

	}

	postorder(1);

	for (int i = 1; i < (node_num << 1); i++) {
		//printf("%d\n", tree[i]);
	}

	for (int i = 0; i < query_num; i++) {
		scanf("%d %d", &start, &end);
		//printf("%d %d\n", start, end);

		getMax(int start, int end);


	}


	
	return 0;
}
