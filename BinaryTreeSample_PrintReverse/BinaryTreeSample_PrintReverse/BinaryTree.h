//=========================================================
//	２分探索木
//=========================================================
#ifndef __BinaryTree
#define __BinaryTree

#include "Member.h"

// ノード
typedef struct __node {
	Member         data;  // データ
	struct __node* left;  // 左ポインター(左子ノードへのポインター)
	struct __node* right; // 右ポインター(右子ノードへのポインター)
} BinNode;

// 探索
BinNode* Search(BinNode* p, const Member* x);
// ノードの挿入
BinNode* Add(BinNode* p, const Member* x);
// ノードの削除
bool Remove(BinNode** root, const Member* x);
// 全ノードの表示
void PrintTree(const BinNode* p);
// 全ノードの削除
void FreeTree(BinNode* p);
// 全ノードの表示(降順)
void PrintTreeReverse(const BinNode* p);
#endif // __BinaryTree