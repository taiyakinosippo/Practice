//==========================================================
//	���`�T�� seqsearch(�V�[�P���V�����T�[�`)
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h> // srand(),rand()
#include <time.h>
// �֐��v���g�^�C�v
void* seqsearch(const void* key, const void* array, size_t arraySize, size_t typeSize, int (*compFunc)(const void*, const void*));
int CompareInt(const int* a, const int* b);
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
		if (data == nullptr) {
			printf("calloc()���s");
			exit(1);
		}
		const int DATA_RANGE = 30;
		for (int i = 0; i < dataSize; i++) {
			data[i] = getRandRange(0, DATA_RANGE);
			printf("data[%d]:%d\n", i, data[i]);
		}
		int key = getRandRange(0, DATA_RANGE);
		printf("�T���l:%d\n", key);

		void* p = seqsearch(
			&key,        // �����L�[�̃A�h���X
			data,        // �f�[�^�z��
			dataSize,    // �f�[�^�z��̗v�f��
			sizeof(int), // �v�f�̃T�C�Y
			(int (*)(const void*, const void*))CompareInt   // ��r�֐�
		);
		if (p == nullptr) {
			puts("�T���Ɏ��s���܂���");
		}
		else {
			int idx = (int*)p - data;
			printf("%d �� data[%d] �ɂ���܂�\n", key, idx);
		}
		free(data);
	}
	return 0;
}

void* seqsearch(const void* key, const void* array, size_t arraySize, size_t typeSize, int compFunc(const void*, const void*))
{
	// �������R�[�f�B���O���Ă��������B
	// ���`�������s���܂��B
	// data[idx] �̃|�C���^�[���擾���邱�Ƃ��̂ł��B
	// intptr_t �𒲂ׂĂ݂܂��傤�B

}

int CompareInt(const int* a, const int* b)
{
	return *a - *b;
}

int getRandRange(int min, int max)
{
	int wid = max - min + 1;
	return min + rand() % wid;
}
