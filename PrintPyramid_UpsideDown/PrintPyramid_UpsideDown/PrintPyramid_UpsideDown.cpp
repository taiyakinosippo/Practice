//==========================================================
//	�s���~�b�h��\������ �|�u
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
// �֐��v���g�^�C�v
void PrintPyramid_UpsideDown(int n);

int main()
{
	while (true) {
		int n;
		do {
			printf("���i�̃s���~�b�h�ł���? ");
			scanf("%d", &n);
		} while (n <= 0);
 		PrintPyramid_UpsideDown(n);
	}
	return 0;
}

void PrintPyramid_UpsideDown(int n)
{
	// �������R�[�f�B���O���Ă��������B
	for (int i = 0; i < n; i++)
	{
		for (int j = n; j >= 0; j--)
		{
			if (j < n - i)
			{
				printf("%d", i + 1);
				
			}
			else
			{
				printf(" ");
			}
		}
		for (int k = 1; k < n - i; k++)
		{
			printf("%d", i + 1);
		}
		putchar('\n');
	}
}