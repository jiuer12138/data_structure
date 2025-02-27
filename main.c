#include <stdio.h>
#include "seq_list.h"

int main(void) {
    // 顺序表
    SeqList seqList;
    InitSeqList(&seqList);
    InsertSeqList(&seqList, 1, 10);
    InsertSeqList(&seqList, 2, 20);
    InsertSeqList(&seqList, 3, 30);
    ElemType e;
    DeleteSeqList(&seqList, 1, &e);
    printf("删除的元素为:%d ", e);
    printf("\n");
    PrintSeqList(&seqList);
    // 可动态改变长度 顺序表
    DynamicSeqList dynamicSeqList;
    InitDynamicSeqList(&dynamicSeqList);
    PrintDynamicSeqList(&dynamicSeqList);
    // 增加10的最大长度
    IncreaseSize(&dynamicSeqList,10);
    PrintDynamicSeqList(&dynamicSeqList);
    return 0;
}
