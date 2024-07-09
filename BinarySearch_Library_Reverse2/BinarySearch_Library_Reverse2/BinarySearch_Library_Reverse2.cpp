//==========================================================
//	�Q���T��  ���C�u�����[���p �~��2
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h> // srand(),rand(),bsearch()
#include <time.h>
// �֐��v���g�^�C�v
int CompareLong(const long* a, const long* b);
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

        long* data = (long*)calloc(dataSize, sizeof(long));
        if (data == nullptr) {
            printf("calloc()���s");
            exit(1);
        }
        const int DATA_RANGE = 100;
        int tmp = DATA_RANGE;
        for (int i = 0; i < dataSize; i++) {
            tmp -= getRandRange(1, DATA_RANGE / dataSize);
            data[i] = tmp;
            printf("data[%d]:%ld\n", i, data[i]);
        }
        long key = getRandRange(tmp, DATA_RANGE);
        printf("�T���l:%ld\n", key);

        long* p = (long*)bsearch(
            &key,        // �����l�ւ̃|�C���^�[
            data,        // �f�[�^�z��
            dataSize,    // �f�[�^�v�f��
            sizeof(long), // �f�[�^�v�f�̑傫��
            (int(*)(const void*, const void*))CompareLong   // �f�[�^�ǂ����̔�r�֐� 
        );
        if (p == nullptr) {
            puts("�T���Ɏ��s���܂���");
        }
        else {
            int idx = p - data;
            printf("%ld �� data[%d] �ɂ���܂�\n", key, idx);
        }
        free(data);
    }
    return 0;
}

int CompareLong(const long* a, const long* b)
{
    // �������R�[�f�B���O���Ă��������B
    // �f�[�^���~���ł��邱�Ƃɒ��ӂ��Ă��������B
    // ���X�g3-6���Q�l�ɂ��Ă��������B
    if (*a < *b)
    {
        return 1;
    }
    else if (*a > *b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int getRandRange(int min, int max)
{
    int wid = max - min + 1;
    return min + rand() % wid;
}