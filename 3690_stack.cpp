#ifndef NULL
#define NULL 0
#endif
const int SIZE = 100010;
struct Node {
    int num;
    Node* next;
}buf[SIZE];
int bcnt;
 
struct Stack {
    Node*head;
    int cnt;
}stkObject;
 
Stack* newStack() {
    Stack* stack = new Stack;
    stack->head = nullptr;
    stack->cnt = 0;
    return stack;
}
 
void delStack(Stack*stk) {
    delete(stk);
}
 
bool empty(Stack*stk) {
    if (stk->cnt == 0) return true;
    else return false;
}
 
int size(Stack*stk) {
    return stk->cnt;
}
 
int top(Stack*stk) {
    return stk->head->num;
}
 
void push(Stack*stk, int num) {
    Node* node = &buf[bcnt++];
    node->num = num;     
    node->next = stk->head;
    stk->head = node;
    (stk->cnt)++;
}
 
void pop(Stack*stk) {
    if (stk->cnt == 0) return;
    stk->head =stk->head->next;
    (stk->cnt)--;
}
