#pragma once
//=========================================================
//	�A���C�����N���X�g
//=========================================================
#ifndef __ArrayLinkedList
#define __ArrayLinkedList

#include "Member.h"

typedef int Index;   // �J�[�\���^

const Index NullIndex = -1;  // ��J�[�\��

// �m�[�h
typedef struct __node {
	Member   data;     // �f�[�^
	Index    next;     // �㑱�J�[�\��
	Index    freeNext; // �t���[���X�g�̌㑱�J�[�\��
} Node;

// ���`���X�g
typedef struct {
	Node* array;    // ���X�g�{��(�z��)
	Index head;     // �擪�J�[�\��
	Index freeHead; // �t���[���X�g�̐擪�J�[�\��
	Index current;  // ���ڃJ�[�\��
} List;

// ���`���X�g�̏�����
void Initialize(List* list, int size);
// ����
Index Search(List* list, const Member* x, int compare(const Member* a, const Member* b));
// �擪�Ƀm�[�h��}��
void InsertFront(List* list, const Member* x);
// �����Ƀm�[�h��}��
void InsertRear(List* list, const Member* x);
// �擪�m�[�h���폜
void RemoveFront(List* list);
// �����m�[�h���폜
void RemoveRear(List* list);
// ���ڃm�[�h���폜
void RemoveCurrent(List* list);
// �S�m�[�h���폜
void Clear(List* list);
// ���ڃm�[�h�̃f�[�^��\��
void PrintCurrent(const List* list);
// ���ڃm�[�h�̃f�[�^��\��(���s����)
void PrintLnCurrent(const List* list);
// �S�m�[�h�̃f�[�^�����X�g���ɕ\��
void Print(const List* list);
// ���`���X�g�̌�n��
void Terminate(List* list);

#endif // __ArrayLinkedList