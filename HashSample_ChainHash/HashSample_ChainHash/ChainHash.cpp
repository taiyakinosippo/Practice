//==========================================================
//	チェインハッシュ
//==========================================================
#include "ChainHash.h"
#include <stdio.h>   // printf(),putchar()
#include <stdlib.h>  // calloc(),free()

// 関数プロトタイプ
static int hash(const ChainHash* h, const Member* x);
static void setNode(Node* n, const Member* x, Node* next);

ChainHashResult Initialize(ChainHash* h, int size)
{
	h->table = (Node**)calloc(size, sizeof(Node*));
	if (h->table == nullptr) {
		h->size = 0;
		return INITIALIZE_FAIL;
	}
	h->size = size;
	for (int i = 0; i < size; i++) {
		h->table[i] = nullptr;
	}
	return SUCCESS;
}

Node* Search(const ChainHash* h, const Member* x)
{
	int key = hash(h, x);
	Node* p = h->table[key];
	while (p != nullptr) {
		if (p->data.no == x->no) {
			return p;
		}
		p = p->next;
	}
	return nullptr;
}
ChainHashResult Add(ChainHash* h, const Member* x)
{
	int key = hash(h, x);
	Node* p = h->table[key];
	// 既に登録済?
	while (p != nullptr) {
		if (p->data.no == x->no) {
			return ADD_ALREADY_EXIST;
		}
		p = p->next;
	}
	Node* temp = (Node*)calloc(1, sizeof(Node));
	if (temp == nullptr) {
		return ADD_CALLOC_FAIL;
	}
	setNode(temp, x, h->table[key]);
	h->table[key] = temp;
	return SUCCESS;
}

ChainHashResult Remove(ChainHash* h, const Member* x)
{
	int key = hash(h, x);
	Node* p = h->table[key];
	Node** pp = &h->table[key];
	while (p != nullptr) {
		if (p->data.no == x->no) {
			*pp = p->next;
			free(p);
			return SUCCESS;
		}
		pp = &p->next;
		p = p->next;
	}
	return REMOVE_NOT_FOUND;
}

void Dump(const ChainHash* h)
{
	for (int i = 0; i < h->size; i++) {
		Node* p = h->table[i];
		printf("%02d ", i);
		while (p != nullptr) {
			printf("->%d(%s) ", p->data.no, p->data.name);
			p = p->next;
		}
		putchar('\n');
	}
}

void Clear(ChainHash* h)
{
	for (int i = 0; i < h->size; i++) {
		Node* p = h->table[i];
		while (p != nullptr) {
			Node* next = p->next;
			free(p);   // free(p)したあとに p=p->next;はNG
			p = next;
		}
		h->table[i] = nullptr;
	}
}
void Terminate(ChainHash* h)
{
	Clear(h);
	free(h->table);
	h->size = 0;
}
static int hash(const ChainHash* h, const Member* x)
{
	return x->no % h->size;
}
static void setNode(Node* n, const Member* x, Node* next)
{
	n->data = *x;
	n->next = next;
}
