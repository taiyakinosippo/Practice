
//=========================================================
//	再帰アルゴリズムの解析(メモ化)
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <string.h>  // strcpy()

// 関数プロトタイプ
void recur(int n);
void dumpMemo(int n);

int main()
{
	while (true) {
		int n;
		do {
			printf("数値:");
			scanf("%d", &n);
		} while (n < 0);

		recur(n);
		dumpMemo(n);
	}
	return 0;
}

static char _memo[128][1024] = { 0 };
// memo[-1]も大丈夫
static char(*memo)[1024] = &_memo[1];

void recur(int n)
{
	if (memo[n][0] != '\0') {
		printf("%s", memo[n]);
	}
	else {
		if (n > 0) {
			recur(n - 1);
			printf("%d\n", n);
			recur(n - 2);
			sprintf(memo[n], "%s%d\n%s", memo[n - 1], n, memo[n - 2]);
		}
		else {
			strcpy(memo[n], "");
		}
	}
}

void dumpMemo(int n)
{
	puts("-------");
	for (int i = -1; i <= n; i++) {
		printf("memo[%d]:%s\n", i, memo[i]);
	}
}