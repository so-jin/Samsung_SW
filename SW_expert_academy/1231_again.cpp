#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
int num;
char n;
string input;
char tree[101];

void inorder(int index) {
	if (index <1 || index >num) return;
	inorder(index << 1);
	printf("%c", tree[index]);
	inorder(index << 1 | 1);
}

int main() {
	freopen("input.txt", "r", stdin);
	for (int k = 0; k < 10; k++) {
		scanf(" %d", &num);
		//printf("%d %d\n",k, num);
		scanf("%c", &n);
		for (int i = 1; i <= num; i++) {
			//scanf("%s", a);
			getline(cin, input);
			//cout << input << endl;
			//printf("%c", input[0]);
			tree[i] = input[2];
			//printf("%c\n", tree[i]);
		}
		printf("#%d ", k + 1);
		inorder(1);
		printf("\n");

		
	}

	return 0;
}
