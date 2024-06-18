//==========================================================
//	1〜Nの総和　while版 確認
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
		sscanf(argv[1], "%d", &N);
		calcSum(N);
	}
	else {
		while (true) {
			printf("nの値:");
			scanf("%d", &N);
			calcSum(N);
		}
	}
	return 0;
}
void calcSum(int N)
{
	int sum = SumOfN(N);
	printf("1～%dの総和は%d\n", N, sum);
}

int SumOfN(int n)
{
	int sum = 0;
	int i = 1;
	while (i <= n) {
		sum += i;
		i++;
	}
	//
	//  ここをコーディングしてください。
	//   i の値をプリントして、n+1 になっていることを確認しましょう
	//
	printf("%d\n", i);
	return sum;
}