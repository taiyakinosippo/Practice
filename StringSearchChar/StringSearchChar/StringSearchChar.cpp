//=========================================================
//	�����񂩂當������
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf(),scanf()

const int NOT_FOUND = -1;

// �֐��v���g�^�C�v
int str_chr(const char* str, int ch);

int main()
{
	char str[256];
	char tmp[256];
	char ch;
	while (true) {
		printf("������:");
		scanf("%s", str);
		printf("��������:");
		scanf("%s", tmp);
		ch = tmp[0];

		int idx = str_chr(str, ch);
		if (idx == NOT_FOUND) {
			printf("����'%c'�͕����񒆂ɑ��݂��܂���\n", ch);
		}
		else {
			printf("����'%c'��%d�����ڂɑ��݂��܂�\n", ch, idx + 1);
		}
		putchar('\n');
	}
	return 0;
}

int str_chr(const char* str, int c)
{
	int idx = 0;
	c = (char)c;
	while (str[idx] != c) {
		if (str[idx] == '\0') {
			return NOT_FOUND;
		}
		idx++;
	}
	return idx;
}