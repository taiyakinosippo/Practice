//==========================================================
//	差分b-a
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // sscanf(),scanf(),printf()
// 関数プロトタイプ

int main(int argc, char* argv[])
{
	int a, b;
	do {
		printf("aの値:");
		scanf_s("%d", &a);
	} while (a <= 0);

	// ここをコーディングしてください。
	// b<=a なら再度入力させます。
	do {
		printf("aより大きな値を入力せよ！\n");
		scanf_s("%d", &b);
		if (b <= a)
		{
			b = -1;
		}
	} while (b < 0);

	printf("%d - %d = %d\n", b, a, b - a);
	return 0;
}