//=========================================================
//	�K��̌v�Z
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()

// �֐��v���g�^�C�v
int Factorial(int n);

int main()
{
	while (true) {
		int n;
		do {
			printf("���l:");
			scanf("%d", &n);
		} while (n < 0);

		int ans = Factorial(n);
		printf("%d�̊K��́A%d�ł�\n", n, ans);
	}
	return 0;
}

int Factorial(int n)
{
	if (n > 0) {
		return n * Factorial(n - 1);
	}
	else {
		// 0!��1
		return 1;
	}
}