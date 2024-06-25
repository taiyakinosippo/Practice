//==========================================================
//	�z��̍ŏ��l
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// �֐��v���g�^�C�v
int MinOfArray(int array[], int arraySize);
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

	int min = MinOfArray(height, number);
	printf("�ŏ��l�� %d �ł�\n", min);

	free(height);
	return 0;
}

int MinOfArray(int array[], int arraySize)
{
	// �������R�[�f�B���O���Ă��������B
	int min = array[0];
	for (int i = 1; i < arraySize; i++)
	{
		if (min > array[i])
		{
			min = array[i];
		}
	}
	return min;
}

int randRange(int min, int max)
{
	int wid = max - min + 1;
	return min + rand() % wid;
}