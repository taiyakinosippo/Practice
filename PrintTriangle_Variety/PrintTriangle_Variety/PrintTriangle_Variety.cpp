//==========================================================
//	三角形を表示する バラエティ
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
// 関数プロトタイプ
void PrintTriangle(int n);

void PrintTriangleLB(int n)
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
}
void PrintTriangleLU(int n)
{
	// ここをコーディングしましょう。
	// 左上側が直角の２等辺三角形
	for (int i = n; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			putchar('*');
		}
		putchar('\n');
	}
}
void PrintTriangleRU(int n)
{
	// ここをコーディングしましょう。
	// 右上側が直角の２等辺三角形
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j < i)
			{
				printf(" ");
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
}
void PrintTriangleRB(int n)
{
	// ここをコーディングしましょう。
	// 右下側が直角の２等辺三角形
	for (int i = n-1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (j < i)
			{
				printf(" ");
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
}

int main()
{
	while (true) {
		int n;
		do {
			printf("何段の三角形ですか? ");
			scanf_s("%d", &n);
		} while (n <= 0);
		PrintTriangleLB(n); printf("\n");
		PrintTriangleLU(n); printf("\n");
		PrintTriangleRU(n); printf("\n");
		PrintTriangleRB(n); printf("\n");
	}
	return 0;
}


