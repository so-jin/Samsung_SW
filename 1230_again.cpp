#include <stdio.h>

int size;
int miro[10][10];
int x_[4] = { 0,0,1,-1 };
int y_[4] = { 1,-1,0,0 };


struct Node {
	int x;
	int y;
};



void printMiro() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d ", miro[i][j]);
		}
		printf("\n");

	}
}

void go(int nowX, int nowY, int present) {
	printMiro();
	printf("now : %d %d %d\n", nowX, nowY, present);
	printf("\n");
	if (nowX == size - 1 && nowY == size - 1) {
		printf("present %d\n", present);
	}
	for (int i = 0; i < 4; i++) {
		int x = nowX + x_[i];
		int y = nowY + y_[i];
		// out of index
		if (x < 0 || y<0 || x>size || y>size) continue;
		if (miro[x][y] != 1) {
			int tmp = miro[x][y];
			if (miro[x][y] == 2) {
				go(x, y, present + 1);
			}
			else {
				go(x, y, present);
			}
			miro[x][y] = 0;
		}

	}

}






int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			scanf("%d", &miro[i][j]);
		}
	}
	printMiro();
	miro[0][0] = 1;
	go(0, 0, 0);


	return 0;
}
