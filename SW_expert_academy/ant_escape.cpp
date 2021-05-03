#include<stdio.h>
#include<queue>
int SIZE;
int antNum;
int rank_;
int rankCnt;
int time;
int nowCnt;

using namespace std;
struct ant {
	int x;
	int y;
	int direct;
	int fin = 0;
}arr[5000];

queue<int> que;

void printAnt() {
	for (int i = 1; i <= antNum; i++) {
		printf("num%d %d %d %d\n", i, arr[i].x, arr[i].y, arr[i].direct);
	}
	printf("\n");
}

void collision(ant* A, ant* B) {
	if (A->x == B->x && A->y == B->y) {
		int tmp = A->direct;
		A->direct = B->direct;
		B->direct = tmp;
	}
}

void move(ant* A, int index) {
	switch (A->direct) {
	case 1:
		A->y++;
		break;
	case 2:
		A->y--;
		break;
	case 3:
		A->x--;
		break;
	case 4:
		A->x++;
		break;
	default:
		break;
	}
	if (A->x == SIZE) {
		nowCnt++;
		A->fin = 1;
		if (nowCnt + rankCnt >= rank_) {
			que.push(index);
		}
		printf("arrive %d %d %d\n", index, A->x, A->y);
	}for (int i = 1; i < index; i++) {
		if (A->x == arr[i].x && A->y == arr[i].y && arr[i].fin == 0) {
			collision(A, &arr[i]);
		}
	}
}


int escape() {
	while (1) {
		printAnt();
		time++;
		nowCnt = 0;
		for (int i = 1; i <= antNum; i++) {
			if (arr[i].fin == 0) {
				move(&arr[i], i);
			}
		}

		if ( rankCnt+nowCnt >= rank_) {
			if (rankCnt != rank_ - 1) return 0;
			int minY = SIZE+1;
			int re = 0;
			int now;
			while (que.size() != 0) {
				now = que.front();
				que.pop();
				if (minY > arr[now].y) {
					re = now;
					minY = arr[now].y;
				}
			}
			printf("result : %d \n", re);
			return re;
		}
	//	else if (rankCnt + nowCnt >= rank_) return 0;
		rankCnt += nowCnt;
		
	}
}
int main() {
	int test_num;
	scanf("%d", &test_num);
	for (int k = 0; k < test_num; k++) {
		scanf("%d %d %d\n", &SIZE, &antNum, &rank_);

		for (int i = 1; i <= antNum; i++) {
			scanf("%d %d %d", &arr[i].x, &arr[i].y, &arr[i].direct);
		}
		int re = escape();
		if (re == 0) {
			printf("#%d %d %d", k + 1, 0, 0);
		}
		else {
			printf("#%d %d %d\n", k + 1, time, re);
		}
	}
}
