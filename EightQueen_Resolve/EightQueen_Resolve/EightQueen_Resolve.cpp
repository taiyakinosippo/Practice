//=========================================================
//	8王妃問題　解法
//==========================================================
#include <stdio.h> // printf(),scanf()

// 関数プロトタイプ
void set(int column);
void print();

const int FIELD_SIZE = 8;
const int DIAGONAL_SIZE = FIELD_SIZE * 2 - 1; // 斜線のサイズ
//  上斜線 column+line         下斜線  (7-column)+line
//  +--+--+--+--+--+--+--+--+　+--+--+--+--+--+--+--+--+
//  |0 |1 |2 |3 |4 |5 |6 |7 |  |7 |6 |5 |4 |3 |2 |1 |0 |
//  +--+--+--+--+--+--+--+--+  +--+--+--+--+--+--+--+--+
//  |1 |2 |3 |4 |5 |6 |7 |8 |  |8 |7 |6 |5 |4 |3 |2 |1 |
//  +--+--+--+--+--+--+--+--+  +--+--+--+--+--+--+--+--+
//  |2 |3 |4 |5 |6 |7 |8 |9 |  |9 |8 |7 |6 |5 |4 |3 |2 |
//  +--+--+--+--+--+--+--+--+  +--+--+--+--+--+--+--+--+
//  |3 |4 |5 |6 |7 |8 |9 |10|  |10|9 |8 |7 |6 |5 |4 |3 |
//  +--+--+--+--+--+--+--+--+  +--+--+--+--+--+--+--+--+
//  |4 |5 |6 |7 |8 |9 |10|11|  |11|10|9 |8 |7 |6 |5 |4 |
//  +--+--+--+--+--+--+--+--+  +--+--+--+--+--+--+--+--+
//  |5 |6 |7 |8 |9 |10|11|12|  |12|11|10|9 |8 |7 |6 |5 |
//  +--+--+--+--+--+--+--+--+  +--+--+--+--+--+--+--+--+
//  |6 |7 |8 |9 |10|11|12|13|  |13|12|11|10|9 |8 |7 |6 |
//  +--+--+--+--+--+--+--+--+  +--+--+--+--+--+--+--+--+
//  |7 |8 |9 |10|11|12|13|14|  |14|13|12|11|10|9 |8 |7 |
//  +--+--+--+--+--+--+--+--+  +--+--+--+--+--+--+--+--+
// 
// 各列の王妃の位置
int pos[FIELD_SIZE];
// 各行に王妃が配置済か?
bool flag[FIELD_SIZE];
// 各上斜めに王妃が配置済か?
bool flag2[DIAGONAL_SIZE];
// 各下斜めに王妃が配置済か?
bool flag3[DIAGONAL_SIZE];

int main()
{
	for (int line = 0; line < FIELD_SIZE; line++) {
		flag[line] = false;
	}
	for (int i = 0; i < DIAGONAL_SIZE; i++) {
		flag2[i] = flag3[i] = false;
	}

	set(0);
	return 0;
}

void set(int column)
{
	for (int line = 0; line < FIELD_SIZE; line++) {
		if (!flag[line] && !flag2[column + line] && !flag3[(FIELD_SIZE - 1) - column + line]) {
			pos[column] = line;
			if (column == FIELD_SIZE - 1) {
				print();
			}
			else {
				flag[line] = true;
				flag2[column + line] = true;
				flag3[(FIELD_SIZE - 1) - column + line] = true;
				set(column + 1);
				flag[line] = false;
				flag2[column + line] = false;
				flag3[(FIELD_SIZE - 1) - column + line] = false;
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