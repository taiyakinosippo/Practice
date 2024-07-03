//=========================================================
//	qsortサンプル 構造体
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand(),qsort()
#include <string.h>  // strcmp()

const int NAME_SIZE = 10;

typedef struct {
	char name[NAME_SIZE];  // 名前
	int height;            // 身長
	int weight;            // 体重
} Person;

// 関数プロトタイプ
int CompareName(const Person* a, const Person* b);
int CompareHeight(const Person* a, const Person* b);
int CompareWeight(const Person* a, const Person* b);
void printPerson(const Person array[], int arraySize);

int main()
{
	Person x[] = {
		{"Shibata",179,52},
		{"Takaoka",180,70},
		{"Nangoh",172,63},
		{"Sugiyama",165,50},
	};

	int xSize = sizeof(x) / sizeof(x[0]);

	puts("ソート前");
	printPerson(x, xSize);
	// 名前の昇順にソート
	qsort(x, xSize, sizeof(Person), (int(*)(const void*, const void*))CompareName);
	puts("名前の昇順ソート");
	printPerson(x, xSize);
	// 身長の昇順にソート
	qsort(x, xSize, sizeof(Person), (int(*)(const void*, const void*))CompareHeight);
	puts("身長の昇順ソート");
	printPerson(x, xSize);
	// 体重の昇順にソート
	qsort(x, xSize, sizeof(Person), (int(*)(const void*, const void*))CompareWeight);
	puts("体重の昇順ソート");
	printPerson(x, xSize);

}

int CompareName(const Person* a, const Person* b)
{
	return strcmp(a->name, b->name);
}
int CompareHeight(const Person* a, const Person* b)
{
	return a->height - b->height;
}

int CompareWeight(const Person* a, const Person* b)
{
	return a->weight - b->weight;
}

void printPerson(const Person array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++) {
		printf("%-10s %dcm %dkg\n", array[i].name, array[i].height, array[i].weight);
	}
}