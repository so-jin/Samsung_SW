#include <stdio.h>
#include <string.h>  
#include<iostream>
#include <stdlib.h>
using namespace std;
int node_size;

union data_index_{
	long double num;
	char cal;
};
enum flag_{
	NUM, CAL
};

struct Node {
	data_index_ data_index;
	flag_ flag;
	int left;
	int right;
};

long double postorder(int index, Node* tree[]) {
	//printf("cal %d\n", index);
	Node *node = tree[index];
	if (node == NULL) {
		//printf("Node is not found \n");
		return 0;
	}

	if (node->flag == NUM) {
		//printf("Num: %d %Lf\n",index, node->data_index.num);
		return (long double)node->data_index.num;

	}
	long double result=0;
	long double left = postorder(node->left, tree);
	long double right = postorder(node->right, tree);
	switch (node->data_index.cal) {
		case '+':
			return result = left + right;
			break;
		case '-':
			return result = left - right;
			break;
		case '*':
			return result = left * right;
			break;
		case '/':
			return result = left / right;
			break;
	}
	//node->flag = NUM;
	//node->data_index.num = result;
	//printf("tmp result %Lf %c %Lf = %Lf\n",left, node->data_index.cal, right, result);
}

int main() {
	freopen("input.txt", "r", stdin);
	for (int k = 0; k < 10; k++) {
		scanf("%d ", &node_size);
		//printf("%d ", node_size);
		Node* tree[10001] = { nullptr, };


		for (int i = 1; i <=node_size; i++) {
			char input[20] = { 0, };
			char *check[4] = {NULL, };
			int index;
			
			cin.getline(input, 100);


			//printf("check\n");
			char *ptr = strtok(input, " ");      // " " 공백 문자를 기준으로 문자열을 자름, 포인터 반환
			int j = 0;

			while (ptr != NULL)               // 자른 문자열이 나오지 않을 때까지 반복
			{
				check[j++] = ptr;
				//printf("%s ", ptr);
				// 자른 문자열 출력
				ptr = strtok(NULL, " ");      // 다음 문자열을 잘라서 포인터를 반환

			}
			if (j == 4) {
				Node *newNode = new Node;
				if (newNode != NULL) {
					newNode->data_index.cal = *check[1];
					newNode->left = atoi(check[2]);
					newNode->right = atoi(check[3]);
					newNode->flag = CAL;
					//printf("make node %c %d %d\n", newNode->data_index.cal, newNode->left, newNode->right);
				}
				tree[atoi(check[0])] = newNode;
			}
			else {
				Node *newNode = new Node;
				newNode->data_index.num = (long double)atoi(check[1]);
				newNode->left = 0;
				newNode->right = 0;
				newNode->flag = NUM;
				//printf("make node %Lf\n", newNode->data_index.num);
				tree[atoi(check[0])] = newNode;

			}
			//printf(" %d \n",j);

		}


		

		printf("#%d %.0Lf \n",k+1, postorder(1, tree));

	
		for (int i = 1; i <= node_size; i++) {
			delete(tree[i]);
		}
		
		//start by root // post order




	}

	return 0;
}
