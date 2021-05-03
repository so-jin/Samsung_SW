#include<stdio.h>
int B[1000];
int arr[1000];
int flag[1000];
int num;
int rnt;

int check(int *ele, int i) {
	if (i < 2) return 1;
	if (ele[i - 2] > ele[i - 1] && ele[i] > ele[i - 1]) return 1;
	if (ele[i - 2] < ele[i - 1] && ele[i] < ele[i - 1]) return 1;
	else {
		//printf("           fail: %d %d %d\n", *(ele+i - 2), *(ele+i - 1), *(ele+i));
		return 0;
	}
}


void swap(int *first, int*second) {
	int temp = *first;
	*first = *second;
	*second = temp;
}

void dfs(int cnt) {
	if(check(B, cnt-1)==0) return;
	if(cnt == num) {
		rnt++;
	}
	else {
		for (int i = 1; i <= num; i++) {
			if (flag[i] == 0) {
				B[cnt] = arr[i];
				flag[i] = 1;
				dfs(cnt + 1);
				flag[i] = 0;
			}
		}
	}

}


int main() {
	int k;
	scanf("%d", &k);
	for (int j = 0; j < k; j++) {
		rnt = 0;
		scanf("%d", &num);
		for (int i = 1; i <= num; i++) {
			arr[i] = i;
		}
		dfs(0);
		printf("#%d %d\n", j+1,rnt);
	}
	return 0;

}
