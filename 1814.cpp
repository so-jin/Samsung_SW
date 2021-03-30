#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;
int sum;
int main() {
	stack<int> st;
	int num, input;
	scanf("%d ", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &input);
		if (st.empty() || st.top() < input) {
			st.push(input);
		}
		else {
			stack<int> tmp;
			while (!st.empty() && st.top() > input) {
				tmp.push(st.top());
				st.pop();
				sum++;
			}
			st.push(input);
			while (!tmp.empty()) {
				st.push(tmp.top());
				tmp.pop();
			}
		}
	}
	printf("%d", sum);

	return 0;
}
