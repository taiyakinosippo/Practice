//==========================================================
//	�A���C���`���X�g�T���v��
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include "member.h"
#include "ArrayLinkedList.h"
#include <stdio.h> // printf(),scanf()

typedef enum {
	TERMINATE,
	INSERT_FRONT,
	INSERT_REAR,
	REMOVE_FRONT,
	REMOVE_REAR,
	PRINT_CURRENT,
	REMOVE_CURRENT,
	SEARCH_NO,
	SEARCH_NAME,
	PRINT_ALL,
	CLEAR,
} Menu;

// �֐��v���g�^�C�v
Menu SelectMenu();
void setup(List* list);

int main()
{
	Menu menu;
	List list;

	Initialize(&list, 30);
	setup(&list);
	do {
		Member x;
		Index idx;
		Node* node;
		menu = SelectMenu();
		switch (menu) {
		case INSERT_FRONT:
			x = ScanMember("�擪�ɑ}������", MEMBER_NO + MEMBER_NAME);
			InsertFront(&list, &x);
			break;
		case INSERT_REAR:
			x = ScanMember("�����ɑ}������", MEMBER_NO + MEMBER_NAME);
			InsertRear(&list, &x);
			break;
		case REMOVE_FRONT:
			RemoveFront(&list);
			break;
		case REMOVE_REAR:
			RemoveRear(&list);
			break;
		case PRINT_CURRENT:
			PrintLnCurrent(&list);
			break;
		case REMOVE_CURRENT:
			RemoveCurrent(&list);
			break;
		case SEARCH_NO:
			x = ScanMember("����", MEMBER_NO);
			idx = Search(&list, &x, MemberNoCmp);
			if (idx != NullIndex) {
				PrintCurrent(&list);
				putchar('\n');
			}
			else {
				puts("���̔ԍ��̃f�[�^�͂���܂���");
			}
			break;
		case SEARCH_NAME:
			x = ScanMember("����", MEMBER_NAME);
			idx = Search(&list, &x, MemberNameCmp);
			if (idx != NullIndex) {
				PrintCurrent(&list);
				putchar('\n');
			}
			else {
				puts("���̖��O�̃f�[�^�͂���܂���");
			}
			break;
		case PRINT_ALL:
			Print(&list);
			break;
		case CLEAR:
			Clear(&list);
			break;
		}
		putchar('\n');
	} while (menu != TERMINATE);

	Terminate(&list);
	return 0;
}

Menu SelectMenu()
{
	int ch;
	const char* menuStr[] = {
		"�擪�Ƀm�[�h��}��",
		"�����Ƀm�[�h��}��",
		"�擪�̃m�[�h���폜",
		"�����̃m�[�h���폜",
		"���ڃm�[�h��\��",
		"���ڃm�[�h���폜",
		"�ԍ��Ō���",
		"�����Ō���",
		"�S�m�[�h��\��",
		"�S�m�[�h���폜",
	};
	int menuStrSize = sizeof(menuStr) / sizeof(menuStr[0]);

	do {
		for (int i = 0; i < menuStrSize; i++) {
			printf("(%2d)%-18.18s  ", i + 1, menuStr[i]);
			if (i % 3 == 2) {
				putchar('\n');
			}
		}
		printf("( 0)�I��\t:");
		scanf("%d", &ch);
	} while (ch < TERMINATE || CLEAR < ch);
	return (Menu)ch;
}
void setup(List* list)
{
	Member data[] = {
		{1,"�Ԕ�"},
		{5,"���c"},
		{10,"����"}, 
		{12,"���"},
		{14,"�_��"},
	};
	int dataSize = sizeof(data) / sizeof(data[0]);
	for (int i = 0; i < dataSize; i++) {
		InsertRear(list, &data[i]);
	}
}