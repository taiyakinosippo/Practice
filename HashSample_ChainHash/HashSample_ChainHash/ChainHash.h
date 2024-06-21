#pragma once
//=========================================================
//	チェインハッシュ
//==========================================================
#ifndef __CHAIN_HASH
#define __CHAIN_HASH
#include "Member.h"

// バケットを表すノード
typedef struct __node {
	Member         data;   // データ
	struct __node* next;   // 後続データへのポインタ
} Node;

// ハッシュ表
typedef struct {
	int size;
	Node** table;
} ChainHash;

// 各関数の成功/失敗リザルト
typedef enum {
	SUCCESS = 0,
	INITIALIZE_FAIL = 1,
	ADD_ALREADY_EXIST = 2,
	ADD_CALLOC_FAIL = 3,
	REMOVE_NOT_FOUND = 4,
} ChainHashResult;

// ハッシュ表を初期化
ChainHashResult Initialize(ChainHash* h, int size);

// 探索
Node* Search(const ChainHash* h, const Member* x);

// データの追加
ChainHashResult Add(ChainHash* h, const Member* x);

// データの削除
ChainHashResult Remove(ChainHash* h, const Member* x);

// 全データの削除
void Clear(ChainHash* h);

// ハッシュ表の後します
void Terminate(ChainHash* h);

// ハッシュ表をダンプ
void Dump(const ChainHash* h);

#endif // __CHAIN_HASH