//==========================================================
//	配列の反転 経過表示
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// 関数プロトタイプ
void ReverseArray(int array[], int arraySize);
void dumpArray(int array[], int arraySize);
// 関数マクロ 
#define SWAP(type, x, y) do{type tmp=x; x=y; y=tmp; }while(false)

int main()
{
    int nx;
    srand(time(nullptr));

    do {
        printf("要素数:");
        scanf("%d", &nx);
    } while (nx <= 0);

    int* x = (int*)calloc(nx, sizeof(int));
    if (x == nullptr) {
        printf("calloc()失敗");
        exit(1);
    }
    

    for (int i = 0; i < nx; i++) {
        x[i] = rand() % 100;
        //printf("x[%d] = %d\n", i, x[i]);
    }
    dumpArray(x, nx);

    ReverseArray(x, nx);

    printf("\n要素の並びを反転しました\n");
    dumpArray(x, nx);

    free(x);
    return 0;
}

void ReverseArray(int array[], int arraySize)
{
    // ここをコーディングしてください。
    int a = 0;
    for (int i = 0; i < arraySize/2; i++)
    {
        a = array[i];
        array[i] = array[arraySize - i - 1];
        array[arraySize - i - 1] = a;
    }
}

void dumpArray(int array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
