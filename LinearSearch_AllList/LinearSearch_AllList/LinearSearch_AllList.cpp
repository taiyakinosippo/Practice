//==========================================================
//	線形探索 全検出
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h> // srand(),rand()
#include <time.h>
// 関数プロトタイプ
int LinearSearch_AllList(const int data[], int dataSize, int key, int idx[]);
int getRandRange(int min, int max);

int main()
{
	srand(time(nullptr));
	int dataSize;

	while (true) {
		printf("要素数:");
		do {
			scanf("%d", &dataSize);
		} while (dataSize <= 0);

		int* data = (int*)calloc(dataSize, sizeof(int));
		int* idx = (int*)calloc(dataSize, sizeof(int));
		if (data == nullptr || idx == nullptr) {
			printf("calloc()失敗");
			exit(1);
		}
		const int DATA_RANGE = 20;
		for (int i = 0; i < dataSize; i++) {
			data[i] = getRandRange(0, DATA_RANGE);
			printf("data[%d]:%d\n", i, data[i]);
		}
		int key = getRandRange(0, DATA_RANGE);
		printf("探す値:%d\n", key);

		int count = LinearSearch_AllList(data, dataSize, key, idx);
		printf("%d は %d個あります\n", key, count);
		for (int i = 0; i < count; i++) {
			printf("data[%d] ", idx[i]);
		}
		printf("\n");
		free(idx);
		free(data);
	}
	return 0;
}

int LinearSearch_AllList(const int data[], int dataSize, int key, int idx[])
{
	// ここをコーディングしてください。
	// keyと同じdata[] のインデックス値をすべてidx[]に格納し
	// 格納した量数を返り値とします。
	int count = 0;
	for (int i = 0; i < dataSize; i++)
	{
		if (data[i] == key)
		{
			idx[count] = i;
			count++;
		}
	}

	return count;
}

int getRandRange(int min, int max)
{
	int wid = max - min + 1;
	return min + rand() % wid;
}
