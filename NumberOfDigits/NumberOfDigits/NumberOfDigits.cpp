//==========================================================
//	�J�����̌���
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // sscanf(),scanf(),printf()
// �֐��v���g�^�C�v
int NumberOfDigits(int num);
void calcDigit(int num);

int main(int argc, char* argv[])
{
	int num;
	if (argc >= 2) {
		sscanf_s(argv[1], "%d", &num);
		calcDigit(num);
	}
	else {
		while (true) {
			do {
				printf("���̐���:");
				scanf_s("%d", &num);
			} while (num <= 0);
			calcDigit(num);
		}
	}
	return 0;
}
void calcDigit(int num)
{
	int digit = NumberOfDigits(num);
	printf("%d�̌����� %d\n", num, digit);
}

int NumberOfDigits(int num)
{
	// �������R�[�f�B���O���Ă��������B
	int count = 0;
	while (num > 9)
	{
		count++;
		num = num / 10;
	}
	return count + 1;
}