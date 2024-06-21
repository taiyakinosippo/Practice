//==========================================================
//	�Q���T��  ���C�u�����[���p �\����
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h> // bsearch()
#include <string.h> // strcmp()

const int NAME_SIZE = 32;

typedef struct {
	char name[NAME_SIZE]; // ���O
	int height;           // �g��
	int weight;           // �̏d
} Person;

// �֐��v���g�^�C�v
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
	puts("���O�ɂ�錟�����s���܂�");
	do {
		Person key;
		printf("���O:");
		scanf("%s", key.name);

		Person* p = (Person*)bsearch(
			&key,
			data,
			dataSize,
			sizeof(Person),
			(int (*)(const void*, const void*))ComparePerson
		);

		if (p == nullptr) {
			puts("�������s");
		}
		else {
			puts("��������!! �ȉ��̗v�f�������܂���");
			int idx = p - data;
			printf("data[%d]:%s %d cm %d kg\n", idx, p->name, p->height, p->weight);
		}
		printf("������x�T�����܂���?(1:�͂�/0:������)");
		scanf("%d", &retry);
	} while (retry == 1);
	return 0;
}

int ComparePerson(const Person* a, const Person* b)
{
	return strcmp(a->name, b->name);
}