//=========================================================
//	文字列の長さ
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf(),scanf()

// 関数プロトタイプ
int str_len(const char* str);
int str_len2(const char* str);
int str_len3(const char* str);

int main()
{
	char str[256];
	while (true) {
		printf("文字列:");
		scanf("%s", str);

		int len = str_len(str);
		int len2 = str_len2(str);
		int len3 = str_len3(str);
		printf("その文字列は%d文字です\n", len);
		printf("その文字列は%d文字です\n", len2);
		printf("その文字列は%d文字です\n", len3);
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
