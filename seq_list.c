#include <stdio.h>
#include "seq_list.h"

// 初始顺序表
void InitSeqList(SeqList *seqList) {
    for (int i = 0; i < MaxSize; i++) {
        // 初始值  不初始可能会 随机垃圾值
        seqList->data[i] = 0;
    }
    // 不初始length 会是随机值 影响遍历 读取等操作
    seqList->length = 0;
}

// 在pos处 插入value  注意：顺序表是从1开始的  约定插入返回 0 为失败 1为成功
int InsertSeqList(SeqList *seqList, int pos, ElemType value) {
    // 边界判断
    if (pos < 1 || pos > MaxSize) return 0;
    // pos开始都往后移动一位
    for (int i = seqList->length; i > pos - 1; i--) {
        seqList->data[i] = seqList->data[i - 1];
    }
    seqList->data[pos - 1] = value;
    // 不能忘记改变长度，不然顺序表逻辑长度不会更新
    seqList->length++;
    return 1;
}

// 删除pos处的 值 并通过e 返回 不合法的pos 返回false
bool DeleteSeqList(SeqList *seqList, int pos, ElemType *e) {
    // 边界判断
    if (pos < 1 || pos > MaxSize) return false;
    // 获取pos处的值
    *e = seqList->data[pos - 1];
    // pos开始 都往前移动一位
    for (int i = pos - 1; i < seqList->length - 1; i++) {
        seqList->data[i] = seqList->data[i + 1];
    }
    // 不能忘记改变长度，不然顺序表逻辑长度不会更新
    seqList->length--;
    return true;
}


// 打印顺序表
void PrintSeqList(SeqList *list) {
    printf("顺序表: ");
    for (int i = 0; i < list->length; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

//初始动态顺序表
void InitDynamicSeqList(DynamicSeqList *dynamicSeqList) {
    // 用malloc申请一片连续的存储空间
    dynamicSeqList->data = (int *) malloc(InitSize * sizeof(int));
    dynamicSeqList->MAXSIZE = InitSize;
    dynamicSeqList->length = 0;
}

// 动态改变动态顺序表长度 增加len长度
void IncreaseSize(DynamicSeqList *dynamicSeqList, int len) {
    int *p = dynamicSeqList->data;
    dynamicSeqList->data = (int *) malloc((InitSize + len) * sizeof(int));
    for (int i = 0; i < dynamicSeqList->length; i++) {
        dynamicSeqList->data[i] = p[i];  //复制元素到新的区域
    }
    dynamicSeqList->MAXSIZE += len;
    free(p);
}

// 打印顺序表
void PrintDynamicSeqList(DynamicSeqList *list) {
    printf("动态顺序表: ");
    for (int i = 0; i < list->length; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
    printf("动态顺序表当前长度: %d", list->length);
    printf("\n");
    printf("动态顺序表最大长度: %d", list->MAXSIZE);
    printf("\n");
}