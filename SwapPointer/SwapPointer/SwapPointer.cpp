//=========================================================
//	�|�C���^�[�̌���
//=========================================================
#include <stdio.h> // printf()
// �֐��v���g�^�C�v
void swap_ptr(const char** x, const char** y);

int main()
{
	const char* s1 = "ABCD";
	const char* s2 = "EFGH";

	printf("�|�C���^s1��\"%s\"���w���Ă��܂�\n", s1);
	printf("�|�C���^s2��\"%s\"���w���Ă��܂�\n", s2);

	swap_ptr(&s1, &s2);
	puts("\n�|�C���^s1��s2�̒l���������܂���");

	printf("�|�C���^s1��\"%s\"���w���Ă��܂�\n", s1);
	printf("�|�C���^s2��\"%s\"���w���Ă��܂�\n", s2);
	return 0;
}

void swap_ptr(const char** x, const char** y)
{
	const char* tmp = *x;
	*x = *y;
	*y = tmp;
}