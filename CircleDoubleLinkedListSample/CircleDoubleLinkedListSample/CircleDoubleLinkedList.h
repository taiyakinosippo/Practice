#pragma once
//=========================================================
//	循環・重連結リスト
// --------------------------------------------------------
//  list.head 
//        ↓     (先頭)                       (末尾)
//     ダミー → データ1 → データ2 →.... → データN 
//        ↑                                    ｜
//        ＋−−−−−−−−−−−−−−−−−−＋
//=========================================================
#ifndef __CircleDoubleLinkedList
#define __CircleDoubleLinkedList

#include "Member.h"

/*--- ノード ---*/
typedef struct __node {
	Member        data;    // データ
	struct __node* prev;   // 先行ポインタ（先行ノードへのポインタ）
	struct __node* next;   // 後続ポインタ（後続ノードへのポインタ）
} DblNode;

/*--- 循環・重連結リスト ---*/
typedef struct {
	DblNode* head;      // 先頭ポインタ（ダミーノードへのポインタ）
	DblNode* current;   // 着目ポインタ（着目ノードへのポインタ）
} DblList;

// リストを初期化 
void Initialize(DblList* list);
// 着目ノードのデータを表示 
void PrintCurrent(const DblList* list);
// 着目ノードのデータを表示（改行付き）
void PrintLnCurrent(const DblList* list);
// 関数compareによってxと一致すると判定されるノードを探索 
DblNode* Search(DblList* list, const Member* x, int compare(const Member* x, const Member* y));
// 全ノードのデータをリスト順に表示
void Print(const DblList* list);
// 全ノードのデータをリストの逆順に表示 
void PrintReverse(const DblList* list);
// 着目ノードを一つ後方に進める 
bool Next(DblList* list);
// 着目ノードを一つ前方に戻す 
bool Prev(DblList* list);
// pが指すノードの直後にノードを挿入 
void InsertAfter(DblList* list, DblNode* p, const Member* x);
// 先頭にノードを挿入 
void InsertFront(DblList* list, const Member* x);
// 末尾にノードを挿入 
void InsertRear(DblList* list, const Member* x);
// pが指すノードを削除 
void Remove(DblList* list, DblNode* p);
// 先頭ノードを削除 
void RemoveFront(DblList* list);
// 末尾ノードを削除 
void RemoveRear(DblList* list);
// 着目ノードを削除 
void RemoveCurrent(DblList* list);
// 全ノードを削除
void Clear(DblList* list);
// 循環・重連結リストの後始末
void Terminate(DblList* list);

#endif // __CircleDoubleLinkedList
