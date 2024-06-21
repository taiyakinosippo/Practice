#pragma once
//=========================================================
//	�`�F�C���n�b�V��
//==========================================================
#ifndef __CHAIN_HASH
#define __CHAIN_HASH
#include "Member.h"

// �o�P�b�g��\���m�[�h
typedef struct __node {
	Member         data;   // �f�[�^
	struct __node* next;   // �㑱�f�[�^�ւ̃|�C���^
} Node;

// �n�b�V���\
typedef struct {
	int size;
	Node** table;
} ChainHash;

// �e�֐��̐���/���s���U���g
typedef enum {
	SUCCESS = 0,
	INITIALIZE_FAIL = 1,
	ADD_ALREADY_EXIST = 2,
	ADD_CALLOC_FAIL = 3,
	REMOVE_NOT_FOUND = 4,
} ChainHashResult;

// �n�b�V���\��������
ChainHashResult Initialize(ChainHash* h, int size);

// �T��
Node* Search(const ChainHash* h, const Member* x);

// �f�[�^�̒ǉ�
ChainHashResult Add(ChainHash* h, const Member* x);

// �f�[�^�̍폜
ChainHashResult Remove(ChainHash* h, const Member* x);

// �S�f�[�^�̍폜
void Clear(ChainHash* h);

// �n�b�V���\�̌サ�܂�
void Terminate(ChainHash* h);

// �n�b�V���\���_���v
void Dump(const ChainHash* h);

#endif // __CHAIN_HASH