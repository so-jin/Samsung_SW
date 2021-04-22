#include<stdio.h>

struct Node {
	int x;
	int y;
};

int x_size, y_size;
int arr[102][102];
int xs, ys;
Node queue[10000];
int front = -1;
int rear = -1;
int x_[4] = { 0,0,1,-1 };
int y_[4] = { 1,-1,0,0 };

void printMap() {
	for (int i = 1; i <= y_size; i++) {
		for (int j = 1; j <= x_size; j++) {
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

int die(int x, int y) {
	int day = -1;
	queue[++rear] = { xs,ys };
	arr[ys][xs] = 0;
	while (front != rear) {
		
		day++;
		//printf("%d\n", day);
		//printMap();
		int size = rear - front;
		for (int k = 0; k < size; k++) {
			Node now = queue[++front];
			//printf("die %d %d\n", now.x, now.y);
			for (int i = 0; i < 4; i++) {
				int X = now.x + x_[i];
				int Y = now.y + y_[i];
				if (arr[Y][X] == 1) {
					arr[Y][X] = 0;
					queue[++rear] = { X,Y };
				}
			}
		}

	}
	return day;
}




int main() {
	freopen("die.txt", "r", stdin);
	scanf("%d %d", &x_size, &y_size);
	for (int i = 1; i <= y_size; i++) {
		for (int j = 1; j <= x_size; j++) {
			scanf("%1d", &arr[i][j]);
			//printf("%d", arr[i][j]);
		}
		//printf("\n");
	}
	scanf("%d %d", &xs, &ys);

	printf("%d\n", die(ys, xs)+3);
	int remain = 0;
	for (int i = 1; i <= y_size; i++) {
		for (int j = 1; j <= x_size; j++) {
			if (arr[i][j] == 1) remain++;
		}
	}
	printf("%d\n", remain);
	return 0;
}
