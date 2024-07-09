//=========================================================
//	循環・重連結リスト
// --------------------------------------------------------
//  list.head 
//        ↓     (先頭)                       (末尾)
//     ダミー → データ1 → データ2 →.... → データN 
//        ↑                                    ｜
//        ＋−−−−−−−−−−−−−−−−−−＋
//=========================================================
#include "CircleDoubleLinkedList.h"
#include <stdio.h>  // printf()
#include <stdlib.h> // exit()

// 関数プロトタイプ
static DblNode* allocDblNode();
static void setDblNode(DblNode* node, const Member* x, const DblNode* prev, const DblNode* next);
static bool isEmpty(const DblList* list);

// 初期化
void Initialize(DblList* list)
{
	// ダミーノードをトップ、着目にする
	DblNode* dummy = allocDblNode();
	dummy->prev = dummy;
	dummy->next = dummy;
	list->head = dummy;
	list->current = dummy;
}
// 着目ノードのデータを表示
void PrintCurrent(const DblList* list)
{
	if (isEmpty(list)) {
		printf("着目ノードはありません");
	}
	else {
		PrintMember(&list->current->data);
	}
}
// 着目ノードのデータを表示(改行つき)
void PrintLnCurrent(const DblList* list)
{
	PrintCurrent(list);
	putchar('\n');
}
DblNode* Search(DblList* list, const Member* x, int compare(const Member* a, const Member* b))
{
	DblNode* ptr = list->head->next;
	while (ptr != list->head) {
		if (compare(&ptr->data, x) == 0) {
			list->current = ptr;
			return ptr;
		}
		ptr = ptr->next;
	}
	return nullptr;
}
// 全ノードの表示
void Print(const DblList* list)
{
	if (isEmpty(list)) {
		puts("ノードがありません");
	}
	else {
		DblNode* head = list->head;
		DblNode* ptr = head->next;
		puts("【一覧表】");
		while (ptr != head) {
			PrintLnMember(&ptr->data);
			ptr = ptr->next;
		}
	}
}
// 全ノードの表示(逆順)
// 全ノードのデータをリストの逆順に表示 
void PrintReverse(const DblList* list)
{
	if (isEmpty(list)) {
		puts("ノードがありません");
	}
	else {
		DblNode* head = list->head;
		DblNode* ptr = head->prev;
		puts("【一覧表】");
		while (ptr != head) {
			PrintLnMember(&ptr->data);
			ptr = ptr->prev;
		}
	}
}
// 注目ノードを1つ後方に進める(成功フラグを返す)
bool Next(DblList* list)
{
	DblNode* cur = list->current;
	if (isEmpty(list) || cur->next == list->head) {
		// 進めることはできない
		return false;
	}
	list->current = cur->next;
	return true;
}
// 注目ノードを1つ前方に戻す(成功フラグを返す)
bool Prev(DblList* list)
{
	DblNode* cur = list->current;
	if (isEmpty(list) || cur->prev == list->head) {
		// 戻すことはできない
		return false;
	}
	list->current = cur->prev;
	return true;
}
// pが指すノードの直後にノードを挿入
void InsertAfter(DblList* list, DblNode* p, const Member* x)
{
	DblNode* newNode = allocDblNode();
	DblNode* next = p->next;
	setDblNode(newNode, x, p, p->next);
	p->next = newNode;
	next->prev = newNode;
	list->current = newNode;
}
// 先頭にノードを挿入
void InsertFront(DblList* list, const Member* x)
{
	InsertAfter(list, list->head, x);
}
// 末尾にノードを挿入
void InsertRear(DblList* list, const Member* x)
{
	InsertAfter(list, list->head->prev, x);
}
// pが指すノードを削除
void Remove(DblList* list, DblNode* p)
{
	DblNode* prev = p->prev;
	DblNode* next = p->next;
	prev->next = next;
	next->prev = prev;
	free(p);
	// 注目は、削除ノードの手前
	list->current = prev;
	if (list->current == list->head) {
		list->current = list->head->next;
	}
}
// 先頭ノードを削除
void RemoveFront(DblList* list)
{
	if (isEmpty(list) == false) {
		Remove(list, list->head->next);
	}
}
// 末尾ノードを削除
void RemoveRear(DblList* list)
{
	if (isEmpty(list) == false) {
		Remove(list, list->head->prev);
	}
}
void RemoveCurrent(DblList* list)
{
	DblNode* cur = list->current;
	if (cur != list->head) {
		Remove(list, cur);
	}
}
// 全ノードを削除
void Clear(DblList* list)
{
	while (isEmpty(list) == false) {
		RemoveFront(list);
	}
}
// 循環・重連結リストの後始末
void Terminate(DblList* list)
{
	Clear(list);
	free(list->head);
	list->head = nullptr;
}
// ノード生成
static DblNode* allocDblNode()
{
	DblNode* node = (DblNode*)calloc(1, sizeof(DblNode));
	if (node == nullptr) {
		puts("calloc失敗");
		exit(1);
	}
	return node;
}
// ノードのメンバー設定
static void setDblNode(DblNode* node, const Member* x, const DblNode* prev, const DblNode* next)
{
	node->data = *x;
	node->prev = (DblNode*)prev;
	node->next = (DblNode*)next;
}
// リストは空か?
static bool isEmpty(const DblList* list)
{
	DblNode* head = list->head;
	return head->next == head;
}