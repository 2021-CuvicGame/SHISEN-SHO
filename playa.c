#include <stdio.h>

int ipan2(int b, int d, char array[6][6], int i)
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

	//���ڰ� ���� ĭ�� array[x][y]���� 0
	//position_array[][]���� ���� ����

	//��� �� ��ġ�� ���ڰ� ���õ�([a][b]�� [c][d]����)
	//a�� c/b�� d�� ��� �� ���, a>c b>d �� �Ǿ��ٰ� ����(a�� b�� �� ū���� ���� �ִ� �ڵ� ���� �ʿ�)

	for (i = 0; i < 6; i++)
	{
		panjeong = 0;
		del = 0;
		last = 0;

		for (k = d; k <= b; k++)
		{
			if (ipan2(b, d, array[6][6], i) != 100)
				if (array[ipan2(b, d, array[6][6], i)][k] == 0) //ipan(b,d,array[6][6],0) �� ����� isave
					panjeong++;
		}

		//i, b, d�� ��Ҹ� ���Ͽ� i�� b �� ū ���� bb ���� ���� bbb, i�� d �� ū ���� dd ���� ���� ddd

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
			break; //������ �� ���ڸ� ������ ��
	}
}