//=========================================================
//	文字列探索Boyer-Moore法
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf(),scanf()
#include <string.h> // strlen()

// 関数プロトタイプ
int bm_match(const char* txt, const char* pat);

const int NOT_FOUND = -1;

int main()
{
	const int STRING_SIZE = 256;
	char str1[STRING_SIZE];
	char str2[STRING_SIZE];

	while (true) {
		puts("Boyer-Moore法");
		printf("テキスト:");
		scanf("%s", str1);

		printf("パターン:");
		scanf("%s", str2);

		int idx = kmp_match(str1, str2);
		if (idx == NOT_FOUND) {
			puts("テキスト中にパターンは存在しません");
		}
		else {
			printf("%d文字目にマッチしました\n", idx + 1);
		}
		putchar('\n');
	}
	return 0;
}

int bm_match(const char* txt, const char* pat)
{
	int txtLen = strlen(txt);
	int patLen = strlen(pat);
	int pt; // txtをなぞるカーソル
	int pp; // patをなぞるカーソル
	int skip[UCHAR_MAX + 1]; // スキップテーブル

	// スキップ表の作成
	int skipSize = sizeof(skip) / sizeof(skip[0]);
	for (int i = 0; i < skipSize; i++) {
		skip[i] = patLen;
	}
	for (int i = 0; i < patLen - 1; i++) {
		unsigned char c = pat[i];
		skip[c] = patLen - i - 1;
	}
	// 探索
	pt = patLen - 1;
	while (pt < txtLen) {
		pp = patLen - 1;
		while (txt[pt] == pat[pp]) {
			if (pp == 0) {
				return pt;
			}
			pp--;
			pt--;
		}
		unsigned char c = txt[pt];
		pt += (skip[c] > patLen - pp) ? skip[c] : patLen - pp;
	}
	return NOT_FOUND;
}