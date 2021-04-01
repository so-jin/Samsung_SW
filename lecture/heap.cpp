#include <iostream>

using namespace std;

const int HEAP_SIZE = 50;

int heap[HEAP_SIZE] = { 0, };
int heapCount = 0;

void push(int value) {
	heap[++heapCount] = value;

	int child = heapCount;
	int parent = child >> 1;
	while (parent > 0 && heap[parent] > heap[child]) {
		int tmp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = tmp;

		child = parent;
		parent = child >> 1;
	}
}
//PQ로 운영하는 경우 extractMin(), extractMax()이름을 사용함.
int pop() {
	int parent = 1;	//root
	int ret = heap[parent];
	heap[parent] = heap[heapCount];
	heap[heapCount--] = 0;
	int child = 2 * parent;	//left child
	//right child is exist
	if (child + 1 <= heapCount) {
		child = (heap[child] < heap[child + 1]) ? child : child + 1;

	}
	//위치 바꾸기
	while (child <= heapCount && heap[parent] > heap[child]) {
		int tmp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = tmp;

		parent = child;
		child = parent << 1;
		if (child + 1 <= heapCount) {
			child = (heap[child] < heap[child + 1]) ? child : child + 1;

		}
	}
	return ret;
}



void printHeap() {
	int pow2[] = { 1,2,4,8,16,32,64 };
	int nextLevel = 1;
	for (int i = 1; i < HEAP_SIZE; i++) {
		//한 줄마다 개행 찍기
		if (i == pow2[nextLevel]) {
			cout << endl;
			nextLevel++;
		}
		//완전 이진트리가 아님
		if (heap[i]) {
			cout << heap[i] << " ";
		}

	}
	cout << endl;
}



int main() {
	push(20);
	push(17);
	push(19);
	push(4);
	push(13);
	push(11);
	push(23);

	printHeap();

	cout << pop() << endl << endl;
	printHeap();
	return 0;
}
