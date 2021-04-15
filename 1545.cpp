#include<iostream>

int size;
int W[20][20];
int D[20][524288];
//calculate minimun
int minimun(int start, int flag) {
	int index = 1;
	int min = 2000;
	while (index < flag) {
		if (flag & index) {
			W[start][index] + D[index][flag & (~index)];
		}
		index = index >> 1;
	}
}

int travel(int flag) {
	for (int i = 2; i <= size; i++) {
		D[i][0] = W[i][1];
	}



	for (int k = 1; k <= size; k++) {
		for (int) {
			for () {

				D[i][flag] = minimun(i, flag);
			}
		}
	}
	return 0;
}
void printDist() {
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			printf("%d ", W[i][j]);
		}
		printf("\n");
	}
}
int main() {
	freopen("map.txt", "r", stdin);
	scanf("%d", &size);
	//printf("%d", size);
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			scanf("%d", &W[i][j]);
		}
	}
	travel();
	printDist();
}
