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

//����չʾ���Ա�
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

//������ ��ʼ����
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

//��Ҫ��˼�� ����3��4������ ���Ա���ɾ��Ԫ��ʱ��˼��
//����֮�����ڽ���������֮�ڵ�ͳ������ �����ĽǶ�˼��
//Ӧ�÷�ΧӦ�ýϹ�
//�о�͸

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

	//�������ϵĲ�ͬ �����ϵ�˵������� ����ͨ��������ı���ͬʱҲ����ʵ����������Ա�
	//�����ϵĵ��������Լ򵥣����Ǻ͵�����İ취֮���ʱ�临�Ӷȿ��ܲ�һ����

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

