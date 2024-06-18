//==========================================================
//	1〜Nの総和　ガウスの方法
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // sscanf(),scanf(),printf()
#include <stdlib.h> // exit()
// 関数プロトタイプ
int SumOfN(int n);
int SumOfN_GaussMethod(int n);
void calcSum(int N);

int main(int argc, char* argv[])
{
	int N;
	if (argc >= 2) {
		sscanf_s(argv[1], "%d", &N);
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
	int sum1 = SumOfN_GaussMethod(N);
	int sum2 = SumOfN(N);
	if (sum1 != sum2) {
		printf("ガウスの方法の結果が間違っています:N=%d,sum1=%d,sum2=%d", N, sum1, sum2);
		exit(1);
	}

	printf("1～%dの総和は%d\n", N, sum1);
}

int SumOfN(int n)
{
	int sum = 0;
	for (int i = 0; i <= n; i++) {
		sum += i;
	}
	return sum;
}

int SumOfN_GaussMethod(int n)
{
	// ここをコーディングします
	// nが奇数の時に注意してください。
	return (1 + n) * n/2;

}