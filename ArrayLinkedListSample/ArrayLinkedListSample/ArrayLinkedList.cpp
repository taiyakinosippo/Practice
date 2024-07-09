//==========================================================
//	アレイリンクリスト
//==========================================================
#include "ArrayLinkedList.h"
#include <stdio.h>   // printf(),puts()
#include <stdlib.h>  // calloc(),free(),exit()

// 関数プロトタイプ
static Index getNewNodeIndex(List* list);
static void deleteNodeIndex(List* list, Index idx);
static void setNode(Node* node, const Member* x, Index next);

// 線形リストの初期化
void Initialize(List* list, int size)
{
	list->array = (Node*)calloc(size, sizeof(Node));
	if (list->array == nullptr) {
		puts("calloc()失敗");
		exit(1);
	}
	// array[0～size-1]をフリーリストに登録
	list->freeHead = 0;
	for (int i = 0; i < size - 1; i++) {
		list->array[i].freeNext = i + 1;
	}
	list->array[size - 1].freeNext = NullIndex;
	// データリストは、空に
	list->head = NullIndex;
	list->current = NullIndex;
}
// 検索
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
	// 見つからなかった!!
	return NullIndex;
}
// 先頭にノードを挿入
void InsertFront(List* list, const Member* x)
{
	Index next = list->head;
	Index newIdx = getNewNodeIndex(list);
	setNode(&list->array[newIdx], x, next);
	list->head = newIdx;
	list->current = newIdx;
}
// 末尾にノードを挿入
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
// 先頭ノードを削除
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
// 末尾ノードを削除
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
// 着目ノードを削除
void RemoveCurrent(List* list)
{
	if (list->current != NullIndex) {
		if (list->current == list->head) {
			RemoveFront(list);
		}
		else {
			// カレントの手前を探す
			Index cur = list->current;
			Index ptr = list->head;
			while (list->array[ptr].next != cur) {
				ptr = list->array[ptr].next;
			}
			// 手前->カレントの次 に繋ぎ変える
			list->array[ptr].next = list->array[cur].next;
			deleteNodeIndex(list, cur);
			list->current = ptr;
		}
	}
}
// 全ノードを削除
void Clear(List* list)
{
	while (list->head != NullIndex) {
		RemoveFront(list);
	}
	list->current = NullIndex;
}
// 着目ノードのデータを表示
void PrintCurrent(const List* list)
{
	Index cur = list->current;
	if (cur == NullIndex) {
		printf("着目ノードはありません");
	}
	else {
		PrintMember(&list->array[cur].data);
	}
}
// 着目ノードのデータを表示(改行あり)
void PrintLnCurrent(const List* list)
{
	PrintCurrent(list);
	putchar('\n');
}
// 全ノードのデータをリスト順に表示
void Print(const List* list)
{
	Index ptr = list->head;
	if (ptr == NullIndex) {
		puts("ノードがありません");
	}
	else {
		puts("【一覧表】");
		while (ptr != NullIndex) {
			PrintLnMember(&list->array[ptr].data);
			ptr = list->array[ptr].next;
		}
	}
}
// 線形リストの後始末
void Terminate(List* list)
{
	Clear(list);
	free(list->array);
	list->array = nullptr;
}
// 新しいノードのインデックスを取得する
static Index getNewNodeIndex(List* list)
{
	if (list->freeHead == NullIndex) {
		puts("Node配列が足りません");
		exit(1);
	}
	else {
		Index idx = list->freeHead;
		list->freeHead = list->array[idx].freeNext;
		return idx;
	}
}
// ノードをフリーリストに登録する(ノードの解放)
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
// ノードの設定
static void setNode(Node* node, const Member* x, Index next)
{
	node->data = *x;
	node->next = next;
}