//==========================================================
//	配列の反転
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// 関数プロトタイプ
void ReverseArray(int array[], int arraySize);
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
		printf("x[%d] = %d\n", i, x[i]);
	}

	ReverseArray(x, nx);

	printf("要素の並びを反転しました\n");
	for (int i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}
	free(x);
	return 0;
}

void ReverseArray(int array[], int arraySize)
{
	for (int i = 0; i < arraySize / 2; i++) {
		SWAP(int, array[i], array[arraySize - 1 - i]);
	}
}