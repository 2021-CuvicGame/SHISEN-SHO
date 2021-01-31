#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#include "play.c"
#include "playa.c"

void arrange(char* array);     //�� �迭
void shuffle(int* arr, int num);     //����
void ch_green();      //���� ����
void gotoxy(int x, int y);  //��ǥ
void wasd(int* cur, char* array);    //����Ű
int position_array[6][6] = { {0,1,2,3,4,5},{6,7,8,9,10,11},{12,13,14,15,16,17},{18,19,20,21,22,23},{24,25,26,27,28,29},{30,31,32,33,34,35} };


int main() {
	int level = 4;
	char array[36] = {'','','','','','','','a','a','b','b','','','c','c','d','d','','','e','e','f','f','','','g','g','h','h','','','','','','',''};

	printf("\n                Sacheonseong Game\n\n");
	printf("                                          level : %d\n\n", level);
	arrange(array);
	int cursor = 0;
	while (1) {
		if (_kbhit()) {
			wasd(cursor, array);
		}
	}

	//상한님
	pan_set();
	play_set();
	playa_set();
}


void arrange(char* array) {

	int x = 0;
	shuffle(*position_array, 36);


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


	for (int i = 1; i < 5; i++) {
		gotoxy(7, 4 * i + 7);
		for (int j = 1; j < 5; j++) {
			printf(" | %2.c  | ", array[position_array[i][j]]);
		}
		printf("\n\n");
	}
}
void shuffle(int* arr, int num) {
	srand(time(NULL));
	int temp;
	int rn;
	for (int i = 0; i < num - 1; i++) {
		rn = rand() % (num - i);
		temp = arr[i];
		arr[i] = arr[rn];
		arr[rn] = temp;
	}
}
void ch_green() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
}
void gotoxy(int x, int y) {
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void wasd(int* cur, char* array) {
	int x = 11;
	int y = 7;
	int chr;

	gotoxy(x, y);
	while (1) {
		chr = _getch();
		if (chr == 0 || chr == 0xe0) {
			chr = _getch();
			if (chr == 72) { //��             
				y -= 2;
				cur -= 4;
				if (y < 7)
					y = 7;

			}
			else if (chr == 80) { //��
				y += 2;
				cur += 4;
			}
			else if (chr == 75) { //��
				x -= 6;
				cur -= 1;
				if (x < 2)
					x = 2;

			}
			else if (chr == 77) { //��
				x += 6;
				cur += 1;
			}
			int pos = position_array[*cur];
			gotoxy(x, y);
			ch_green();
			printf("%c", array[pos]);
		}

	}
}

