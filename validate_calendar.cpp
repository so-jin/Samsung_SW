# include <stdio.h>


int main() {
	int num;
	char input[9];
	int cal[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf(" %s", input);
		int month = (input[4] - '0') * 10 + (input[5]-'0');
		int day = (input[6] - '0') * 10 + (input[7] - '0');
		if (month < 1 || month>12 || day < 1 || day>31) {
			printf("#%d %d\n", i + 1, -1);
		}
		else if(cal[month] >= day){
			printf("#%d %s\n", i + 1, input);
		}
		else {
			printf("#%d %d\n", i + 1, -1);
		}

	}

	return 0;
}
