//
// Created by 刘剑飞 on 2025/3/3.
//

#include <printf.h>
#include <stdlib.h>
#include "queue.h"

// 初始化队列
void InitQueue(SqQueue *Q) {
    Q->front = Q->rear = 0;
}


bool EnQueue(SqQueue *Q, ElemType e) {
    if ((Q->rear + 1) % MaxSize == Q->front) return false; // 队列满
    Q->data[Q->rear] = e; // 元素入队
    Q->rear = (Q->rear + 1) % MaxSize; // 队尾指针加 1
    return true;
}

bool DeQueue(SqQueue *Q, ElemType *e) {
    if (Q->front == Q->rear) return false; // 队列为空
    *e = Q->data[Q->front]; // 取出队头元素
    Q->front = (Q->front + 1) % MaxSize; // 队头指针加 1
    return true;
}

bool IsQueueFull(SqQueue Q) {
    return (Q.rear + 1) % MaxSize == Q.front; // 尾指针下一个是头指针则满
}

bool IsQueueEmpty(SqQueue Q) {
    return Q.front == Q.rear; // 头尾指针相等则空
}

void TestQueue() {
    SqQueue Q;
    InitQueue(&Q);

    printf("队列是否为空: %d\n", IsQueueEmpty(Q)); // 应该输出 1 (true)

    EnQueue(&Q, 10);
    EnQueue(&Q, 20);
    EnQueue(&Q, 30);

    printf("队列是否为空: %d\n", IsQueueEmpty(Q)); // 应该输出 0 (false)

    ElemType e;
    DeQueue(&Q, &e);
    printf("出队元素: %d\n", e); // 应该输出 10

    DeQueue(&Q, &e);
    printf("出队元素: %d\n", e); // 应该输出 20

    printf("队列是否满: %d\n", IsQueueFull(Q)); // 应该输出 0 (false)
}

// 带头结点的链队列
bool InitLinkQueue(LinkQueue *Q) {
    Q->front = Q->rear = (LinkQueueNode *) malloc(sizeof(LinkQueueNode)); // 创建头结点
    if (Q->front == NULL) { // 内存分配失败
        printf("内存分配失败");
        return false;
    }
    Q->front->next = NULL; // 头结点的指针域置空
    return true;
}

// 入队
bool EnLinkQueue(LinkQueue *Q, ElemType e) {
    LinkQueueNode *p = (LinkQueueNode *) malloc(sizeof(LinkQueueNode)); // 创建新结点
    if (p == NULL) { // 内存分配失败
        return false; // 入队失败
    }
    p->data = e; // 新结点赋值
    p->next = NULL; // 新结点指针域置空
    Q->rear->next = p; // 尾结点指向新结点
    Q->rear = p; // 尾指针指向新结点
    return true;
}
// 出队
bool DeLinkQueue(LinkQueue *Q, ElemType *e) {
    if (Q->front == Q->rear) return false; // 队列为空
    LinkQueueNode *p = Q->front->next; // 指向头结点的下一个结点
    *e = p->data; // 取出队头元素
    Q->front->next = p->next; // 头结点指向下一个结点
    if (Q->rear == p) Q->rear = Q->front; // 如果只有一个结点，删除后置空
    free(p); // 释放结点
    return true;
}


// 不带头结点的链队列
bool InitLinkQueue1(LinkQueue *Q) {
    Q->front = Q->rear = NULL; // 头尾指针置空
    return true;
}

bool EnLinkQueue1(LinkQueue *Q, ElemType e) {
    LinkQueueNode *p = (LinkQueueNode *) malloc(sizeof(LinkQueueNode)); // 创建新结点
    if (p == NULL) { // 内存分配失败
        return false; // 入队失败
    }
    p->data = e; // 新结点赋值
    p->next = NULL; // 新结点指针域置空
    if (Q->front == NULL) { // 队列为空
        Q->front = Q->rear = p; // 头尾指针指向新结点
    } else {
        Q->rear->next = p; // 尾结点指向新结点
        Q->rear = p; // 尾指针指向新结点
    }
    return true;
}

// 出队
bool DeLinkQueue1(LinkQueue *Q, ElemType *e) {
    if (Q->front == NULL) return false; // 队列为空
    LinkQueueNode *p = Q->front; // 指向头结点
    *e = p->data; // 取出队头元素
    Q->front = p->next; // 头结点指向下一个结点
    if (Q->front == NULL) { // 如果队列删除后为空，rear 也要置空
        Q->rear = NULL;
    }
    free(p); // 释放结点
    return true;
}