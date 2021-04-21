
#include <stdio.h>
//#include <queue>
using namespace std;
struct node {
	int i;
	int j;
};



int row, col;
int box[1000][1000];
//int visit[1000][1000];
//queue<node> que;
node queue[7000000];
int rear = -1;
int front = -1;
int x_[4] = { 0,0,1,-1 };
int y_[4] = { 1,-1,0,0 };
int visit[1000][1000];
int toma_num;
void print_tomato() {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%3d ", box[i][j]);
		}
		printf("\n");
	}
}


int tomato() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (box[i][j] == 1) {
				//  que.push({ i,j });
				queue[++rear] = { i,j };
			}
		}
	}

	int day = -1;
	while (front != rear/*que.size() != 0*/) {
		day++;
		//int num = que.size();
		int num = rear - front;

		//이미 익은 상태
		if (num == row * col) return 0;
		
		for (int k = 0; k < num; k++) {
			//node now = que.front();
			node now = queue[++front];


			for (int i = 0; i < 4; i++) {
				int x = now.i + x_[i];
				int y = now.j + y_[i];

				//bound check
				if (x < 0 || y < 0 || x >= row || y >= col) continue;
				if (box[x][y] == 0) {
					//que.push({ x,y });
					queue[++rear] = { x,y };
					box[x][y] = 1;
				}
			}

		}

	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (box[i][j] == 0) {
				return -1;
			}
		}
	}


	return day;
}



int main() {
	freopen("tomato.txt", "r", stdin);
	scanf("%d %d", &col, &row);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf(" %d", &box[i][j]);
			if (box[i][j] == 0) {
				toma_num++;
			}
		}
	}
	//print_tomato();
	//printf("%d\n", toma_num);
	printf("%d\n", tomato());


	return 0;
}
