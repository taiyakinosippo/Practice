//==========================================================
//	����b-a
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // sscanf(),scanf(),printf()
// �֐��v���g�^�C�v

int main(int argc, char* argv[])
{
	int a, b;
	do {
		printf("a�̒l:");
		scanf_s("%d", &a);
	} while (a <= 0);

	// �������R�[�f�B���O���Ă��������B
	// b<=a �Ȃ�ēx���͂����܂��B
	do {
		printf("a���傫�Ȓl����͂���I\n");
		scanf_s("%d", &b);
		if (b <= a)
		{
			b = -1;
		}
	} while (b < 0);

	printf("%d - %d = %d\n", b, a, b - a);
	return 0;
}