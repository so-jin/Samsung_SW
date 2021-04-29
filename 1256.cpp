#include<stdio.h>
int cnt;
struct Node {
	int i;
	int j;

}arr[100];
Node st[100];
int top = -1;

int ccw(Node p1, Node p2, Node p3) {
	int result = (p1.i - p2.i)*(p3.j - p2.j) - (p1.j - p2.j) * (p3.i - p2.i);
	return result;
}


int main() {
	freopen("input.txt", "r", stdin);
		scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++) {
		scanf("%d %d", &arr[i].i, &arr[i].j);
	}
	st[++top] = arr[0];
	st[++top] = arr[1];
	st[++top] = arr[2];

	for (int i = 3; i < cnt; i++) {
		while ( ccw(st[top - 1], st[top], arr[i]) < 0) {
			top--;
		}
		st[++top] = arr[i];
	}
	while (top >= 0) {
		printf("%d %d\n", st[top].i, st[top].j);
		top--;
	}
}
