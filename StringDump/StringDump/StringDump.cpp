//=========================================================
//	文字列ダンプ
//=========================================================
#include <stdio.h> // printf
#include <limits.h> // CHAR_BIT
// 関数プロトタイプ
void str_dump(const char* str);

int main()
{
	str_dump("STRING");
	return 0;
}

void str_dump(const char* str)
{
	// 文字コードを16進数表示する時の桁数
	int w = (CHAR_BIT + 3) / 4;

	for (; *str != '\0'; str++) {
		unsigned int c = *str;
		printf("%c %0*X ", c, w, c);
		for (int i = CHAR_BIT - 1; i >= 0; i--) {
			putchar(((c >> i) & 1) != 0 ? '1' : '0');
		}
		putchar('\n');
	}
}