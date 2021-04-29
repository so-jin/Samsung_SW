#include <stdio.h>
#define MAX(A,B) (((A)>(B))? (A):(B))

int DP[505][505];
char DNA[20];
char st[20];
int top = -1;
char match[256];
int len;

void printStack() {
	for (int i = 0; i <= top; i++) {
		printf("%c ", st[i]);
	}
	printf("\n");
}

int main() {
	freopen("input.txt", "r", stdin);
	match['t'] = 'a';
	match['c'] = 'g';
	scanf("%s", &DNA[1]);

	int i = 1;
	int cnt = 0;
	while (DNA[i] != '\0') {
		i++;
		cnt++;
	}

	for (int j = 2; j <= cnt; j++) {
		for (int i = j - 1; i >= 1; i--) {
			if ((DNA[i] == 'a' && DNA[j] == 't' )|| (DNA[i] == 'g' && DNA[j] == 'c')){
				DP[i][j] = DP[i + 1][j - 1] + 2;
			}
			int max = 0;
			for (int k = 1; k <= (j - i); k++) {
				int temp = DP[j  + 1 - k][j] + DP[i][j - k];
				if (max < temp) {
					max = temp;
				}
			}
			DP[i][j] = MAX(DP[i][j], max);
		}
	}
	
	printf("%d\n", DP[1][cnt]);


}
