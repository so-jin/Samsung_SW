#include <iostream>

using namespace std;


//부분집합 : O(n^2)
//핵심: 각 원소가 포함되는 경우와 포함되지 않는 경우의 조합

const int N = 5;
const int CANDIDATE = 2;
int src[] = { 6,2,8,3,4,5,1 };	//원본 데이터
// a[] : 선택집합 - 현재까지 선택된 부분해
// k : 선택집합에 포함된 해의 수, backtrack이 호출된 깊이
void process_solution(int a[], int k, int n) {
	cout << "{ ";
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {			//포함되는 경우
			//cout << i << " ";		//원본배열에 대한 인덱스 값을 생성
			cout << src[i - 1] << " ";
		}
	}
	cout << " } \n";
}

int make_candidate(int a[], int k, int n, int c[]) {
	c[0] = 1;		//포함되는 경우
	c[1] = 0;		//포함되지 않는 경우
	return 2;

}
void backtrack(int a[], int k, int n) {
	int c[CANDIDATE] = { 0, };	// 후보해 집합
	int nCands = 0;				// 후보해 집합에 포함된 원소의 수

	//뽑아야 할 숫자가 다 뽑히면
	if (k == n) {
		process_solution(a, k, n);
	}
	else {
		k++;
		nCands = make_candidate(a, k, n, c);	//후보해 생성
		for (int i = 0; i < nCands; i++) {	//후보해의 수 만큼 반복
			a[k] = c[i];					//후보해 중에 하나를 선택집합에 추가
			//a에는 1또는 0기록 
			//a[]: index 1~N에 기록`
			backtrack(a, k, n);
		}
	}
}

int main() {

	int a[N + 1] = { 0, };
	backtrack(a, 0, 3);

	return 0;
}
