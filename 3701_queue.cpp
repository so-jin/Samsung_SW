/// === user.cpp ===
 
#ifndef NULL
#define NULL 0
#endif
const int SIZE = 100010;
struct Node {
    int num;
    Node* next;
}buf[SIZE];
int bcnt;
 
struct Queue {
    Node*head, *tail;
    int cnt;
}que;
 
Queue* newQueue() {
    Queue* queue = new Queue;
    queue->head = nullptr;
    queue->tail = nullptr;
    queue->cnt = 0;
    return queue;
}
 
void delQueue(Queue*que) {
    delete(que);
}
 
bool empty(Queue*que) {
    if (que->head == nullptr) return true;
    return false;
}
 
int size(Queue*que) {
    Node* now = que->head;
    int cnt = 0;
    while (now != nullptr) {
        now = now->next;
        cnt++;
    }
    return cnt;
}
 
int front(Queue*que) {
    return que->head->num;
}
 
int back(Queue*que) {
    return que->tail->num;
}
 
void push(Queue*que, int num) {
    Node* node = &buf[bcnt++];
    node->num = num;
    node->next = nullptr;
     
    if (que->head == nullptr) {
        que->head = node;
    }
    if (que->tail == nullptr) {
        que->tail = node;
    }
    else {
        que->tail->next = node;
        que->tail = node;
    }
}
 
void pop(Queue*que) {
     
    //delete(node);
    //que->head = que->head->next;
 
    if (que->head != nullptr) {
        que->head = que->head->next;
    }
}
