#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int num;
char ch;
int com[128];
int in[128];

int main() {
	com['('] = 3;
	in['('] = 0;
	com['*'] = in['*'] = com['/'] = in['/'] = 2;
	com['+'] = in['+'] = com['-'] = in['-'] = 1;

	freopen("input.txt", "r", stdin);
	for (int k = 0; k < 10; k++) {
		vector<char> ve;
		stack<char> st;
		//for calculate
		scanf("%d", &num);
		scanf("%c", &ch);
		for (int i = 0; i < num; i++) {
			scanf("%c", &ch);
			if ('0' <= ch && ch <= '9') {
				ve.push_back(ch);
			}
			else if (st.empty()) {
				st.push(ch);
			}
			else if (com[ch] > in[st.top()]) {
				st.push(ch);
			}
			else if (ch == ')') {
				while (st.top() != '(') {
					ve.push_back(st.top());
					st.pop();
				}
				st.pop();
			}
			else {
				while (in[st.top()] >= com[ch]) {
					ve.push_back(st.top());
					st.pop();
				}
				st.push(ch);
			}
		}
		while (!st.empty()) {
			ve.push_back(st.top());
			st.pop();
		}
		int i = 0;

		//real calculate
		stack<int> re;
		for(int i=0 ; i< ve.size(); i++) {
			if (ve[i] >= '0' && ve[i] <= '9') {
				re.push(ve[i]-'0');
			}
			else {
				int b = re.top();
				re.pop();
				int a = re.top();
				re.pop();
				int result;
				switch (ve[i]) {
					case '+':
						result = a + b;
						break;
					case '-':
						result = a - b;
						break;
					case '*':
						result = a * b;
						break;
					case '/':
						result = a / b;
				}
				re.push(result);
			}
		}
		printf("#%d %d\n", k+1, re.top());

	}
	return 0;
}


