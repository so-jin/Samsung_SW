#include <iostream>
#include <stdio.h>
using namespace std;

int m, n,row,col,max_val;
char arr[20][20];
int visit[128];



void find(int m, int n,int count) {
	//out of index
	if (m < 0 || n < 0 || m >= row || n >= col) return;
	if (count > max_val) max_val = count;
	if (visit[arr[m][n]] == 0) {
		visit[arr[m][n]] = 1;
		find(m - 1, n,count+1);
		find(m, n - 1,count+1);
		find(m + 1, n,count+1);
		find(m, n + 1,count+1);
		visit[arr[m][n]] = 0;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d",&row,&col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf(" %c", &arr[i][j]);

		}
	}
	find(0, 0, 0);
	printf("%d", max_val);
	return 0;
}
