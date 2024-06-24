#pragma once
//==========================================================
//	�N���[�Y�h�n�b�V���@�ɂ��n�b�V���̗��p��
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include "Member.h"
#include "ClosedHash.h"
#include <stdio.h>   // printf()
#include <stdlib.h>  // exit()

typedef enum {
	TERMINATE, ADD, DELETE, SEARCH, CLEAR, DUMP
}Menu;

// �֐��v���g�^�C�v
Menu SelectMenu(void);
void setup(ClosedHash* h);

int main()
{
	const int HASH_SIZE = 13;
	Menu menu;
	ClosedHash hash;
	ClosedHashResult result = Initialize(&hash, HASH_SIZE);
	if (result != SUCCESS) {
		printf("���������s!\n");
		exit(1);
	}
	setup(&hash);
	do {
		Member x;
		Bucket* temp;
		menu = SelectMenu();
		switch (menu) {
		case ADD:
			x = ScanMember("�ǉ�", MEMBER_NO | MEMBER_NAME);
			result = Add(&hash, &x);
			if (result != SUCCESS) {
				const char* cause = result == ADD_ALREADY_EXIST ? "�o�^��" : "�e�[�u���s��";
				printf("�ǉ��Ɏ��s���܂���(%s)\n", cause);
			}
			break;
		case DELETE:
			x = ScanMember("�폜", MEMBER_NO);
			result = Remove(&hash, &x);
			if (result != SUCCESS) {
				printf("\n�G���[:���̔ԍ��̃f�[�^�͑��݂��܂���\n");
			}
			break;
		case SEARCH:
			x = ScanMember("�T��", MEMBER_NO);
			temp = Search(&hash, &x);
			if (temp == nullptr) {
				printf("\n�T���Ɏ��s���܂���\n");
			}
			else {
				printf("�T���ɐ������܂���:");
				PrintLnMember(&temp->data);
			}
			break;
		case CLEAR:
			Clear(&hash);
			break;
		case DUMP:
			Dump(&hash);
			break;
		}
	} while (menu != TERMINATE);
	Terminate(&hash);
	return 0;
}

Menu SelectMenu()
{
	int ch;
	do {
		printf("1)�ǉ� 2)�폜 3)�T�� 4)�S�폜 5)�_���v 0)�I��:");
		scanf("%d", &ch);
	} while (ch < TERMINATE || DUMP < ch);
	return (Menu)ch;
}
void setup(ClosedHash* h)
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
		Add(h, &data[i]);
	}
}