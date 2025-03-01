//
// Created by 刘剑飞 on 2025/2/27.
//

#ifndef DATASTRUCTUREDEMO_LINK_LIST_H
#define DATASTRUCTUREDEMO_LINK_LIST_H
typedef int ElemType; // 定义数据类型为 int
// 定义链表节点结构
typedef struct LNode {
    ElemType data;      // 存储数据
    struct LNode *next; // 指向下一个节点
} LNode, *LinkList;    // LNode 是结构体类型，LinkList 是指向 LNode 的指针类型Ï

bool InitLinkList(LinkList *L);

bool InitLinkList1(LinkList *L);

bool Empty(LinkList L);

bool Empty1(LinkList L);

bool InsertList(LinkList *L, int i, ElemType e);

bool InsertList1(LinkList *L, int i, ElemType e);

void PintLinkList(LinkList L);

void PintLinkList1(LinkList L);

void List_TailInsert(LinkList *L);

void List_TailInsert1(LinkList *L);

void List_HeadInsert(LinkList *L);

void List_HeadInsert1(LinkList *L);

#endif //DATASTRUCTUREDEMO_LINK_LIST_H
