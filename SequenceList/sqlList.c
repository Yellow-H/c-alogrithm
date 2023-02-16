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

// 搜索查找返回为第几个
int FindByValue(SqList *L, EleType val) {
	if (L->length ==0 || !L->data)
	{
		printf("空表");
		return -1;
	}
	for (int i = 0; i <=L->length-1; i++)
	{
		if (L->data[i] == val)
		{
			return i+1;
		}
	}
}

// 指定位置插入
void InsertSqList(SqList *L, int ele, int pos) {
	// 首先判断是否越界
	if (L->length == MAXSIZE)
	{
		printf("已满不允许插入");
	}
	else
	{
		if (pos <1 || pos > L->length + 1)
		{
			printf("越界重新选择位置");
		}
		else
		{
			for (int i = L->length - 1; i >= pos - 1; i--)
			{
				L->data[i + 1] = L->data[i];
			}
			L->data[pos - 1] = ele;
			L->length++;
		}
	}
}

// 指定位置删除
void DelSqList(SqList *L, int pos)
{
	if (pos<1 || pos>L->length)
	{
		printf("越界了");
	}
	else
	{
		if (pos < L->length)
		{
			for (int i = pos - 1; i < L->length; i++)
			{
				L->data[i] = L->data[i + 1];
			}
			L->length--;
		}
	}
}
// 指定值删除
int DelByValue(SqList *L, EleType val) {
	if (!L->data ||L->length ==0)
	{
		printf("无元素无法删除");
		return -1;
	}
	int i = 0;
	while (i < L->length) {
		printf("L长：%d\n", L->length);
		// 定位元素
		if (L->data[i] == val){
			// 删除
			for (int j = i; j < L->length-1; j++){
				L->data[j] = L->data[j + 1];
			}
			L->length--;
		}
		i++;
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
	SqList sqList;
	SqList *p1;
	p1 = &sqList;
	InitSqList(&sqList);
	DelByValue(&sqList, 5);
	PrintSqList(&sqList);
	return 0;
}