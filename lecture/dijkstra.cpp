#include <iostream>

using namespace std;

const int VERTEX = 10;
const int INFINITI = 999;

int A[VERTEX][VERTEX] = { 0, };	//인접 행렬
int D[VERTEX] = { 0, };			//거리 갱신
bool U[VERTEX] = { false };		//선택정점 집합
int V;							//정점의 총수

int extractMin() {
	//선택되지 않은 정점 중에서 거리가 최소인 정점의 번호를 return
	int minVertex = 0;
	int minDistance = INFINITI;

	for (int i = 1; i <= V; i++) {
		if (U[i] == false && minDistance > D[i]) {
			minVertex = i;
			minDistance = D[i];
		}
	}
	return minVertex;
}
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

//O(V^2)
int dijkstra(int s) {
	U[s] = true;
	for (int v = 1; v <= V; v++) {
		D[v] = A[s][v];
	}

	//D[s] = 0;		//지금은 출발정점의 가중치가 0으로 되어 있어 안해도 된다.

	for (int i = 1; i < V; i++) {
		int w = extractMin();	// w선택
		U[w] = true;
		//인접한 모든 정점
		for (int v = 1; v <= V; v++) {
			if (A[w][v] != INFINITI && D[v] > D[w] + A[w][v]) {
				D[v] = D[w] + A[w][v];
			}
		}
	}

	return D[V];
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
	
	int distance = dijkstra(1);
	cout << "최단거리 : " << distance << endl;

	printDistance();
	return 0;

}
