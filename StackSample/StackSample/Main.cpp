//=========================================================
//	�X�^�b�N�T���v��
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include "IntStack.h"
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // exit()

typedef enum {
	TERMINATE, PUSH, POP, PEEK, PRINT
} Menu;

// �֐��v���g�^�C�v
Menu SelectMenu();
void setup(IntStack* s);

int main()
{
	const int STACK_SIZE = 64;

	IntStack s;
	IntStackResult result = Initialize(&s, STACK_SIZE);
	if (result != SUCCESS) {
		printf("���������s\n");
		exit(1);
	}
	setup(&s);
	Menu menu;
	do {
		int x;
		printf("���݂̃f�[�^��: % d / % d\n", Size(&s), Capacity(&s));
		menu = SelectMenu();
		switch (menu) {
		case PUSH:
			printf("�f�[�^:");
			scanf("%d", &x);
			result = Push(&s, x);
			if (result != SUCCESS) {
				puts("�G���[:�v�b�V���Ɏ��s���܂���");
			}
			break;
		case POP:
			result = Pop(&s, &x);
			if (result != SUCCESS) {
				puts("�G���[:�|�b�v�Ɏ��s���܂���");
			}
			else {
				printf("�|�b�v�����f�[�^��%d�ł�\n", x);
			}
			break;
		case PEEK:
			result = Peek(&s, &x);
			if (result != SUCCESS) {
				puts("�G���[:�s�[�N�Ɏ��s���܂���");
			}
			else {
				printf("�s�[�N�����f�[�^��%d�ł�\n", x);
			}
			break;
		case PRINT:
			Print(&s);
			break;
		}
	} while (menu != TERMINATE);
	Terminate(&s);
	return 0;
}

Menu SelectMenu()
{
	int ch;
	do {
		printf("1)�v�b�V�� 2)�|�b�v 3)�s�[�N 4)�\�� 0)�I��:");
		scanf("%d", &ch);
	} while (ch < TERMINATE || PRINT < ch);
	return (Menu)ch;
}

void setup(IntStack* s)
{
	int data[] = { 1,2,3,4, };
	int dataSize = sizeof(data) / sizeof(data[0]);
	for (int i = 0; i < dataSize; i++) {
		Push(s, data[i]);
	}
}