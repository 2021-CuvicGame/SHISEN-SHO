#include "util.h"
#include "Gmain.h"
#include "Judge.h"

int gLoop();
void levCh(int level);		//���� üũ �Լ�
void drawMap(int level);
int selected[2] = { 0,0 };		// ������ array ���(?) ����

int move(int* array_zo, int* x, int* y, int* correct);

int main() {
	init();
	while (1) {
		title();
		int menuCh = menu();
		if (menuCh == 0) {	//���� ����
			return 0;
		}
		else if (menuCh == 1) {		//���� ����
			while(1) {
				int status = gLoop();	//���� ���� >>0�̸� ����, 1�̸� ������ or clear
				if (status == CLEAR) {
					if (level < 4) {
						levCh(++level);
					}
					else {
						game_clear();
						return 0;
					}
				}
				if (status == AGAIN) {	//reset -> again
					continue;
				}
				if (status == END)	//life==0 -> end
					game_over();
				if (status == MAIN) {
					break;	//����ȭ������ �Ѿ		quit -> main
				}
			}
		}
		else if (menuCh == 2) {		//���� ���
			game_rule();
		}
		system("cls");
	}
	return 0;
}

int gLoop() {
	int correct=0;	
	int array_zo[6][6];		//array_zo ����	//����...?
	for (int j = 0; j < 6; j++)
		for (int i = 0; i < 6; i++)
			array_zo[i][j] = 1;
	for (int i = 0; i < 6; i++){
		array_zo[0][i] = 0;
		array_zo[i][0] = 0;
		array_zo[5][i] = 0;
		array_zo[i][5] = 0;
	}
	shuffle(array);
	drawMap(level);		//�� ���
	cursor = 0;
	setcolor(10, 0);	//�ʱ� Ŀ�� ��ġ���� ���
	int x = 11, y = 7;	
	gotoxy(x+1 , y);
	printf("\b%c", array[cursor]);
	while (1) {	//���� ����
		if (_kbhit()) {
			int ans=move(array_zo, &x, &y, &correct);
			if (correct == 8)		//correct==1�� �ϸ� ���� �� �ϴ� �� Ȯ�� ����
				return CLEAR;
			if (life == 0)
				return END;
			if (ans == RESET) {
				return AGAIN;
			}
			if (ans == QUIT) {
				return MAIN;
			}
		}
	}
}
int move(int* array_zo,int *x,int*y,int *correct) {	
	setcolor(7, 0);		//�̵� �� ������� ���
	printf("\b%c", array[cursor]);
	int key = keyControl();
	if (key == UP) {
		*y -= 4;
		cursor -= 4;
		if (*y < 7) {
			*y = 19;
			cursor += 16;
		}
	}
	else if (key == DOWN) {
		*y += 4;
		cursor += 4;
		if (*y > 19) {
			*y = 7;
			cursor -= 16;
		}
	}
	else if (key == LEFT) {
		*x -= 9;
		cursor -= 1;
		if (*x < 3) {
			*x = 38;
			cursor += 4;
		}
	}
	else if (key == RIGHT) {
		*x += 9;
		cursor += 1;
		if (*x > 38) {
			*x = 11;
			cursor -= 4;
		}
	}
	else if (key ==RESET) {
		return RESET;
	}
	else if (key == QUIT) {
		return QUIT;
	}
	//Enter ù ��°
	else if (key == ENTER && number == 0) {
		setcolor(4, 0);
		printf("*");
		a = (*x - 11) / 9;
		b = (*y - 7) / 4;
		number++;
		selected[0] = cursor;
	}
	//Enter �� ��°
	else if (key == ENTER && number == 1)
	{
		c = (*x - 11) / 9;
		d = (*y - 7) / 4;
		number = 0;
		selected[1] = cursor;

		gotoxy(a * 9 + 11 + 1, b * 4 + 7);
		printf(" ");

		if (a == c && b == d || array[selected[0]] != array[selected[1]]) {		//���� �� ����
			for (int i = 0; i < 2; i++) {	//selected �Լ� �ʱ�ȭ
				selected[i] = 0;
				life--;		//Ȯ�� �ʿ�
			}
		}
		else {
			if (play_set(a, b, c, d, array_zo, array) == 1 || playa_set(a, b, c, d, array_zo, array) == 1 || playb_set(a, b, c, d, array_zo, array) == 1) {
				array[selected[0]] = 0;
				array[selected[1]] = 0;
				gotoxy(a * 9 + 11, b * 4 + 7);
				printf("\b\b\b\b        ");
				gotoxy(c * 9 + 11, d * 4 + 7);
				printf("\b\b\b\b        ");

				(*correct)++;	//correct 8�� �Ǹ� ������ ����
			}
			else
				life--;		//Ȯ���ʿ�
		}
	}
	gotoxy(*x, *y);
	setcolor(10, 0);
	printf("%c", array[cursor]);

	
}

void levCh(int level) {
	if (level == 2) {	//����
		memcpy(array, L2, sizeof(L2));
	}
	else if (level == 3) {		//���� ��ȣ
		memcpy(array, L3, sizeof(L3));
	}
	else if (level == 4) {		//����� ��ȣ
		memcpy(array, L4, sizeof(L4));
	}
}
