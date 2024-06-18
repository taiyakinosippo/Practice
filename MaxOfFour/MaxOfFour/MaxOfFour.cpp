//==============================================
//  4値の最大値
//==============================================
#include <stdio.h>
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// 関数プロトタイプ
int MaxOfFour(int a, int b, int c, int d);

int main()
{
	srand(time(nullptr));
	int a = rand() % 100;
	int b = rand() % 100;
	int c = rand() % 100;
	int d = rand() % 100;
	int ans = MaxOfFour(a, b, c, d);
	printf("MaxOfFour(%d,%d,%d,%d) => %d\n", a, b, c, d, ans);
	return 0;
}
int MaxOfFour(int a, int b, int c, int d)
{
	// ここをコーディングしてください。
	return a + b + c + d;
}