#pragma once
//=========================================================
//	�Q���T����
//=========================================================
#ifndef __BinaryTree
#define __BinaryTree

#include "Member.h"

// �m�[�h
typedef struct __node {
	Member         data;  // �f�[�^
	struct __node* left;  // ���|�C���^�[(���q�m�[�h�ւ̃|�C���^�[)
	struct __node* right; // �E�|�C���^�[(�E�q�m�[�h�ւ̃|�C���^�[)
} BinNode;

// �T��
BinNode* Search(BinNode* p, const Member* x);
// �m�[�h�̑}��
BinNode* Add(BinNode* p, const Member* x);
// �m�[�h�̍폜
bool Remove(BinNode** root, const Member* x);
// �S�m�[�h�̕\��
void PrintTree(const BinNode* p);
// �S�m�[�h�̍폜
void FreeTree(BinNode* p);
// �_���v
void DumpTree(BinNode* p, int level = 0);
// �c���[��ԕ\��
void PrintTreeState(BinNode* p);

#endif // __BinaryTree
