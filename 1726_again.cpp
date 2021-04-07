#include <stdio.h>
int node_num, query_num, start, end;
int node[500001] = { 0 , };
struct Node {
	int max;
	int left;
	int right;
};

Node* tree[100002] = { nullptr, };

Node* postorder(int index) {
	//printf("postorder %d\n", index);
	if (index >= node_num && index < 2 * node_num) {
		Node *newNode = new Node;
		tree[index] = newNode;
		tree[index]->max = node[index - node_num + 1];
		printf("node %d %d\n", index, tree[index]);
		tree[index]->left = index;
		tree[index]->right = index;

		return tree[index];
	}
	else {
		Node* left = postorder(index << 1);
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
	//start, end가 같거나 더 넓으면
	if (start <= left && right <= end) {
		return tree[index]->max;
	}
	//left, right이 더 클 때
	/*else if (start > left && right > end) {
		//max 찾는과정 필요
		int l = getMax(start, end, (index >> 1));
		int r = getMax(start, end, (index >> 1) | 1);
		int result = l > r ? l : r;

	}*/
	else if (right < start || left >end) {
		return 0;
	}
	//일부만 겹칠 때
	else {
		int l = getMax(start, end, (index >> 1));
		int r = getMax(start, end, (index >> 1) | 1);
		int result = l > r ? l : r;

	}
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

		printf("%d\n",getMax(start, end,1));


	}



	return 0;
}
