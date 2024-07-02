//==========================================================
//	�z��̃R�s�[
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// �֐��v���g�^�C�v
void CopyArray(int srcArray[], int dstArray[], int arraySize);
void setRandomArray(int array[], int arraySize);
void dumpArray(int array[], int arraySize);

int main()
{
    srand(time(nullptr));
    int size;
    do {
        printf("�v�f��:");
        scanf("%d", &size);
    } while (size <= 0);

    int* a = (int*)calloc(size, sizeof(int));
    int* b = (int*)calloc(size, sizeof(int));
    if (a == nullptr || b == nullptr) {
        printf("calloc���s\n");
        exit(1);
    }

    setRandomArray(a, size);
    setRandomArray(b, size);
    printf("a[]��\n");
    dumpArray(a, size);
    printf("b[]��\n");
    dumpArray(b, size);

    CopyArray(a, b, size);
    printf("\na[]��b[]�փR�s�[���܂���\n");
    printf("a[]��\n");
    dumpArray(a, size);
    printf("b[]��\n");
    dumpArray(b, size);

    free(a);
    free(b);
    return 0;
}

void CopyArray(int srcArray[], int dstArray[], int arraySize)
{
    // �������R�[�f�B���O���Ă��������B
    for (int i = 0; i < arraySize; i++)
    {
        dstArray[i] = srcArray[i];
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