//=========================================================
//	�P�������\�[�g �o�ߕ\��
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// �֐��v���g�^�C�v
void BubbleSort(int array[], int arraySize);
int getRandRange(int min, int max);
void dumpArray(const int array[], int arraySize);
// �����}�N��
#define swap(type,a,b)	do{type tmp=a; a=b; b=tmp;}while(false)

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
		BubbleSort(array, arraySize);
		printf("�����Ƀ\�[�g���܂���\n");
		dumpArray(array, arraySize);

		free(array);
	}
	return 0;
}
//
// ���̊֐����C���R�[�f�B���O���Ă��������B
// ��r�񐔂ƌ����񐔂̕ϐ��́A�K���ȂƂ���ɐ錾���Ă��������B
// 
void BubbleSort(int array[], int arraySize)
{
	int hikaku = 0;
	int koukann = 0;
	for (int i = 0; i < arraySize - 1; i++) {
		for (int j = arraySize - 1; j > i; j--) {
			hikaku++;
			if (array[j - 1] > array[j]) {
				swap(int, array[j - 1], array[j]);
				koukann++;
			}
		}
	}
	printf("��r��%d\n������%d\n", hikaku, koukann);
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