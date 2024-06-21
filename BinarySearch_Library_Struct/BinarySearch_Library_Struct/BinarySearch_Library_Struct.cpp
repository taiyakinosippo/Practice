//==========================================================
//	２分探索  ライブラリー利用 構造体
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h> // bsearch()
#include <string.h> // strcmp()

const int NAME_SIZE = 32;

typedef struct {
	char name[NAME_SIZE]; // 名前
	int height;           // 身長
	int weight;           // 体重
} Person;

// 関数プロトタイプ
int ComparePerson(const Person* a, const Person* b);

int main()
{
	Person data[] = {
		{"ABE",     179,79},
		{"NANGO",   172,63},
		{"SHIBATA", 176,62},
		{"SUGIYAMA",165,61},
		{"TAKAOKA", 181,73},
		{"TSURUMI", 172,64},
	};
	int dataSize = sizeof(data) / sizeof(data[0]);
	int retry;
	puts("名前による検索を行います");
	do {
		Person key;
		printf("名前:");
		scanf("%s", key.name);

		Person* p = (Person*)bsearch(
			&key,
			data,
			dataSize,
			sizeof(Person),
			(int (*)(const void*, const void*))ComparePerson
		);

		if (p == nullptr) {
			puts("検索失敗");
		}
		else {
			puts("検索成功!! 以下の要素を見つけました");
			int idx = p - data;
			printf("data[%d]:%s %d cm %d kg\n", idx, p->name, p->height, p->weight);
		}
		printf("もう一度探索しますか?(1:はい/0:いいえ)");
		scanf("%d", &retry);
	} while (retry == 1);
	return 0;
}

int ComparePerson(const Person* a, const Person* b)
{
	return strcmp(a->name, b->name);
}