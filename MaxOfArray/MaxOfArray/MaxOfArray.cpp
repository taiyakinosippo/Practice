//==========================================================
//	�z��̍ő�l
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// �֐��v���g�^�C�v
int MaxOfArray(int array[], int arraySize);
int randRange(int min, int max);

int main()
{
	int number;
	srand(time(nullptr));

	do {
		printf("�l��:");
		scanf("%d", &number);
	} while (number <= 0);

	int* height = (int*)calloc(number, sizeof(int));
	if (height == nullptr) {
		printf("calloc()���s");
		exit(1);
	}

	printf("%d�l�̐g������͂��܂�\n", number);
	for (int i = 0; i < number; i++) {
		height[i] = randRange(140, 190);
		printf("%d\n", height[i]);
	}

	int max = MaxOfArray(height, number);
	printf("�ő�l�� %d �ł�\n", max);

	free(height);
	return 0;
}

int MaxOfArray(int array[], int arraySize)
{
	int max = array[0];
	for (int i = 1; i < arraySize; i++) {
		if (max < array[i]) {
			max = array[i];
		}
	}
	return max;
}

int randRange(int min, int max)
{
	int wid = max - min + 1;
	return min + rand() % wid;
}