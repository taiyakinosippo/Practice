//==========================================================
//	�Q���T����
//==========================================================
#include "BinaryTree.h"
#include <stdio.h>   // printf(),puts()
#include <stdlib.h>  // calloc(),free()

// �֐��v���g�^�C�v
static BinNode* allocBinNode(void);
static void setBinNode(BinNode* node, const Member* x, const BinNode* left, const BinNode* right);

// �T��
BinNode* Search(BinNode* p, const Member* x)
{
	if (p == nullptr) {
		return nullptr;
	}
	int cond = MemberNoCmp(x, &p->data);
	if (cond == 0) {
		return p;
	}
	else if (cond < 0) {
		return Search(p->left, x);
	}
	else { // cond>0
		return Search(p->right, x);
	}
}
// �m�[�h�̑}��
BinNode* Add(BinNode* p, const Member* x)
{
	if (p == nullptr) {
		p = allocBinNode();
		setBinNode(p, x, nullptr, nullptr);
		return p;
	}
	int cond = MemberNoCmp(x, &p->data);
	if (cond == 0) {
		printf("�y�G���[�z%d�͊��ɓo�^����Ă��܂�\n", x->no);
	}
	else if (cond < 0) {
		p->left = Add(p->left, x);
	}
	else {
		p->right = Add(p->right, x);
	}
	return p;
}
// �m�[�h�̍폜
bool Remove(BinNode** root, const Member* x)
{
	BinNode* next, * temp;
	BinNode** left;
	BinNode** p = root;

	while (true) {
		int cond;
		if (*p == nullptr) {
			printf("�y�G���[�z%d�͓o�^����Ă��܂���\n", x->no);
			return false;
		}
		cond = MemberNoCmp(x, &(*p)->data);
		if (cond == 0) {
			break;
		}
		else if (cond < 0) {
			p = &(*p)->left;
		}
		else {
			p = &(*p)->right;
		}
	}
	if ((*p)->left == nullptr) {
		next = (*p)->right;
	}
	else {
		left = &(*p)->left;
		while ((*left)->right != nullptr) {
			left = &(*left)->right;
		}
		next = *left;
		*left = (*left)->left;
		next->left = (*p)->left;
		next->right = (*p)->right;
	}
	temp = *p;
	*p = next;
	free(temp);

	return true;
}
// �S�m�[�h�̕\��
void PrintTree(const BinNode* p)
{
	if (p != nullptr) {
		PrintTree(p->left);
		PrintLnMember(&p->data);
		PrintTree(p->right);
	}
}
// �S�m�[�h�̕\��(�~��)
void PrintTreeReverse(const BinNode* p)
{
	// �������R�[�f�B���O���Ă��������B
	if (p != nullptr) {
		PrintTreeReverse(p->right);
		PrintLnMember(&p->data);
		PrintTreeReverse(p->left);
	}
}
// �S�m�[�h�̍폜
void FreeTree(BinNode* p)
{
	if (p != nullptr) {
		FreeTree(p->left);
		FreeTree(p->right);
		free(p);
	}
}

// �m�[�h�𓮓I�Ɋm��
static BinNode* allocBinNode(void)
{
	BinNode* node = (BinNode*)calloc(1, sizeof(BinNode));
	if (node == nullptr) {
		printf("calloc���s");
		exit(1);
	}
	return node;
}
// �m�[�h�̃����o�[�ݒ�
static void setBinNode(BinNode* node, const Member* x, const BinNode* left, const BinNode* right)
{
	node->data = *x;
	node->left = (BinNode*)left;
	node->right = (BinNode*)right;
}