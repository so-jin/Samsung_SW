#include <iostream>
#include <vector>

using namespace std;
int num;
int sum;
int cal = 1;
int main() {
	scanf("%d", &num);
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num - i; j++) {
			printf("  ");
		}
		for (int j = 1; j <= i; j++) {
			printf("%d ", j);
		}
		printf("\n");
	}

	return 0;
}
