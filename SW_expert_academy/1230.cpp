#include <stdio.h>
#include <stdlib.h>
int len, num;
char dir;
//struct Node node;
typedef struct Node {
	int num;
	struct Node *next;
}node;

node * make(int num) {
	node *n = (node *)malloc(sizeof(node));
	n->num = num;
	n->next = NULL;
	return n;
}

void insert(node * head, node * tail) {
	int num, input, len;
	node* now = head->next;
	node* tmp = NULL;
	scanf("%d %d", &num, &len);
	//printf("insert num : %d\n", num);

	if (num == 0) {
		scanf("%d", &num);
		node *n = (node *)malloc(sizeof(node));
		n->num = num;
		n->next = NULL;
		tmp = head->next;
		head->next = n;
		now = n;
		for (int i = 0; i < len-1; i++) {
			scanf("%d", &num);
			node *n = (node *)malloc(sizeof(node));
			n->num = num;
			n->next = NULL;
			now->next = n;
			now = n;
		}
		now->next = tmp;
		//printf("now %d", head->num);
		return;
	}


	for (int i = 0; i < num-1; i++) {
		now = now->next;
	}
	//last
	if (now == tail->next) {
		for (int i = 0; i < len; i++) {
			scanf("%d", &num);
			node *n = (node *)malloc(sizeof(node));
			n->num = num;
			n->next = NULL;
			now->next = n;
			now = n;
		}
	}
	//middle
	else {
		tmp = now->next;
		for (int i = 0; i < len; i++) {
			scanf("%d", &num);
			node *n = (node *)malloc(sizeof(node));
			n->num = num;
			n->next = NULL;
			now->next = n;
			now = n;
		}
		now->next = tmp;
	}


}

void add(node * head, node * tail) {
	int num, input, len;
	node* now = tail->next;
	scanf("%d", &len);

	for (int i = 0; i < len; i++) {
		scanf("%d", &num);
		node *n = (node *)malloc(sizeof(node));
		n->num = num;
		n->next = NULL;
		now->next = n;
		now = n;
	}
	tail = now;
}

void del(node * head, node * tail) {
	int num, input, len;
	node* now = head->next;
	node* tmp = NULL;
	node* start = NULL;
	node* end = NULL;
	scanf("%d %d", &num, &len);
	//printf("insert num : %d\n", num);

	if (num==0) {
		for (int i = 0; i < len; i++) {
			now = now->next;
			//printf("num %d ", now->num);
		}
		head->next = now;
		//printf("now %d", head->num);
		return;
	}

	for (int i = 0; i < num-1; i++) {
		now = now->next;
	}
	start = now;
	for (int i = 0; i < len + 1; i++) {
		now = now->next;
	}

	//tail
	if (now == tail) {
		start->next = NULL;
		tail->next = start;
	}
	//middle
	else {
		end = now;
		start->next = end;
	}
}


void print(node * head) {
	node * now = head->next;
	while (now != NULL) {
		printf("%d ", now->num);
		now = now->next;
	}
	printf("\n");
}

void print10(node * head) {
	node * now = head->next;
	for (int i = 0; i < 10; i++) {
		printf("%d ", now->num);
		now = now->next;
	}
	printf("\n");
}


int main() {


	freopen("input.txt", "r", stdin);
	for (int k = 0; k < 10; k++) {
		struct Node *head = (node *)malloc(sizeof(node));
		struct Node *tail = (node *)malloc(sizeof(node));

		head->next = tail->next = NULL;
		scanf("%d", &len);
		//crypto
		for (int i = 0; i < len; i++) {
			scanf("%d", &num);
			node *n = (node *)malloc(sizeof(node));
			n->num = num;
			n->next = NULL;
			if (head->next == NULL) {
				head->next = n;
				tail->next = n;
			}
			else {
				(tail->next)->next = n;
				tail->next = n;
			}
		}
		//print(head);
		//direction
		scanf("%d", &num);
		for (int i = 0; i < num; i++) {
			scanf(" %c", &dir);
			//printf("dir: %c\n", dir);
			switch (dir) {
			case 'I':
				insert(head, tail);
				break;
			case 'D':
				del(head, tail);
				break;
			case 'A':
				add(head, tail);
				break;
			}
		}
		printf("#%d ", k + 1);
		print10(head);
	}

	return 0;
}
