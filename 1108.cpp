#include <iostream>
using namespace std;
const int INFINITI = 999;
int num,k;
int graph[501][501];
int map[501][501];
bool visit[501];
int start, fin;

int getMin(int start) {
	int minVertex = start;
	int minDistance = INFINITI;

	for (int i = 1; i <= num; i++) {
		if (visit[i] == false && minDistance > map[start][i]) {
			minVertex = i;
			minDistance = map[start][i];
		}
	}
	return minVertex;
}

int dijkstra(int s) {
	visit[s] = true;
	for (int i = 1; i <= num; i++) {
		//map[s][i] = graph[s][i];
	}
	for (int i = 1; i < num; i++) {
		int v = getMin(s);
		visit[v] = true;
		//printf("getmin %d \n",v);
		for (int j = 1; j <= num; j++) {
			if (map[s][j] != INFINITI && map[s][j] > map[s][v] + map[v][j]) {
				//printf("update");
				map[s][j] = map[s][v] + map[v][j];
			}
		}
	}
	return map[s][num];

}
void printDistance() {
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			printf("%3d ", map[i][j]);
		}
		printf("\n");
	}
}
void printGraph() {
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			printf("%3d ", graph[i][j]);
		}
		printf("\n");
	}
}


int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &k);
	num = 0;
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &start, &fin);
		map[start][fin] = 1;
		int size_ = start > fin ? start : fin;
		if (size_ > num) num = size_;
	}

	//preprosesor
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			// no way
			if (map[i][j] == 0)
				map[i][j] = 500;
		}
	}

	//printDistance();
	//printf("%d \n", dijkstra(1));
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			visit[j] = false;
		}
		dijkstra(i);
	}
	//printDistance();
	double sum = 0;
	for (int i = 1; i <= num; i++) {
		for (int j = i + 1; j <= num; j++) {
			sum += map[i][j];
			sum += map[j][i];
		}
	}
	printf("%f\n", sum);
	printf("%.3f\n", (float)sum / (num*(num - 1) ));
	cout << sum << endl; 
	cout << (float)sum / (num*(num - 1));
}
