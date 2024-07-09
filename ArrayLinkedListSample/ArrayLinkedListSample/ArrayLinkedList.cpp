//==========================================================
//	�A���C�����N���X�g
//==========================================================
#include "ArrayLinkedList.h"
#include <stdio.h>   // printf(),puts()
#include <stdlib.h>  // calloc(),free(),exit()

// �֐��v���g�^�C�v
static Index getNewNodeIndex(List* list);
static void deleteNodeIndex(List* list, Index idx);
static void setNode(Node* node, const Member* x, Index next);

// ���`���X�g�̏�����
void Initialize(List* list, int size)
{
	list->array = (Node*)calloc(size, sizeof(Node));
	if (list->array == nullptr) {
		puts("calloc()���s");
		exit(1);
	}
	// array[0�`size-1]���t���[���X�g�ɓo�^
	list->freeHead = 0;
	for (int i = 0; i < size - 1; i++) {
		list->array[i].freeNext = i + 1;
	}
	list->array[size - 1].freeNext = NullIndex;
	// �f�[�^���X�g�́A���
	list->head = NullIndex;
	list->current = NullIndex;
}
// ����
Index Search(List* list, const Member* x, int compare(const Member* a, const Member* b))
{
	Index ptr = list->head;
	while (ptr != NullIndex) {
		if (compare(&list->array[ptr].data, x) == 0) {
			list->current = ptr;
			return ptr;
		}
		ptr = list->array[ptr].next;
	}
	// ������Ȃ�����!!
	return NullIndex;
}
// �擪�Ƀm�[�h��}��
void InsertFront(List* list, const Member* x)
{
	Index next = list->head;
	Index newIdx = getNewNodeIndex(list);
	setNode(&list->array[newIdx], x, next);
	list->head = newIdx;
	list->current = newIdx;
}
// �����Ƀm�[�h��}��
void InsertRear(List* list, const Member* x)
{
	if (list->head == NullIndex) {
		InsertFront(list, x);
	}
	else {
		Index ptr = list->head;
		while (list->array[ptr].next != NullIndex) {
			ptr = list->array[ptr].next;
		}
		Index newIdx = getNewNodeIndex(list);
		setNode(&list->array[newIdx], x, NullIndex);
		list->array[ptr].next = newIdx;
		list->current = newIdx;
	}
}
// �擪�m�[�h���폜
void RemoveFront(List* list)
{
	if (list->head != NullIndex) {
		Index delIdx = list->head;
		Index next = list->array[delIdx].next;
		deleteNodeIndex(list, delIdx);
		list->head = next;
		list->current = next;
	}
}
// �����m�[�h���폜
void RemoveRear(List* list)
{
	if (list->head != NullIndex) {
		Index ptr = list->head;
		if (list->array[ptr].next == NullIndex) {
			RemoveFront(list);
		}
		else {
			Index prev;
			do {
				prev = ptr;
				ptr = list->array[ptr].next;
			} while (list->array[ptr].next != NullIndex);
			list->array[prev].next = NullIndex;
			deleteNodeIndex(list, ptr);
			list->current = prev;
		}
	}
}
// ���ڃm�[�h���폜
void RemoveCurrent(List* list)
{
	if (list->current != NullIndex) {
		if (list->current == list->head) {
			RemoveFront(list);
		}
		else {
			// �J�����g�̎�O��T��
			Index cur = list->current;
			Index ptr = list->head;
			while (list->array[ptr].next != cur) {
				ptr = list->array[ptr].next;
			}
			// ��O->�J�����g�̎� �Ɍq���ς���
			list->array[ptr].next = list->array[cur].next;
			deleteNodeIndex(list, cur);
			list->current = ptr;
		}
	}
}
// �S�m�[�h���폜
void Clear(List* list)
{
	while (list->head != NullIndex) {
		RemoveFront(list);
	}
	list->current = NullIndex;
}
// ���ڃm�[�h�̃f�[�^��\��
void PrintCurrent(const List* list)
{
	Index cur = list->current;
	if (cur == NullIndex) {
		printf("���ڃm�[�h�͂���܂���");
	}
	else {
		PrintMember(&list->array[cur].data);
	}
}
// ���ڃm�[�h�̃f�[�^��\��(���s����)
void PrintLnCurrent(const List* list)
{
	PrintCurrent(list);
	putchar('\n');
}
// �S�m�[�h�̃f�[�^�����X�g���ɕ\��
void Print(const List* list)
{
	Index ptr = list->head;
	if (ptr == NullIndex) {
		puts("�m�[�h������܂���");
	}
	else {
		puts("�y�ꗗ�\�z");
		while (ptr != NullIndex) {
			PrintLnMember(&list->array[ptr].data);
			ptr = list->array[ptr].next;
		}
	}
}
// ���`���X�g�̌�n��
void Terminate(List* list)
{
	Clear(list);
	free(list->array);
	list->array = nullptr;
}
// �V�����m�[�h�̃C���f�b�N�X���擾����
static Index getNewNodeIndex(List* list)
{
	if (list->freeHead == NullIndex) {
		puts("Node�z�񂪑���܂���");
		exit(1);
	}
	else {
		Index idx = list->freeHead;
		list->freeHead = list->array[idx].freeNext;
		return idx;
	}
}
// �m�[�h���t���[���X�g�ɓo�^����(�m�[�h�̉��)
static void deleteNodeIndex(List* list, Index idx)
{
	if (list->freeHead == NullIndex) {
		list->freeHead = idx;
		list->array[idx].freeNext = NullIndex;
	}
	else {
		Index next = list->freeHead;
		list->freeHead = idx;
		list->array[idx].freeNext = next;
	}
}
// �m�[�h�̐ݒ�
static void setNode(Node* node, const Member* x, Index next)
{
	node->data = *x;
	node->next = next;
}