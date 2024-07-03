//=========================================================
//	qsortサンプル
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand(),qsort()
#include <time.h>    // time()
// 関数プロトタイプ
int CompareInt(const int* a, const int* b);
void dumpArray(const int array[], int arraySize);
int getRandRange(int min, int max);

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
		qsort(
			array,        // 配列
			arraySize,    // 配列の要素数
			sizeof(int),  // 要素のサイズ
			(int(*)(const void*, const void*))CompareInt // 比較関数
		);
		printf("昇順にソートしました\n");
		dumpArray(array, arraySize);

		free(array);
	}
	return 0;
}

int CompareInt(const int* a, const int* b)
{
	return *a - *b;
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