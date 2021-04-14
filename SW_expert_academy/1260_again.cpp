#include <iostream>
using namespace std;

int test_num, len, matrix_size;
int m, n;
int start, end, in, box_count;
int matrix[100][100];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &test_num);
	for (int k = 0; k < test_num; k++) {
		int box[20][2];
		box_count = 0;
		scanf("%d", &matrix_size);
		for (int i = 0; i < matrix_size; i++) {
			for (int j = 0; j < matrix_size; j++) {
				scanf("%d", &matrix[i][j]);
			}
		}

		for (int i = 0; i < matrix_size; i++) {
			for (int j = 0; j < matrix_size; j++) {
				//if there is a block
				if (matrix[i][j] != 0) {
					printf("find block %d %d \n", i,j);
					// n size
					n = j;
					do {
						matrix[i][n] = 0;
						n++;

					} while (matrix[i][n] != 0);
					n = n - j;
					// m  size
					m = i;
					do {
						for (int l = j; l < j + n; l++) {
							matrix[m][l] = 0;
						}
						matrix[m][j] = 0;
						m++;

					} while (matrix[m][j] != 0);
					m = m - i;
					box[box_count][0] = m;
					box[box_count][1] = n;
					printf("%d %d\n", m, n);
					box_count++;
					j = j + n;

				}
			}
		}
		for (int i = 0; i < box_count; i++) {
			printf("%d %d\n", box[i][0], box[i][1]);
		}

		printf("#%d %d\n", k + 1,10 );
	}
	
	return 0;
}
