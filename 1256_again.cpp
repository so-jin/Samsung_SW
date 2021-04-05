#include <stdio.h>
#include <string.h>

int test, kth;

int small(int a, int b, char arr[]) {
	//printf("compare\n");
	if (arr[a] == '\0') {
		//printf("out of rage\n");
		return 1;
	}
	if (arr[b] == '\0') {
		//printf("out of range1\n");
		return 0;
	}

	if (arr[a] < arr[b]) return 1;
	if (arr[a] > arr[b]) return 0;
	else {
		//int result = small(a + 1, b + 1, arr);
		//printf("compare again \n");
		return small(a+1,b+1,arr);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &test);
	for (int k = 0; k < 2; k++) {
		char arr[402];
		int A[402];

		scanf("%d", &kth);
		scanf("%s\n", arr);


		//printf("#%d %s %d \n", k + 1, arr, kth);

		for (int i = 1; i <= strlen(arr); i++) {
			A[i] = i;
			//printf("input %d %d %c \n",i, A[i], arr[i]);
		}
		//printf("len %d \n", strlen(arr));
		for (int i = strlen(arr); i >0; i--) {
			for (int j = 1; j < i; j++) {
				//printf("index %d   \n", j);

				//if (arr[A[j]-1] > arr[A[j + 1]-1]) {
				if(small(arr[A[j+1]-1],arr[A[j]-1], arr)){
					//printf("change %d j+1 %c <-> %d j %c \n", A[j+1], arr[A[j + 1]-1],A[j], arr[A[j]-1]);
					int tmp = A[j + 1];
					A[j + 1] = A[j];
					A[j] = tmp;
				}
				

			}
		}
		for (int i = 1; i <= strlen(arr); i++) {
			printf("%d%c ", A[i] ,arr[A[i]-1]);
		}

		//printf("%d %d\n", kth, A[kth]);
		printf("#%d ", k + 1);
		for (int i = A[kth] - 1; i < strlen(arr); i++) {
			printf("%c", arr[i]);
		}
		printf("\n");
	}
	return 0;
}
