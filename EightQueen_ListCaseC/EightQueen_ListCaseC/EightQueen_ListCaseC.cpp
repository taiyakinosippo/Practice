//=========================================================
//	8���ܖ��@���X�g�P�[�XC
//==========================================================
#include <stdio.h> // printf(),scanf()

// �֐��v���g�^�C�v
void set(int column);
void print();

const int FIELD_SIZE = 8;
// �e��̉��܂̈ʒu
int pos[FIELD_SIZE];
// �e�s�ɉ��܂��z�u�ς�?
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