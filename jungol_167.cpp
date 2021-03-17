#include <iostream>
#include <vector>
using namespace std;
int integer = 1;
int cal = 1;
char cha = 65;
int l, r;
int sum = 0;
int arr[4][2];
char s[13];
string str;

int main() {
	//fgets(s,13,stdin);
	int row = 0;
	for (int i = 0; i < 4; i++) {
		row = 0;
		for (int j = 0; j < 2; j++) {
			scanf("%d", &arr[i][j]);
			row += arr[i][j];
		}
		printf("%d ", row / 2);
		sum += row;
	}
	printf("\n");
	int col = 0;
	for (int i = 0; i < 2; i++) {
		col = 0;
		for (int j = 0; j < 4; j++) {
			col += arr[j][i];
		}
		printf("%d ", col / 4);
	}

	printf("\n");
	printf("%d", sum / 8);
	return 0;
}
