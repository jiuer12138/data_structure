//
// Created by 刘剑飞 on 2025/3/3.
//

#ifndef DATASTRUCTUREDEMO_QUEUE_H
#define DATASTRUCTUREDEMO_QUEUE_H

#include <stdbool.h>

#define MaxSize 10
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

void InitQueue(SqQueue *Q);

bool EnQueue(SqQueue *Q, ElemType e);

bool DeQueue(SqQueue *Q, ElemType *e);

bool IsQueueFull(SqQueue Q);

bool IsQueueEmpty(SqQueue Q);

void TestQueue();
typedef struct {
    ElemType data; // 数据域
    struct LinkQueueNode *next; // 指针域
} LinkQueueNode; // 链队列结点
typedef struct {
    LinkQueueNode *front, *rear; // 头指针和尾指针
} LinkQueue; // 链队列

bool InitLinkQueue(LinkQueue *Q);

bool EnLinkQueue(LinkQueue *Q, ElemType e);

bool DeLinkQueue(LinkQueue *Q, ElemType *e);

bool InitLinkQueue1(LinkQueue *Q);

bool EnLinkQueue1(LinkQueue *Q, ElemType e);

bool DeLinkQueue1(LinkQueue *Q, ElemType *e);

#endif //DATASTRUCTUREDEMO_QUEUE_H
