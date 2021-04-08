#include <iostream>

using namespace std;

const int VERTEX = 10;
const int INFINITI = 999;

int A[VERTEX][VERTEX] = { 0, };	//인접 행렬
int D[VERTEX] = { 0, };			//거리 갱신
bool U[VERTEX] = { false };		//선택정점 집합
int V;							//정점의 총수




const int HEAP_SIZE = 50;

int heap[HEAP_SIZE] = { 0, };
int heapCount = 0;

void push(int value) {
	heap[++heapCount] = value;

	int child = heapCount;
	int parent = child >> 1;
	while (parent > 0 && heap[parent] > heap[child]) {
		int tmp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = tmp;

		child = parent;
		parent = child >> 1;
	}
}
//PQ로 운영하는 경우 extractMin(), extractMax()이름을 사용함.
int pop() {
	int parent = 1;	//root
	int ret = heap[parent];
	heap[parent] = heap[heapCount];
	heap[heapCount--] = 0;
	int child = 2 * parent;	//left child
	//right child is exist
	if (child + 1 <= heapCount) {
		child = (heap[child] < heap[child + 1]) ? child : child + 1;

	}
	//위치 바꾸기
	while (child <= heapCount && heap[parent] > heap[child]) {
		int tmp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = tmp;

		parent = child;
		child = parent << 1;
		if (child + 1 <= heapCount) {
			child = (heap[child] < heap[child + 1]) ? child : child + 1;

		}
	}
	return ret;
}









int dijkstra(int s) {
	//U[s] = true;
	//for (int v = 1; v < V; v++) {
	//	D[v] = A[s][v];
	//}

	D[s] = 0;		//지금은 출발정점의 가중치가 0으로 되어 있어 안해도 된다.
	push(s);

	//empty가 아닌 동안
	while(heapCount>0) {
		int w = pop();	// w선택
		U[w] = true;

		//인접한 모든 정점
		for (int v = 1; v <= V; v++) {
			if (A[w][v] != INFINITI && D[v] > D[w] + A[w][v]) {
				D[v] = D[w] + A[w][v];
				push(v);
			}
		}
	}
	return D[V];
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

int main() {
	freopen("dijkstra.txt", "r", stdin);
	cin >> V;
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			cin >> A[i][j];
			if (i != j && A[i][j] == 0) {
				A[i][j] = INFINITI;
			}

		}
		//초기화

		D[i] = INFINITI;
		U[i] = false;

	}
	int distance = dijkstra(1);
	cout << "최단거리 : " << distance << endl;

	printDistance();
	return 0;

}
