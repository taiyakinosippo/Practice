//=========================================================
//	度数ソート
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// 関数プロトタイプ
void CountingSort(int array[], int arraySize, int valueMax);
int getRandRange(int min, int max);
void dumpArray(const int array[], int arraySize);

int main()
{
	srand(time(nullptr));
	int arraySize;
	int* array;
	const int VALUE_MAX = 100;

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
			array[i] = getRandRange(1, VALUE_MAX);
		}
		dumpArray(array, arraySize);
		CountingSort(array, arraySize, VALUE_MAX);
		printf("昇順にソートしました\n");
		dumpArray(array, arraySize);

		free(array);
	}
	return 0;
}

void CountingSort(int array[], int arraySize, int valueMax)
{
	int* count = (int*)calloc(valueMax + 1, sizeof(int)); // 累積度数の配列
	int* sort = (int*)calloc(arraySize, sizeof(int));   // ソート作業の配列
	if (count == nullptr || sort == nullptr) {
		puts("calloc失敗");
		exit(1);
	}
	// step0 : 
	for (int i = 0; i <= valueMax; i++) {
		count[i] = 0;
	}
	// step1
	for (int i = 0; i < arraySize; i++) {
		int value = array[i];
		if (value < 0 || valueMax < value) {
			puts("0～max以外のデータがありました\n");
			exit(1);
		}
		count[value]++;
	}
	// step2
	for (int i = 1; i <= valueMax; i++) {
		count[i] += count[i - 1];
	}
	// step3
	for (int i = arraySize - 1; i >= 0; i--) {
		int value = array[i];
		int idx = --count[value];
		sort[idx] = value;
	}
	// step4
	for (int i = 0; i < arraySize; i++) {
		array[i] = sort[i];
	}

	free(sort);
	free(count);
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