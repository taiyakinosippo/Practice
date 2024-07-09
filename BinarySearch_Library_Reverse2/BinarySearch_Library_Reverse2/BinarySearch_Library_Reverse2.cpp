//==========================================================
//	２分探索  ライブラリー利用 降順2
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h> // srand(),rand(),bsearch()
#include <time.h>
// 関数プロトタイプ
int CompareLong(const long* a, const long* b);
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

        long* data = (long*)calloc(dataSize, sizeof(long));
        if (data == nullptr) {
            printf("calloc()失敗");
            exit(1);
        }
        const int DATA_RANGE = 100;
        int tmp = DATA_RANGE;
        for (int i = 0; i < dataSize; i++) {
            tmp -= getRandRange(1, DATA_RANGE / dataSize);
            data[i] = tmp;
            printf("data[%d]:%ld\n", i, data[i]);
        }
        long key = getRandRange(tmp, DATA_RANGE);
        printf("探す値:%ld\n", key);

        long* p = (long*)bsearch(
            &key,        // 検索値へのポインター
            data,        // データ配列
            dataSize,    // データ要素数
            sizeof(long), // データ要素の大きさ
            (int(*)(const void*, const void*))CompareLong   // データどおしの比較関数 
        );
        if (p == nullptr) {
            puts("探索に失敗しました");
        }
        else {
            int idx = p - data;
            printf("%ld は data[%d] にあります\n", key, idx);
        }
        free(data);
    }
    return 0;
}

int CompareLong(const long* a, const long* b)
{
    // ここをコーディングしてください。
    // データが降順であることに注意してください。
    // リスト3-6を参考にしてください。
    if (*a < *b)
    {
        return 1;
    }
    else if (*a > *b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int getRandRange(int min, int max)
{
    int wid = max - min + 1;
    return min + rand() % wid;
}