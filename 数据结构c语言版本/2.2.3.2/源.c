#include"stdio.h"
#define MaxSize 30
#define true 1
#define false 0
typedef int ElemType;

typedef struct {
	int Data[MaxSize];
	int length;
}SqlList;

void InitList(SqlList* L) {
	L->length = 0;
	return true;
}

visit(ElemType c) {
	printf("%d", c);
	return true;
}

ListTraverse(SqlList L)
{
	int i;
	for (i = 0; i < L.length; i++)
		visit(L.Data[i]);
	printf("\n");
	return true;
}

ListInsert(SqlList* L, int i, ElemType e) {
	int j;
	if (i<1 || i>L->length + 1) {
		return false;
	}
	if (L->length >= MaxSize)
		return false;
	for (j = L->length; j >= i; j--)
		L->Data[j] = L->Data[j - 1];
	L->Data[i - 1] = e;
	L->length++;
	return true;
}

void NiZhi(SqlList* L) {
	ElemType temp;
	for (int i = 0; i < L->length/2; i++)
	{
		temp = L->Data[i];
		L->Data[i] = L->Data[L->length-i - 1];
		L->Data[L->length - 1 - i] = temp;
	}
}

int main() {
	SqlList L;
	InitList(&L);
	ListInsert(&L, 1, 7);
	ListInsert(&L, 1, 8);
	ListInsert(&L, 1, 2);
	ListInsert(&L, 1, 3);
	ListInsert(&L, 1, 6);
	ListTraverse(L);
	NiZhi(&L);
	ListTraverse(L);
}