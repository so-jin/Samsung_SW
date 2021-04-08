#include <iostream>

using namespace std;

const int VERTEX = 10;
const int INFINITI = 999;

int A[VERTEX][VERTEX] = { 0, };	//인접 행렬
int D[VERTEX] = { 0, };			//거리 갱신
//bool U[VERTEX] = { false };		//선택정점 집합
int V;							//정점의 총수


void printDistance() {
	for (int i = 0; i < V; i++) {
		printf("%3c ", 'A' + i);
	}
	printf("\n");

	for (int i = 1; i <= V; i++) {
		printf("%3d ", D[i]);
	}

	printf("\n");
}

int shortest_BFS(int s) {

	int q[100] = { 0, };
	int front = -1;
	int rear = -1;

	for (int v = 1; v <= V; v++) {
		D[v] = INFINITI;
	}

	D[s] = 0;		//지금은 출발정점의 가중치가 0으로 되어 있어 안해도 된다.


	q[++rear] = s;
	while(front != rear) {
		int w = q[++front];	// w선택

		if (w == V) return D[V];
		
		for (int v = 1; v <= V; v++) {
			if (A[w][v] != INFINITI && D[v] > D[w] + A[w][v]) {
				D[v] = D[w] + A[w][v];
				q[++rear] = v;		//enqueue
			}
		}
	}
	//while loop를 빠져나왔다는 것은 길이 없다는 것
	return -1;
}


int main() {
	freopen("dijkstra.txt", "r", stdin);
	cin >> V;
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			cin >> A[i][j];
			if (i != j && A[i][j] == 0) {
				A[i][j] = INFINITI;
				//printf("%d %d %d\n", i, j, A[i][j]);
			}
		}
	}

	int distance = shortest_BFS(1);
	cout << "최단거리 : " << distance << endl;

	printDistance();
	return 0;

}
