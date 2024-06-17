//==========================================================
//	ëfêî 
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()

int main()
{
    const int N = 1000;
    unsigned long counter = 0;

    for (int n = 2; n <= N; n++) {
        int i;
        for (i = 2; i < n; i++) {
            counter++;
            if (n % i == 0) {
                break;
            }
        }
        if (n == i) {
            printf("%d ", n);
        }
    }
    printf("\nèúéZÇçsÇ¡ÇΩâÒêî:%lu\n", counter);
    return 0;
}