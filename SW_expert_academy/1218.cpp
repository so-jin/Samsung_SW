#include <iostream>
#include <stack>

using namespace std;
int size_;
char brace;
char match[128];
int result;
char tmp[300];
stack<char> st;


int main() {
	freopen("brace.txt", "r", stdin);
	match['('] = ')';
	match['{'] = '}';
	match['['] = ']';
	match['<'] = '>';
 
	for (int k = 0; k < 10; k++) {

		scanf("%d", &size_);
		result = 1;
		for (int i = 0; i < size_; i++) {
			scanf(" %c", &brace);
			if (brace == ')' || brace == ']' || brace == '>' || brace == '}') {
				if (st.top() != brace) {
					//printf("fail %d %c\n", i, brace);
					result = 0;
					scanf("%s ", tmp);
				//	printf("final print %s\n", tmp);
					break;
				}
				st.pop();
			}
			else {
				st.push(match[brace]);
			}
		}
		if (st.size() != 0) {
			result = 0;
			//printf("fail of size %d\n", st.size());
		}
		printf("#%d %d\n", k + 1, result);

		while (st.size() != 0) {
			st.pop();
		}
	}
}
