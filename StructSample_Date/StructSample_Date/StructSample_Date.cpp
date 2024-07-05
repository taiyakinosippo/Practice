//==========================================================
//	構造体サンプル Date
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  // printf()
#include <stdlib.h> // srand(),rand()
#include <time.h>   // time()
#include <stdbool.h> // bool

typedef struct {
    int y;  // 西暦年
    int m;  // 月(1〜12)
    int d;  // 日(1〜31)
} Date;

// 関数プロトタイプ
Date DateOf(int year, int month, int day);
Date AfterDate(Date date, int days);
Date BeforeDate(Date date, int days);
bool isLeapYear(int year);
int getRandRange(int min, int max);
char* getStringOf(Date date, char buff[]);
int getMonthDays(int year, int month);

int MonthDays[][12] = {
    {31,28,31,30,31,30,31,31,30,31,30,31},
    {31,29,31,30,31,30,31,31,30,31,30,31},
};

int main()
{
    const int BUFF_SIZE = 64;
    srand(time(NULL));

    int retry;
    char buff1[BUFF_SIZE];
    char buff2[BUFF_SIZE];
    char buff3[BUFF_SIZE];
    do {
        int year = getRandRange(1900, 2024);
        int month = getRandRange(1, 12);
        int day = getRandRange(1, getMonthDays(year, month));
        Date date = DateOf(year, month, day);

        int val = getRandRange(1, 100);
        Date after = AfterDate(date, val);
        Date before = BeforeDate(date, val);

        char* s1 = getStringOf(date, buff1);
        char* s2 = getStringOf(after, buff2);
        char* s3 = getStringOf(before, buff3);
        printf("%s の %d日後は %s\n", s1, val, s2);
        printf("%s の %d日前は %s\n", s1, val, s3);

        printf("\nもう一度?(1:はい/0:いいえ)");
        scanf("%d", &retry);
    } while (retry == 1);

    return 0;
}

int getRandRange(int min, int max)
{
    int wid = max - min + 1;
    return min + rand() % wid;
}

// 年月日から日付を返す
Date DateOf(int year, int month, int day)
{
    return Date { year, month, day };
}

// N日前の日付を返す
Date BeforeDate(Date date, int subDays)
{
    while (subDays > 0) {
        if (date.d > subDays) {
            date.d -= subDays;
            subDays = 0;
        }
        else {
            subDays -= date.d;
            date.m--;
            if (date.m < 1) {
                date.m = 12;
                date.y--;
            }
            date.d = getMonthDays(date.y, date.m);
        }
    }
    return date;
}

// N日後の日付を返す
Date AfterDate(Date date, int addDays)
{
    while (addDays > 0) {
        int daysInMonth = getMonthDays(date.y, date.m);
        if (date.d + addDays <= daysInMonth) {
            date.d += addDays;
            addDays = 0;
        }
        else {
            addDays -= (daysInMonth - date.d + 1);
            date.d = 1;
            date.m++;
            if (date.m > 12) {
                date.m = 1;
                date.y++;
            }
        }
    }
    return date;
}

// 日付の文字列を返す
char* getStringOf(Date date, char buff[])
{
    sprintf(buff, "%d年%02d月%02d日", date.y, date.m, date.d);
    return buff;
}

// 年月からその月の日数を得る
int getMonthDays(int year, int month)
{
    int idx = isLeapYear(year) ? 1 : 0;
    return MonthDays[idx][month - 1];
}

// うるう年か?
bool isLeapYear(int year)
{
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}
