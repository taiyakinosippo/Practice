//==========================================================
//	構造体サンプル
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()

const double VISION_MAX = 2.1;       // 視力最大値
const double VISION_DIST_WID = 0.1;  // 分布刻み幅
const double VISION_DIST_CORRECT = 0.1; // 計算誤差の補正
const int VMAX = (int)(VISION_MAX / VISION_DIST_WID + VISION_DIST_CORRECT);

typedef struct {
	char   name[20]; // 名前
	int    height;   // 身長
	double vision;   // 視力
} PhysCheck;

// 関数プロトタイプ
double AverageHeight(const PhysCheck data[], int dataSize);
void DistributeVision(const PhysCheck data[], int dataSize, int dist[]);

int main()
{
	PhysCheck data[] = {
		{"AKASAKU Tadao", 162,0.3},
		{"KATO Tomiaki",173,0.7},
		{"SAITO Shouji",175,2.0},
		{"TAKEDA Shinya",171,1.5},
		{"NAGAHAMA Masaki",168,0.4},
		{"HAMADA Tetsuaki",174,1.2},
		{"MATSUTOMI Akio",169,0.8}
	};
	int dataSize = sizeof(data) / sizeof(data[0]);
	int vdist[VMAX];
	puts("■□■　身体検査一覧表 ■□■");
	puts(" 氏名             身長　視力");
	puts("-----------------------------");
	for (int i = 0; i < dataSize; i++) {
		printf("%-18.18s%4d%5.1f\n", data[i].name, data[i].height, data[i].vision);
	}
	double ave = AverageHeight(data, dataSize);
	printf("\n平均身長:%5.1f\n", ave);

	DistributeVision(data, dataSize, vdist);
	printf("\n視力の分布\n");
	for (int i = 0; i < VMAX; i++) {
		printf("%3.1f～:%2d人\n", i * VISION_DIST_WID, vdist[i]);
	}
	return 0;
}

double AverageHeight(const PhysCheck data[], int dataSize)
{
	int sum = 0;
	for (int i = 0; i < dataSize; i++) {
		sum += data[i].height;
	}
	return (double)sum / dataSize;
}
void DistributeVision(const PhysCheck data[], int dataSize, int dist[])
{
	for (int i = 0; i < VMAX; i++) {
		dist[i] = 0;
	}
	for (int i = 0; i < dataSize; i++) {
		int idx = (int)(data[i].vision / VISION_DIST_WID + VISION_DIST_CORRECT);
		// printf("%f %d |", data[i].vision / VISION_DIST_WID,(int)(data[i].vision / VISION_DIST_WID));
		// vision/VISION_DIST_WIDの計算で誤差が生じている
		if (idx < VMAX) {
			dist[idx]++;
		}
	}
}