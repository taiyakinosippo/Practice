//==========================================================
//	�z��̔��] �o�ߕ\��
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// �֐��v���g�^�C�v
void ReverseArray(int array[], int arraySize);
void dumpArray(int array[], int arraySize);
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
        //printf("x[%d] = %d\n", i, x[i]);
    }
    dumpArray(x, nx);

    ReverseArray(x, nx);

    printf("\n�v�f�̕��т𔽓]���܂���\n");
    dumpArray(x, nx);

    free(x);
    return 0;
}

void ReverseArray(int array[], int arraySize)
{
    // �������R�[�f�B���O���Ă��������B
    int a = 0;
    for (int i = 0; i < arraySize/2; i++)
    {
        a = array[i];
        array[i] = array[arraySize - i - 1];
        array[arraySize - i - 1] = a;
    }
}

void dumpArray(int array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
