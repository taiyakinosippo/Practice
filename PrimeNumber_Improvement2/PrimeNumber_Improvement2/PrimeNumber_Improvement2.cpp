//==========================================================
//	ëfêîÅ@â¸ó«î≈2
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
        bool isPrimeNumber = true;
        for (i = 0; counter++, prime[i] * prime[i] <= n; i++) {
            counter++;
            if (n % prime[i] == 0) {
                isPrimeNumber = false;
                break;
            }
        }
        if (isPrimeNumber) {
            prime[primePtr++] = n;
        }
    }
    for (int i = 0; i < primePtr; i++) {
        printf("%d ", prime[i]);
    }
    printf("\nèÊèúéZÇçsÇ¡ÇΩâÒêî:%lu\n", counter);
    return 0;
}
