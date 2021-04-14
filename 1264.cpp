#include <iostream>
using namespace std;

int test_num, len;
char a[501];
char b[501];
int LCS[501][501];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &test_num);
	for (int k = 0; k < test_num; k++) {
		scanf("%d", &len);
		for (int i = 1; i <= len; i++) {
			scanf(" %c", &a[i]);
		}
		for (int i = 1; i <= len; i++) {
			scanf(" %c", &b[i]);
			//printf("%c", b[i]);
		}
		//printf("\n");
	
		for (int i = 1; i <= len; i++) {
			for (int j = 1; j <= len; j++) {
				if (a[i] == b[j]) LCS[i][j] = LCS[i-1][j-1] + 1;
				else {
					LCS[i][j] = LCS[i - 1][j] > LCS[i][j - 1] ? LCS[i - 1][j] : LCS[i][j - 1];
				}
			}
		}
		printf("#%d %.2f\n", k + 1, (float)LCS[len][len]/(float)len *100);
	}
	
	return 0;
}
