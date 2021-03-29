#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
char ch;
int p, w;
int n, pay;
long long sum;
vector<int> price;
vector<int> week;

int main() {

	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &pay);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p, &w);
		price.push_back(p);
		week.push_back(w);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (price[i] + pay * (j - i) < price[j]) {
				price[j] = price[i] + pay * (j - i);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		sum += (long long)price[i] * week[i];
	}
	printf("%lld", sum);

	return 0;
}
