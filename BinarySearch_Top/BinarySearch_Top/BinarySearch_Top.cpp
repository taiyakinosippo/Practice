//==========================================================
//	�Q���T�� �擪
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h> // srand(),rand()
#include <time.h>
// �֐��v���g�^�C�v
int BinarySearch(int data[], int dataSize, int key);
int getRandRange(int min, int max);

#define SEARCH_FAIL (-1)

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
		if (data == nullptr) {
			printf("calloc()���s");
			exit(1);
		}
		const int DATA_RANGE = 100;
		int tmp = 0;
		for (int i = 0; i < dataSize; i++) {
			tmp += getRandRange(1, DATA_RANGE / dataSize);
			data[i] = tmp;
			printf("data[%d]:%d\n", i, data[i]);
		}
		int key = getRandRange(1, tmp);
		printf("�T���l:%d\n", key);

		int idx = BinarySearch(data, dataSize, key);
		if (idx == SEARCH_FAIL) {
			puts("�T���Ɏ��s���܂���");
		}
		else {
			printf("%d �� data[%d] �ɂ���܂�\n", key, idx);
		}
		free(data);
	}
	return 0;
}

int BinarySearch(int data[], int dataSize, int key)
{
	// �������R�[�f�B���O���Ă��������B
	// key��������������A�擪�̃C���f�b�N�X��Ԃ��悤�ɂ��Ă��������B
	for (int i = 0; i < dataSize; i++)
	{
		if (data[i] == key)
		{
			return i;
		}
		else if (i == dataSize - 1)
		{
			return -1;
		}
	}
}

int getRandRange(int min, int max)
{
	int wid = max - min + 1;
	return min + rand() % wid;
}