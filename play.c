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

void play_set()
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

	//���ڰ� ���� ĭ�� array[x][y]���� 0
	//position_array[][]���� ���� ����

	//��� �� ��ġ�� ���ڰ� ���õ�([a][b]�� [c][d]����)
	//a�� c/b�� d�� ��� �� ���, a>c b>d �� �Ǿ��ٰ� ����(a�� b�� �� ū���� ���� �ִ� �ڵ� ���� �ʿ�)

	for (i = 0; i < 6; i++)
	{
		panjeong = 0;
		del = 0;
		last = 0;

		for (k = c; k <= a; k++)
		{
			if (ipan(a, c, array[6][6], i) != 100)
				if (array[k][ipan(a, c, array[6][6], i)] == 0) //ipan(a,c,array[6][6],0) �� ����� isave
					panjeong++;
		}

		//i, a, c�� ��Ҹ� ���Ͽ� i�� a �� ū ���� bb ���� ���� bbb, i�� c �� ū ���� dd ���� ���� ddd

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
			break; //������ �� ���ڸ� ������ ��
	}
}