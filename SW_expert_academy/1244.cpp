#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coun, change;
char arr[7];
char in[7];
int t[7];
int max = 0;
void printArray(int arr[], int n) {
	printf("end : ");
	for (int i = 0; i < n; i++) {
		printf("%c ", arr[i]);
	}
	printf("\n");
}

/*
void nPIr(int n, int r, int q) {
	if (r == 0) {
		printArray(t, q);
	}
	else {
		for (int i = n - 1; i >= 0; i--) {
			swap(arr[i], arr[n - 1]);
			t[r - 1] = arr[n - 1];
			nPIr(n, r - 1, q);
			swap(arr[i], arr[n - 1]);
		}
	}
}
void Combination(int n, int r, int q) {
	if (r == 0) printArray(t, q);
	else if (n < r) return;
	else {
		t[r - 1] = arr[n - 1];
		Combination(n - 1, r - 1, q);
		Combination(n - 1, r, q);
	}
}
*/
/*
void Combination(int n, int r, int q) {
	if (r == 0) printArray(t, q);
	else if (n < r) return;
	else {
		t[r - 1] = arr[n - 1];
		Combination(n - 1, r - 1, q);
		Combination(n - 1, r, q);
	}
}

*/


void cal(int size, int count) {
	int sum = 1;
	int index = 1;
	if (count == 0) {
		for (int i = size - 1; i >= 0; i--) {
			sum *= (arr[i] - '0')*index;
			index *= 10;
			printf("sum : %d\n", sum);
		}

		printf("%s\n", arr);
		return;
	}
	else if (count < 0) return;
	for (int i = 0; i < size; i++) {
		for (int j = i+1; j < size; j++) {
			if (i != j) {
				swap(arr[i], arr[j]);
				cal(size, count - 1);
				swap(arr[i], arr[j]);
			}
		}

	}
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &coun);

	for (int i = 0; i < 1; i++) {
		int j = 0;
		scanf("%s", arr);
		printf("%s\n", arr);
		while (*(arr + j) != '\0') {
			j++;
		}
		//sprintf(arr, "%07s", in);
		scanf("%d", &change);

		printf("%s size %d change %d\n", arr, j, change);
		cal(j, change);

	}
	return 0;
}
