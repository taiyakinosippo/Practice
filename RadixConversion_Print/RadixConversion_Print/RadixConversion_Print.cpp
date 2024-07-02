//==========================================================
//	��ϊ� �o�ߕ\��
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// �֐��v���g�^�C�v
int card_convert(char* buff, int num, int radix);
// �֐��}�N��
#define SWAP(type, x, y) do{ type tmp=x; x=y; y=tmp; }while(false) 

int main()
{
    srand(time(nullptr));
    const int BUFF_SIZE = 128;
    char buff[BUFF_SIZE];
    int yes;
    do {
        int num = rand();
        int radix = rand() % 34 + 2;  // radix=2�`36
        card_convert(buff, num, radix);

        printf("%d ���%3d �ŕ\������� %s\n", num, radix, buff);

        printf("\n������x���܂���?(1:�͂�/0:������)");
        scanf("%d", &yes);
    } while (yes == 1);
    return 0;
}

int card_convert(char* buff, int num, int radix)
{
    // �������R�[�f�B���O���Ă��������B
    char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int digits = 0;
    if (num == 0) {
        
        buff[digits++] = dchar[0];
    }
    else
    {
        while (num != 0) {
            
            buff[digits++] = dchar[num % radix];
            printf_s("%d|%7d   �E�E�E %d\n--+--------\n", radix, num, num % radix);
            num /= radix;
        }
        printf("         0\n");
    }
    for (int i = 0; i < digits / 2; i++) {
        SWAP(char, buff[i], buff[digits - 1 - i]);
    }
    buff[digits] = '\0';
    return digits;
}