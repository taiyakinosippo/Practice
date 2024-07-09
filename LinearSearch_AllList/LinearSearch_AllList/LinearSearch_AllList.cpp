//==========================================================
//	���`�T�� �S���o
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h> // srand(),rand()
#include <time.h>
// �֐��v���g�^�C�v
int LinearSearch_AllList(const int data[], int dataSize, int key, int idx[]);
int getRandRange(int min, int max);

int main()
{
	srand(time(nullptr));
	int dataSize;

	while (true) {
		printf("�v�f��:");
		do {
			scanf("%d", &dataSize);
		} while (dataSize <= 0);

		int* data = (int*)calloc(dataSize, sizeof(int));
		int* idx = (int*)calloc(dataSize, sizeof(int));
		if (data == nullptr || idx == nullptr) {
			printf("calloc()���s");
			exit(1);
		}
		const int DATA_RANGE = 20;
		for (int i = 0; i < dataSize; i++) {
			data[i] = getRandRange(0, DATA_RANGE);
			printf("data[%d]:%d\n", i, data[i]);
		}
		int key = getRandRange(0, DATA_RANGE);
		printf("�T���l:%d\n", key);

		int count = LinearSearch_AllList(data, dataSize, key, idx);
		printf("%d �� %d����܂�\n", key, count);
		for (int i = 0; i < count; i++) {
			printf("data[%d] ", idx[i]);
		}
		printf("\n");
		free(idx);
		free(data);
	}
	return 0;
}

int LinearSearch_AllList(const int data[], int dataSize, int key, int idx[])
{
	// �������R�[�f�B���O���Ă��������B
	// key�Ɠ���data[] �̃C���f�b�N�X�l�����ׂ�idx[]�Ɋi�[��
	// �i�[�����ʐ���Ԃ�l�Ƃ��܂��B
	int count = 0;
	for (int i = 0; i < dataSize; i++)
	{
		if (data[i] == key)
		{
			idx[count] = i;
			count++;
		}
	}

	return count;
}

int getRandRange(int min, int max)
{
	int wid = max - min + 1;
	return min + rand() % wid;
}
