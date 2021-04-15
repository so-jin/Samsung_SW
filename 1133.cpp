#include<iostream>
int hashing(char *s) {
	int val = 1;
	int sum = 0;
	int i = 0;
	//printf("%s", s);
	while (s[i]) {
		sum += (s[i] >> val);
		val >>= 3;
		i++;
	}
	//printf("hash %d\n", sum);
	return sum;
}

int strlen(char *s, int i = 0) {
	while (s[i]) i++;
	if (i && s[i - 1] == '\n') s[--i] = 0;
	if (i&& s[i - 1] == '\r') s[--i] = 0;
	return i;
}
 
int strcmp(const char*s, const char*t) {
	while (*s && *s == *t) s++, t++;
	return *s - *t;
}

int num;
char st[10001][21];
short visit[10001];
int hash[10001];
int flag;
int found;
int main() {
	freopen("string.txt", "r", stdin);
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		scanf("%s", st[i]);
		//len[i] = strlen(st[i]);
		hash[i] = hashing(st[i]);
	}


	for (int i = 1; i <= num; i++) {
		flag = 0;
		for (int j = i+1; j <= num; j++) {
			if (visit[j] == 0 && hash[i] == hash[j] && strcmp(st[i], st[j]) == 0) {
				//printf("same %s %s\n", st[i], st[j]);
				//first found 
				if (visit[i] == 0) {
					printf("%s %d ", st[i], i);
					visit[i] = 1;
					flag = 1;
					found = 1;
				} 
				visit[j] = 1;
				printf("%d ", j);
			}
		}
		if (flag == 1) {
			printf("\n");
		}
	}
	if (found == 0) {
		printf("unique");
	}
}
