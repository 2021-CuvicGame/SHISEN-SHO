#include <stdio.h>

int ipan(int a, int c, char array[6][6], int i)
{
	int gout = 0;
	int isave;

	while (c <= a)
	{
		if (array[c][i] == 0)
		{
			isave = i;
			gout = 1;
			break;
		}
		c++;
	}

	if (gout == 1)
		return isave;
	else
		return 100;
}

void main()
{
	int a, c;
	int i, j;
	int array[6][6];
	char position_array[6][6];
	int k;
	int panjeong = 0;
	int last;
	int bb, bbb;
	int dd, ddd;
	int del = 0;

	//문자가 없는 칸은 array[x][y]값이 0
	//position_array[][]에는 문자 저장

	//어느 두 위치의 문자가 선택됨([a][b]와 [c][d]에서)
	//a와 c/b와 d의 대소 비교 결과, a>c b>d 가 되었다고 가정(a와 b에 더 큰쪽의 수를 넣는 코드 삽입 필요)

	for (i = 0; i < 6; i++)
	{
		panjeong = 0;
		del = 0;
		last = 0;

		for (k = c; k <= a; k++)
		{
			if (ipan(a, c, array[6][6], i) != 100)
				if (array[k][ipan(a, c, array[6][6], i)] == 0) //ipan(a,c,array[6][6],0) 의 결과물 isave
					panjeong++;
		}

		//i, a, c의 대소를 비교하여 i와 a 중 큰 쪽을 bb 작은 쪽을 bbb, i와 c 중 큰 쪽을 dd 작은 쪽을 ddd

		if (panjeong == a - c + 1)
		{
			for (j = bbb; j < bb; j++)
			{
				if (array[a][j] == 0)
					last++;
			}
			if (last == bb - bbb)
				del++;

			last = 0;

			for (j = ddd; j < dd; j++)
			{
				if (array[c][j] == 0)
					last++;
			}
			if (last == dd - ddd)
				del++;
		}

		if (del == 2)
			break; //선택한 두 문자를 지워야 함
	}
}