//=========================================================
//	������T���@strstr�֐�
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf(),scanf()
#include <string.h> // strstr()

int main()
{
	const int STRING_SIZE = 256;
	char str1[STRING_SIZE];
	char str2[STRING_SIZE];

	while (true) {
		puts("strstr�֐�");
		printf("�e�L�X�g:");
		scanf("%s", str1);

		printf("�p�^�[��:");
		scanf("%s", str2);

		const char* p = strstr(str1, str2);
		if (p == nullptr) {
			puts("�e�L�X�g���Ƀp�^�[���͑��݂��܂���");
		}
		else {
			int idx = p - str1;
			printf("%d�����ڂɃ}�b�`���܂���\n", idx + 1);
			printf("%s\n", str1);
			printf("%*s|\n", idx, "");
			printf("%*s%s\n", idx, "", str2);
		}
		putchar('\n');
	}
	return 0;
}