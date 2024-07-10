//=========================================================
//	����\����
//==========================================================
#ifndef __MEMBER
#define __MEMBER

#define NAME_SIZE (32)

typedef struct {
	int no;               // �ԍ�  
	char name[NAME_SIZE]; // ���O
} Member;

#define MEMBER_NO   (1<<0)  // �ԍ���\�������l
#define MEMBER_NAME (1<<1)  // ���O��\�������l

// ����ԍ��̔�r�֐�
int MemberNoCmp(const Member* x, const Member* y);
// ������O�̔�r�֐�
int MemberNameCmp(const Member* x, const Member* y);
// ����f�[�^�̕\��(���s�Ȃ�)
void PrintMember(const Member* x);
// ����f�[�^�̕\��(���s����)
void PrintLnMember(const Member* x);
// ����f�[�^�̓ǂݍ���
Member ScanMember(const char* message, int sw);

#endif // __MEMBER