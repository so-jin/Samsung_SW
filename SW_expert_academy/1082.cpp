#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;
int row, col;
char in;
char map[51][51];
int way[51][51];
int fireMap[51][51];
struct Node {
	int i;
	int j;
};
Node start;
Node home;
int minTime = 9999;
int d[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };


void printMap() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void printWay() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d ", way[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


int DFS(Node now, int time, queue<Node> fire) {
	if (time >= minTime) return 0;
	//make fire
/*

	int size = fire.size();
	for (int i = 0; i < size; i++) {
		Node nowFire = fire.front();
		fire.pop();
		for (int k = 0; k < 4; k++) {
			int r = nowFire.i + d[k][0];
			int c = nowFire.j + d[k][1];
			if (r < 0 || c < 0 || r >= row || c >= col) continue;
			if (map[r][c] != '*' && map[r][c] != 'D' && map[r][c] !='X' && map[r][c] !='W') {
				map[r][c] = '*';
				fire.push({ r,c });
			}
		}
	}



*/


	//make way	
//	if (now.j == home.j && now.i == home.i) {
	//	sif (time < minTime) minTime = time;
		//return minTime;
	//}


	for (int k = 0; k < 4; k++) {
		int r = now.i + d[k][0];
		int c = now.j + d[k][1];
		if (r<0 || c<0 || c>=col || r>=row || way[r][c] == 'X' || way[r][c] == 1) continue;
		else if (map[r][c] == 'D') {
			minTime = time + 1;
			printf("home: %d\n", time + 1);
		}
		else{
			way[r][c] = 1;
			printMap();
			printWay();
			DFS({ r,c}, time + 1, fire);
			way[r][c] = 0;
		}
	}
	return minTime;
}






int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &row, &col);
	queue<Node> fire;
	int firecnt = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'S') {
				start.i = i;
				start.j = j;
				way[i][j] = 1;
				printf("start: %d %d\n", i, j);
			}
			else if (map[i][j] == 'D'){
				home.i = i;
				home.j = j;
				printf("home: %d %d\n", i, j);

			}
			else if (map[i][j] == '*') {
				fire.push({ i,j });
				fireMap[i][j] = 1;
				firecnt++;
			}
		}
	}
	// *을 다 돌면서 불이 번지는 과정을 미리 저장해 둔다. 
	// 불이 시간에 따라 번져가는 것을 확인

	int size = firecnt;
	for (int i = 0; i < size; i++) {
		Node nowFire = fire.front();
		fire.pop();
		for (int k = 0; k < 4; k++) {
			int r = nowFire.i + d[k][0];
			int c = nowFire.j + d[k][1];
			if (r < 0 || c < 0 || r >= row || c >= col) continue;
			if (map[r][c] != '*' && map[r][c] != 'D' && map[r][c] != 'X') {
				fireMap = day;
				fire.push({ r,c });
			}
		}
	}


	printf("%d\n", DFS(start, 0, fire));



	return 0;
}
