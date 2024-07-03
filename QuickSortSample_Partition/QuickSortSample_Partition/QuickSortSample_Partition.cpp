//=========================================================
//	�N�C�b�N�\�[�g�@Partition
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// �֐��v���g�^�C�v
void Partition(int array[], int arraySize);
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
		Partition(array, arraySize);

		free(array);
	}
	return 0;
}

void Partition(int array[], int arraySize)
{
	int pl = 0;
	int pr = arraySize - 1;
	int x = array[arraySize / 2];

	do {
		while (array[pl] < x) pl++;
		while (array[pr] > x) pr--;
		if (pl <= pr) {
			swap(int, array[pl], array[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	printf("�����̒l�� %d�ł�\n", x);

	printf("�����ȉ��̃O���[�v\n");
	for (int i = 0; i <= pl - 1; i++) {
		printf("%d ", array[i]);
	}
	putchar('\n');

	if (pl > pr + 1) {
		printf("�����ƈ�v����O���[�v\n");
		for (int i = pr + 1; i <= pl - 1; i++) {
			printf("%d ", array[i]);
		}
		putchar('\n');
	}

	printf("�����ȏ�̃O���[�v\n");
	for (int i = pr + 1; i < arraySize; i++) {
		printf("%d ", array[i]);
	}
	putchar('\n');
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
