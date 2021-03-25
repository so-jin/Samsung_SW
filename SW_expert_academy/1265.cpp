#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int money;
int pack, test;
double sum;
int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &test);

	for (int i = 0; i < test; i++) {
		unsigned long arr[100] = { 0 };
		sum = 1;
		scanf("%d %d", &money,&pack);
		//printf("money %d pack %d\n", money, pack);
		while (money>0) {
			for (int j = 0; j < pack; j++) {
				arr[j] += 1;
				money--;
				if (money == 0)break;
			}
		}
		printf("%d\n", arr[0]);
		for (int j = 0; j < pack; j++) {
			sum *= (double)arr[j];
		}
		printf("#%d %.0f\n", i + 1, sum);
	}

	return 0;
}
