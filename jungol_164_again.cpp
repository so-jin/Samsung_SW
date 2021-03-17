#include <iostream>
#include <vector>

using namespace std;
int integer = 1;
int cal = 1;
char cha = 65;
int num1, num2, num3;
int sum = 0;
char str[8];
int arr[4];
int main() {
	for (int i = 0; i < 4; i++) {
		scanf("%s %d %d %d",str, &num1, &num2, &num3);
		arr[i] = num1 + num2 + num3;
	}
	for (int i = 0; i < 4; i++) {
		printf("%dclass : %d\n", i + 1, arr[i]);
	}
	return 0;
}
