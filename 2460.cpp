#include <stdio.h>
int col, row;
int student_num;
int score[4][4];

int a_, b_, c_;
int sum[4];
int maxSum;


int findMax(int arr[4], int a, int b, int c) {
	if (arr[a] > arr[b]) {
		if (arr[a] > arr[c]) return a;
		return c;
	}
	else {
		if (arr[b] > arr[c]) return b;
		return c;
	}
}
int countCompare(int num, int a, int b) {
	//printf("compare\n");
	if (num == 0) return 0;
	if (score[a][num] == score[b][num]) return countCompare(num - 1, a, b);
	else if (score[a][num] > score[b][num]) return a;
	else return b;
}

int countCompare(int num, int a,int b,int c) {
	//printf("compare\n");
	if (num == 0) return 0;
	if (score[num][a] == score[num][b] && score[num][b] == score[num][c]) return countCompare(num - 1, a, b, c);
	else if (score[num][a] == score[num][b] && score[num][a] > score[num][c]) return countCompare(num - 1, a, b);
	else if (score[num][a] == score[num][c] && score[num][a] > score[num][b]) return countCompare(num - 1, a, c);
	else if (score[num][b] == score[num][c] && score[num][b] > score[num][a]) return countCompare(num - 1, b, c);
	else {
		return findMax(score[num], a, b, c);
	}
}


int getMax() {
	//printf("get\n");
	if (sum[1] == sum[2] && sum[2] == sum[3]) {
		//printf("same\n");
		maxSum = sum[1];
		return countCompare(3, 1, 2, 3);
	}
	else if (sum[1] == sum[2] && sum[1] > sum[3]) {
		maxSum = sum[1];
		return countCompare(3, 1, 2);
	}
	else if (sum[1] == sum[3] && sum[1] > sum[2]) {
		maxSum = sum[1];
		return countCompare(3, 1, 3);
	}
	else if (sum[2] == sum[3] && sum[2] > sum[1]) {
		maxSum = sum[2];
		return countCompare(3, 2, 3);
	}
	else {
		int maxIndex = findMax(sum, 1, 2, 3);
		//printf("%d %d\n", maxIndex, sum[maxIndex]);
		maxSum = sum[maxIndex];
		return maxIndex;
	}

}





int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &student_num);
	for (int i = 0; i < student_num; i++) {
		scanf("%d %d %d", &a_, &b_, &c_);
		score[1][a_]++;
		score[2][b_]++;
		score[3][c_]++;
	}
	for (int i = 1; i < 4; i++) {
		sum[1] += score[1][i] * i;
		sum[2] += score[2][i] * i;
		sum[3] += score[3][i] * i;
	}

	//printf("%d %d %d\n", sum[1], sum[2], sum[3]);
	//int max = 0;
//	int result = getMax();
	printf("%d ", getMax());
	printf("%d \n", maxSum);
}
