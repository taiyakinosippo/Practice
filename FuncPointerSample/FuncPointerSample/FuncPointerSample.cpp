//==========================================================
//	�֐��|�C���^�T���v��
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
// �֐��v���g�^�C�v
void kuku(int func(int, int));
int add(int a, int b);
int mul(int a, int b);

int main()
{
    printf("���̉��Z�\\n");
    kuku(add);
    printf("\n");
    printf("���̏�Z�\\n");
    kuku(mul);

    return 0;
}

void kuku(int func(int, int))
{
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            printf("%3d", func(i, j));
        }
        printf("\n");
    }
}

int add(int a, int b)
{
    return a + b;
}
int mul(int a, int b) {
    return a * b;
}