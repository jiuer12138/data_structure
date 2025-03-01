//
// Created by 刘剑飞 on 2025/3/1.
//

#ifndef DATASTRUCTUREDEMO_DOUBLY_LINKED_LIST_H
#define DATASTRUCTUREDEMO_DOUBLY_LINKED_LIST_H

#include <stdbool.h>

typedef int ElemType;
// 定义双链表节点结构
typedef struct DNode {
    ElemType data; // 存储数据
    struct DNode *prior, *next; // 指向前驱节点的指针和指向后继节点的指针
} DNode, *DLinkList; // DNode 结构体类型，DLinkList 表示双向链表的头指针

bool InitDLinkList(DLinkList *D);

bool InitDLinkList1(DLinkList *D);

bool InsertDLinkList(DNode *p, DNode *s);

void PrintDLinkList(DLinkList D);

void PrintDLinkListReverse(DLinkList D);

void TestInsertDLinkList();

bool DeleteDLinkList(DNode *p);
void TestDeleteDLinkList();

#endif //DATASTRUCTUREDEMO_DOUBLY_LINKED_LIST_H
