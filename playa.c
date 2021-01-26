#include <stdio.h>

int ipan2(int b, int d, int array[6][6], int i)
{
	int gout = 0;
	int isave;

	while (d <= b)
	{
		if (array[i][d] == 0)
		{
			isave = i;
			gout = 1;
			break;
		}
		d++;
	}

	if (gout == 1)
		return isave;
	else
		return 100;
}

void playa_set()
{
	int b, d;
	int i, j;
	int array[6][6];
	char position_array[6][6];
	int k;
	int panjeong = 0;
	int last;
	int aa, aaa;
	int cc, ccc;
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

		for (k = d; k <= b; k++)
		{
			if (ipan2(b, d, array[6][6], i) != 100)
				if (array[ipan2(b, d, array[6][6], i)][k] == 0) //ipan2(b,d,array[6][6],0) 의 결과물 isave
					panjeong++;
		}

		//i, b, d의 대소를 비교하여 i와 b 중 큰 쪽을 bb 작은 쪽을 bbb, i와 d 중 큰 쪽을 dd 작은 쪽을 ddd

		if (panjeong == b - d + 1)
		{
			for (j = aaa; j < aa; j++)
			{
				if (array[j][b] == 0)
					last++;
			}
			if (last == aa - aaa)
				del++;

			last = 0;

			for (j = ccc; j < cc; j++)
			{
				if (array[j][d] == 0)
					last++;
			}
			if (last == cc - ccc)
				del++;
		}

		if (del == 2)
			break; //루프문 탈출 후 선택한 두 문자를 지워야 함
	}
}