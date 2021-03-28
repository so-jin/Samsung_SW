// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int matching(char pattern[], char text[]) {
	int i = 0, j = 0;
	int count = 0;
	int pattern_len = strlen(pattern);
	int text_len = strlen(text);
	while ( i < text_len) {
		if (text[i] != pattern[j]) {
			i = i - j;
			j = -1;
		}
		i = i + 1;
		j = j + 1;
		if (j == pattern_len) {
			count++;
			j = 0;
		}
	}
	return count;
}
int num;

char reverse(char in) {
	switch (in) {
		case 112:
			return 113;
		case 113:
			return 112;
		case 98:
			return 100;
		case 100:
			return 98;
	}
	return 0;
}

void mirror(char input[]) {
	int len = strlen(input);
	for (int i = 0; i < len / 2; i++) {
		input[i] = reverse(input[i]);
		input[len - i - 1] = reverse(input[len - i - 1]);
		swap(input[i], input[len - 1 - i]);
	}
	if (len & 1) {
		input[len / 2] = reverse(input[len / 2]);
	}
}

int skillA, skillB;

/*
int Combination(int n, int r, int count) {
	if (r == 0) {
		return count;
	}
	else if (n < r) {
		return;
	}
	else {
		return Combination(n - 1, r - 1, count + 1) + Combination(n - 1, r, count);
	}
}
*/

int in[] = { 1,4,6,8,9,10,12,14,15,16,18 };
double A[19], A_[19];
double B[19], B_[19];
int com[19][19] = { 0 };

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &num);
	com[1][0] = com[1][1] = 1;

	//pre data
	for (int i = 2; i < 19; i++) {
		for (int j = 0; j < i + 1; j++) {
			com[i][j] = com[i - 1][j - 1] + com[i - 1][j];
		}
	}

	//testcase
	for (int i = 0; i < num; i++) {
		double probA = 0;
		double probB = 0;
		double prob = 1;

		scanf("%d %d", &skillA, &skillB);
		A[0] = B[0] = A_[0] = B_[0] = 1;
		A[1] = (double)skillA / 100;
		A_[1] = 1.0 - A[1];
		B[1] = (double)skillB / 100;
		B_[1] = 1.0 - B[1];
		for (int j = 2; j < 19; j++) {
			A[j] = (double)A[j - 1] * A[1];
			A_[j] = (double)A_[j - 1] * A_[1];
			B[j] = (double)B[j - 1] * B[1];
			B_[j] = (double)B_[j - 1] * B_[1];
			//printf("%f %f\n", A_[j], B_[j]);
		}

		for (int j = 0; j < 11; j++) {
			probA += (double)(com[18][in[j]] * A[in[j]] * A_[18 - in[j]]);
			probB += (double)(com[18][in[j]] * B[in[j]] * B_[18 - in[j]]);
			//printf("%d %.6f %.6f %.6f\n", com[18][in[j]], A[in[j]], A_[18 - in[j]], (com[18][in[j]] * A[in[j]] * A_[18 - in[j]]));
			//printf("A: %.6f B: %.6f   ", com[18][in[j]] * A[in[j]] * A[18 - in[j]], com[18][in[j]] * B[in[j]] * B[18 - in[j]]);
		}
		//printf("\n");
		//printf("%f %f\n", probA, probB);
		prob = (double)probA * probB;
		if (prob == 0.0) {
			printf("#%d %.6f\n", i + 1, 0.0);

		}
		else {
			printf("#%d %.6f\n", i + 1, 1.0 - prob);
		}
	}
	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴nZV 

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
