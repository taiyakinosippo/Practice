//==========================================================
//	九九表を表示する
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()

int main()
{
	// ここをコーディングしてください。
	for (int i = 0; i <= 9; i++)
	{
		if (i == 0)
		{
			printf("   |");
			continue;
		}
		printf("%3d", i);
	}
	printf("\n");

	for (int i = 0; i <= 9; i++)
	{
		if (i == 0)
		{
			printf("---+");
			continue;
		}
		printf("---");
	}
	printf("\n");
	
	for (int i = 1; i <= 9; i++) 
	{
		for (int j = 1; j <= 9; j++)
		{
			if (j == 1) 
			{
				printf("%3d|", i);
			}
			printf("%3d", i * j);
		}
		printf("\n");
	}
	return 0;
}