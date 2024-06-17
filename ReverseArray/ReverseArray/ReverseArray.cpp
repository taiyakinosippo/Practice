//==========================================================
//	�z��̔��]
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// �֐��v���g�^�C�v
void ReverseArray(int array[], int arraySize);
// �֐��}�N�� 
#define SWAP(type, x, y) do{type tmp=x; x=y; y=tmp; }while(false)

int main()
{
	int nx;
	srand(time(nullptr));

	do {
		printf("�v�f��:");
		scanf("%d", &nx);
	} while (nx <= 0);

	int* x = (int*)calloc(nx, sizeof(int));
	if (x == nullptr) {
		printf("calloc()���s");
		exit(1);
	}

	for (int i = 0; i < nx; i++) {
		x[i] = rand() % 100;
		printf("x[%d] = %d\n", i, x[i]);
	}

	ReverseArray(x, nx);

	printf("�v�f�̕��т𔽓]���܂���\n");
	for (int i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}
	free(x);
	return 0;
}

void ReverseArray(int array[], int arraySize)
{
	for (int i = 0; i < arraySize / 2; i++) {
		SWAP(int, array[i], array[arraySize - 1 - i]);
	}
}