//=========================================================
//	������T���@�͂܂����@
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf(),scanf()

// �֐��v���g�^�C�v
int bf_match(const char* string, const char* pattern);

const int NOT_FOUND = -1;

int main()
{
	const int STRING_SIZE = 256;
	char str1[STRING_SIZE];
	char str2[STRING_SIZE];

	while (true) {
		puts("�͂܂����@");
		printf("�e�L�X�g:");
		scanf("%s", str1);

		printf("�p�^�[��:");
		scanf("%s", str2);

		int idx = bf_match(str1, str2);
		if (idx == NOT_FOUND) {
			puts("�e�L�X�g���Ƀp�^�[���͑��݂��܂���");
		}
		else {
			printf("%d�����ڂɃ}�b�`���܂���\n", idx + 1);
		}
		putchar('\n');
	}
	return 0;
}

int bf_match(const char* txt, const char* pat)
{
	int cmpStart = 0;
	int pt = cmpStart;
	int pp = 0;
	int pStart = pt;
	while (txt[pt] != '\0' && pat[pp] != '\0') {
		if (txt[pt] == pat[pp]) {
			pt++;
			pp++;
		}
		else {
			cmpStart++;
			pt = cmpStart;
			pp = 0;
		}
	}
	if (pat[pp] == '\0') {
		return cmpStart;
	}
	return NOT_FOUND;
}