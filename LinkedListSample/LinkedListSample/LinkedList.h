//=========================================================
//	リンクリスト
//=========================================================
#ifndef __LinkedList
#define __LinkedList

#include "Member.h"

// ノード
typedef struct __node {
	Member         data;  // データ
	struct __node* next;  // 後続ポインター(後続ノードへのポインター)
} Node;

// 線形リスト
typedef struct {
	Node* head;    // 先頭ポインター(先頭ノードへのポインター)
	Node* current; // 着目ポインター(着目ノードへのポインター)
} List;

// 線形リストの初期化
void Initialize(List* list);
// 検索
Node* Search(List* list, const Member* x, int compare(const Member* a, const Member* b));
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

#endif // __LinkedList