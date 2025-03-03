//
// Created by 刘剑飞 on 2025/3/1.
//

#ifndef DATASTRUCTUREDEMO_STACK_H
#define DATASTRUCTUREDEMO_STACK_H

#include <stdbool.h>

#define MaxSize 10 // 栈的最大容量
typedef struct {
    int data[MaxSize]; // 存储栈的元素
    int top; // 栈顶指针
} Stack;

void InitStack(Stack *S);

void DestroyStack(Stack *S);

bool Push(Stack *S, int e);

bool Pop(Stack *S, int *e);

bool IsEmpty(Stack S);

bool IsFull(Stack S);

void TestStack();

typedef struct {
    int data[MaxSize];
    int top1;
    int top2;
} ShStack;

void InitShStack(ShStack *S);

bool Push1(ShStack *S, int e);

bool Push2(ShStack *S, int e);

bool Pop1(ShStack *S, int *e);

bool Pop2(ShStack *S, int *e);

bool IsShStackEmpty(ShStack S);

bool IsShStackFull(ShStack S);

typedef struct LinkStackNode {
    int data;
    struct LinkStackNode *next;
} LinkStackNode, *LinkStack;

void InitLinkStack(LinkStack *S);

bool PushLinkStack(LinkStack *S, int e);

bool PopLinkStack(LinkStack *S, int *e);

bool IsLinkStackEmpty(LinkStack S);

void TestLinkStack();

#endif //DATASTRUCTUREDEMO_STACK_H
