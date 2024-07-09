#pragma once
//=========================================================
//	アレイリンクリスト
//=========================================================
#ifndef __ArrayLinkedList
#define __ArrayLinkedList

#include "Member.h"

typedef int Index;   // カーソル型

const Index NullIndex = -1;  // 空カーソル

// ノード
typedef struct __node {
	Member   data;     // データ
	Index    next;     // 後続カーソル
	Index    freeNext; // フリーリストの後続カーソル
} Node;

// 線形リスト
typedef struct {
	Node* array;    // リスト本体(配列)
	Index head;     // 先頭カーソル
	Index freeHead; // フリーリストの先頭カーソル
	Index current;  // 着目カーソル
} List;

// 線形リストの初期化
void Initialize(List* list, int size);
// 検索
Index Search(List* list, const Member* x, int compare(const Member* a, const Member* b));
// 先頭にノードを挿入
void InsertFront(List* list, const Member* x);
// 末尾にノードを挿入
void InsertRear(List* list, const Member* x);
// 先頭ノードを削除
void RemoveFront(List* list);
// 末尾ノードを削除
void RemoveRear(List* list);
// 着目ノードを削除
void RemoveCurrent(List* list);
// 全ノードを削除
void Clear(List* list);
// 着目ノードのデータを表示
void PrintCurrent(const List* list);
// 着目ノードのデータを表示(改行あり)
void PrintLnCurrent(const List* list);
// 全ノードのデータをリスト順に表示
void Print(const List* list);
// 線形リストの後始末
void Terminate(List* list);

#endif // __ArrayLinkedList