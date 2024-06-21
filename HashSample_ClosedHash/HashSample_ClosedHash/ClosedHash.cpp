//==========================================================
//	クローズドハッシュ
//==========================================================
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ClosedHash.h"

// 関数プロトタイプ
static int hash(const ClosedHash* h, const Member* x);
static int rehash(const ClosedHash* h, int key);
static void setBucket(Bucket* n, const Member* x, Status stat);

ClosedHashResult Initialize(ClosedHash* h, int size)
{
	h->table = (Bucket*)calloc(size, sizeof(Bucket));
	if (h->table == nullptr) {
		h->size = 0;
		return INITIALIZE_FAIL;
	}
	h->size = size;
	for (int i = 0; i < size; i++) {
		h->table[i].stat = Empty;
	}
	return SUCCESS;
}

Bucket* Search(const ClosedHash* h, const Member* x)
{
	int key = hash(h, x);
	Bucket* p = &h->table[key];
	for (int i = 0; p->stat != Empty && i < h->size; i++) {
		if (p->stat == Occupied && p->data.no == x->no) {
			return p;
		}
		key = rehash(h, key);
		p = &h->table[key];
	}
	return nullptr;
}

ClosedHashResult Add(ClosedHash* h, const Member* x)
{
	int key = hash(h, x);
	Bucket* p = &h->table[key];

	if (Search(h, x) != nullptr) {
		return ADD_ALREADY_EXIST;
	}
	for (int i = 0; i < h->size; i++) {
		if (p->stat == Empty || p->stat == Deleted) {
			setBucket(p, x, Occupied);
			return SUCCESS;
		}
		key = rehash(h, key);
		p = &h->table[key];
	}
	return ADD_NO_SPACE;
}

ClosedHashResult Remove(ClosedHash* h, const Member* x)
{
	Bucket* p = Search(h, x);
	if (p == nullptr) {
		return REMOVE_NOT_FOUND;
	}
	p->stat = Deleted;
	return SUCCESS;
}

void Dump(const ClosedHash* h)
{
	for (int i = 0; i < h->size; i++) {
		printf("%02d:", i);
		Bucket* p = &h->table[i];
		switch (p->stat) {
		case Occupied:
			printf("%d(%s)\n", p->data.no, p->data.name);
			break;
		case Empty:
			printf("-- 未登録 -- \n");
			break;
		case Deleted:
			printf("-- 削除済 --\n");
			break;
		}
	}
}

void Clear(ClosedHash* h)
{
	for (int i = 0; i < h->size; i++) {
		h->table[i].stat = Empty;
	}
}

void Terminate(ClosedHash* h)
{
	Clear(h);
	free(h->table);
	h->size = 0;
	h->table = nullptr;
}

static int hash(const ClosedHash* h, const Member* x)
{
	return x->no % h->size;
}
static int rehash(const ClosedHash* h, int key)
{
	return (key + 1) % h->size;
}
static void setBucket(Bucket* n, const Member* x, Status stat)
{
	n->data = *x;
	n->stat = stat;
}