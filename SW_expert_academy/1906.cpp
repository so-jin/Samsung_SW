#include<stdio.h>

int size;
int get[2];
int parent[101];
int par, child;


int getFamily() {
	int nowA = get[0];
	int countA = -1;

	while (nowA != 0) {
		countA++;
		int nowB = get[1];
		int countB = -1;

		while (nowB != 0) {
			//printf("A %d B %d\n", nowA, nowB);
			countB++;
			if (nowA == nowB) {
				return countA + countB;
			}
			nowB = parent[nowB];
		}
		nowA = parent[nowA];
	}
	return -1;
}



int main() {

	int k;
	freopen("input.txt", "r", stdin);
	scanf("%d", &size);
	scanf("%d %d", &get[0], &get[1]);
	scanf("%d", &k);
	for (int i = 0; i < k; i++){
		scanf("%d %d", &par, &child);
		parent[child] = par;
	}
	

	printf("%d\n", getFamily());


}
