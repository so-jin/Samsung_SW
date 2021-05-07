#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;


struct node {
	bool isLeaf = true;
	int childCnt = 0;
	int parent = 0;
	int depth = 0;
	int index;
}list[128];



struct cmp {
	bool operator()(node n1, node n2) {
		if (n1.depth > n2.depth) return true;
		else return false;
	}
};

priority_queue<node, vector<node>, cmp> que;

int st[128];
int top = -1;
int tmp = -1;
int st_t[128];
int rootDir;
int testNum;
int dirNum;

void printList() {
	for (int i = 1; i <= dirNum; i++) {
		printf("*%d %d %d %d \n", i, list[i].depth, list[i].childCnt, list[i].parent);
	}
	printf("\n");
}

int main() {
	freopen("test.txt", "r", stdin);

	scanf("%d", &testNum);
	for (int k = 1; k <= testNum; k++) {
		scanf("%d %d", &dirNum, &rootDir);

		for (int i = 1; i <= dirNum; i++) {
			list[i].parent = 0;
			list[i].isLeaf = true;
			list[i].childCnt = 0;
			list[i].depth = 0;
			list[i].index = i;
		}

		for (int i = 1; i < dirNum; i++) {
			int p, c;
			scanf("%d %d", &p, &c);
			list[p].isLeaf = false;
			list[c].parent = p;

		}
		int sum = 0;

		for (int i = 1; i <= dirNum; i++) {
			if (list[i].isLeaf) {
				int now = list[i].parent;
				int depth = 1;
				while (now != 0) {
					if (depth > list[now].depth) {
						list[now].depth = depth++;
					}
					else break;
					now = list[now].parent;
				}
			}
		}

		for (int i = 1; i <= dirNum; i++) {
			que.push(list[i]);
		}


		for (int i = 1; i <= dirNum; i++) {
			top = -1;
			int find;
			if (list[i].isLeaf) {
				st[++top] = i;
				int now = list[i].parent;
				int flag = 0;
				find = top;

				while (now != 0) {
					find = top;
					while (st[find] > now) {
						find--;
					}
					for (int j = top; j > find; j--) {
						st[j + 1] = st[j];
					}
					if (flag == 1) {
						flag = 0;
						if (top == find) {
							list[now].childCnt--;
						}
						else {
							//list[now].childCnt--;

						}
					}
					if (list[now].childCnt != 0) flag = 1;
					list[now].childCnt += find + 1;
					st[++find] = now;
					now = list[now].parent;
					top++;
				}

			}
		}
		//printList();
	

		sum = 0;
		for (int i = 1; i <= dirNum; i++) {
			sum += list[i].childCnt;
		}
		printf("#%d %d\n", k, sum);
		

	}

	return 0;
}
