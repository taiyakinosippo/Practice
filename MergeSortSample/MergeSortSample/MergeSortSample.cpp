//=========================================================
//	�}�[�W�\�[�g
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// �֐��v���g�^�C�v
bool MergeSort(int array[], int arraySize);
void __mergeSort(int array[], int left, int right);
int getRandRange(int min, int max);
void dumpArray(const int array[], int arraySize);

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
		bool ok = MergeSort(array, arraySize);
		if (ok == false) {
			puts("�}�[�W�\�[�g���s");
			exit(1);
		}
		printf("�����Ƀ\�[�g���܂���\n");
		dumpArray(array, arraySize);

		free(array);
	}
	return 0;
}

static int* buff;

// �}�[�W�\�[�g(�����t���O��Ԃ�)
bool MergeSort(int array[], int arraySize)
{
	buff = (int*)calloc(arraySize, sizeof(int));
	if (buff == nullptr) {
		return false;
	}
	__mergeSort(array, 0, arraySize - 1);
	free(buff);
	return true;
}

void __mergeSort(int array[], int left, int right)
{
	if (left < right) {
		int center = (left + right) / 2;
		__mergeSort(array, left, center);
		__mergeSort(array, center + 1, right);

		int pa;
		int pb;
		int pc;
		// �z��a[left�`center] => buff[left�`center]�փR�s�[
		for (int i = left; i <= center; i++) {
			buff[i] = array[i];
		}
		pa = left;
		pb = center + 1;
		pc = left;
		// �z��a : buff[left�`center] 
		// �z��b : array[center+1�`right]
		// a��b��z��c ; array[left�`right] �փ}�[�W����
		while (pa <= center && pb <= right) {
			array[pc++] = buff[pa] <= array[pb] ? buff[pa++] : array[pb++];
		}
		while (pa <= center) {
			array[pc++] = buff[pa++];
		}
		// �ȉ��͍s���K�v�Ȃ�
		//while (pb <= right) {
		//	array[pc++] = array[pb++];
		//}
	}
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