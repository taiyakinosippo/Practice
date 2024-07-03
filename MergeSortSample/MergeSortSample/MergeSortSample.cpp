//=========================================================
//	マージソート
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// 関数プロトタイプ
bool MergeSort(int array[], int arraySize);
void __mergeSort(int array[], int left, int right);
int getRandRange(int min, int max);
void dumpArray(const int array[], int arraySize);

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
		bool ok = MergeSort(array, arraySize);
		if (ok == false) {
			puts("マージソート失敗");
			exit(1);
		}
		printf("昇順にソートしました\n");
		dumpArray(array, arraySize);

		free(array);
	}
	return 0;
}

static int* buff;

// マージソート(成功フラグを返す)
bool MergeSort(int array[], int arraySize)
{
	buff = (int*)calloc(arraySize, sizeof(int));
	if (buff == nullptr) {
		return false;
	}
	__mergeSort(array, 0, arraySize - 1);
	free(buff);
	return true;
}

void __mergeSort(int array[], int left, int right)
{
	if (left < right) {
		int center = (left + right) / 2;
		__mergeSort(array, left, center);
		__mergeSort(array, center + 1, right);

		int pa;
		int pb;
		int pc;
		// 配列a[left～center] => buff[left～center]へコピー
		for (int i = left; i <= center; i++) {
			buff[i] = array[i];
		}
		pa = left;
		pb = center + 1;
		pc = left;
		// 配列a : buff[left～center] 
		// 配列b : array[center+1～right]
		// aとbを配列c ; array[left～right] へマージする
		while (pa <= center && pb <= right) {
			array[pc++] = buff[pa] <= array[pb] ? buff[pa++] : array[pb++];
		}
		while (pa <= center) {
			array[pc++] = buff[pa++];
		}
		// 以下は行う必要なし
		//while (pb <= right) {
		//	array[pc++] = array[pb++];
		//}
	}
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