#include<stdio.h>
#include<vector>

using namespace std;
int testNum;
struct vector2 {
	int x, y;
};
typedef vector<vector2> polygon;

polygon old;
polygon add;

bool isInside(vector2 B, const polygon& p) {
	int crosses = 0;
	for (int i = 0; i < p.size(); i++) {
		int j = (i + 1) % p.size();
		if ((p[i].y > B.y) != (p[j].y > B.y)) {
			double atX = (p[j].x - p[i].x) * (B.y - p[i].y) / (p[j].y - p[i].y) + p[i].x;
			if (B.x <= atX) crosses++;
		}
	}
	return crosses % 2 > 0;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &testNum);

	for (int i = 0; i < testNum; i++) {
		int oldNum, newNum;
		old.clear();

		scanf("%d", &oldNum);
		for (int j = 0; j < oldNum; j++) {
			int x, y;
			scanf("%d %d", &x, &y);
			old.push_back({ x,y });
		}
		//print to check
		for (int k = 0; k < oldNum; k++) {
			printf("%d %d\n", old[k].x, old[k].y);
		}

		int cnt = 0;

		scanf("%d", &newNum);
		for (int j = 0; j < newNum; j++) {
			int x, y;
			scanf("%d %d", &x, &y);
			printf("%d %d", x, y);
			if (isInside({ x,y }, old) == false) {
				cnt++;
			}
			printf("#%d %d %d %d\n", i + 1, x, y, cnt);
		}
		//print to check
		for (int j = 0; j < newNum; j++) {
			printf("%d %d\n", add[j].x, add[j].y);
		}

	}
	return 0;
}
