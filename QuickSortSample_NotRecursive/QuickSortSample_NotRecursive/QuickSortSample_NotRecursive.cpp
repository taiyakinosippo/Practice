//=========================================================
//	�N�C�b�N�\�[�g�@��ċA
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
#include "IntStack.h"
// �֐��v���g�^�C�v
void QuickSort(int array[], int left, int right);
void dumpArray(const int array[], int arraySize);
int getRandRange(int min, int max);
// �����}�N��
#define swap(type,a,b)   do{ type tmp=a; a=b; b=tmp; }while(false)

int main()
{
	srand(time(nullptr));
	int arraySize;
	int* array;

	while (true) {
		do {
			printf("�v�f��:");
			scanf("%d", &arraySize);
		} while (arraySize <= 2);

		array = (int*)calloc(arraySize, sizeof(int));
		if (array == nullptr) {
			printf("calloc()���s\n");
			exit(1);
		}
		for (int i = 0; i < arraySize; i++) {
			array[i] = getRandRange(1, 100);
		}
		dumpArray(array, arraySize);
		QuickSort(array, 0, arraySize - 1);
		printf("�����Ƀ\�[�g���܂���\n");
		dumpArray(array, arraySize);

		free(array);
	}
	return 0;
}

void QuickSort(int array[], int left, int right)
{
	IntStack stk;
	Initialize(&stk, right - left + 1);

	Push(&stk, left);
	Push(&stk, right);
	while (IsEmpty(&stk) == false) {
		Pop(&stk, &right);
		Pop(&stk, &right);
		Pop(&stk, &left);
		int pl = left;
		int pr = right;
		int x = array[(left + right) / 2];
		do {
			while (array[pl] < x) pl++;
			while (array[pr] > x) pr--;
			if (pl <= pr) {
				swap(int, array[pl], array[pr]);
				pl++;
				pr--;
			}
		} while (pl <= pr);
		if (left < pr) {
			Push(&stk, left);
			Push(&stk, pr);
		}
		if (pl < right) {
			Push(&stk, pl);
			Push(&stk, right);
		}
	}
	Terminate(&stk);
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
