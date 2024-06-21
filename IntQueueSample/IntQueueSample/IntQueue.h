//=========================================================
//	Int�L���[
//==========================================================
#ifndef __IntQueue
#define __IntQueue

typedef struct {
	int max;  // �L���[�̗e��
	int num;  // ���݂̃f�[�^��
	int front; // �擪�v�f�̃J�[�\��
	int rear;  // �����v�f�̃J�[�\��
	int* que;  // �L���[�{��
} IntQueue;

typedef enum {
	SUCCESS = 0,
	INITIALIZE_FAIL = 1,
	ENQUE_NO_SPACE = 2,
	DEQUE_NO_DATA = 3,
	PEEK_NO_DATA = 4,
} IntQueueResult;

#define SEARCH_NOT_FOUND (-1)

// �L���[�̏�����
IntQueueResult Initialize(IntQueue* q, int max);
// �L���[�Ƀf�[�^���G���L���[����
IntQueueResult Enque(IntQueue* q, int x);
// �L���[����f�[�^���f�L���[����
IntQueueResult Deque(IntQueue* q, int* x);
// �L���[����f�[�^���s�[�N����
IntQueueResult Peek(const IntQueue* q, int* x);
// �S�f�[�^���폜
void Clear(IntQueue* q);
// �L���[�̗e��
int Capacity(const IntQueue* q);
// �L���[��̃f�[�^��
int Size(const IntQueue* q);
// �L���[�͋�?
bool IsEmpty(const IntQueue* q);
// �L���[�͖��t��?
bool IsFull(const IntQueue* q);
// �L���[����f�[�^��T������
int Search(const IntQueue* q, int x);
// �S�f�[�^�̕\��
void Print(const IntQueue* q);
// �L���[�̌�n��
void Terminate(IntQueue* q);

#endif // __IntQueue