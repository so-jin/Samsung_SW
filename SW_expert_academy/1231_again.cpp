#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
int num;
char n;
//string input;
char tree[101];
char input[20];

void inorder(int index) {
	if (index < 1 || index >num) return;
	inorder(index << 1);
	cout << tree[index];
	inorder(index << 1 | 1);
}

int main() {
	freopen("input.txt", "r", stdin);
	for (int k = 0; k < 1; k++) {
		cin >> num;
		//printf("%d %d\n",k, num);
		cin >> n;
		for (int i = 1; i <= num; i++) {
			//scanf("%s", a);
			//cin.ignore();
			cin.getline(input,20);
			cout << "get: " << input;
			//getline(cin, input);
			//cout << input << endl;
			cout <<' ' <<  input[2] << endl;
			tree[i] = input[2];
			//printf("%c", tree[i]);
		}
		cout << '#' << k + 1;
		inorder(1);
		cout << endl;

	}

	return 0;
}
