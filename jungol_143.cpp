#include <iostream>
#include <vector>

using namespace std;
int num;
int sum;
int cal = 1;
int main() {
	scanf("%d", &num);
	for (int i = num * 2 - 1; i > 0; i -= 2) {
		for (int k = num * 2 - 1 - i; k > 0; k -= 2) {
			printf(" ");
		}
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		for (int k = num * 2 - 1 - i; k > 0; k -= 2) {
			printf(" ");
		}
		printf("\n");
	}
	int line = num-2;
	for (int i = 3; i <= num * 2 - 1; i += 2) {
		for (int i = 0; i < line; i++) {
			printf(" ");
		}
		line--;
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
