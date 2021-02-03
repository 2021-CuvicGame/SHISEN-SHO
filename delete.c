#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>

//array[a] (0~35)
//array[x][y] (0~5)
//a=x*6+y

void make_board(char* array);
void shuffle(int* arr, int num1, int num2);
void gotoxy(int x, int y);
void wasd(int cur, char* array, int x, int y, int array_zo);
int position_array[6][6] = { {0,1,2,3,4,5},{6,7,8,9,10,11},{12,13,14,15,16,17},{18,19,20,21,22,23},{24,25,26,27,28,29},{30,31,32,33,34,35} };
void game_rule();
void play_set(int a, int b, int c, int d, int array_zo, char array);
void playa_set(int a, int b, int c, int d, int array_zo, char array);

int main() {
	game_rule();
	int i, j;
	char array[36] = { ' ',' ',' ',' ',' ',' ',' ','a','a','b','b',' ',' ','c','c','d','d',' ',' ','e','e','f','f',' ',' ','g','g','h','h',' ',' ',' ',' ',' ',' ',' ' };
	int array_zo[6][6];
	int number=0;

	for (j = 0; j < 6; j++)
		for (i = 0; i < 6; i++)
			array_zo[i][j] = 1;

	for (i = 0; i < 6; i++)
	{
		array_zo[0][i] = 0;
		array_zo[i][0] = 0;
		array_zo[5][i] = 0;
		array_zo[i][5] = 0;
	}

	while (1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
		printf("\n                Sacheonseong Game                  \n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		int level = 1;
		printf("                                          level : %d\n\n", level);
		make_board(array);

		time_t start, fin;
		srand((unsigned)time(NULL));
		start = clock();
		int cursor = 0;
		int x = 11;
		int y = 7;
		while (1) {
			gotoxy(x, y);
			if (_kbhit()) {
				wasd(cursor, array, x, y, array_zo, array);
			}
		}
		//do {
			//fin = clock;

		//} while (difftime(start, fin) > 60000);
	}
}

//���Ѵ�
//	pan_set();
//	play_set();
//	playa_set();

void make_board(char* array) {

	int x = 0;
	shuffle(*position_array, 4 + 2, 4 + 2);

	for (int i = 1; i < 5; i++) {
		gotoxy(7, 4 * i + 3);
		for (int j = 1; j < 5; j++) {
			printf(" | %2.c  | ", array[position_array[j][i]]);
		}
		printf("\n\n");
	}
}
void shuffle(int* arr, int num1, int num2) {
	srand(time(NULL));
	int temp;
	int rn;
	int bnum = num1 * num2;
	for (int i = 6; i < bnum - 6; i++) {
		rn = rand() % 36;
		if (i % 6 != 0 && i % 6 != 5)
		{
			if (rn >= 6 && rn <= 30 && rn % 6 != 0 && rn % 6 != 5)
			{
				temp = arr[i];
				arr[i] = arr[rn];
				arr[rn] = temp;
			}
		}
	}
}

void gotoxy(int x, int y) {
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void wasd(int cur, char* array, int x, int y,int array_zo[6][6]) {

	int chr;
	int a, b, c, d;
	int number = 0;
	while (1) {
		chr = _getch();
		if (chr == 72) {	//��
			y -= 4;
			cur -= 4;
			if (y < 7)
				y = 19;
		}
		else if (chr == 80) {	//��
			y += 4;
			cur += 4;
			if (y > 19)
				y = 7;
		}
		else if (chr == 75) {		//��
			x -= 9;
			cur -= 1;
			if (x < 3)
				x = 38;
		}
		else if (chr == 77) {	//��
			x += 9;
			cur += 1;
			if (x > 38)
				x = 11;
		}
		else if (chr == 13)
		{
			a = (x - 11) / 9;
			b = (y - 7) / 4;
			number++;
		}
		else if (chr == 13)
		{
			c = (x - 11) / 9;
			d = (y - 7) / 4;
			number++;
		}
		else if (number >= 2)
		{
			play_set(a, b, c, d, array_zo, array);
			playa_set(a, b, c, d, array_zo, array);
		}
		int pos = position_array[cur];
		gotoxy(x, y);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		//printf("%c", array[pos]);
		printf("_");
	}
}

void game_rule() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("==========��õ�� ���� ���===========\n\n\n");
	printf("* ��� �и� ���� �ϸ� ������ ����˴ϴ�.\n\n");
	printf("  �и� ������ �� �ִ� ���� ������ �����ϴ�.\n\n");
	printf("  >>������ �� 2���� ������ ���� ��\n\n");
	printf("  >>������ ����� �� 2�� ���̿� �ٸ� �а� ���� ���, \n\n");
	printf("    ���� �Ǵ� ������ �������� �����Ͽ� �� ���� ���η����� Ƚ���� 2ȸ �̳� �� �� \n\n");
	printf("    (��, 3�� �̳��� ������ �Ǵ� ������ �������� 2���� �и� ���� ��) \n\n\n");
	printf("* ����Ű�� �����ϰ�, ���� �� ���͸� �����ϴ�.\n\n");
	printf("* �ð� ������ �ֽ��ϴ�.\n\n\n");
	//printf("* �߸� ���� �� ����� �پ��ϴ�.\n");
	system("pause");
	system("cls");

}


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

void play_set(int a,int b,int c,int d,int array_zo[6][6],char array[36])
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

	//���ڰ� ���� ĭ�� array_zo[x][y]���� 0
	//array[][]���� ���� ����
	//��� �� ��ġ�� ���ڰ� ���õ�(array[m]=[x][y]�� array[n]=[w][z]����)

	//x�� w/y�� z�� ��� �� ���, x>w y>z �� �Ǿ��ٰ� ����(a�� b�� �� ū���� ��(a=x, b=y)�� �ִ� �ڵ� ���� �ʿ�)
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
				if (array_zo[k][ipan(a, c, array_zo, i)] == 0) //ipan(a,c,array[6][6],0) �� ����� isave
					panjeong++;
		}

		//i, b, d�� ��Ҹ� ���Ͽ� i�� a �� ū ���� bb ���� ���� bbb, i�� c �� ū ���� dd ���� ���� ddd
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
			break; //������ Ż�� �� ������ �� ���ڸ� ������ ��
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

void playa_set(int a,int b,int c,int d,int array_zo[6][6],char array[36])
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

	//���ڰ� ���� ĭ�� array_zo[x][y]���� 0
	//array[][]���� ���� ����
	//��� �� ��ġ�� ���ڰ� ���õ�(array[m]=[x][y]�� array[n]=[w][z]����)

	//x�� w/y�� z�� ��� �� ���, x>w y>z �� �Ǿ��ٰ� ����(a�� b�� �� ū���� ��(a=x, b=y)�� �ִ� �ڵ� ���� �ʿ�)
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
				if (array_zo[ipan2(b, d, array_zo, i)][k] == 0) //ipan2(b,d,array[6][6],0) �� ����� isave
					panjeong++;
		}

		//i, b, d�� ��Ҹ� ���Ͽ� i�� b �� ū ���� bb ���� ���� bbb, i�� d �� ū ���� dd ���� ���� ddd
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
			break; //������ Ż�� �� ������ �� ���ڸ� ������ ��
		}
	}
}

