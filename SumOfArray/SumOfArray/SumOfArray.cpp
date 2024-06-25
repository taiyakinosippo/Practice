//==========================================================
//	�z��̍��v�l
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// �֐��v���g�^�C�v
int SumOfArray(int array[], int arraySize);
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

	int sum = SumOfArray(height, number);
	printf("���v�l�� %d �ł�\n", sum);

	free(height);
	return 0;
}

int SumOfArray(int array[], int arraySize)
{
	// �������R�[�f�B���O���Ă��������B
	int sum = 0;
	for (int i = 0; i < arraySize; i++)
	{
		sum += array[i];
	}
	return sum;
}

int randRange(int min, int max)
{
	int wid = max - min + 1;
	return min + rand() % wid;
}