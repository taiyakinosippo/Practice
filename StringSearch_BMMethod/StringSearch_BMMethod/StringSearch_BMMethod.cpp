//=========================================================
//	������T��Boyer-Moore�@
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf(),scanf()
#include <string.h> // strlen()

// �֐��v���g�^�C�v
int bm_match(const char* txt, const char* pat);

const int NOT_FOUND = -1;

int main()
{
	const int STRING_SIZE = 256;
	char str1[STRING_SIZE];
	char str2[STRING_SIZE];

	while (true) {
		puts("Boyer-Moore�@");
		printf("�e�L�X�g:");
		scanf("%s", str1);

		printf("�p�^�[��:");
		scanf("%s", str2);

		int idx = kmp_match(str1, str2);
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

int bm_match(const char* txt, const char* pat)
{
	int txtLen = strlen(txt);
	int patLen = strlen(pat);
	int pt; // txt���Ȃ���J�[�\��
	int pp; // pat���Ȃ���J�[�\��
	int skip[UCHAR_MAX + 1]; // �X�L�b�v�e�[�u��

	// �X�L�b�v�\�̍쐬
	int skipSize = sizeof(skip) / sizeof(skip[0]);
	for (int i = 0; i < skipSize; i++) {
		skip[i] = patLen;
	}
	for (int i = 0; i < patLen - 1; i++) {
		unsigned char c = pat[i];
		skip[c] = patLen - i - 1;
	}
	// �T��
	pt = patLen - 1;
	while (pt < txtLen) {
		pp = patLen - 1;
		while (txt[pt] == pat[pp]) {
			if (pp == 0) {
				return pt;
			}
			pp--;
			pt--;
		}
		unsigned char c = txt[pt];
		pt += (skip[c] > patLen - pp) ? skip[c] : patLen - pp;
	}
	return NOT_FOUND;
}