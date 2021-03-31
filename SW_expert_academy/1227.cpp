#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;
typedef struct node {
	int m;
	int n;
}node;

int arr[100][100];
int success;
int start_i, start_j, end_i, end_j;
stack<node> st;

void findway(int visit[100][100]) {

	while (st.size()!=0) {
		node now = st.top();
		int m = now.m;
		int n = now.n;
		st.pop();

		//already visit
		if (visit[m][n] == 0) {
			//visit
			//printf("visit: %d %d \n", m, n);
			visit[m][n] = 1;
			if (now.m == end_i && now.n == end_j) {
				printf("1\n");
				while (!st.empty()) {
					st.pop();
				}
				return;
			}
			if (arr[m - 1][n] != 1 && visit[m - 1][n] == 0) st.push({ m - 1,n });
			if (arr[m][n - 1] != 1 && visit[m][n - 1] == 0) st.push({ m,n - 1 });
			if (arr[m + 1][n] != 1 && visit[m + 1][n] == 0) st.push({ m + 1,n });
			if (arr[m][n + 1] != 1 && visit[m][n + 1] == 0) st.push({ m,n + 1 });
		}
	}
	printf("0\n");
}


int main() {
	char ch;
	int num;
	freopen("miro.txt", "r", stdin);
	for (int k = 0; k < 10; k++) {
		int visit[100][100] = { 0, };

		scanf("%d", &num);
		//scan
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				scanf(" %c", &ch);
				arr[i][j] = ch - '0';
				//printf("%d", arr[i][j]);
				if (arr[i][j] == 2) {
					start_i = i;
					start_j = j;
					//printf("start : %d %d \n", start_i, start_j);
				}
				if (arr[i][j] == 3) {
					end_i = i;
					end_j = j;
					//printf("end: %d %d\n", end_i, end_j);
				}
			}
			//printf("\n");
		}
		printf("#%d ", k + 1);
		//find way
		st.push({ start_i,start_j });
		findway(visit);

	}

	return 0;
}
