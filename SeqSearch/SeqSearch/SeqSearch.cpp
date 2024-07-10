//==========================================================
//	線形探索 seqsearch(シーケンシャルサーチ)
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h> // srand(),rand()
#include <time.h>
// 関数プロトタイプ
void* seqsearch(const void* key, const void* array, size_t arraySize, size_t typeSize, int (*compFunc)(const void*, const void*));
int CompareInt(const int* a, const int* b);
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
		if (data == nullptr) {
			printf("calloc()失敗");
			exit(1);
		}
		const int DATA_RANGE = 30;
		for (int i = 0; i < dataSize; i++) {
			data[i] = getRandRange(0, DATA_RANGE);
			printf("data[%d]:%d\n", i, data[i]);
		}
		int key = getRandRange(0, DATA_RANGE);
		printf("探す値:%d\n", key);

		void* p = seqsearch(
			&key,        // 検索キーのアドレス
			data,        // データ配列
			dataSize,    // データ配列の要素数
			sizeof(int), // 要素のサイズ
			(int (*)(const void*, const void*))CompareInt   // 比較関数
		);
		if (p == nullptr) {
			puts("探索に失敗しました");
		}
		else {
			int idx = (int*)p - data;
			printf("%d は data[%d] にあります\n", key, idx);
		}
		free(data);
	}
	return 0;
}

void* seqsearch(const void* key, const void* array, size_t arraySize, size_t typeSize, int compFunc(const void*, const void*))
{
	// ここをコーディングしてください。
	// 線形検索を行います。
	// data[idx] のポインターを取得することが肝です。
	// intptr_t を調べてみましょう。

}

int CompareInt(const int* a, const int* b)
{
	return *a - *b;
}

int getRandRange(int min, int max)
{
	int wid = max - min + 1;
	return min + rand() % wid;
}
