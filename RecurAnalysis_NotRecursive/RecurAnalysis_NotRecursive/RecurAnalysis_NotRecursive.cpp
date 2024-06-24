//=========================================================
//	Recur 非再帰化
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // exit()
#include "IntStack.h"

// 関数プロトタイプ
void recur(int n);

int main()
{
    while (true) {
        int n;
        do {
            printf("数値:");
            scanf("%d", &n);
        } while (n < 0);

        recur(n);
    }
    return 0;
}

void recur(int n)
{
    IntStack stk;
    IntStackResult result = Initialize(&stk, 100);
    if (result != SUCCESS) {
        printf("初期化失敗\n");
        exit(1);
    }

    while (true) {
        if (n > 0) {
            Push(&stk, n);
            n = n - 1;
            continue;
        }
        if (IsEmpty(&stk) == false) {
            Pop(&stk, &n);
            printf("%d\n", n);
            n = n - 2;
            continue;
        }
        break;
    }

    Terminate(&stk);
}