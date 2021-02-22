#pragma once
//void title();
//int menu();
//void game_rule();

//���� ����
#define END 7
#define CLEAR 8
#define AGAIN 9
#define MAIN 10
char array[17] = { '1','2','3','4','5','6','7','8','1','2','3','4','5','6','7','8' };
char L2[16] = { 'a','a','b','b','c','c','d','d','e','e','f','f','g','g','h','h' };
char L3[16] = { '#','#','&','&','!','!','?','?','$','$','@','@','+','+','=','=' };
char L4[16] = { '~','~','-','-','=','=',',',',','.','.','/','/','|','|','_','_' };
//�ѱ۰� ���ڴ� 2����Ʈ��,,,,, ����,,,,,
//char L4[] = "�ääŤŤƤƤĤĤ����¤¤ϤϤʤ�";
//char L5[]
//����Ҷ��� printf("%c%c",L4[i],L4[i+1])  �̷�������....
int level = 1, life = 5;

void title() {
	setcolor(14, 0);
	printf("\n\n=========================================================================\n\n");
	setcolor(10, 0);
	printf("                 #            #       #          #        #    \n");
	printf("         #       #        # # # # #   #         #         # \n");
	printf("        ##       #            #    ## #        ##     # # # \n");
	printf("       #  #      # # #      #   #     #       #   #       #    \n");
	printf("      #    #     #        #       #   #      #      #     #       \n");
	printf("     #      #    #           #                    # # # # #     \n");
	printf("                 #           #                  #          #  \n");
	printf("                 #           # # # # # #          # # # # #  \n");
	setcolor(14, 0);
	printf("\n=======================================================================\n");
}
int menu() {
	setcolor(7, 0);
	gotoxy(28, 15);
	printf("���� ����");
	gotoxy(28, 17);
	printf("���� ���");
	gotoxy(28, 19);
	printf("����\n\n\n");
	int x = 26, y = 15;
	gotoxy(x, y);
	printf(">");
	while (1) {		//���ѹݺ�	>> enter ġ�� ����
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 15) {
				gotoxy(x, y);
				printf("  ");
				gotoxy(x, y - 2);
				printf(">");
				y -= 2;
			}
			break;
		}
		case DOWN: {
			if (y < 19) {
				gotoxy(x, y);
				printf("  ");
				gotoxy(x, y + 2);
				printf(">");
				y += 2;
			}
			break;
		}
		case ENTER: {
			switch (y) {
			case 19: {
				system("cls");
				return 0;	//���� ����
			}
			case 15: {
				system("cls");
				return 1;	//���� ����
			}
			case 17: {
				system("cls");
				return 2;	//���� ���
			}
			}
		}
		}
	}
}

void game_rule() {
	system("cls");
	setcolor(6, 0);
	printf("\n\n\n========== �� õ ��  �� ��  �� �� ===========\n\n\n");
	setcolor(14, 0);
	printf("* ��� �и� ���� �ϸ� ������ ����˴ϴ�.\n\n");
	printf("  �и� ������ �� �ִ� ���� ������ �����ϴ�.\n\n");
	printf("  >>������ �� 2���� ������ ���� ��\n\n");
	printf("  >>������ ����� �� 2�� ���̿� �ٸ� �а� ���� ���, \n\n");
	printf("    ���� �Ǵ� ������ �������� �����Ͽ� �� ���� ���η����� Ƚ���� 2ȸ �̳� �� �� \n\n");
	printf("    (��, 3�� �̳��� ������ �Ǵ� ������ �������� 2���� �и� ���� ��) \n\n\n");
	printf("* ����Ű�� �����ϰ�, ���� �� ���͸� �����ϴ�.\n\n\n");
	printf("* �ð� ������ �ֽ��ϴ�.\n\n\n");
	printf("* �߸� ���� �� ����� �پ��ϴ�. (��� 5��)\n\n");
	printf("=====================================================");
	printf("\n\n �縦 ������ ����ȭ������ �̵��մϴ�..........");

	while (1) {
		if (keyControl() == LEFT) {
			break;
		}
	}
}
void print_life(int life) {
	gotoxy(7, 25);
	printf("[ life : ");
	for (int k = 0; k < life; k++) {
		printf(" �� ");	//��
	}
	for (int l = 0; l < 5 - life; l++) {
		if (5 - life <= 5)
			printf(" �� ");
		else
			printf("    ");
	}
	printf("  ]");
}
void drawMap(int level) {
	gotoxy(0, 0);
	setcolor(14, 2);
	printf("\n                   ��  õ  ��                    \n\n");
	setcolor(7, 0);
	printf("                                          level : %d\n\n", level);
	
	for (int i = 0; i < 16; i++) {
		if (i % 4 == 0) {
			gotoxy(7, i + 7);
		}
		printf(" [  %c  ] ", array[i]);
	}
	gotoxy(50, 10);
	printf("  ������������������           ");
	gotoxy(50, 11);
	printf("  �� reset ��  : R Ű    ");
	gotoxy(50, 12);
	printf("  ������������������      ");
	gotoxy(53, 13);
	printf("   ���������������� ");
	gotoxy(53, 14);
	printf("   �� quit ��  : Q Ű ");
	gotoxy(53, 15);
	printf("   ����������������");
	gotoxy(0, 23);
	printf("================================================\n\n");
	gotoxy(0, 25);
	print_life(life);
	system("pause>NULL");
}
void game_clear() {
	system("cls");
	gotoxy(0, 0);
	setcolor(14, 2);
	printf("\n                   ��  õ  ��                    \n\n");
	setcolor(7, 0);
	printf("                                          level : %d\n\n", level);

	gotoxy(0, 7);
	setcolor(14,0);
	printf("==============================================================                    \n\n");
	Sleep(50);
	printf("        # # #   #         # # # #       #       # # #                                                \n");
	Sleep(50);
	printf("       #        #         #            # #      #     #                                               \n");
	Sleep(50);
	printf("      #         #         # # #       #   #     # # #                                            \n");
	Sleep(50);                     
	printf("       #        #         #          # # # #    #  #                                          \n");
	Sleep(50);   
	printf("        # # #   # # # #   # # # #   #       #   #     #                                      \n");
	Sleep(50);
	setcolor(14, 0);
	printf("\n==============================================================                              \n");
	system("pause>NULL");
}
void game_over() {
	system("cls");
	gotoxy(0, 0);
	setcolor(14, 2);
	printf("\n                   ��  õ  ��                    \n\n");
	setcolor(7, 0);
	printf("                                          level : %d\n\n", level);

	Sleep(50);
	gotoxy(0, 7);
	setcolor(14, 0);
	printf("======================================================================                    \n\n");
	Sleep(50);
	Sleep(50);
	printf("        ###      #     #     #  ####      ##    #   #  ####  ####                                      \n");
	Sleep(50);
	printf("       #        # #    # # # #  #        #  #   #   #  #     #   #                           \n");
	Sleep(50);
	printf("       #  ##   # # #   #  #  #  ###     #    #  #   #  ###   ####                                   \n");
	Sleep(50);
	printf("       #   #   #   #   #     #  #        #  #    # #   #     #  #                                 \n");
	Sleep(50);
	printf("        ####  #     #  #     #  ####      ##      #    ####  #   #                              \n");
	Sleep(50);
	setcolor(14, 0);
	printf("\n======================================================================                              \n");
	system("pause>NULL");
}