//=========================================================
//	クイックソート　Partition
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// 関数プロトタイプ
void Partition(int array[], int arraySize);
void dumpArray(const int array[], int arraySize);
int getRandRange(int min, int max);
// 交換マクロ
#define swap(type,a,b)   do{ type tmp=a; a=b; b=tmp; }while(false)

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
		Partition(array, arraySize);

		free(array);
	}
	return 0;
}

void Partition(int array[], int arraySize)
{
	int pl = 0;
	int pr = arraySize - 1;
	int x = array[arraySize / 2];

	do {
		while (array[pl] < x) pl++;
		while (array[pr] > x) pr--;
		if (pl <= pr) {
			swap(int, array[pl], array[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	printf("枢軸の値は %dです\n", x);

	printf("枢軸以下のグループ\n");
	for (int i = 0; i <= pl - 1; i++) {
		printf("%d ", array[i]);
	}
	putchar('\n');

	if (pl > pr + 1) {
		printf("枢軸と一致するグループ\n");
		for (int i = pr + 1; i <= pl - 1; i++) {
			printf("%d ", array[i]);
		}
		putchar('\n');
	}

	printf("枢軸以上のグループ\n");
	for (int i = pr + 1; i < arraySize; i++) {
		printf("%d ", array[i]);
	}
	putchar('\n');
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
