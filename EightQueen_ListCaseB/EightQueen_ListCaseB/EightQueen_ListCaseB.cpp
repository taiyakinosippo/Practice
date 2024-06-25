//=========================================================
//	8王妃問題　リストケースB
//==========================================================
#include <stdio.h> // printf(),scanf()

// 関数プロトタイプ
void set(int column);
void print();

const int FIELD_SIZE = 8;
// 各列の王妃の位置
int pos[FIELD_SIZE];

int main()
{
	set(0);
	return 0;
}

void set(int column)
{
	for (int line = 0; line < FIELD_SIZE; line++) {
		pos[column] = line;
		if (column == FIELD_SIZE - 1) {
			print();
		}
		else {
			set(column + 1);
		}
	}
}

void print()
{
	for (int column = 0; column < FIELD_SIZE; column++) {
		printf("%2d", pos[column]);
	}
	putchar('\n');
}