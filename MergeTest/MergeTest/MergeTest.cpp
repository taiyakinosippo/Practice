//=========================================================
//	マージテスト
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// 関数プロトタイプ
void Merge(const int a[], int aSize, const int b[], int bSize, int c[]);
void dumpArray(const int array[], int arraySize, const char* arrayName);
int getRandRange(int min, int max);

int main()
{
    srand(time(nullptr));
    int aSize;
    int* a;
    int bSize;
    int* b;
    int cSize;
    int* c;

    while (true) {
        do {
            printf("a[]の要素数:");
            scanf("%d", &aSize);
        } while (aSize <= 2);
        do {
            printf("b[]の要素数:");
            scanf("%d", &bSize);
        } while (bSize <= 2);

        cSize = aSize + bSize;
        a = (int*)calloc(aSize, sizeof(int));
        b = (int*)calloc(bSize, sizeof(int));
        c = (int*)calloc(cSize, sizeof(int));
        if (a == nullptr || b == nullptr || c == nullptr) {
            printf("calloc()失敗\n");
            exit(1);
        }
        int tmp = getRandRange(1, 10);
        for (int i = 0; i < aSize; i++) {
            tmp += getRandRange(1, 10);
            a[i] = tmp;
        }
        tmp = getRandRange(1, 10);
        for (int i = 0; i < bSize; i++) {
            tmp += getRandRange(1, 10);
            b[i] = tmp;
        }
        dumpArray(a, aSize, "a");
        dumpArray(b, bSize, "b");
        Merge(a, aSize, b, bSize, c);
        puts("配列aとbをマージしてCに格納しました");
        dumpArray(c, cSize, "c");

        free(c);
        free(b);
        free(a);
    }
    return 0;
}

void Merge(const int a[], int aSize, const int b[], int bSize, int c[])
{
    int pa = 0;
    int pb = 0;
    int pc = 0;
    while (pa < aSize && pb < bSize) {
        c[pc++] = a[pa] <= b[pb] ? a[pa++] : b[pb++];
    }
    while (pa < aSize) {
        c[pc++] = a[pa++];
    }
    while (pb < bSize) {
        c[pc++] = b[pb++];
    }
}
void dumpArray(const int array[], int arraySize, const char* arrayName)
{
    for (int i = 0; i < arraySize; i++) {
        printf("%s[%d] = %d\n", arrayName, i, array[i]);
    }
}

int getRandRange(int min, int max)
{
    int wid = max - min + 1;
    return min + rand() % wid;
}