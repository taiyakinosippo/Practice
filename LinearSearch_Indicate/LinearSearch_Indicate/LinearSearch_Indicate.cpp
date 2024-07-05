//==========================================================
//	���`�T�� �o�ߕ\��
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h> // srand(),rand()
#include <time.h>
// �֐��v���g�^�C�v
int LinearSearch(const int data[], int dataSize, int key);
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
        for (int i = 0; i < dataSize; i++) {
            data[i] = getRandRange(0, 50);
            printf("data[%d]:%d\n", i, data[i]);
        }
        int key = getRandRange(0, 50);
        printf("�T���l:%d\n", key);

        int idx = LinearSearch(data, dataSize, key);
        if (idx == SEARCH_FAIL) {
            puts("�T���Ɏ��s���܂���");
        }
        else {
            printf("%d��data[%d]�ɂ���܂�\n", key, idx);
        }
        free(data);
    }
    return 0;
}

int LinearSearch(const int data[], int dataSize, int key)
{
    printf("   |");
    for (int i = 0; i < dataSize; i++) {
        printf(" %2d", i);
    }
    printf("\n---+");
    for (int i = 0; i < dataSize; i++) {
        printf("---");
    }
    printf("\n");

    for (int i = 0; i < dataSize; i++) {
        printf("   |");
        for (int j = 0; j < i; j++) {
            printf("   ");
        }
        printf(" *\n");
        printf("%3d|", i);
        for (int j = 0; j < dataSize; j++) {
            printf(" %2d", data[j]);
        }
        printf("\n");

        if (data[i] == key) {
            return i;
        }
    }
    return SEARCH_FAIL;
}

int getRandRange(int min, int max)
{
    int wid = max - min + 1;
    return min + rand() % wid;
}