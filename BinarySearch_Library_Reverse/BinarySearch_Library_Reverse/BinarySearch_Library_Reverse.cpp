//==========================================================
//	�Q���T��  ���C�u�����[���p �~��
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h> // srand(),rand(),bsearch()
#include <time.h>
// �֐��v���g�^�C�v
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
        const int DATA_RANGE = 100;
        int tmp = DATA_RANGE;
        for (int i = 0; i < dataSize; i++) {
            tmp -= getRandRange(1, DATA_RANGE / dataSize);
            data[i] = tmp;
            printf("data[%d]:%d\n", i, data[i]);
        }
        int key = getRandRange(tmp, DATA_RANGE);
        printf("�T���l:%d\n", key);

        int* p = (int*)bsearch(
            &key,        // �����l�ւ̃|�C���^�[
            data,        // �f�[�^�z��
            dataSize,    // �f�[�^�v�f��
            sizeof(int), // �f�[�^�v�f�̑傫��
            (int(*)(const void*, const void*))CompareInt   // �f�[�^�ǂ����̔�r�֐� 
        );
        if (p == nullptr) {
            puts("�T���Ɏ��s���܂���");
        }
        else {
            int idx = p - data;
            printf("%d �� data[%d] �ɂ���܂�\n", key, idx);
        }
        free(data);
    }
    return 0;
}

int CompareInt(const int* a, const int* b)
{
    if (*a < *b) {
        return 1;
    }
    else if (*a > *b) {
        return -1;
    }
    else {
        return 0;
    }
}

int getRandRange(int min, int max)
{
    int wid = max - min + 1;
    return min + rand() % wid;
}