#include <stdio.h>
int row, col, num;
int area[100][100];
int left_x, left_y, right_x, right_y;
int x_[4] = { 0,0,1,-1 };
int y_[4] = { 1,-1,0,0 };
int box[20];

struct Node {
	int x;
	int y;
};

Node stack[10000]; 
int top = -1;

void printArea() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d ", area[i][j]);
		}
		printf("\n");
	}
}



int findSet(int start_y, int start_x) {
	int size = 0;
	stack[++top] = { start_x, start_y };

	while (top != -1) {
		Node node = stack[top--];
		
		if (area[node.y][node.x] == 0) {
			area[node.y][node.x] = 1;
			size++;
			for (int i = 0; i < 4; i++) {
				int x = node.x + x_[i];
				int y = node.y + y_[i];
				if (x < 0 || y < 0 || x >= col || y >= row) continue;
				if (area[y][x] == 0) {
					stack[++top] = { x,y };
				}
			}
		}
	}
	return size;
}


int main() {
	freopen("sub.txt", "r", stdin);
	scanf("%d %d %d", &row, &col, &num);
	for (int i = 0; i < num; i++) {
		scanf("%d %d %d %d", &left_x, &left_y, &right_x, &right_y);

		for (int m = left_x; m < right_x; m++) {
			for (int n = left_y; n < right_y; n++) {
				area[n][m] = 1;
			}
		}
	}

	//printArea();
	int boxCount = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (area[i][j] == 0) {
				//printf("%d\n", findSet(i, j));
				box[boxCount++] = findSet(i, j);
			}
		}
	}
	for (int i = boxCount - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (box[j] > box[j + 1]) {
				int tmp = box[j];
				box[j] = box[j + 1];
				box[j + 1] = tmp;
			}
		}
	}
	printf("%d\n", boxCount);
	for (int i = 0; i < boxCount; i++) {
		printf("%d ", box[i]);
	}
	printf("\n");
	//printArea();

}
