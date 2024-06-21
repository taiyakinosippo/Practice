#pragma once
//=========================================================
//	�N���[�Y�h�n�b�V��
//==========================================================
#ifndef __CLOSED_HASH
#define __CLOSED_HASH

#include "Member.h"

// �v�f�̏��
typedef enum {
	Occupied, Empty, Deleted
} Status;

typedef struct {
	Member data;   // �f�[�^
	Status stat;   // �v�f�̏��
} Bucket;

typedef struct {
	int     size;        // �n�b�V���\�z��̑傫��
	Bucket* table;   // �n�b�V���\�z��ւ̃|�C���^�[
} ClosedHash;

// �e�֐��̐���/���s���U���g
typedef enum {
	SUCCESS = 0,
	INITIALIZE_FAIL = 1,   // ���������s
	ADD_ALREADY_EXIST = 2, // ADD���ɑ��݂��Ă� 
	ADD_NO_SPACE = 3,      // ADD�n�b�V���e�[�u������t
	REMOVE_NOT_FOUND = 4,
} ClosedHashResult;

// �n�b�V���\��������
ClosedHashResult Initialize(ClosedHash* h, int size);
// �T��
Bucket* Search(const ClosedHash* h, const Member* x);
// �f�[�^�̒ǉ�
ClosedHashResult Add(ClosedHash* h, const Member* x);
// �f�[�^�̍폜
ClosedHashResult Remove(ClosedHash* h, const Member* x);
// �n�b�V���\���_���v
void Dump(const ClosedHash* h);
// �S�f�[�^�̍폜
void Clear(ClosedHash* h);
// �n�b�V���\�̌�n��
void Terminate(ClosedHash* h);

#endif // __CLOSED_HASH
