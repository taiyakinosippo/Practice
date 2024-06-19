//==========================================================
//	２分探索  ライブラリー利用 降順
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h> // srand(),rand(),bsearch()
#include <time.h>
// 関数プロトタイプ
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
        const int DATA_RANGE = 100;
        int tmp = DATA_RANGE;
        for (int i = 0; i < dataSize; i++) {
            tmp -= getRandRange(1, DATA_RANGE / dataSize);
            data[i] = tmp;
            printf("data[%d]:%d\n", i, data[i]);
        }
        int key = getRandRange(tmp, DATA_RANGE);
        printf("探す値:%d\n", key);

        int* p = (int*)bsearch(
            &key,        // 検索値へのポインター
            data,        // データ配列
            dataSize,    // データ要素数
            sizeof(int), // データ要素の大きさ
            (int(*)(const void*, const void*))CompareInt   // データどおしの比較関数 
        );
        if (p == nullptr) {
            puts("探索に失敗しました");
        }
        else {
            int idx = p - data;
            printf("%d は data[%d] にあります\n", key, idx);
        }
        free(data);
    }
    return 0;
}

int CompareInt(const int* a, const int* b)
{
    if (*a < *b) {
        return 1;
    }
    else if (*a > *b) {
        return -1;
    }
    else {
        return 0;
    }
}

int getRandRange(int min, int max)
{
    int wid = max - min + 1;
    return min + rand() % wid;
}