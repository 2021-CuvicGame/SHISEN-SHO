#pragma once
//void title();
//int menu();
//void game_rule();

//게임 상태
#define END 7
#define CLEAR 8
#define AGAIN 9
#define MAIN 10
char array[17] = { '1','2','3','4','5','6','7','8','1','2','3','4','5','6','7','8' };
char L2[16] = { 'a','a','b','b','c','c','d','d','e','e','f','f','g','g','h','h' };
char L3[16] = { '#','#','&','&','!','!','?','?','$','$','@','@','+','+','=','=' };
char L4[16] = { '~','~','-','-','=','=',',',',','.','.','/','/','|','|','_','_' };
//한글과 한자는 2바이트라,,,,, 꼬임,,,,,
//char L4[] = "ㅓㅓㅕㅕㅖㅖㅔㅔㅐㅐㅒㅒㅟㅟㅚㅚ";
//char L5[]
//출력할때는 printf("%c%c",L4[i],L4[i+1])  이런식으로....
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
	printf("게임 시작");
	gotoxy(28, 17);
	printf("게임 방법");
	gotoxy(28, 19);
	printf("종료\n\n\n");
	int x = 26, y = 15;
	gotoxy(x, y);
	printf(">");
	while (1) {		//무한반복	>> enter 치면 종료
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
				return 0;	//게임 종료
			}
			case 15: {
				system("cls");
				return 1;	//게임 시작
			}
			case 17: {
				system("cls");
				return 2;	//게임 방법
			}
			}
		}
		}
	}
}

void game_rule() {
	system("cls");
	setcolor(6, 0);
	printf("\n\n\n========== 사 천 성  게 임  방 법 ===========\n\n\n");
	setcolor(14, 0);
	printf("* 모든 패를 제거 하면 게임이 종료됩니다.\n\n");
	printf("  패를 제거할 수 있는 경우는 다음과 같습니다.\n\n");
	printf("  >>동일한 패 2개가 인접해 있을 때\n\n");
	printf("  >>동일한 모양의 패 2개 사이에 다른 패가 있을 경우, \n\n");
	printf("    수평 또는 수직의 직선으로 연결하여 그 선이 구부러지는 횟수가 2회 이내 일 때 \n\n");
	printf("    (즉, 3개 이내의 수직선 또는 수평선의 조합으로 2개의 패를 이을 때) \n\n\n");
	printf("* 방향키로 제어하고, 선택 시 엔터를 누릅니다.\n\n\n");
	printf("* 시간 제한이 있습니다.\n\n\n");
	printf("* 잘못 선택 시 목숨이 줄어듭니다. (목숨 5개)\n\n");
	printf("=====================================================");
	printf("\n\n ←를 누르면 메인화면으로 이동합니다..........");

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
		printf(" ★ ");	//★
	}
	for (int l = 0; l < 5 - life; l++) {
		if (5 - life <= 5)
			printf(" ☆ ");
		else
			printf("    ");
	}
	printf("  ]");
}
void drawMap(int level) {
	gotoxy(0, 0);
	setcolor(14, 2);
	printf("\n                   사  천  성                    \n\n");
	setcolor(7, 0);
	printf("                                          level : %d\n\n", level);
	
	for (int i = 0; i < 16; i++) {
		if (i % 4 == 0) {
			gotoxy(7, i + 7);
		}
		printf(" [  %c  ] ", array[i]);
	}
	gotoxy(50, 10);
	printf("  ┌───────┐           ");
	gotoxy(50, 11);
	printf("  │ reset │  : R 키    ");
	gotoxy(50, 12);
	printf("  └───────┘      ");
	gotoxy(53, 13);
	printf("   ┌──────┐ ");
	gotoxy(53, 14);
	printf("   │ quit │  : Q 키 ");
	gotoxy(53, 15);
	printf("   └──────┘");
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
	printf("\n                   사  천  성                    \n\n");
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
	printf("\n                   사  천  성                    \n\n");
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