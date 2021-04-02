// ConsoleApplication3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>

using namespace std;
int num_count, client_num, min_length =1000000;
const int CANDIDATE = 11;
int go[2][2];
int client[12][12];
int length[12][12];

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
	int inPerm[11] = { 0, };

	for (int i = 1; i < k; i++) {
		inPerm[a[i]] ++ ;
	}
	int nCands = 0;
	for (int i = 1; i <= n; i++) {
		if (inPerm[i] == 0) {
			c[nCands] = i;
			nCands += 1;
		}
	}
	return nCands;
}

void backtrack(int a[], int k, int n, int cSum) {
	int c[CANDIDATE] = { 0, };	// 후보해 집합
	int nCands = 0;				// 후보해 집합에 포함된 원소의 수


	//가지치기
	//if (cSum > K) return;		// 현재까지 고려한 값을 가지고 찾은 가지치기 조건
	//if (cSum + tSum < k) return;	//미래에 구할 수 있는 값을 가지고 찾은 가지치기 조건

	//뽑아야 할 숫자가 다 뽑히면
	if (k == n) {
		if (cSum + length[a[k]][k + 1] < min_length) {
			min_length = cSum + length[a[k]][k+1];
			//cout << cSum <<"!" << length[a[k]][k+1] << endl;
			//process_solution(a, k, n);
		}
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
			if (a[k] != 0) {
						//cSum은 매개변수, 매개변수의 변경은 반드시 호출시점에 변경해야 한다!
				num = length[a[k]][a[k - 1]];

			}
			//backtrack(a, k, n, cSum + num, tSum - k);
			// 재귀호출의 횟수를 줄여라
			// min보다 작다면! PASS
			if (cSum + num < min_length) {
				backtrack(a, k, n, cSum + num);
			}
		}
	}
}


int main()
{
	freopen("input.txt", "r", stdin);
	cin >> num_count;
	
	for (int k = 0; k < 10; k++) {
		//client = { 0, };
		min_length = 100000;
		int a[11] = { 0, };

		cin >> client_num;
		cin >> client[0][0] >> client[0][1];
		cin >> client[client_num+1][0] >> client[client_num+1][1];
		//cout << client[client_num + 1][0] << " : " << client[client_num + 1][1] << endl;
		//cout << "client num" << client_num << endl;5
		for (int i = 1; i <= client_num; i++) {
			cin >> client[i][0] >> client[i][1];
		}

		for (int i = 0; i <= client_num+1; i++) {
			for (int j = i+1; j <= client_num+1; j++) {
				int x = client[i][0] > client[j][0] ? client[i][0] - client[j][0] : client[j][0] - client[i][0];
				int y = client[i][1] > client[j][1] ? client[i][1] - client[j][1] : client[j][1] - client[i][1];

				length[i][j] = length[j][i] = x + y;

				//cout << i << " " << j << " " << length[i][j] << endl;
			}
		}

		backtrack(a, 0, client_num,0);
		cout << "#" << k + 1 << " ";
		cout << min_length << endl;

	}
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
