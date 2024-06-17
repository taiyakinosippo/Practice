//==========================================================
//	�N���̌o�ߓ���
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>�@// printf()
#include <stdlib.h> // srand(),rand()
#include <time.h>   // time()
// �֐��v���g�^�C�v
int DaysInYear(int year, int month, int day);
bool isLeapYear(int year);
int getRandRange(int min, int max);

int MonthDays[][12] = {
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31},
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
		printf("%d�N%d��%d���́A�N����%d���ڂł�\n", year, month, day, dayCount);

		printf("\n������x���܂���?(1:�͂�/0:������)");
		scanf("%d", &retry);
	} while (retry == 1);
	return 0;
}

int DaysInYear(int year, int month, int day)
{
	int dayCount = day;
	int idx = isLeapYear(year) ? 1 : 0;
	for (int i = 1; i < month; i++) {
		dayCount += MonthDays[idx][i - 1];
	}
	return dayCount;
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