#pragma once
#include<stdio.h>
int a = 0, b = 0, c = 0, d = 0;
int ipan(int a, int c, int array_zo[6][6], int i)
{
	int gout = 0;

	while (c <= a)
	{
		if (array_zo[c][i] == 0)
		{
			gout = 1;
			break;
		}
		c++;
	}

	if (gout == 1)
		return i;
	else
		return 100;
}

int play_set(int a, int b, int c, int d, int array_zo[6][6], char array[16])
{
	//	int a, c;
	int i, j;
	//	int array_zo[6][6];
	int k;
	int panjeong = 0;
	int last;
	int bb, bbb;
	int dd, ddd;
	int del = 0;
	int temp;

	//문자가 없는 칸은 array_zo[x][y]값이 0
	//array[][]에는 문자 저장
	//어느 두 위치의 문자가 선택됨(array[m]=[x][y]와 array[n]=[w][z]에서)

	//x와 w/y와 z의 대소 비교 결과, x>w y>z 가 되었다고 가정(a와 b에 더 큰쪽의 수(a=x, b=y)를 넣는 코드 삽입 필요)
	if (c > a)
	{
		temp = a;
		a = c;
		c = temp;
	}

	for (i = 0; i < 6; i++)
	{
		panjeong = 0;
		del = 0;
		last = 0;

		for (k = c; k <= a; k++)
		{
			if (ipan(a, c, array_zo, i) != 100)
				if (array_zo[k][ipan(a, c, array_zo, i)] == 0) //ipan(a,c,array[6][6],0) 의 결과물 isave
					panjeong++;
		}

		//i, b, d의 대소를 비교하여 i와 a 중 큰 쪽을 bb 작은 쪽을 bbb, i와 c 중 큰 쪽을 dd 작은 쪽을 ddd
		if (i > b)
		{
			bb = i;
			bbb = b;
		}
		else
		{
			bb = b;
			bbb = i;
		}

		if (i > d)
		{
			dd = i;
			ddd = d;
		}
		else
		{
			dd = d;
			ddd = i;
		}

		if (panjeong == a - c + 1)
		{
			for (j = bbb; j < bb; j++)
			{
				if (array_zo[a][j] == 0)
					last++;
			}
			if (last == bb - bbb)
				del++;

			last = 0;

			for (j = ddd; j < dd; j++)
			{
				if (array_zo[c][j] == 0)
					last++;
			}
			if (last == dd - ddd)
				del++;
		}

		if (del == 2)
		{
			return 1;
		}
	}
}

int ipan2(int b, int d, int array_zo[6][6], int i)
{
	int gout = 0;

	while (d <= b)
	{
		if (array_zo[i][d] == 0)
		{
			gout = 1;
			break;
		}
		d++;
	}

	if (gout == 1)
		return i;
	else
		return 100;
}

int playa_set(int a, int b, int c, int d, int array_zo[6][6], char array[16])
{
	//	int b, d;
	int i, j;
	//	int array_zo[6][6];
	int k;
	int panjeong = 0;
	int last;
	int bb, bbb;
	int dd, ddd;
	int del = 0;
	int temp;

	//문자가 없는 칸은 array_zo[x][y]값이 0
	//array[][]에는 문자 저장
	//어느 두 위치의 문자가 선택됨(array[m]=[x][y]와 array[n]=[w][z]에서)

	//x와 w/y와 z의 대소 비교 결과, x>w y>z 가 되었다고 가정(a와 b에 더 큰쪽의 수(a=x, b=y)를 넣는 코드 삽입 필요)
	if (d > b)
	{
		temp = b;
		b = d;
		d = temp;
	}

	for (i = 0; i < 6; i++)
	{
		panjeong = 0;
		del = 0;
		last = 0;

		for (k = d; k <= b; k++)
		{
			if (ipan2(b, d, array_zo, i) != 100)
				if (array_zo[ipan2(b, d, array_zo, i)][k] == 0) //ipan2(b,d,array[6][6],0) 의 결과물 isave
					panjeong++;
		}

		//i, b, d의 대소를 비교하여 i와 b 중 큰 쪽을 bb 작은 쪽을 bbb, i와 d 중 큰 쪽을 dd 작은 쪽을 ddd
		if (i > a)
		{
			bb = i;
			bbb = a;
		}
		else
		{
			bb = a;
			bbb = i;
		}

		if (i > c)
		{
			dd = i;
			ddd = c;
		}
		else
		{
			dd = c;
			ddd = i;
		}

		if (panjeong == b - d + 1)
		{
			for (j = bbb; j < bb; j++)
			{
				if (array_zo[j][b] == 0)
					last++;
			}
			if (last == bb - bbb)
				del++;

			last = 0;

			for (j = ddd; j < dd; j++)
			{
				if (array_zo[j][d] == 0)
					last++;
			}
			if (last == dd - ddd)
				del++;
		}

		if (del == 2)
		{
			return 1;
		}
	}
}
int playb_set(int a, int b, int c, int d, int array_zo[6][6], char array[16])
{
	if (a - 1 == c || c - 1 == a)
	{
		if (b == d)
		{
			return 1; //선택한 두 문자를 지워야 함
		}
	}
	if (b - 1 == d || d - 1 == b)
	{
		if (a == c)
		{
			return 1; //선택한 두 문자를 지워야 함
		}
	}
}
