//=========================================================
//	���[�N���b�h�̌ݏ��@(2���̍ő���񐔂����߂�)
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
// �֐��v���g�^�C�v
int gcd(int x, int y); // Greatest Common Divisor �����߂�

int main()
{
	while (true) {
		int x, y;
		do {
			printf("�P�ڂ̐���:");
			scanf("%d", &x);
		} while (x <= 0);
		do {
			printf("�Q�ڂ̐���:");
			scanf("%d", &y);
		} while (y <= 0);

		int ans = gcd(x, y);
		printf("%d �� %d �̍ő���񐔂� %d\n", x, y, ans);
	}
	return 0;
}

int gcd(int x, int y)
{
	if (y == 0) {
		return x;
	}
	else {
		return gcd(y, x % y);
	}
}
