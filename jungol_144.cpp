#include <iostream>
#include <vector>

using namespace std;
int num;
int sum;
int cal = 1;
int main() {
	scanf("%d", &num);
	for (int i = 1; i <= num; i++) {

		for (int j = 1; j < num * 2 - (i*2-1); j++) {
			printf(" ");
		}
		for (int j = 1; j < i * 2 ; j++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
