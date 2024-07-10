//==========================================================
//	２分探索木サンプル
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include "member.h"
#include "BinaryTree.h"
#include <stdio.h> // printf(),scanf()

typedef enum {
	TERMINATE,
	ADD,
	REMOVE,
	SEARCH,
	PRINT,
	PRINT_TREE,
	DUMP,
} Menu;

// 関数プロトタイプ
Menu SelectMenu();
void setup(BinNode** root);

int main()
{
	Menu menu;
	BinNode* root = nullptr;

	setup(&root);
	do {
		Member x;
		BinNode* temp;
		menu = SelectMenu();
		switch (menu) {
		case ADD:
			x = ScanMember("挿入", MEMBER_NO + MEMBER_NAME);
			root = Add(root, &x);
			break;
		case REMOVE:
			x = ScanMember("削除", MEMBER_NO);
			Remove(&root, &x);
			break;
		case SEARCH:
			x = ScanMember("探索", MEMBER_NO);
			temp = Search(root, &x);
			if (temp != nullptr) {
				PrintLnMember(&temp->data);
			}
			break;
		case PRINT:
			puts("【一覧表】");
			PrintTree(root);
			break;
		case PRINT_TREE:
			PrintTreeState(root);
			break;
		case DUMP:
			DumpTree(root);
			break;
		}
	} while (menu != TERMINATE);

	FreeTree(root);
	return 0;
}

Menu SelectMenu()
{
	int ch;
	do {
		printf("\n(1)挿入 (2)削除 (3)探索 (4)表示 (5) ツリー表示 (6)ダンプ (0)終了:");
		scanf("%d", &ch);
	} while (ch < TERMINATE || DUMP < ch);
	return (Menu)ch;
}
void setup(BinNode** root)
{
	Member data[] = {
		{1,"赤尾"},
		{10,"小野"},
		{5,"武田"},
		{12,"鈴木"},
		{14,"神崎"},
	};
	int dataSize = sizeof(data) / sizeof(data[0]);
	for (int i = 0; i < dataSize; i++) {
		*root = Add(*root, &data[i]);
	}
}