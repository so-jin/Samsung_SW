#include <stdio.h>
#include <queue>
#include <iostream>
//#include <stack>
using namespace std;

struct Vertex {
	int x;
	int y;
};

queue<Vertex> que;
char tmp;
int test_num, road_size;
const int INFINIT = 999;
const int SIZE = 100000;
int road[101][101];
int D[101][101];
int x_[4] = { 0,0,1,-1 };
int y_[4] = { 1,-1,0,0 };
Vertex q[SIZE] = {};

void print_distance() {
	for (int i = 1; i < road_size; i++) {
		for (int j = 1; j < road_size; j++) {
			printf("%d", D[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

Vertex shortest_BFS() {
	//find smallest way
	//que.push({ 1,1 });
	int front = -1; 
	int rear = -1;
	q[++rear] = { 1,1 };

	while (rear != front) {
		//Vertex v = que.front();
		//que.pop();
		Vertex v = q[(++front)%SIZE];
		int x = v.x;
		int y = v.y;


		if (x == road_size && y == road_size) {
			return v;
		}

		for (int i = 0; i < 4; i++) {
			// 인접한 것 들 중에서
			int X = x + x_[i];
			int Y = y + y_[i];
			if (X >0 && X <= road_size && Y > 0 && Y <= road_size) {
				if (D[X][Y] > D[x][y] + road[X][Y]) {
					//printf("new distance %d %d\n", D[X][Y], D[x][y] + road[X][Y]);
					D[X][Y] = D[x][y] + road[X][Y];
					//printf("X%d Y%d x%d y%d %d = %d+%d\n", X, Y,x,y, D[X][Y], D[x][y], road[X][Y]);
					//print_distance();
					q[(++rear)%SIZE] = { X,Y };
					//que.push({ X, Y });
				}
			}
		}
		
	}
	return {0,0};
}


int main(){
	freopen("road.txt", "r", stdin);
	scanf("%d", &test_num);


	for (int k = 0; k < 10; k++) {
		scanf("%d", &road_size);
		for (int i = 1; i <= road_size; i++) {
			for (int j = 1; j <= road_size; j++) {
				scanf(" %c", &tmp);
				D[i][j] = INFINIT;
				road[i][j] = tmp-'0';
				//printf("%d", road[i][j]);
			}
			//printf("\n");
		}
		D[1][1] = 0;
		Vertex v = shortest_BFS();
		
	
		printf("#%d %d\n", k + 1, D[road_size][road_size]);
	}


	return 0;

}
