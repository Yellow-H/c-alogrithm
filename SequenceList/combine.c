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
		for (i; i < 5; i++)
		{
			scanf("%d", &L->data[i]);
		}
		L->length = i;
		return true;
	}
};

// 两个表合并（a,b有序递增）
void combination(SqList *listA, SqList *listB, SqList *listC) {
	int i=0,j=0,k = 0;
	if (listA->length == 0 && !listA->data) {
		listC->data = listB->data;
	}
	if (listB->length == 0 && !listB->data) {
		listC->data = listA->data;
	}
	while (i != listA->length && j != listB->length) {
		// 小的往c放 相同就随便取一个
		if (listA->data[i] > listB->data[j]) {
			listC->data[k] = listB->data[j];
			k++;
			j++;
		}
		else if (listA->data[i] < listB->data[j]) {
			listC->data[k] = listA->data[i];
			k++;
			i++;
		}
		else {
			listC->data[k] = listA->data[i];
			i++;
			j++;
			k++;
		}
		listC->length++;
	}
	// 剩下的直接放
	while (i < listA->length) {
		listC->data[k] = listA->data[i];
		k++;
		i++;
		listC->length++;
	}
	while (j < listB->length) {
		listC->data[k] = listB->data[j];
		k++;
		j++;
		listC->length++;
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
	SqList B;
	InitSqList(&B);
	SqList C;
	C.data = (EleType*)malloc(MAXSIZE*2*sizeof(EleType));
	C.length = 0;
	combination(&A, &B, &C);
	PrintSqList(&C);
	return 0;
}