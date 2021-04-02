#include <iostream>

using namespace std;


//부분집합 : O(n^2)
//핵심: 각 원소가 포함되는 경우와 포함되지 않는 경우의 조합

const int N = 5;
const int CANDIDATE = 2;
int src[] = { 6,2,8,3,4,5,1 };	//원본 데이터
// a[] : 선택집합 - 현재까지 선택된 부분해
// k : 선택집합에 포함된 해의 수, backtrack이 호출된 깊이

//make candidate와 process solution만 수정하면 순열 문제를 풀 수 있다.
void process_solution(int a[], int k, int n) {
	cout << "{ ";
	for (int i = 1; i <= n; i++) {
		//포함되는 경우
		cout << a[i] << " ";		//원본배열에 대한 인덱스 값을 생성
		//cout << src[i - 1] << " ";
		
	}
	cout << " } \n";
}

int make_candidate(int a[], int k, int n, int c[]) {
	// 순열 :	nPr = n * (n-1) * ,,, * (n-r+1)
	//			nPr = n * (n-1)P(r-1)	(r<=n)
	// 순열의 핵심 : 앞에서 선택한 것을 제외한 나머지가 다음 선택 대상이 된다.
	int inPerm[N + 1] = { 0, };		// a[]에 포함된 값을 체크하기 위한 배열 선언
	for (int i = 1; i < k; i++) {
		inPerm[a[i]]++;
	}

	int nCands = 0;
	for (int i = 1; i <= n; i++) {
		if (inPerm[i] == 0) {		// a[]에 포함되지 않은 값이면
			c[nCands] = i;
			nCands += 1;
		}
	}
	return nCands; 

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
