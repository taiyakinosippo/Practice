//==========================================================
//	�����`��\������
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
// �֐��v���g�^�C�v
void PrintSquare(int n);

int main()
{
	while (true) {
		int n;
		do {
			puts("�����`��\�����܂�");
			printf("�i����: ");
			scanf_s("%d", &n);
			PrintSquare(n);
		} while (n <= 0);
	}
	return 0;
}

void PrintSquare(int n)
{
	// �������R�[�f�B���O���Ă�������
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("*");
		}
		putchar('\n');
	}
}