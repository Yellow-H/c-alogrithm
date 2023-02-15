// 不再强制使用scanf_s
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdbool.h>

#define MAXSIZE 100

typedef struct{
	int *data;
	int length;
}SqList;

// 初始化
bool InitSqList(SqList * L){
	L->data = (int*)malloc(MAXSIZE * sizeof(int));
	if (!L->data){
		return false;
	}
	else{
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

// 指定位置插入
void InsertSqList(SqList *L,int ele, int pos) {
	// 首先判断是否越界
	if (L->length ==MAXSIZE)
	{
		printf("已满不允许插入");
	}
	else
	{
		if (pos <1 || pos > L->length+1)
		{
			printf("越界重新选择位置");
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

// 指定位置删除
void DelSqList(SqList *L, int pos)
{
	if (pos<1||pos>L->length)
	{
		printf("越界了");
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
// 指定值删除


// 销毁线性表
void DestroySqList(SqList *L){
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