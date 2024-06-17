//==========================================================
//	基数変換
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// 関数プロトタイプ
int card_convert(char* buff, int num, int radix);
// 関数マクロ
#define SWAP(type, x, y) do{ type tmp=x; x=y; y=tmp; }while(false)

int main()
{
    srand(time(nullptr));
    const int BUFF_SIZE = 128;
    char buff[BUFF_SIZE];
    do {
        int num = rand();
        int radix = rand() % 34 + 2;  // radix=2～36
        card_convert(buff, num, radix);

        printf("%d を基数%3d で表示すると %s\n", num, radix, buff);
    } while (getchar() != ' ');
    return 0;
}

int card_convert(char* buff, int num, int radix)
{
    char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int digits = 0;
    if (num == 0) {
        buff[digits++] = dchar[0];
    }
    else
    {
        while (num != 0) {
            buff[digits++] = dchar[num % radix];
            num /= radix;
        }
    }
    for (int i = 0; i < digits / 2; i++) {
        SWAP(char, buff[i], buff[digits - 1 - i]);
    }
    buff[digits] = '\0';
    return digits;
}