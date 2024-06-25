//=========================================================
//	8王妃問題　リストケースC
//==========================================================
#include <stdio.h> // printf(),scanf()

// 関数プロトタイプ
void set(int column);
void print();

const int FIELD_SIZE = 8;
// 各列の王妃の位置
int pos[FIELD_SIZE];
// 各行に王妃が配置済か?
bool flag[FIELD_SIZE];

int main()
{
	for (int line = 0; line < FIELD_SIZE; line++) {
		flag[line] = false;
	}
	set(0);
	return 0;
}

void set(int column)
{
	for (int line = 0; line < FIELD_SIZE; line++) {
		if (flag[line] == false) {
			pos[column] = line;
			if (column == FIELD_SIZE - 1) {
				print();
			}
			else {
				flag[line] = true;
				set(column + 1);
				flag[line] = false;
			}
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