#include <stdio.h>


const int INFINITI = 999;
const int VERTEX = 101;
int num, dest;
int sub[101][101];
int D[VERTEX] = { 0, };
bool U[VERTEX] = { false };
int W[VERTEX] = { 0, };
int stack[100];
int top = -1;

int extractMin() {
	int minVertex = 0;
	int minDistance = INFINITI;
	for (int i = 1; i <= num; i++) {
		if (U[i] == false && minDistance > D[i]) {
			minVertex = i;
			minDistance = D[i];
		}
	}
	//printf("min: %d %d\n", minVertex, minDistance);
	return minVertex;
}

void printDistance() {
	for (int i = 0; i < num; i++) {
		printf("%3c ", 'A' + i);
	}
	printf("\n");
	for (int i = 1; i <= num; i++) {
		printf("%3d ", D[i]);
	}
	printf("\n");
}
void printWay() {
	for (int i = 0; i < num; i++) {
		printf("%3c ", '1' + i);
	}
	printf("\n");
	for (int i = 1; i <= num; i++) {
		printf("%3d ", W[i]);
	}
	printf("\n");
}

int dijkstra(int s) {
	U[s] = true;
	for (int v = 1; v <= num; v++) {
		D[v] = sub[s][v];
		W[v] = 1;
	}
	for (int i = 1; i < num; i++) {
		int w = extractMin();
		U[w] = true;
		if (w == dest) {
			return D[dest];
		}

		for (int v = 1; v <= num; v++) {
			if (sub[w][v] != INFINITI && D[v] > D[w] + sub[w][v]) {
				D[v] = D[w] + sub[w][v];
				W[v] = w;
			}
		}
	}
	//return D[num];
}




int main() {
	freopen("sub.txt", "r", stdin);
	scanf("%d %d", &num, &dest);
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			scanf("%d", &sub[i][j]);
		}
	}


	int distance = dijkstra(1);
	printf("%d\n", distance);
	//printDistance();
	//printWay();

	int now = dest;
	while (now != 1) {
		//printf("%d ", W[now]);
		stack[++top] = W[now];
		now = W[now];
	}
//	printf("\n");
	while (top != -1) {
		printf("%d ", stack[top--]);
	}
	printf("%d ", dest);
}

//분할 정복
//계속 작은 거리를 가지는 길을 찾아가기
