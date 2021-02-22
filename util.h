#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>

//키보드 값
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define ENTER 4
#define RESET 5
#define QUIT 6

//void init();
//int keyControl();
//void setcolor(unsigned short text, unsigned short back);
//void gotoxy(int x, int y);
//void shuffle(char* arr);
int cursor = 0, number = 0;
void init() {
	system("mode con cols=80 lines=35|title 사천성");
	
	//커서 숨기는 함수
	/*HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);*/
}
void gotoxy(int x, int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
int keyControl() {
	int chr;
	chr = _getch();
	if (chr == 72) {	//상
		return UP;
	}
	else if (chr == 80) {	//하
		return DOWN;
	}
	else if (chr == 75) {		//좌
		return LEFT;
	}
	else if (chr == 77) {	//우
		return RIGHT;
	}
	else if (chr == 13) {	//엔터
		return ENTER;
	}
	else if (chr == 'R' || chr == 'r') {
		return RESET;
	}
	else if (chr == 'Q' || chr == 'q') {
		return QUIT;
	}
}
void setcolor(unsigned short text, unsigned short back) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

void shuffle(char* arr) {
	srand(time(NULL));
	char temp;
	int rn;
	for (int i = 0; i < 16; i++) {
		rn = rand() % (16 - i); // i 부터 num-1 사이에 임의의 정수 생성
		temp = arr[i];
		arr[i] = arr[rn];
		arr[rn] = temp;
	}
}