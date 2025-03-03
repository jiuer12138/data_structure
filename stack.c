//
// Created by 刘剑飞 on 2025/3/1.
//

#include <stdlib.h>
#include <printf.h>
#include "stack.h"

// 初始化栈
void InitStack(Stack *S) {
    S->top = -1; // 栈顶初始化为 -1，表示空栈
}

// 销毁栈（顺序栈只需将栈顶重置，无需释放内存）
void DestroyStack(Stack *S) {
    S->top = -1; // 直接将栈顶置为 -1，表示栈为空
}

// 入栈
bool Push(Stack *S, int e) {
    // 栈满检查
    if (S->top == MaxSize - 1) return false;
    S->data[++S->top] = e; // 先移动栈顶指针，再存储元素
    // S->top++;
    // S->data[S->top] = e;
    return true;
}

// 出栈
bool Pop(Stack *S, int *e) {
    // 栈空检查
    if (S->top == -1) return false;
    *e = S->data[S->top--]; // 先取值，再移动栈顶指针
    return true;
}

// 判断是否空栈
bool IsEmpty(Stack S) {
    return S.top == -1;
}

// 判断是否栈满
bool IsFull(Stack S) {
    return S.top == MaxSize - 1;
}

// 测试函数
void TestStack() {
    Stack S;
    InitStack(&S);

    printf("栈是否为空: %d\n", IsEmpty(S)); // 应该输出 1 (true)

    Push(&S, 10);
    Push(&S, 20);
    Push(&S, 30);

    printf("栈是否为空: %d\n", IsEmpty(S)); // 应该输出 0 (false)

    int e;
    Pop(&S, &e);
    printf("出栈元素: %d\n", e); // 应该输出 30

    Pop(&S, &e);
    printf("出栈元素: %d\n", e); // 应该输出 20

    printf("栈是否满: %d\n", IsFull(S)); // 应该输出 0 (false)
}

// 初始化共享栈
void InitShStack(ShStack *S) {
    S->top1 = -1;      // 栈 1 初始化为空
    S->top2 = MaxSize; // 栈 2 初始化为空
}

// 栈 1 入栈
bool Push1(ShStack *S, int e) {
    // 栈满：两栈指针相邻
    if (S->top2 - S->top1 == 1) return false;
    S->data[++S->top1] = e; // 先增加 top1，再存入数据
    return true;
}

// 栈 2 入栈
bool Push2(ShStack *S, int e) {
    // 栈满：两栈指针相邻
    if (S->top2 - S->top1 == 1) return false;
    S->data[--S->top2] = e; // 先减少 top2，再存入数据
    return true;
}

// 栈 1 出栈
bool Pop1(ShStack *S, int *e) {
    if (S->top1 == -1) return false; // 栈 1 为空
    *e = S->data[S->top1--]; // 先取数据，再减少 top1
    return true;
}

// 栈 2 出栈
bool Pop2(ShStack *S, int *e) {
    if (S->top2 == MaxSize) return false; // 栈 2 为空
    *e = S->data[S->top2++]; // 先取数据，再增加 top2
    return true;
}

// 判断共享栈是否为空
bool IsShStackEmpty(ShStack S) {
    return S.top1 == -1 && S.top2 == MaxSize; // 两个栈都为空
}

// 判断共享栈是否满
bool IsShStackFull(ShStack S) {
    return S.top2 - S.top1 == 1; // 两栈指针相邻则满
}


void InitLinkStack(LinkStack *S) {
    *S = NULL;
}

bool PushLinkStack(LinkStack *S, int e) {
    LinkStackNode *p = (LinkStackNode *) malloc(sizeof(LinkStackNode));
    if (p == NULL) {
        return false;
    }
    p->data = e;
    p->next = *S;
    *S = p;
    return true;
}

bool PopLinkStack(LinkStack *S, int *e) {
    if (*S == NULL) {
        return false;
    }
    LinkStackNode *p = *S;
    *e = p->data;
    *S = p->next;
    free(p);
    return true;
}

bool IsLinkStackEmpty(LinkStack S) {
    return S == NULL;
}

void TestLinkStack() {
    LinkStack S;
    InitLinkStack(&S);

    printf("栈是否为空: %d\n", IsLinkStackEmpty(S)); // 应该输出 1 (true)

    PushLinkStack(&S, 10);
    PushLinkStack(&S, 20);
    PushLinkStack(&S, 30);

    printf("栈是否为空: %d\n", IsLinkStackEmpty(S)); // 应该输出 0 (false)

    int e;
    PopLinkStack(&S, &e);
    printf("出栈元素: %d\n", e); // 应该输出 30

    PopLinkStack(&S, &e);
    printf("出栈元素: %d\n", e); // 应该输出 20

    printf("栈是否空: %d\n", IsLinkStackEmpty(S)); // 应该输出 0 (false)
}