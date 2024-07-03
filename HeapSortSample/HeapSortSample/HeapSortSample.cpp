//=========================================================
//	ヒープソート
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// 関数プロトタイプ
void HeapSort(int array[], int arraySize);
void downheap(int array[], int left, int right);
int getRandRange(int min, int max);
void dumpArray(const int array[], int arraySize);
// 交換マクロ
#define swap(type,a,b)  do{ type tmp=a; a=b; b=tmp;}while(false)

int main()
{
	srand(time(nullptr));
	int arraySize;
	int* array;

	while (true) {
		do {
			printf("要素数:");
			scanf("%d", &arraySize);
		} while (arraySize <= 2);

		array = (int*)calloc(arraySize, sizeof(int));
		if (array == nullptr) {
			printf("calloc()失敗\n");
			exit(1);
		}
		for (int i = 0; i < arraySize; i++) {
			array[i] = getRandRange(1, 100);
		}
		dumpArray(array, arraySize);
		HeapSort(array, arraySize);
		printf("昇順にソートしました\n");
		dumpArray(array, arraySize);

		free(array);
	}
	return 0;
}

void HeapSort(int array[], int arraySize)
{
	for (int i = (arraySize - 1) / 2; i >= 0; i--) {
		downheap(array, i, arraySize - 1);
	}
	for (int i = arraySize - 1; i > 0; i--) {
		swap(int, array[0], array[i]);
		downheap(array, 0, i - 1);
	}
}

void downheap(int array[], int left, int right)
{
	int temp = array[left];  // 根
	int child;
	int parent = left;
	while (parent < (right + 1) / 2) {
		int cl = parent * 2 + 1;  // 左の子
		int cr = cl + 1;          // 右の子
		child = (cr <= right && array[cr] > array[cl]) ? cr : cl; // 大きい方の子
		if (temp >= array[child]) {
			break;
		}
		array[parent] = array[child];
		parent = child;
	}
	array[parent] = temp;
}

void dumpArray(const int array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++) {
		printf("array[%d] = %d\n", i, array[i]);
	}
}

int getRandRange(int min, int max)
{
	int wid = max - min + 1;
	return min + rand() % wid;
}