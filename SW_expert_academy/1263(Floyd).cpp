#include <iostream>
#include <stdio.h>
const int MAX = 1001;
int test_num, node_num;
//ar D[MAX][MAX];
int D[MAX][MAX];
//int connect[MAX];
using namespace std;

void AllPairsShortest(int node_num) {
	for (int k = 1; k <= node_num; k++) {
		for (int i = 1; i <= node_num; i++) {
			for (int j = 1; j <= node_num; j++) {
				if (i == k || j == k || i == j) continue;
				D[i][j] = D[i][k] + D[k][j] < D[i][j] ? D[i][k] + D[k][j] : D[i][j];
			}
		}
	}
}

int getMinNode() {
	int min = 9999;
	int sum;

	for (int i = 1; i <= node_num; i++) {
		sum = 0;
		for (int j = 1; j <= node_num; j++) {
			if (i == j)continue;
			sum += D[i][j];
		}
		if (min > sum) min = sum;
	}
	return min;
}
int main() {
	//printf("HI\n");
	freopen("input.txt", "r", stdin);
	scanf("%d", &test_num);
	for (int k = 0; k < test_num; k++) {
		scanf("%d", &node_num);
		for (int i = 1; i <= node_num; i++) {
			for (int j = 1; j <= node_num; j++) {
				scanf(" %d", &D[i][j]);
				if (D[i][j] == 0) D[i][j] = 9999;
			}
		}
		AllPairsShortest(node_num);

		
		
		printf("#%d %d\n",k+1, getMinNode());
		//printf("fin\n");
	}
	//scanf("%d", &test_num);
	//system("pause");

	return 0;
}
