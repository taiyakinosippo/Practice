//=========================================================
//	ポインターの交換
//=========================================================
#include <stdio.h> // printf()
// 関数プロトタイプ
void swap_ptr(const char** x, const char** y);

int main()
{
	const char* s1 = "ABCD";
	const char* s2 = "EFGH";

	printf("ポインタs1は\"%s\"を指しています\n", s1);
	printf("ポインタs2は\"%s\"を指しています\n", s2);

	swap_ptr(&s1, &s2);
	puts("\nポインタs1とs2の値を交換しました");

	printf("ポインタs1は\"%s\"を指しています\n", s1);
	printf("ポインタs2は\"%s\"を指しています\n", s2);
	return 0;
}

void swap_ptr(const char** x, const char** y)
{
	const char* tmp = *x;
	*x = *y;
	*y = tmp;
}