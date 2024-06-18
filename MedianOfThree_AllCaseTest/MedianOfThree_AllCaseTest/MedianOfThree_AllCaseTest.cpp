//==========================================================
//  3値の中央値　全ケースでテスト
//==========================================================
#include <stdio.h>
// 関数プロトタイプ
int MedianOfThree(int a, int b, int c);

int main()
{
	int value[][3] = {
		{3,2,1}, // [A] a>b>c
		{3,2,2}, // [B] a>b=c
		{3,1,2}, // [C] a>c>b
		{3,2,3}, // [D] a=c>b
		{2,1,3}, // [E] c>a>b
		{3,3,2}, // [F] a=b>c
		{3,3,3}, // [G] a=b=c
		{2,2,3}, // [H] c>a=b
		{2,3,1}, // [I] b>a>c
		{2,3,2}, // [J] b>a=c
		{1,3,2}, // [K] b>c>a
		{2,3,3}, // [L] b=c>a
		{1,2,3}, // [M] c>b>a
	};
	int valueSize = sizeof(value) / sizeof(value[0]);

	for (int i = 0; i < valueSize; i++) {
		int a = value[i][0];
		int b = value[i][1];
		int c = value[i][2];
		int ans = MedianOfThree(a, b, c);
		printf("MedianOfThree(%d,%d,%d) => %d\n", a, b, c, ans);
	}
	return 0;
}
int MedianOfThree(int a, int b, int c)
{
	// ここをコーディングしてください。 
	if (a >= b)
	{
		if (b >= c)
		{
			return b;
		}
		else if(a <= c)
		{
			return a;
		}
		else
		{
			return c;
		}
	}
	else if (a > c)
	{
		return a;
	}
	else if (b > c)
	{
		return c;
	}
	else
	{
		return b;
	}
}