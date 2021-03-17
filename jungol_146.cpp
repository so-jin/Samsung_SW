#include <iostream>
#include <vector>

using namespace std;
int integer = 0;
int cal = 1;
char cha = 65;
int num = 0;
int main() {
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num-i; j++) {
			printf("%c ", cha++);
		}
		for (int j = 0; j < i; j++) {
			printf("%d ", integer++);
		}
		printf("\n");
	}

	return 0;
}
