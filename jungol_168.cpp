#include <iostream>
#include <vector>
using namespace std;
int integer = 1;
int cal = 1;
char cha = 65;
int l, r;
int sum = 0;
int arr[10][10];
int num;
int main() {
	//fgets(s,13,stdin);
	scanf("%d", &num);
	arr[0][0] = 1;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j==i) arr[i][j] = 1;
			else{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
	}

	for (int i = num - 1; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
