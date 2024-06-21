//=========================================================
//	IntÉLÉÖÅ[
//==========================================================
#include "IntQueue.h"
#include <stdio.h> // printf()
#include <stdlib.h> // calloc(),free()

IntQueueResult Initialize(IntQueue* q, int max)
{
	q->num = q->front = q->rear = 0;
	q->que = (int*)calloc(max, sizeof(int));
	if (q->que == nullptr) {
		q->max = 0;
		return INITIALIZE_FAIL;
	}
	q->max = max;
	return SUCCESS;
}

IntQueueResult Enque(IntQueue* q, int x)
{
	if (q->num >= q->max) {
		return ENQUE_NO_SPACE;
	}
	else {
		q->num++;
		q->que[q->rear++] = x;
		if (q->rear == q->max) {
			q->rear = 0;
		}
		return SUCCESS;
	}
}
IntQueueResult Deque(IntQueue* q, int* x)
{
	if (q->num <= 0) {
		return	DEQUE_NO_DATA;
	}
	else {
		q->num--;
		*x = q->que[q->front++];
		if (q->front == q->max) {
			q->front = 0;
		}
		return SUCCESS;
	}
}
IntQueueResult Peek(const IntQueue* q, int* x)
{
	if (q->num <= 0) {
		return	PEEK_NO_DATA;
	}
	else {
		*x = q->que[q->front];
		return SUCCESS;
	}
}
void Clear(IntQueue* q)
{
	q->num = q->front = q->rear = 0;
}
int Capacity(const IntQueue* q)
{
	return q->max;
}
int Size(const IntQueue* q)
{
	return q->num;
}
bool IsEmpty(const IntQueue* q)
{
	return q->num <= 0;
}
bool IsFull(const IntQueue* q)
{
	return q->num == q->max;
}
int Search(const IntQueue* q, int x)
{
	for (int i = 0; i < q->num; i++) {
		int idx = (q->front + i) % q->max;
		if (q->que[idx] == x) {
			return idx;
		}
	}
	return SEARCH_NOT_FOUND; // -1
}
void Print(const IntQueue* q)
{
	for (int i = 0; i < q->num; i++) {
		int idx = (q->front + i) % q->max;
		printf("%d ", q->que[idx]);
	}
	putchar('\n');
}
void Terminate(IntQueue* q)
{
	if (q->que != nullptr) {
		free(q->que);
		q->que = nullptr;
	}
	q->max = q->num = q->front = q->rear = 0;
}