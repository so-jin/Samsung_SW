#include <iostream>

using namespace std;


//부분집합 : O(n^2)
//핵심: 각 원소가 포함되는 경우와 포함되지 않는 경우의 조합

const int N = 100;
const int CANDIDATE = 2;
int K = 10, cnt;
// a[] : 선택집합 - 현재까지 선택된 부분해
// k : 선택집합에 포함된 해의 수, backtrack이 호출된 깊이

//make candidate와 process solution만 수정하면 순열 문제를 풀 수 있다.
void process_solution(int a[], int k, int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			sum += i;
		}
	}
	if (sum == K) {
		cnt++;

	}
}

int make_candidate(int a[], int k, int n, int c[]) {
	c[0] = 1;   //포함되는 경우
	c[1] = 0;   //포함되지 않는 경우
	return 2;
}
void backtrack(int a[], int k, int n, int cSum, int tSum) {
	int c[CANDIDATE] = { 0, };	// 후보해 집합
	int nCands = 0;				// 후보해 집합에 포함된 원소의 수
	
	//가지치기
	if (cSum > K) return;		// 현재까지 고려한 값을 가지고 찾은 가지치기 조건
	if (cSum + tSum < K) return;	//미래에 구할 수 있는 값을 가지고 찾은 가지치기 조건

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
			//a[]: index 1~N에 기록


			// 1이 들어갔다면 k에 해당하는 값이 출력된다. k를 cSum에 더해주면 된다.
			int num = 0;
			if (a[k] == 1 ) {
				num = k;		//cSum은 매개변수, 매개변수의 변경은 반드시 호출시점에 변경해야 한다!
			}
			//backtrack(a, k, n, cSum + num, tSum - k);
			// 재귀호출의 횟수를 줄여라
			if (cSum + num <= K || cSum + tSum >= K) {
				backtrack(a, k, n, cSum + num, tSum - k);
			}
		}
	}
}

int main() {

	int a[N + 1] = { 0, };
	//K = 100;
	int tSum = N * (N + 1) / 2;

	backtrack(a, 0, N, 0, tSum);
	cout << cnt << endl;
	return 0;
}
