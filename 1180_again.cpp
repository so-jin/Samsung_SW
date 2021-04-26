
#include<stdio.h>
#include<iostream>
#include<stack>
int num;
int cnt;
char arr[20];
using namespace std;
int cal() {
	int st[100];
	int top = -1;
	int front = 0;
	//int result = 1;
	st[++top] = 1;
	for (int i = 1; i < num; i++) {
		if (arr[i] == '.') {
			int t = st[top--];
			t = t * 10;
			st[++top] = t +i + 1;
		}
		else {
			st[++top] = i+1;
		}
	}

	for (int i = 1; i < num; i++) {
		if (arr[i] == '.') continue;
		else if (arr[i] == '+') {
			int a = st[front++];
			int b = st[front++];
			st[--front] = a + b;
		}
		else {
			int a = st[front++];
			int b = st[front++];
			st[--front] = a - b;
		}
	}
	int re = st[front];
	//printf("result %d\n", re);
	return re;

}

int makeSet(int k) {
	if (cnt >= 20) //return 0;{
	{
		cnt++;
		//return 0;
	}
	if (k == num) {
		if (cal() == 0) {
			cnt++;
			for (int i = 1; i < k; i++) {
				printf("%d %c ", i, arr[i]);
			}
			printf("%d\n", k);
		}
		return 0;
	}

	arr[k] = '+';
	makeSet(k + 1);
	arr[k] = '-';
	makeSet(k + 1);
	arr[k] = '.';
	makeSet(k + 1);
}

int main() {

	scanf("%d", &num);
	
	makeSet(1);
	printf("%d", cnt);
}
