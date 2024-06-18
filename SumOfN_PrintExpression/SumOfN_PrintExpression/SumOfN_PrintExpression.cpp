//==========================================================
//	1〜Nの総和　式を表示する
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // sscanf(),scanf(),printf()
// 関数プロトタイプ
int SumOfN(int n);
void calcSum(int N);

int main(int argc, char* argv[])
{
	int N;
	if (argc >= 2) {
		scanf_s(argv[1], "%d", &N);
		calcSum(N);
	}
	else {
		while (true) {
			printf("nの値:");
			scanf_s("%d", &N);
			calcSum(N);
		}
	}
	return 0;
}
void calcSum(int N)
{
	int sum = SumOfN(N);
	// ここをコーディングしてください。
	//  ヒント: "数値 + "か"数値 = " を表示する 
	//  '+' か '=' かは３項演算子を使うと良い
	printf("『");
	for(int i = 1; i <= N; i++)
	{
		if (i == N)
		{
			printf("%d = ", i);
			break;
		}
		printf("%d + ", i);
	}
	printf("%d』\n", sum);
}

int SumOfN(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	return sum;
}