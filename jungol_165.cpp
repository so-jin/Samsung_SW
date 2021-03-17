#include <iostream>
#include <vector>

using namespace std;
int integer = 1;
int cal = 1;
char cha = 65;
int l,r;
int sum = 0;
int arr[5][5] = {0, };
int main() {
	arr[0][0] = arr[0][2] = arr[0][4] = 1;
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[0][i]);
	}
	printf("\n");
	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (j - 1 >= 0 ) l = arr[i - 1][j - 1];
			else l = 0;
			if (j + 1 < 5) r = arr[i - 1][j + 1];
			else r = 0;
			arr[i][j] = l + r;
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
