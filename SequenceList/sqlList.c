// ����ǿ��ʹ��scanf_s
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdbool.h>

#define MAXSIZE 100

typedef struct{
	int *data;
	int length;
}SqList;

// ��ʼ��
bool InitSqList(SqList * L){
	L->data = (int*)malloc(MAXSIZE * sizeof(int));
	if (!L->data){
		return false;
	}
	else{
		L->length = 0;
		// Ĭ�ϳ�ʼ��5����
		int i = 0;
		for (i; i < 5; i++)
		{
			scanf("%d", &L->data[i]);
		}
		L->length = i;
		return true;
	}
};

// ָ��λ�ò���
void InsertSqList(SqList *L,int ele, int pos) {
	// �����ж��Ƿ�Խ��
	if (L->length ==MAXSIZE)
	{
		printf("�������������");
	}
	else
	{
		if (pos <1 || pos > L->length+1)
		{
			printf("Խ������ѡ��λ��");
		}
		else
		{
			for (int i = L->length-1; i>= pos-1; i--)
			{
				L->data[i+1] = L->data[i];
			}
			L->data[pos-1] = ele;
			L->length++;
		}
	}
}

// ָ��λ��ɾ��
void DelSqList(SqList *L, int pos)
{
	if (pos<1||pos>L->length)
	{
		printf("Խ����");
	}
	else
	{
		if (pos <L->length)
		{
			for (int i = pos-1; i < L->length; i++)
			{
				L->data[i] = L->data[i + 1];
			}
			L->length--;
		}
	}
}
// ָ��ֵɾ��


// �������Ա�
void DestroySqList(SqList *L){
	if (L->data) {
		free(L->data);
	}
}

//������Ա�
void ClearList(SqList *L) {
	//�����Ա�ĳ�����Ϊ0
	L->length = 0;
}

//�����Ա�L�ĳ���
int GetLength(SqList *L) {
	return L->length;
}

// ��ӡ���Ա�
void PrintSqList(SqList *L) {
	for (int i = 0; i < L->length; i++)
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");
}
int main(){
	SqList sqList;
	SqList *p1;
	p1 = &sqList;
	InitSqList(&sqList);
	InsertSqList(&sqList, 213, 2);
	PrintSqList(p1);
	DelSqList(&sqList, 7);
	PrintSqList(p1);
	return 0;
}