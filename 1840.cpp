#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
typedef struct node {
	int m;
	int n;
}node;

int m, n, row, col, last_size;
int arr[100][100];
int visit[100][100];
queue<node> que;


int check(int i, int j) {
	//out of index
	if (i == 0 || j == 0 || i == row || j == col) return 1;
	//exposed
	if (arr[i - 1][j] == 0 || arr[i][j - 1] == 0 || arr[i + 1][j] == 0 || arr[i][j + 1] == 0) return 1;
	return 0;
}


void init() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == 1 && check(i, j) == 1) {
				que.push({ i,j });
			}
		}
	}
}

void next(int i, int j) {
	//melting
	if (i - 1 >= 0 && arr[i - 1][j] == 1) que.push({ i - 1,j });
	if (j - 1 >= 0 && arr[i][j - 1] == 1) que.push({ i,j - 1 });
	if (i + 1 < row && arr[i + 1][j] == 1) que.push({ i + 1,j });
	if (j + 1 < col && arr[i][j + 1] == 1) que.push({ i,j + 1 });
}

void melt(int time) {
	if (que.size() == 0) {
		printf("%d\n%d", time - 1, last_size);
		return;
	}
	//for one hour
	int size = que.size();
	int count = 0;
	for (int i = 0; i < size; i++) {
		node n = que.front();
		que.pop();

		if (arr[n.m][n.n] == 1) {
			arr[n.m][n.n] = 0;
			printf("time: %d, %d %d\n", time, n.m, n.n);
			next(n.m, n.n);
			count++;
		}
	}

	last_size = count;
	melt(time + 1);
}


void melting(int m, int n) {
	que.push({ m,n });

	while (que.size()) {
		node now = que.front();
		int m = now.m;
		int n = now.n;
		if (visit[m][n] == 0) {
			visit[m][n] = 1;
			//find next
			if (m - 1 >= 0 && arr[m - 1][n] == 0 && visit[m - 1][n] == 0) que.push({ m - 1,n });
			if (n - 1 >= 0 && arr[m][n - 1] == 0 && visit[m][n - 1] == 0) que.push({ m,n - 1 });
			if (m + 1 < row && arr[m + 1][n] == 0 && visit[m + 1][n] == 0) que.push({ m + 1,n });
			if (n + 1 < col && arr[m][n + 1] == 0 && visit[m][n + 1] == 0) que.push({ m,n + 1 });
		}
	}
}



int main() {

	freopen("input.txt", "r", stdin);
	scanf("%d %d", &row, &col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf(" %d", &arr[i][j]);
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	init();
	melt(0);
	return 0;
}
