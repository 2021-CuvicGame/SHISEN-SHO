#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>

void arrange(char *array);     //ÆÇ ¹è¿­
void shuffle(int* arr, int num);     //¼¯±â
void ch_green();      //±ÛÀÚ »ö±ò
void gotoxy(int x, int y);  //ÁÂÇ¥
void wasd(int *cur,char *array);    //¹æÇâÅ°
int position_array[4][4] = { {0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15} };



int main() {
    int level = 4;
    char array[16] = { 'a','a','b','b','c','c','d','d','e','e','f','f','g','g','h','h'};
    
    printf("\n                Sacheonseong Game\n\n");
    printf("                                          level : %d\n\n", level);
    arrange(array);
    int cursor = 0;
    while (1) {
        if (_kbhit()) {         
            wasd(cursor,array);
        }        
    }
    
}


void arrange(char *array) {
   
    int x = 0;
    shuffle(*position_array, 16);
    for (int i = 0; i < 4; i++) {
        gotoxy(7,4*i+7);
        for (int j = 0; j < 4; j++) {
           printf(" | %2.c  | ", array[position_array[i][j]]);
        }
        printf("\n\n");
    }
}
void shuffle(int* arr, int num) {
    srand(time(NULL));
    int temp;
    int rn;
    for (int i= 0; i < num - 1; i++) {
        rn = rand() % (num - i) ;
        temp = arr[i];
        arr[i] = arr[rn];
        arr[rn] = temp;
    }
}
void ch_green() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
}
void gotoxy(int x, int y) {
    COORD Pos = { x - 1, y - 1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void wasd(int* cur, char *array) {
    int x = 11;
    int y = 7;
    int chr;
    
    gotoxy(x, y);
    while (1) {
        chr = _getch();
        if (chr == 0 || chr == 0xe0) {
            chr = _getch();
            if (chr == 72) { //»ó             
                y -= 2;
                cur -= 4;
                if (y < 7)
                    y = 7;                
                
            }
            else if (chr == 80) { //ÇÏ
                y+=2;
                cur += 4;
            }
            else if (chr == 75) { //ÁÂ
                x -= 6;
                cur -= 1;
                if (x <2)
                    x = 2;               
                
            }
            else if (chr == 77) { //¿ì
                x+=6;
                cur += 1;
            }
            int pos = position_array[*cur];
            gotoxy(x, y);
            ch_green();
            printf("%c",array[pos]);
        }

    }
}

