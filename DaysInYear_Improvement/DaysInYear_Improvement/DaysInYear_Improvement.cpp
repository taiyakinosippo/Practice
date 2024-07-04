//==========================================================
//	年内の経過日数 改良版
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>　// printf()
#include <stdlib.h> // srand(),rand()
#include <time.h>   // time()
// 関数プロトタイプ
int DaysInYear(int year, int month, int day);
bool isLeapYear(int year);
int getRandRange(int min, int max);

int MonthDays[][12] = {
	{0,
	0+31,
	0+31+28,
	0 + 31 + 28+31,
	0 + 31 + 28 + 31+30,
	0 + 31 + 28 + 31 + 30+31,
	0 + 31 + 28 + 31 + 30 + 31+30,
	0 + 31 + 28 + 31 + 30 + 31 + 30+31,
	0 + 31 + 28 + 31 + 30 + 31 + 30 + 31+31,
	0 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31+30,
	0 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30+31,
	0 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31+30},
	{0,
	0 + 31,
	0 + 31 + 28,
	0 + 31 + 28 + 31,
	0 + 31 + 28 + 31 + 30,
	0 + 31 + 28 + 31 + 30 + 31,
	0 + 31 + 28 + 31 + 30 + 31 + 30,
	0 + 31 + 28 + 31 + 30 + 31 + 30 + 31,
	0 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31,
	0 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30,
	0 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31,
	0 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30},
};

int main()
{
	srand(time(nullptr));

	int retry;
	do {
		int year = getRandRange(1900, 2024);
		int month = getRandRange(1, 12);
		int day = getRandRange(1, 31);

		int dayCount = DaysInYear(year, month, day);
		printf("%d年%d月%d日は、年内で%d日目です\n", year, month, day, dayCount);

		printf("\nもう一度しますか?(1:はい/0:いいえ)");
		scanf("%d", &retry);
	} while (retry == 1);
	return 0;
}

int DaysInYear(int year, int month, int day)
{
	// ここをコーディングしてください。
	// 経過日数の変数、ループ変数を使わない。(かわりに引数変数を使う)
	// for()ではなく while()を使う
	return MonthDays[0][month - 1] + day;
}

bool isLeapYear(int year)
{
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

int getRandRange(int min, int max)
{
	int wid = max - min + 1;
	return min + rand() % wid;
}