//=========================================================
//	Intキュー
//==========================================================
#ifndef __IntQueue
#define __IntQueue

typedef struct {
	int max;  // キューの容量
	int num;  // 現在のデータ数
	int front; // 先頭要素のカーソル
	int rear;  // 末尾要素のカーソル
	int* que;  // キュー本体
} IntQueue;

typedef enum {
	SUCCESS = 0,
	INITIALIZE_FAIL = 1,
	ENQUE_NO_SPACE = 2,
	DEQUE_NO_DATA = 3,
	PEEK_NO_DATA = 4,
} IntQueueResult;

#define SEARCH_NOT_FOUND (-1)

// キューの初期化
IntQueueResult Initialize(IntQueue* q, int max);
// キューにデータをエンキューする
IntQueueResult Enque(IntQueue* q, int x);
// キューからデータをデキューする
IntQueueResult Deque(IntQueue* q, int* x);
// キューからデータをピークする
IntQueueResult Peek(const IntQueue* q, int* x);
// 全データを削除
void Clear(IntQueue* q);
// キューの容量
int Capacity(const IntQueue* q);
// キュー上のデータ数
int Size(const IntQueue* q);
// キューは空か?
bool IsEmpty(const IntQueue* q);
// キューは満杯か?
bool IsFull(const IntQueue* q);
// キューからデータを探索する
int Search(const IntQueue* q, int x);
// 全データの表示
void Print(const IntQueue* q);
// キューの後始末
void Terminate(IntQueue* q);

#endif // __IntQueue