#include<stdio.h>

int testNum;
int map[1001][1001];
int visit[1001][1001];

struct node {
	int i;
	int j;
};

node que[1000000];
int top = -1;
int m, n;
int x_[4] = { 0,0,1,-1 };
int y_[4] = { 1,-1,0,0 };

void printMap() {
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void printVisit() {
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d ", visit[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}

int main() {
	freopen("test.txt", "r", stdin);
	scanf("%d", &testNum);

	for (int k = 1; k <= testNum; k++) {
		scanf("%d %d", &m, &n);
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%d", &map[i][j]);
				visit[i][j] = 0;
			}
		}
		int cnt = 1;


		top = -1;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] == 0 && visit[i][j] == 0) {
					//printMap();
					que[++top] = { i,j };
					visit[i][j] = 1;
					map[i][j] = ++cnt;
				
					while (top != -1) {
						node N = que[top--];
						
						for (int l = 0; l < 4; l++) {
							int x = N.i + x_[l];
							int y = N.j + y_[l];
							
							if (x<1 || y<1 || x>m || y>m) continue;
							if (map[x][y] == 0 && visit[x][y] == 0) {
								map[x][y] = cnt;
								visit[x][y] = 1;
								que[++top] = { x,y };
							}
						}
					}
				
				
				}
				
				
			}
		}
		printf("#%d ", k);
		for (int l = 0; l < n; l++) {
			node start, end;
			scanf("%d %d %d %d", &start.i, &start.j, &end.i, &end.j);
			if (map[start.i][start.j] == map[end.i][end.j]) printf("%d ", 1);
			else printf("%d ", 0);
		}
		printf("\n");


	}



	return 0;
}
