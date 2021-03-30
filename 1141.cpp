#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int coun;
long long sum;
int num;
vector<int> in;
//vector<int> result;
//int input[1000] = { 0 };
stack<int> st;

int main() {

	freopen("input.txt", "r", stdin);
	scanf("%d", &coun);
	for (int i = 0; i < coun; i++) {
		scanf("%d", &num);

		while (!st.empty() && st.top() <= num) {
			st.pop();
		}
		//printf("%d size: %d \n", i, st.size());
		sum += st.size();
		st.push(num);
	}
	printf("%lld", sum);
	return 0;
}
