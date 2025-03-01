//
// Created by 刘剑飞 on 2025/3/1.
//

#include "doubly_linked_list.h"
#include <stdlib.h>
#include <printf.h>
#include <stdbool.h>

// 初始带头节点双链表
bool InitDLinkList(DLinkList *D) {
    *D = (DNode *) malloc(sizeof(DNode));
    if (*D == NULL) {
        printf("内存分配失败\n");
        return false;
    }
    (*D)->next = NULL;
    (*D)->prior = NULL;
    return true;
}

// 初始不带头节点双链表
bool InitDLinkList1(DLinkList *D) {
    *D = NULL;
    return true;
}
// 在p点之后插入s
bool InsertDLinkList(DNode *p, DNode *s) {
    if (p == NULL || s == NULL) return false;
    s->next = p->next; // 让 s 的 next 指向 p 的后继
    s->prior = p;      // 让 s 的 prior 指向 p
    if (p->next != NULL) { // 若 p 不是尾结点
        p->next->prior = s; // 让 p 的后继的 prior 指向 s
    }
    p->next = s; // 让 p 的 next 指向 s
    return true;
}

// 打印双向链表（从头到尾）
void PrintDLinkList(DLinkList D) {
    DNode *p = D->next;
    printf("正向遍历: ");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 逆向打印双向链表
void PrintDLinkListReverse(DLinkList D) {
    DNode *p = D;
    while (p->next != NULL) {
        p = p->next; // 移动到尾结点
    }
    printf("逆向遍历: ");
    while (p->prior != NULL) { // 只要不是头结点
        printf("%d ", p->data);
        p = p->prior;
    }
    printf("\n");
}
// 删除 p 结点的后继结点
bool DeleteDLinkList(DNode *p) {
    if (p == NULL || p->next == NULL) return false; // p 为空 或 没有后继结点
    DNode *q = p->next; // q 指向待删除结点
    p->next = q->next;  // 让 p 直接跳过 q
    if (q->next != NULL) { // 如果 q 不是最后一个结点
        q->next->prior = p; // 更新后继结点的 prior 指针
    }
    free(q); // 释放 q 结点
    return true;
}

// **测试函数**
void TestInsertDLinkList() {
    DLinkList D;
    InitDLinkList(&D); // 初始化带头结点的双向链表

    // **创建三个初始结点**
    DNode *n1 = (DNode *) malloc(sizeof(DNode));
    DNode *n2 = (DNode *) malloc(sizeof(DNode));
    DNode *n3 = (DNode *) malloc(sizeof(DNode));
    n1->data = 10;
    n1->next = NULL;
    n1->prior = D;
    n2->data = 20;
    n2->next = NULL;
    n2->prior = n1;
    n3->data = 30;
    n3->next = NULL;
    n3->prior = n2;

    D->next = n1;
    n1->next = n2;
    n2->next = n3;

    // **插入新结点 X = 25 到 20 之后**
    DNode *X = (DNode *) malloc(sizeof(DNode));
    X->data = 25;

    printf("插入前:\n");
    PrintDLinkList(D);
    PrintDLinkListReverse(D);

    InsertDLinkList(n2, X); // 在 n2 (20) 之后插入 X (25)

    printf("\n插入后:\n");
    PrintDLinkList(D);
    PrintDLinkListReverse(D);
}

// **测试函数**
void TestDeleteDLinkList() {
    DLinkList D;
    InitDLinkList(&D);

    // **创建四个初始结点**
    DNode *n1 = (DNode *) malloc(sizeof(DNode));
    DNode *n2 = (DNode *) malloc(sizeof(DNode));
    DNode *n3 = (DNode *) malloc(sizeof(DNode));
    DNode *n4 = (DNode *) malloc(sizeof(DNode));

    n1->data = 10; n1->prior = D; D->next = n1;
    n2->data = 20; n2->prior = n1; n1->next = n2;
    n3->data = 30; n3->prior = n2; n2->next = n3;
    n4->data = 40; n4->prior = n3; n3->next = n4;
    n4->next = NULL;

    printf("删除前:\n");
    DNode *p = D->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    // **删除 20 之后的结点（即 30）**
    DeleteDLinkList(n2);

    printf("删除后:\n");
    p = D->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}