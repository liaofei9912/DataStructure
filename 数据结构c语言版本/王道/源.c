#include"stdio.h"
#define MaxSize 30

#define true 1
#define false 0
typedef int ElemType;

typedef struct {
	int data[MaxSize];
	int length;
}SqlLast;

void InitList(SqlLast* L) {
	L->length = 0;
	return true;
}

visit(ElemType c) {
	printf("%d", c);
	return true;
}

ListTraverse(SqlLast L)
{
	int i;
	for (i = 0; i < L.length; i++)
		visit(L.data[i]);
	printf("\n");
	return true;
}

//找最小
int Frist(SqlLast* L) {
	int Min = L->data[0];
	int q = L->length - 1;
	int i;
	if (L->length == 0)
	{
		printf("输入有误");
	}
	for (i = 0; i < L->length; i++)
	{
		if (Min < L->data[i])
		{
			Min = L->data[i];
			L->data[i - 1] = L->data[q];
		}
	}
	L->data[i] = L->data[q];
	int w = L->data[i];
	return w;
}


//插入用 初始化用
ListInsert(SqlLast* L, int i, ElemType e) {
	int j;
	if (i<1 || i>L->length + 1) {
		return false;
	}
	if (L->length >= MaxSize)
		return false;
	for (j = L->length; j >= i; j--)
		L->data[j] = L->data[j - 1];
	L->data[i - 1] = e;
	L->length++;
	return true;
}


int main() {
	SqlLast L;
	InitList(&L);
	ListInsert(&L, 1, 7);
	ListInsert(&L, 1, 8);
	ListInsert(&L, 1, 2);
	ListInsert(&L, 1, 3);
	ListInsert(&L, 1, 6);
	ListTraverse(L);
	Frist(&L);
	ListTraverse(L);
}