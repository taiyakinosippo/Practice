//==========================================================
//	ëfêîÅ@â¸ó«î≈
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()

int main()
{
    const int N = 1000;
    unsigned long counter = 0;
    int prime[500];
    int primePtr = 0;

    prime[primePtr++] = 2;
    for (int n = 3; n <= N; n += 2) {
        int i;
        for (i = 0; i < primePtr; i++) {
            counter++;
            if (n % prime[i] == 0) {
                break;
            }
        }
        if (i == primePtr) {
            prime[primePtr++] = n;
        }
    }
    for (int i = 0; i < primePtr; i++) {
        printf("%d ", prime[i]);
    }
    printf("\nèúéZÇçsÇ¡ÇΩâÒêî:%lu\n", counter);
    return 0;
}