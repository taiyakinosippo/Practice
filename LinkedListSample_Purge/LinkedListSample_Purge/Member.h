#pragma once
//=========================================================
//	会員構造体
//==========================================================
#ifndef __MEMBER
#define __MEMBER

#define NAME_SIZE (32)

typedef struct {
	int no;               // 番号  
	char name[NAME_SIZE]; // 名前
} Member;

#define MEMBER_NO   (1<<0)  // 番号を表す整数値
#define MEMBER_NAME (1<<1)  // 名前を表す整数値

// 会員番号の比較関数
int MemberNoCmp(const Member* x, const Member* y);
// 会員名前の比較関数
int MemberNameCmp(const Member* x, const Member* y);
// 会員データの表示(改行なし)
void PrintMember(const Member* x);
// 会員データの表示(改行あり)
void PrintLnMember(const Member* x);
// 会員データの読み込み
Member ScanMember(const char* message, int sw);

#endif // __MEMBER