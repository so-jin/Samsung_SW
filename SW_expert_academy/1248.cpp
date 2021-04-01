#include <iostream>
#include <vector>

using namespace std;
int num, a, b, tmp;

int parent, child, ccount;
int findparent(int a, int b, int up[10001]) {
	int now = a;
	vector<int> list;

	//printf("a : %d  !", a);
	while (up[now]) {
		//printf("%d ", up[now]);
		now = up[now];
		list.push_back(now);
	}
	//printf("\n");
	now = b;
	//printf("b :");
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

void countChild(int root, int down[10001][2]) {
	if (root > num || root < 1) return;
	ccount++;
	//printf("%d %d left: %d right: %d\n", root, ccount,down[root][0],down[root][1]);
	if (down[root][0] != 0 && down[root][0] <= num) { countChild(down[root][0], down); }
	if (down[root][0] !=0 && down[root][0] <= num) { countChild(down[root][1], down); }

}

int main() {
	freopen("tree.txt", "r", stdin);
	//printf("hi");
	scanf("%d", &num);
	//printf("hi");
	for (int k = 0; k < 10; k++) {
		int up[10001] = { 0, };
		int down[10001][2] = { 0, };
		ccount = 0;
		scanf("%d %d %d %d", &num, &tmp, &a, &b);
		//printf("input : %d %d %d %d\n", num, tmp, a, b);
		for (int i = 1; i < num; i++) {
			scanf("%d %d", &parent, &child);
			up[child] = parent;
			if (down[parent][0]) down[parent][1] = child;
			else down[parent][0] = child;
		}
		int root = findparent(a, b, up);
		countChild(root, down);

		printf("#%d %d ", k + 1, root);
		printf("%d\n", ccount);



	}
}
