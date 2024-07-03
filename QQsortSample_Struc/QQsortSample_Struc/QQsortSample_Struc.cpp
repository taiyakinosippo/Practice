//=========================================================
//	qsort�T���v�� �\����
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand(),qsort()
#include <string.h>  // strcmp()

const int NAME_SIZE = 10;

typedef struct {
	char name[NAME_SIZE];  // ���O
	int height;            // �g��
	int weight;            // �̏d
} Person;

// �֐��v���g�^�C�v
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

	puts("�\�[�g�O");
	printPerson(x, xSize);
	// ���O�̏����Ƀ\�[�g
	qsort(x, xSize, sizeof(Person), (int(*)(const void*, const void*))CompareName);
	puts("���O�̏����\�[�g");
	printPerson(x, xSize);
	// �g���̏����Ƀ\�[�g
	qsort(x, xSize, sizeof(Person), (int(*)(const void*, const void*))CompareHeight);
	puts("�g���̏����\�[�g");
	printPerson(x, xSize);
	// �̏d�̏����Ƀ\�[�g
	qsort(x, xSize, sizeof(Person), (int(*)(const void*, const void*))CompareWeight);
	puts("�̏d�̏����\�[�g");
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