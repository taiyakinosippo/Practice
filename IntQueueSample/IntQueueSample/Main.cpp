//=========================================================
//	Int�L���[�T���v��main
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include "IntQueue.h"
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // exit()

typedef enum {
	TERMINATE, ENQUE, DEQUE, PEEK, PRINT,
} Menu;

// �֐��v���g�^�C�v
Menu SelectMenu();
void setup(IntQueue* que);

int main()
{
	const int QUEUE_SIZE = 8;

	IntQueue que;
	IntQueueResult result;
	result = Initialize(&que, QUEUE_SIZE);
	if (result != SUCCESS) {
		puts("�L���[�̐����Ɏ��s���܂���");
		exit(1);
	}
	setup(&que);
	Menu menu;
	do {
		int x;
		printf("���݂̃f�[�^��:%d / %d\n", Size(&que), Capacity(&que));
		menu = SelectMenu();
		switch (menu) {
		case ENQUE:
			printf("�f�[�^:");
			scanf("%d", &x);
			result = Enque(&que, x);
			if (result != SUCCESS) {
				puts("\a�G���[:�G���L���[�Ɏ��s���܂���");
			}
			break;
		case DEQUE:
			result = Deque(&que, &x);
			if (result != SUCCESS) {
				puts("\a�G���[:�f�L���[�Ɏ��s���܂���");
			}
			else {
				printf("�f�L���[�����f�[�^�� %d �ł�\n", x);
			}
			break;
		case PEEK:
			result = Peek(&que, &x);
			if (result != SUCCESS) {
				puts("\a�G���[:�s�[�N�Ɏ��s���܂���");
			}
			else {
				printf("�s�[�N�����f�[�^�� %d �ł�\n", x);
			}
			break;
		case PRINT:
			Print(&que);
			break;
		}
	} while (menu != TERMINATE);

	Terminate(&que);
	return 0;
}

Menu SelectMenu()
{
	int ch;
	do {
		printf("1)�G���L���[ 2)�f�L���[ 3)�s�[�N 4)�\�� 0)�I��:");
		scanf("%d", &ch);
	} while (ch < TERMINATE || PRINT < ch);
	return (Menu)ch;
}

void setup(IntQueue* que)
{
	int data[] = { 1,2,3,4,5 };
	int dataSize = sizeof(data) / sizeof(data[0]);
	for (int i = 0; i < dataSize; i++) {
		Enque(que, data[i]);
	}
}