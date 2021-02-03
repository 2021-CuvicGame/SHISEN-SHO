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

//상한님
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
		if (chr == 72) {	//상
			y -= 4;
			cur -= 4;
			if (y < 7)
				y = 19;
		}
		else if (chr == 80) {	//하
			y += 4;
			cur += 4;
			if (y > 19)
				y = 7;
		}
		else if (chr == 75) {		//좌
			x -= 9;
			cur -= 1;
			if (x < 3)
				x = 38;
		}
		else if (chr == 77) {	//우
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
	printf("==========사천성 게임 방법===========\n\n\n");
	printf("* 모든 패를 제거 하면 게임이 종료됩니다.\n\n");
	printf("  패를 제거할 수 있는 경우는 다음과 같습니다.\n\n");
	printf("  >>동일한 패 2개가 인접해 있을 때\n\n");
	printf("  >>동일한 모양의 패 2개 사이에 다른 패가 있을 경우, \n\n");
	printf("    수평 또는 수직의 직선으로 연결하여 그 선이 구부러지는 횟수가 2회 이내 일 때 \n\n");
	printf("    (즉, 3개 이내의 수직선 또는 수평선의 조합으로 2개의 패를 이을 때) \n\n\n");
	printf("* 방향키로 제어하고, 선택 시 엔터를 누릅니다.\n\n");
	printf("* 시간 제한이 있습니다.\n\n\n");
	//printf("* 잘못 선택 시 목숨이 줄어듭니다.\n");
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
			break; //루프문 탈출 전 선택한 두 문자를 지워야 함
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
			break; //루프문 탈출 전 선택한 두 문자를 지워야 함
		}
	}
}

