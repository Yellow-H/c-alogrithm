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
// prac1
void InsertL(SqList *va, int val) {
	int i = 0;
	if (va->data) {
		while (i < va->length - 1) {
			i++;
			if (val < va->data[i]) {
				for (int j = va->length - 1; j >= i; j--) {
					va->data[j + 1] = va->data[j];
				}
				va->data[i] = val;
				va->length++;
				break;
			}
		}
	}
}

// optimise prac1
// 这个考虑插入时都是将最后个元素后移类推 所以考虑直接从后遍历直接 直到大于列表值位置
// 时间复杂度0(n) 优于上面的0(n^2)
void InsertLOptimise(SqList *va, int val) {
	if (va->length > MAXSIZE) return;
	int i = va->length - 1;
	for (i; i >= 0 && va->data[i] > val; i--) {
		va->data[i + 1] = va->data[i];
	}
	va->data[i + 1] = val;
	va->length++;
}

// prac2 奇数在偶数前面
void OddEvenSort(SqList * L) {
	int low = 0, high = L->length-1,temp = 0;;
	while (low < high) {
		while (low < high && L->data[high] % 2 == 0) high--;
		while (low < high && L->data[low] % 2 == 1) low++;
		if (low < high) {
			temp = L->data[low];
			L->data[low] = L->data[high];
			L->data[high] = temp;
		}
	}
}

// prac3 查找并排在首位
void SearchAndPut(SqList * L,int val) {
	int i = 0;
	while (i < L->length - 1) {
		i++;
		if (L->data[i] == val) {
			for (int j = i; j > 0; j--) {
				L->data[j] = L->data[j - 1];
			}
			L->data[0] = val;
			break;
		}
	}
}

// prac4 最快速查找有序顺序表（二分法），找不到则顺序插入
void HalfSearch(SqList * L,int val) {
	int low = 0, high = L->length - 1, mid = 0, temp = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		if (val > L->data[mid]) {
			low = mid + 1;
		}
		else if (val < L->data[mid]) {
			high = mid - 1;
		}
		else {
			// 注意为最后一个元素就不交换了
			if (mid != L->length - 1) {
				temp = L->data[mid];
				L->data[mid] = L->data[mid + 1];
				L->data[mid + 1] = temp;
			}
			break;
		}
	}
	// 不存在的情况
	if (low > high) {
		int i = 0;
		for (i = L->length - 1; i >= 0 && L->data[i] > val; i--) {
			L->data[i + 1] = L->data[i];
		}
		// 很重要，最后一次i还会减一，所以赋值到i+1位置上
		L->data[i+1] = val;
		L->length++;
	}
}

// prac5见reverse

// prac6 思想 先将线性表所有元素倒置，再分别倒置 0到n-1 n到m+n-1 倒置算法见reverse

//prac7 循环是指如 1 2 3 4 5 6 循环右移2位为 5 6 1 2 3 4
// 向右循环k次 即先将数组倒置 再将前k位倒置 即 0到k-1倒置  再将后 n-k位倒置即可 即 k 至n-1下标元素倒置
// 所以位移操作一般通过倒置实现


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
	HalfSearch(&A, 5);
	PrintSqList(&A);
	return 0;
}