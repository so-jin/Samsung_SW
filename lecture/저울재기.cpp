#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;


enum USAGE {
	NONE, LEFT,RIGHT
};
int Weight[7] = { 1,3,9,27,91,243,729 };
int Usage[7] = { 0, };

int balance(int k, int left, int right) {
	if (k > 7) return 0;
	if (left == right) return 1;
	Usage[k] = LEFT;
	if (balance(k + 1, left + Weight[k], right) == 1) {
		return 1;
	}
	Usage[k] = RIGHT;
	if (balance(k + 1,left, right + Weight[k]) == 1) {
		return 1;
	}
	Usage[k] = NONE;
	if (balance(k + 1, left, right) == 1) {
		return 1;
	}
	return 0;
}


int fun(int k) {
	return 0;
}

int main() {

	int W;
	scanf("%d", &W);
	int result = balance(0, W, 0);
	if (result) {
		printf("%d ", W);
		for (int i = LEFT; i <= RIGHT; i++) {
			for (int j = 0; j < 7; j++) {
				if (Usage[j] == i) {
					printf("%d ", Weight[j]);
				}
			}
			if (i == LEFT) printf("0 ");
		}
		printf("\n");
	}
	else {
		printf("-1 \n");
	}




}
