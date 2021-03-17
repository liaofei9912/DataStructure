#include "stdio.h"

#define true 1
#define false 0
#define MaxSize 30

typedef int ElemType;
typedef struct {
	int Data[MaxSize];
	int Length;
}SqlList;

void InitList(SqlList* L) {
	L->Length = 0;
	return true;
}

//遍历展示线性表
visit(ElemType c) {
	printf("%d", c);
	return true;
}

ListTraverse(SqlList L)
{
	int i;
	for (i = 0; i < L.Length; i++)
		visit(L.Data[i]);
	printf("\n");
	return true;
}

//插入用 初始化用
ListInsert(SqlList* L, int i, ElemType e) {
	int j;
	if (i<1 || i>L->Length + 1) {
		return false;
	}
	if (L->Length >= MaxSize)
		return false;
	for (j = L->Length; j >= i; j--)
		L->Data[j] = L->Data[j - 1];
	L->Data[i - 1] = e;
	L->Length++;
	return true;
}

//重要的思想 在题3和4中运用 线性表中删除元素时的思想
//独特之处在于将不再条件之内的统计下来 对立的角度思考
//应用范围应该较广
//研究透

Delete(SqlList* L, ElemType e, ElemType w) {
	if (L->Length==0||e>=w)
	{
		return false;
	}
	int k = 0;
	for (int i = 0; i < L->Length; i++)
	{
		if ( L->Data[i] <=e||L->Data[i]>=w) {
			L->Data[k] = L->Data[i];
			k++;
		}
	}
	L->Length = k;
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
	Delete(&L, 2,8);
	ListTraverse(L);

	//与王道上的不同 王道上的说是有序的 而我通过第三题的变形同时也可以实现无序的线性表
	//王道上的第四题答案相对简单，但是和第三题的办法之间的时间复杂度可能不一样。

	SqlList A;
	InitList(&A);
	ListInsert(&A, 1, 5);
	ListInsert(&A, 1, 4);
	ListInsert(&A, 1, 3);
	ListInsert(&A, 1, 2);
	ListInsert(&A, 1, 1);
	ListTraverse(A);
	Delete(&A, 2, 4);
	ListTraverse(A);
}

