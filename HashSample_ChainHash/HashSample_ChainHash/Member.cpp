//==========================================================
//	会員構造体
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include "Member.h"
#include <stdio.h>   // printf(), scanf()
#include <string.h>  // strcmp() 

int MemberNoCmp(const Member* x, const Member* y)
{
	return x->no - y->no;
}

int MemberNameCmp(const Member* x, const Member* y)
{
	return strcmp(x->name, y->name);
}
void PrintMember(const Member* x)
{
	printf("%d %s", x->no, x->name);
}
void PrintLnMember(const Member* x)
{
	printf("%d %s\n", x->no, x->name);
}
Member ScanMember(const char* message, int sw)
{
	Member temp = { 0 };
	printf("%sするデータを入力してください\n", message);
	if ((sw & MEMBER_NO) != 0) {
		printf("番号:");
		scanf("%d", &temp.no);
	}
	if ((sw & MEMBER_NAME) != 0) {
		printf("名前:");
		scanf("%s", &temp.name);
	}
	return temp;
}