//==========================================================
//	配列の最小値
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// 関数プロトタイプ
int MinOfArray(int array[], int arraySize);
int randRange(int min, int max);

int main()
{
	int number;
	srand(time(nullptr));

	do {
		printf("人数:");
		scanf("%d", &number);
	} while (number <= 0);

	int* height = (int*)calloc(number, sizeof(int));
	if (height == nullptr) {
		printf("calloc()失敗");
		exit(1);
	}

	printf("%d人の身長を入力します\n", number);
	for (int i = 0; i < number; i++) {
		height[i] = randRange(140, 190);
		printf("%d\n", height[i]);
	}

	int min = MinOfArray(height, number);
	printf("最小値は %d です\n", min);

	free(height);
	return 0;
}

int MinOfArray(int array[], int arraySize)
{
	// ここをコーディングしてください。
	int min = array[0];
	for (int i = 1; i < arraySize; i++)
	{
		if (min > array[i])
		{
			min = array[i];
		}
	}
	return min;
}

int randRange(int min, int max)
{
	int wid = max - min + 1;
	return min + rand() % wid;
}