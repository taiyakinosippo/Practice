//=========================================================
//	文字列から文字検索
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf(),scanf()

const int NOT_FOUND = -1;

// 関数プロトタイプ
int str_chr(const char* str, int ch);

int main()
{
	char str[256];
	char tmp[256];
	char ch;
	while (true) {
		printf("文字列:");
		scanf("%s", str);
		printf("検索文字:");
		scanf("%s", tmp);
		ch = tmp[0];

		int idx = str_chr(str, ch);
		if (idx == NOT_FOUND) {
			printf("文字'%c'は文字列中に存在しません\n", ch);
		}
		else {
			printf("文字'%c'は%d文字目に存在します\n", ch, idx + 1);
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