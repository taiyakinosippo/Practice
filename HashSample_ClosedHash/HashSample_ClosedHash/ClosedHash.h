#pragma once
//=========================================================
//	クローズドハッシュ
//==========================================================
#ifndef __CLOSED_HASH
#define __CLOSED_HASH

#include "Member.h"

// 要素の状態
typedef enum {
	Occupied, Empty, Deleted
} Status;

typedef struct {
	Member data;   // データ
	Status stat;   // 要素の状態
} Bucket;

typedef struct {
	int     size;        // ハッシュ表配列の大きさ
	Bucket* table;   // ハッシュ表配列へのポインター
} ClosedHash;

// 各関数の成功/失敗リザルト
typedef enum {
	SUCCESS = 0,
	INITIALIZE_FAIL = 1,   // 初期化失敗
	ADD_ALREADY_EXIST = 2, // ADD既に存在してる 
	ADD_NO_SPACE = 3,      // ADDハッシュテーブルが一杯
	REMOVE_NOT_FOUND = 4,
} ClosedHashResult;

// ハッシュ表を初期化
ClosedHashResult Initialize(ClosedHash* h, int size);
// 探索
Bucket* Search(const ClosedHash* h, const Member* x);
// データの追加
ClosedHashResult Add(ClosedHash* h, const Member* x);
// データの削除
ClosedHashResult Remove(ClosedHash* h, const Member* x);
// ハッシュ表をダンプ
void Dump(const ClosedHash* h);
// 全データの削除
void Clear(ClosedHash* h);
// ハッシュ表の後始末
void Terminate(ClosedHash* h);

#endif // __CLOSED_HASH
