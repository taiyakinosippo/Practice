//==========================================================
//	�s���~�b�h��\������
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
// �֐��v���g�^�C�v
void PrintPyramid(int n);

int main()
{
	while (true) {
		int n;
		do {
			printf("���i�̃s���~�b�h�ł���? ");
			scanf_s("%d", &n);
		} while (n <= 0);
		PrintPyramid(n);
	}
	return 0;
}

void PrintPyramid(int n)
{
	// �������R�[�f�B���O���Ă��������B
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= n - i; j++)
		{
			if (n-i > j)
			{
				putchar(' ');
			}
			else
			{
				for (int k = n; k >= j; k--)
				{
					printf("*");
				}
				for (int l = 0; l < i; l++)
				{
					printf("*");
				}
			}
		}
		putchar('\n');
	}
}