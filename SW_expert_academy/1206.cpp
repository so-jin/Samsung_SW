#include <iostream>
#include <vector>

using namespace std;
int num;
int sum;
int cal = 1;

int main() {
	freopen("input.txt", "r", stdin);
	for (int k = 0; k < 10; k++) {
		int arr[1000] = { 0 };
		sum = 0;

		scanf("%d", &num);
		for (int i = 0; i < num; i++) {
			scanf("%d", &arr[i]);
		}
		for (int i = 2; i < num; i++) {
			if (arr[i] > arr[i - 1] && arr[i] > arr[i-2] 
				&& arr[i] > arr[i + 1] && arr[i]>arr[i+2]) {
				int l = arr[i - 2] > arr[i - 1] ? arr[i - 2] : arr[i - 1];
				int r = arr[i + 1] > arr[i + 2] ? arr[i + 1] : arr[i + 2];
				int max = l > r ? l : r;
				sum += (arr[i] - max);
			}
		}
		printf("#%d %d\n", k + 1, sum);
	}

	return 0;
}
