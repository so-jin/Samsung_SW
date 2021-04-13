#include <iostream>
#include <stdio.h>
const int MAX = 1001;
int test_num, node_num;
//ar D[MAX][MAX];
int child[201];
//int connect[MAX];
using namespace std;

int findLis() {
	int *d = new int[test_num + 1];
	int LIS_len = 0, LIS_idx = 0;
	for (int i = 1; i <= test_num; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) {
			if (d[j] + 1 > d[i] && child[j] < child[i]) {
				d[i] = d[j] + 1;
			}
		}
		if (LIS_len < d[i]) {
			LIS_len = d[i];
			LIS_idx = i;
		}
	}
	return LIS_len;
}

int main() {
	//printf("HI\n");
	freopen("input.txt", "r", stdin);
	scanf("%d", &test_num);
	for (int k = 1; k <= test_num; k++) {
		scanf("%d", &child[k]);
	}
	
	printf("%d\n", test_num - findLis());

		
	return 0;
}
