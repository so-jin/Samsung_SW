#include <iostream>
#include <vector>

using namespace std;
int num, a, b, tmp;
int up[10001] = { 0, };

int findparent(int a, int b, int up[10001]) {
	int now = a;
	vector<int> list;

	//printf("a : %d  !", a);
	list.push_back(now);
	while (up[now]) {
		//printf("%d ", up[now]);
		now = up[now];
		list.push_back(now);
	}
	//printf("\n");
	now = b;
	//printf("b :");

	for (int j = 0; j < list.size(); j++) {
		if (now == list[j]) {
			//printf("root: %d\n", list[j]);
			return now;
		}
	}


	while (up[now]) {
		//printf("%d ", up[now]);
		now = up[now];

		for (int j = 0; j < list.size(); j++) {
			if (now == list[j]) {
				//printf("root: %d\n", list[j]);
				return now;
			}
		}

	}
	//printf("\n");

	return -1;
}

int main() {
	freopen("tree.txt", "r", stdin);
	scanf("%d", &num);
	for (int i = 1; i < num; i++) {
		scanf("%d %d", &a, &b);
		up[b] = a;
	}
	scanf("%d %d", &a, &b);
	//printf("a: %d b :%d\n", a, b);
	printf("%d", findparent(a, b, up));
}
