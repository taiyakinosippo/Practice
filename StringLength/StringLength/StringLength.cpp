//=========================================================
//	������̒���
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf(),scanf()

// �֐��v���g�^�C�v
int str_len(const char* str);
int str_len2(const char* str);
int str_len3(const char* str);

int main()
{
	char str[256];
	while (true) {
		printf("������:");
		scanf("%s", str);

		int len = str_len(str);
		int len2 = str_len2(str);
		int len3 = str_len3(str);
		printf("���̕������%d�����ł�\n", len);
		printf("���̕������%d�����ł�\n", len2);
		printf("���̕������%d�����ł�\n", len3);
		putchar('\n');
	}
	return 0;
}

int str_len(const char* str)
{
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return len;
}
int str_len2(const char* str)
{
	int len = 0;
	while (*str++ != '\0') {
		len++;
	}
	return len;
}
int str_len3(const char* str)
{
	const char* p = str;
	while (*str != '\0') {
		str++;
	}
	return str - p;
}
