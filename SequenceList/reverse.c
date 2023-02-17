// 不再强制使用scanf_s
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdbool.h>

#define MAXSIZE 100
typedef int EleType;

typedef struct {
	EleType *data;
	int length;
}SqList;

// 初始化
bool InitSqList(SqList * L) {
	L->data = (EleType*)malloc(MAXSIZE * sizeof(EleType));
	if (!L->data) {
		return false;
	}
	else {
		L->length = 0;
		// 默认初始化5个数
		int i = 0;
		for (i; i < 6; i++)
		{
			scanf("%d", &L->data[i]);
		}
		L->length = i;
		return true;
	}
};

// 倒置
void reverseList(SqList * list) {
	if (!list->data || list->length == 0) {
		printf("为空无法操作");
	}
	int i = 0,j=list->length-1;
	while (i < j) {
		EleType temp = 0;
		temp = list->data[i];
		list->data[i] = list->data[j];
		list->data[j] = temp;
		i++;
		j--;
	}
}


// 销毁线性表
void DestroySqList(SqList *L) {
	if (L->data) {
		free(L->data);
	}
}

//清空线性表
void ClearList(SqList *L) {
	//将线性表的长度置为0
	L->length = 0;
}

//求线性表L的长度
int GetLength(SqList *L) {
	return L->length;
}

// 打印线性表
void PrintSqList(SqList *L) {
	for (int i = 0; i < L->length; i++)
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");
}
int main() {
	SqList A;
	InitSqList(&A);
	reverseList(&A);
	PrintSqList(&A);
	return 0;
}