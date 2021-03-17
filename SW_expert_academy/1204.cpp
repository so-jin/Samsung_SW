#include <iostream>
#include <vector>

using namespace std;
int num;
int input;
int cal = 1;

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int arr[1001] = { 0 };
		scanf("%d", &input);
		for (int j = 0; j < 1000; j++) {
			scanf("%d", &input);
			arr[input]++;
		}
		int max = 0;
		int index = 0;
		for (int j = 1; j < 1001; j++) {
			if (arr[j] >= max) {
				max = arr[j];
				index = j;
			}
		}
		printf("#%d %d\n", i + 1, index);
	}

	return 0;
}
