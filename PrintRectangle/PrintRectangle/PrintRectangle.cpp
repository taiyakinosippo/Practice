//==========================================================
//	�����`��\������
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
// �֐��v���g�^�C�v
void PrintRectangle(int w, int h);

int main()
{
    while (true) {
        int h, w;
        puts("�����`��\�����܂�");
        do {
            printf("������: ");
            scanf_s("%d", &h);
        } while (h <= 0);
        do {
            printf("������: ");
            scanf_s("%d", &w);
        } while (w <= 0);
        PrintRectangle(w, h);
    }
    return 0;
}

void PrintRectangle(int w, int h)
{
    // �������R�[�f�B���O���Ă�������
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            putchar('*');
        }
        putchar('\n');
    }
}