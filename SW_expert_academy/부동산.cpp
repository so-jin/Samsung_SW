#include<stdio.h>

struct Node {
	int size;
	int cnt;
}dp[301][301];

int testNum;
int land[301][301];
//Node dp[301][301];
Node result[301][301];
int m, n;
int sPrice;
Node found;



Node cal() {
	Node max = { 0,0 };
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			//init
			for (int r = i; r <= m; r++) {
				dp[r][j-1].size = 0;
			}
			for (int c = j; c <= n; c++) {
				dp[i-1][c].size = 0;
			}
			for (int r = i; r <= m; r++) {
				for (int c = j; c <= n; c++) {
					dp[r][c].size = dp[r - 1][c].size + dp[r][c - 1].size -dp[r-1][c-1].size+ land[r][c];
					if (dp[r][c].size > max.size ) {
						dp[r][c].cnt = (r - i + 1) * (c - j + 1);
						max = dp[r][c];
					}
				}
			}
			result[i][j] = max;

		}
	}
	return max;
}



int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &testNum);
	for (int k = 1; k <= testNum; k++) {
		scanf("%d %d %d", &m, &n, &sPrice);

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &land[i][j]);
				land[i][j] -= sPrice;
			}
		}
		Node re = cal();
	
		printf("#%d %d %d\n", k, re.size, re.cnt * sPrice );

	}



	return 0;
}

