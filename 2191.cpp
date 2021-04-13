#include <iostream>
#include <stdio.h>

using namespace std;
int aLen, bLen;
char a[1001];
char b[1001];
int d[1001][1001];

int getMin(int a, int b, int c) {
	if (a < b) {
		if (c < a) return c;
		else return a;
	}
	else {
		if (c < b) return c;
		else return b;
	}
}

int levenshteinDistance() {
	for (int i = 1; i <= aLen; i++) {
		d[i][0] = i;
	}
	for (int j = 1; j <= bLen; j++) {
		d[0][j] = j;
	}
	for (int j = 1; j <=bLen; j++) {
		for (int i = 1; i <= aLen; i++)
		{
			if (a[i] - b[j] == 0) {
				d[i][j] = d[i - 1][j - 1];
				//printf("same: %d:%c %d:%c %d\n", i, a[i], j, b[i], d[i][j]);
			}
			else {
				int min = getMin(d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]);
				d[i][j] = min + 1;
			}
		}
	}
	return d[aLen ][bLen ];
}


int main() {
	//printf("HI\n");
	freopen("input.txt", "r", stdin);
	scanf("%d ", &aLen);
	for (int i = 1; i <= aLen; i++) {
		scanf(" %c ", &a[i]);
		//printf("%c", a[i]);
	}
	//printf("\n");
	scanf("%d", &bLen);
	for (int i = 1; i <= bLen; i++) {
		scanf(" %c ", &b[i]);
		//printf("%c", b[i]);
	}
	
	printf("%d\n",levenshteinDistance());
	

	return 0;
}
