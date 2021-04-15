#include <iostream>
#include <stack>

using namespace std;
stack<char> st;
stack<char> inverse;

char number;
//har arr[100];
int size_;
void printStack() {
	//printf("printStack\n");
	while (st.size() > 0) {
		inverse.push(st.top());
		//printf("%c", st.top());
		st.pop();
	}
	//printf("\n");
	while (inverse.size() > 0) {
		printf("%c", inverse.top());
		inverse.pop();
	}
}

int main() {
	freopen("brace.txt", "r", stdin);
	for (int k = 0; k < 10; k++) {
		scanf("%d", &size_);
		//end = size_ - 1;
		scanf(" %c", &number);
		st.push(number);
		for (int i = 1; i < size_; i++) {
			scanf(" %c", &number);
			if (st.size()>0 && st.top() == number) {
				//printf("same %c\n", number);
				st.pop();
			}
			else {
				st.push(number);
			}
		}


		printf("#%d ",k+1);
		printStack();
		printf("\n");

	}
}
