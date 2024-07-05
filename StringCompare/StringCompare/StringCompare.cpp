//=========================================================
//	文字列比較
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf(),scanf()

// 関数プロトタイプ
int str_cmp(const char* str1, const char* str2);

int main()
{
	const char* fixStr = "ABCD";
	char str[256];
	while (true) {
		printf("文字列:");
		scanf("%s", str);

		int result = str_cmp(fixStr, str);
		printf("str_cmp(\"%s\",str) = %d\n", fixStr, result);
		putchar('\n');
	}
	return 0;
}

int str_cmp(const char* str1, const char* str2)
{
	while (*str1 == *str2) {
		if (*str1 == '\0') {
			return 0;
		}
		str1++;
		str2++;
	}
	int ch1 = *str1;
	int ch2 = *str2;
	return ch1 - ch2;
}