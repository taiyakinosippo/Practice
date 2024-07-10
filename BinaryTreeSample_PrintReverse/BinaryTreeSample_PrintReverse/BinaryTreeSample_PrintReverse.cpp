//==========================================================
//	�Q���T���؃T���v�� PrintReverse
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include "member.h"
#include "BinaryTree.h"
#include <stdio.h> // printf(),scanf()

typedef enum {
	TERMINATE,
	ADD,
	REMOVE,
	SEARCH,
	PRINT,
	PRINT_REVERSE,
} Menu;

// �֐��v���g�^�C�v
Menu SelectMenu();
void setup(BinNode** root);

int main()
{
	Menu menu;
	BinNode* root = nullptr;

	setup(&root);
	do {
		Member x;
		BinNode* temp;
		menu = SelectMenu();
		switch (menu) {
		case ADD:
			x = ScanMember("�}��", MEMBER_NO + MEMBER_NAME);
			root = Add(root, &x);
			break;
		case REMOVE:
			x = ScanMember("�폜", MEMBER_NO);
			Remove(&root, &x);
			break;
		case SEARCH:
			x = ScanMember("�T��", MEMBER_NO);
			temp = Search(root, &x);
			if (temp != nullptr) {
				PrintLnMember(&temp->data);
			}
			break;
		case PRINT:
			puts("�y�ꗗ�\�z");
			PrintTree(root);
			break;
		case PRINT_REVERSE:
			puts("�y�ꗗ�\�z");
			PrintTreeReverse(root);
			break;
		}
	} while (menu != TERMINATE);

	FreeTree(root);
	return 0;
}

Menu SelectMenu()
{
	int ch;
	do {
		printf("\n(1)�}�� (2)�폜 (3)�T�� (4)�\�� (5)�~���\�� (0)�I��:");
		scanf("%d", &ch);
	} while (ch < TERMINATE || PRINT_REVERSE < ch);
	return (Menu)ch;
}
void setup(BinNode** root)
{
	Member data[] = {
		{1,"�Ԕ�"},
		{10,"����"},
		{5,"���c"},
		{12,"���"},
		{14,"�_��"},
	};
	int dataSize = sizeof(data) / sizeof(data[0]);
	for (int i = 0; i < dataSize; i++) {
		*root = Add(*root, &data[i]);
	}
}