//==========================================================
//	�z��̃V���b�t�� 
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// �֐��v���g�^�C�v
void ShuffleArray(int srcArray[], int dstArray[], int arraySize);
void setRandomArray(int array[], int arraySize);
void dumpArray(int array[], int arraySize);

int randRange(int min, int max);
int main()
{
    srand(time(nullptr));
    int size;
    do {
        printf("�v�f��:");
        scanf("%d", &size);
    } while (size <= 0);

    int* a = (int*)calloc(size, sizeof(int));
    if (a == nullptr) {
        printf("calloc���s\n");
        exit(1);
    }

    setRandomArray(a, size);
    dumpArray(a, size);

    ShuffleArray(a, size);
    printf("\na[]���V���t�����܂���\n");
    dumpArray(a, size);

    free(a);
    return 0;
}

void ShuffleArray(int array[], int arraySize)
{
    // �������R�[�f�B���O���Ă��������B
    for (int i = 0; i < 100; i++)
    {
        int rand1 = randRange(0, arraySize);
        int rand2 = randRange(0, arraySize);
        int a = array[rand1];
        array[rand1] = array[rand2];
        array[rand2] = a;

    }
    
}

void setRandomArray(int array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++) {
        array[i] = rand() % 1000;
    }
}

void dumpArray(int array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}