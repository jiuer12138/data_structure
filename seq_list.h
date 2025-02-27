#ifndef DATASTRUCTUREDEMO_SEQ_LIST_H
#define DATASTRUCTUREDEMO_SEQ_LIST_H

#include <stdbool.h>
#include <stdlib.h>

#define MaxSize 10
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int length;
} SeqList;

void InitSeqList(SeqList *list);

int InsertSeqList(SeqList *list, int pos, ElemType value);

bool DeleteSeqList(SeqList *list, int pos, ElemType *e);

void PrintSeqList(SeqList *list);

#define InitSize 10
typedef struct {
    ElemType *data;
    int length;
    int MAXSIZE;
} DynamicSeqList;

void InitDynamicSeqList(DynamicSeqList *dynamicSeqList);

void IncreaseSize(DynamicSeqList *dynamicSeqList, int len);

void PrintDynamicSeqList(DynamicSeqList *list);

#endif //DATASTRUCTUREDEMO_SEQ_LIST_H
