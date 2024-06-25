//==========================================================
//	配列の合計値
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// 関数プロトタイプ
int SumOfArray(int array[], int arraySize);
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

	int sum = SumOfArray(height, number);
	printf("合計値は %d です\n", sum);

	free(height);
	return 0;
}

int SumOfArray(int array[], int arraySize)
{
	// ここをコーディングしてください。
	int sum = 0;
	for (int i = 0; i < arraySize; i++)
	{
		sum += array[i];
	}
	return sum;
}

int randRange(int min, int max)
{
	int wid = max - min + 1;
	return min + rand() % wid;
}