//
// Created by 刘剑飞 on 2025/2/27.
//

#include <stdlib.h>
#include <printf.h>
#include <stdbool.h>
#include "link_list.h"

// 带头节点
bool InitLinkList(LinkList *L) {
    *L = (LinkList) malloc(sizeof(LNode)); // 为头节点分配内存
    //L 是一个 指向指针的指针（LinkList *L），而 *L 解引用后是链表的头节点指针（LNode*）
    if (*L == NULL) {
        printf("内存分配失败\n");
        return false;
    }
    (*L)->next = NULL; // 设置头节点的 next 指针为空，表示链表为空
    return true;
}
// 不带头节点
bool InitLinkList1(LinkList *L) {
    *L = NULL;
    return true;
}

// 判断带头节点链表是否为空
bool Empty(LinkList L) {
    return L->next == NULL;
}
// 判断不带头节点链表是否为空
bool Empty1(LinkList L) {
    return L == NULL;
}
// 按位序插入
bool InsertList(LinkList *L, int i, ElemType e) {
    // i 不合法
    if (i < 1) return false;
    LNode *p = *L;
    int j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) return false;
    // 创建新节点
    LNode *s = (LNode *) malloc(sizeof(LNode));
    //s 是一个 指向新节点的指针（LNode*）
    if (s == NULL) {
        printf("内存分配失败\n");
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 不带头节点按位序插入元素
bool InsertList1(LinkList *L, int i, ElemType e) {
    // i值不合法，插入位置小于1，返回 false
    if (i < 1) return false;

    // 如果是插入第一个元素，特殊处理
    if (i == 1) {
        // 为新节点分配内存
        LNode *q = (LNode *) malloc(sizeof(LNode));  // malloc 分配了一个 ElemType 大小的内存，实际上应该分配 LNode 类型的内存
        q->data = e;  // 将插入的元素 e 存储在新节点中
        q->next = *L; // 将新节点的 next 指向原链表的头指针 *L
        *L = q;       // 将 *L 更新为指向新节点，表示新节点成为了新的头节点
        return true;  // 插入成功，返回 true
    }

    // 定义一个指针 p 用于遍历链表，p 指向链表的头节点
    LNode *p = *L;
    int j = 1;  // 用 j 记录遍历的节点位置，初始为 1（第一个节点）

    // 遍历链表，寻找第 i-1 个节点的位置（即插入位置的前一个节点）
    while (p != NULL && j < i - 1) {
        p = p->next;  // p 移动到下一个节点
        j++;          // 累加 j，表示当前节点的位置
    }

    // 如果 p 为 NULL，表示链表中没有足够的节点，无法插入
    if (p == NULL) return false;

    // 创建新节点 s
    LNode *s = (LNode *) malloc(sizeof(LNode));  // 为新节点分配内存
    if (s == NULL) {
        printf("内存分配失败\n");  // 如果内存分配失败，打印错误信息
        return false;  // 返回 false，表示插入失败
    }
    s->data = e;       // 将插入的元素 e 存储在新节点 s 中
    s->next = p->next;  // 将新节点的 next 指向 p 的 next（即插入位置的后一个节点）
    p->next = s;        // 将 p 的 next 指向新节点 s，完成插入操作

    return true;  // 插入成功，返回 true
}

// 增加一个尾指针r，每次插入都让r指向新的表尾结点，时间复杂度为O(n)
void List_TailInsert(LinkList *L) {
    int x;
    *L = (LinkList) malloc(sizeof(LNode)); // 创建头结点
    LNode *s, *r = *L; // r 指向表尾

    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode)); // 申请新结点
        s->data = x;
        r->next = s; // 让尾结点指向新结点
        r = s;       // 更新尾指针
        scanf("%d", &x);
    }
    r->next = NULL; // 最后一个结点的 next 置空
}

// 不带头节点
void List_TailInsert1(LinkList *L) {
    int x;
    LNode *s, *r = NULL; // r 初始化为 NULL
    *L = NULL; // 确保链表为空

    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode)); // 申请新结点
        s->data = x;
        s->next = NULL; // 确保 next 为空

        if (*L == NULL) {
            *L = s; // 让 L 指向第一个结点
        } else {
            r->next = s; // 让前一个结点指向新结点
        }
        r = s; // 更新尾指针

        scanf("%d", &x);
    }
}

// 头插法（带头节点）
void List_HeadInsert(LinkList *L) {
    int x;
    // 创建头节点
    *L = (LNode *) malloc(sizeof(LNode));
    if (*L == NULL) {
        printf("内存分配失败\n");
        return;
    }
    (*L)->next = NULL; // 初始化头结点的 next 指针

    scanf("%d", &x);
    while (x != 9999) {
        LNode *s = (LNode *) malloc(sizeof(LNode)); // 分配新节点
        if (s == NULL) {
            printf("内存分配失败\n");
            return;
        }
        s->data = x;       // 赋值
        s->next = (*L)->next; // 头插法，新的结点指向旧的第一个节点
        (*L)->next = s;    // 头结点指向新插入的结点

        scanf("%d", &x);
    }
}

// 头插法（不带头节点）
void List_HeadInsert1(LinkList *L) {
    int x;
    *L = NULL;
    scanf("%d", &x);
    while (x != 9999) {
        LNode *s = (LNode *) malloc(sizeof(LNode));
        if (s == NULL) {
            printf("内存分配失败\n");
            return;
        }
        s->data = x;
        s->next = *L;
        *L = s;
        scanf("%d", &x);
    }
}

void PintLinkList(LinkList L) {
    LinkList p = L->next; // 从第一个有效节点开始打印
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;  // 移动到下一个节点
    }
    printf("NULL\n"); // 链表结束
}

// 打印不带头节点
void PintLinkList1(LinkList L) {
    LinkList p = L;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;  // 移动到下一个节点
    }
    printf("NULL\n"); // 链表结束
}