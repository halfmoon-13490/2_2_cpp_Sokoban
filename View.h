#pragma once
#include "Model.h"
#include "keycode.h"
#include "Map.h"
#include <iostream>
using namespace std;

class View
{
public:
	View() {

	}

	// 사용자로부터 키 값을 받음 
	int getkey() {
		int ch = _getch();
		return (ch != 0xe0) ? ch : (0xe000 | _getch());
	}

	// 사용자 아이콘 그리기
	void drawCharacter(int mx, int my) {
		textbackground(YELLOW);
		gotoxy((MAP_X1 + mx + 1) * 2, MAP_Y1 + my + 1);
		puts("♀");
	}

	// 셀 그리기
	void drawCell(Model* model, int row, int col) {
		int cell = model->getMap(row, col);
		// 각 원소 별 다른 배경색
		if (cell == 1) {
			textbackground(WHITE);
		}
		else if (cell == 3) {
			textbackground(RED);
		}
		else if (cell == 0) {
			textbackground(YELLOW);
		}
		else if (cell == 4) {
			textbackground(CYAN);
		}
		else {
			textbackground(WHITE);
		}
		gotoxy((MAP_X1 + col + 1) * 2, MAP_Y1 + row + 1);
		puts(model->getIcon(cell));
	}

	// 맵 그리는 메소드
	void drawMap(Model *model) {
		for (int row = 0; row < MAP_HEIGHT; ++row)
			for (int col = 0; col < MAP_WIDTH; ++col)
				drawCell(model, row, col);
	}

	// 시작화면 메소드
	int start(Model *model, Map *map) {
		gotoxy(15, 5);
		puts("push push");
		gotoxy(15, 8);
		puts("1. Career Mode");
		gotoxy(15, 10);
		puts("2. Stage Mode");
		gotoxy(15, 12);
		puts("3. How to play");
		gotoxy(15, 14);
		puts("4. Exit");
		int ch = getkey();
	
		switch(ch){
		case M_1: system("cls"); generalGame(model, model->getX(0), model->getY(0), map); break;	// 커리어모드 시작
		case M_2: system("cls"); selectStage(model, map); break;	// 스테이지 모드 시작
		case M_3: system("cls"); howto(model, map); break;	// 도움말 시작
		case M_4: exit(0);	// 종료
		}
	}

	// 스테이지 선택 화면 메소드
	void selectStage(Model* model, Map* map) {
		gotoxy(15, 5);
		puts("Stage Select");
		gotoxy(15, 9);
		puts("1. stage [1]");
		gotoxy(15, 11);
		puts("2. stage [2]");
		gotoxy(15, 13);
		puts("3. stage [3]");
		gotoxy(15, 15);
		puts("4. stage [4]");
		gotoxy(15, 17);
		puts("5. stage [5]");
		gotoxy(15, 19);
		puts("q. Main Menu");
		

		int ch = getkey();
		int x, y;
		int stage = 0;
		switch (ch) {
			// 각각 선택한 스테이지를 파라미터로 하는 stageGame메소드 실행
		case M_1: system("cls"); stage = 0; x = model->getX(stage), y = model->getY(stage); stageGame(model, x, y, stage, map); break;
		case M_2: system("cls"); stage = 1; x = model->getX(stage), y = model->getY(stage); stageGame(model, x, y, stage, map); break;
		case M_3: system("cls"); stage = 2; x = model->getX(stage), y = model->getY(stage); stageGame(model, x, y, stage, map); break;
		case M_4: system("cls"); stage = 3; x = model->getX(stage), y = model->getY(stage); stageGame(model, x, y, stage, map); break;
		case M_5: system("cls"); stage = 4; x = model->getX(stage), y = model->getY(stage); stageGame(model, x, y, stage, map); break;
		case M_Q: system("cls"); start(model, map); break;
		}

	}

	// 도움말
	void howto(Model *model, Map* map) {
		_setcursortype(_NOCURSOR);
		cout << "<How to play>" << endl;
		cout << "1. 요소 설명" << endl;
		cout << "▤(벽): 공과 상자, 그리고 사용자는 벽을 지나서 갈 수 없습니다." << endl;
		cout << "●(공): 사용자는 공을 도착지점에 넣어야 게임에 승리 할 수 있습니다. 또한 여러 개의 공은 서로 맞닿으면 게임오버가 됩니다." << endl;
		cout << "※(도착지점): 사용자는 이곳에 공을 넣어야 승리 할 수 있습니다." << endl;
		cout << "▩(비활성화된 도착지점): 비활성화된 도착지점에는 공이 들어갈 수 없습니다. 사용자는 상자를 상자함에 넣어야 도착지점을 활성화 할 수 있습니다." << endl;
		cout << "■(상자): 사용자는 상자를 상자함에 넣어야 도착지점을 활성화 할 수 있습니다." << endl;
		cout << "□(상자함): 사용자는 이곳에 상자를 넣어야 도착지점을 활성화 할 수 있습니다." << endl;
		cout << "▦(불타는 벽): 공은 이곳에 닿으면 게임오버가 됩니다." << endl;
		cout << endl;
		cout << "2. 게임 방법" << endl;
		cout << "게임은 커리어 모드와 스테이지 모드가 있습니다." << endl;
		cout << "커리어 모드는 연달아 5개의 스테이지를 클리어하고 사용된 무브 수에 따라 알맞은 랭크를 부여받습니다." << endl;
		cout << "스테이지 모드는 연습모드로써, 각각의 스테이지를 자유롭게 선택하여 연습 할 수 있습니다." << endl;
		cout << "커리어 모드에서 리셋 버튼을 누르면 각 요소의 위치가 초기화 되지만, 패널티로 3개의 무브가 추가됩니다." << endl;
		cout << endl;
		cout << "3. 점수" << endl;
		cout << "S랭크 => 총 사용 무브수 < 213" << endl;
		cout << "A랭크 => 총 사용 무브수 < 240 " << endl;
		cout << "B랭크 => 총 사용 무브수 < 277 " << endl;
		cout << "C랭크 => 총 사용 무브수 < 350 " << endl;
		cout << "F랭크 => 이외 " << endl;
		cout << endl;
		cout << "q: 메인 메뉴" << endl;
		
		int ch = getkey();
		if (ch == M_Q) {
			system("cls");
			start(model, map);
		}
		
	}

	// 게임 실행도중 키보드 카운트 값을 출력하는 메소드
	void printCount(Model *model) {
		gotoxy(38, 5);
		textbackground(WHITE);
		int count = model->getCount(); // model의 getCount  호출
		printf("count: %d", count);
	}

	// 커리어 모드 게임 실행도중 정보를 나타내는 메소드
	void printInfo() {
		gotoxy(38, 7);
		textbackground(WHITE);
		printf("r: 리셋");
		gotoxy(38, 9);
		printf("q: 메인메뉴");
		gotoxy(38, 11);
		printf("esc: 종료");
	}

	// 스테이지 모드 게임 실행도중 정보를 나타내는 메소드
	void printStageInfo() {
		gotoxy(38, 7);
		textbackground(WHITE);
		printf("r: 리셋");
		gotoxy(38, 9);
		printf("q: 메인메뉴");
		gotoxy(38, 11);
		printf("1: 이전 맵");
		gotoxy(50, 11);
		printf("2: 다음 맵");
		gotoxy(38, 13);
		printf("m: 스테이지 선택");
		gotoxy(38, 15);
		printf("esc: 종료");
	}

	// 스테이지 성공을 알리는 메소드
	void printStageSucess(Model* model) {
		gotoxy(38, 13);
		printf("%d 스테이지 성공! 사용된 무브 수: %d", (model->getStage()+1), model->getCount());
		delay(3000);
	}

	// 게임 도중 스테이지 번호를 출력하는 메소드
	void printStageNum(Model* model) {
		gotoxy(10, 3);
		printf("<%d stage>", (model->getStage() + 1));
	}

	// 커리어 모드 게임 내 스테이지를 모두 클리어 했을 때 실행되는 메소드 / 무브수 및 랭크 출력
	void printGameSucess(Model* model) {
		gotoxy(38, 13);
		printf("모든 스테이지 성공! 사용된 무브 수: %d", model->getCount());
		delay(3000);
		system("cls");
		gotoxy(18, 7);
		printf("사용된 무브 수: %d =>  %c 클래스 입니다!", model->getCount(), model->rank());
		delay(4000);
	}

	// 커리어모드 게임오버를 알리는 메소드
	int gameOver(Model* model, Map *map) {
		// model의 요소를 초기화
		model->resetStage();
		model->resetCount();
		model->resetMap();
		model->resetBall();
		system("cls");
		gotoxy(20, 7);
		printf("Game Over!");
		gotoxy(20, 9);
		printf("1. main menu");
		gotoxy(35, 9);
		printf("2. quit");
		int ch = getkey();

		switch (ch) {
		case M_1: system("cls"); start(model, map); break;	// 시작화면
		case M_2: system("cls"); return 0;	// 게임 종료
		}
	}

	// 스테이지모드 게임오버를 알리는 메소드
	int stageGameOver(Model* model, Map* map, int stage) {	// 현재 스테이지를 파라미터로 받음
		// 모델의 요소 초기화
		model->resetStage();
		model->resetCount();
		model->resetMap();
		model->resetBall();
		system("cls");
		gotoxy(20, 7);
		printf("Game Over!");
		gotoxy(20, 9);
		printf("1. main menu");
		gotoxy(35, 9);
		printf("2. retry");
		gotoxy(50, 9);
		printf("3. quit");
		int ch = getkey();

		switch (ch) {
		case M_1: system("cls"); start(model, map); break;	// 시작화면
		case M_2: system("cls"); stageGame(model, model->getX(stage), model->getY(stage), stage, map); break;	// 파라미터 스테이지를 기준으로 현재 스테이지 재시작
		case M_3: system("cls"); return 0;
		}
	}

	// 커리어모드 코드
	void generalGame(Model* model, int x, int y, Map* map) {
		int key, oldx, oldy;
		int stage = model->getStage();
		model->loadMap(map, stage); // model이 map에서 스테이지에 맞는 맵을 불러옴
		// 좌표의 초깃값 저장
		int resetX = x; 
		int resetY = y;

		do {
			// 사용자의 다음 지점을 가리키게 하는 인덱스 변수 초기화
			int dx = 0;
			int dy = 0;

			// 게임 화면 출력
			printStageNum(model);
			drawMap(model);
			drawCharacter(x, y);
			printCount(model);
			printInfo();

			key = getkey();

			oldx = x;
			oldy = y;

			switch (key)
			{
				// 방향키를 누를 때 마다 키카운트 증가 및 추가 좌표값 지정
			case M_UPKEY: if (y > 0) dy -= 1; model->increase(); break;
			case M_DOWNKEY: if (y < MAP_HEIGHT - 1) dy += 1; model->increase();  break;
			case M_LEFTKEY: if (x > 0) dx -= 1; model->increase();  break;
			case M_RIGHTKEY: if (x < MAP_WIDTH - 1) dx += 1; model->increase(); break;
			case M_R: model->loadMap(map, stage); printStageNum(model); drawMap(model); x = resetX; y = resetY; drawCharacter(x, y); model->penalty(); /* 패널티 발생*/  printCount(model); printInfo(); break;
			case M_Q: model->resetCount(); model->resetStage(); model->resetMap(); system("cls"); start(model, map); break;
			}

			// x와 y는 새로운 좌표가 됨
			x += dx; 
			y += dy;

			if (model->getMap(y, x) != 0) { // 가려고 하는 지점이 빈공간이 아닐 경우
				if (model->getMap(y, x) == 7) {	// 상자일 경우
					if (model->getMap(y + dy, x + dx) == 0) {	// 상자 너머가 빈공간이 이라면
						model->setMap(y + dy, x + dx, 7);	// 너머가 상자가 되고
						model->setMap(y, x, 0);	// 상자의 위치가 빈 공간이 된다
					}
					else if (model->getMap(y + dy, x + dx) == 6) {	// 짐 너머가 상자함이라면
						model->setMap(y + dy, x + dx, 7);	// 너머가 상자가 되고
						model->setMap(y, x, 0);	// 상자의 위치가 빈 공간이 된다
						model->finishOpen();	// 종료지점 비활성화 
					}
					else {	// 상자 너머가 상자함 혹은 빈공간이 아닌 모든 경우
						x = oldx;
						y = oldy;
					}
				}
				else if (model->getMap(y, x) == 2) { // 공이 있는 경우
					if (model->getMap(y + dy, x + dx) == 0) {	// 공 너머가 빈공간이 이라면
						model->setMap(y + dy, x + dx, 2);	// 너머가 공이 되고
						model->setMap(y, x, 0);	// 공의 위치가 빈 공간이 된다
						drawMap(model);
						// 이후 공의 위치 4방향으로 공이 있다면
						if ((model->getMap(y + dy + 1, x + dx) == 2) || (model->getMap(y + dy - 1, x + dx) == 2) || (model->getMap(y + dy, x + dx + 1) == 2) || (model->getMap(y + dy, x + dx - 1) == 2)) {
							// 게임 오버
							gameOver(model, map);
							break;
						}
						// 이후 공의 위치 4방향으로 터지는 벽이 있다면
						else if ((model->getMap(y + dy + 1, x + dx) == 3) || (model->getMap(y + dy - 1, x + dx) == 3) || (model->getMap(y + dy, x + dx + 1) == 2) || (model->getMap(y + dy, x + dx - 1) == 3)) {
							// 게임 오버
							gameOver(model, map);
							break;
						}
					}
					else if (model->getMap(y + dy, x + dx) == 4) {	// 짐 너머가 성공이라면
						model->ballCount();	// 볼 갯수 가산
						model->setMap(y + dy, x + dx, 2);	// 너머가 짐이 되고
						model->setMap(y, x, 0);	// 짐의 위치가 빈 공간이 된다
						drawMap(model);
						if (model->getBall(stage) > model->getCurBall()) {	// 스테이지 볼 갯수보다 현재 볼 갯수가 많다면
						}
						else {	// 적다면
							if (model->getStage() < 4) {	// 스테이지가 5스테이지 미만일 경우
								printStageSucess(model);	// 스테이지 성공 출력
								// model은 다음 스테이지 준비
								model->nextStage();			
								model->resetMap();
								model->resetBall();
								system("cls");				// 화면 지우기
								// 다음 스테이지로의 재귀호출
								generalGame(model, model->getX(model->getStage()), model->getY(model->getStage()), map);
							}
							else { // 5스테이를 클리어한 경우
								// model 초기화
								model->resetStage();
								model->resetMap();
								model->resetBall();
								printGameSucess(model);	// 게임 성공 출력
								system("cls");
								start(model, map);	// 시작화면
							}
							break;
						}
					}
					else {	// 공 너머가 성공과 빈 공간을 제외한 모든 것이라면
						x = oldx;
						y = oldy;
					}
				}
				else { // 플레이어 다음 위치가 빈 공간, 상자, 공이 아니라면
					x = oldx;
					y = oldy;
				}
			}
			// 새로고침
			if (oldx != x || oldy != y) {
				printStageNum(model);
				drawMap(model);
				printCount(model);
				printInfo();
			}
		} while (key != M_ESCKEY);
	}

	// 스테이지 모드 코드(커리어 모드 코드와 중복은 생략)
	void stageGame(Model *model, int x, int y, int level, Map* map) {	// 파라미터로 스테이지를 받는다
		int key, oldx, oldy;
		int stage = level;	// 현재 스테이지 지정
		model->setStage(level);	// model스테이지 정보 지정
		model->loadMap(map, stage);	// 스테이지에 맞는 맵 불러오기
		int resetX = x;
		int resetY = y;

		do {
			int dx = 0;
			int dy = 0;

			printStageNum(model);
			drawMap(model);
			drawCharacter(x, y);
			printCount(model);
			printStageInfo();

			key = getkey();

			oldx = x;
			oldy = y;

			switch (key)
			{
			case M_UPKEY: if (y > 0) dy -= 1; model->increase(); break;
			case M_DOWNKEY: if (y < MAP_HEIGHT - 1) dy += 1; model->increase();  break;
			case M_LEFTKEY: if (x > 0) dx -= 1; model->increase();  break;
			case M_RIGHTKEY: if (x < MAP_WIDTH - 1) dx += 1; model->increase(); break;
			case M_R: model->loadMap(map, stage); printStageNum(model); drawMap(model); x = resetX; y = resetY; drawCharacter(x, y); model->penalty(); printCount(model); printStageInfo(); break;
			case M_Q: model->resetCount(); model->resetStage(); model->resetMap(); system("cls"); start(model, map); break;
			// 1번을 누르면 이전 스테이지 불러오기(스테이지가 1이면 자동으로 5스테이지 출력 / 반대경우 동일)
			case M_1: system("cls"); stage -= 1; if (stage < 0) { stage = 4; } model->resetCount(); model->resetBall(); x = model->getX(stage), y = model->getY(stage); stageGame(model, x, y, stage, map); break;
			case M_2: system("cls"); stage += 1; if (stage > 4) { stage = 0; } model->resetCount(); model->resetBall(); x = model->getX(stage), y = model->getY(stage); stageGame(model, x, y, stage, map); break;
			case M_M: system("cls"); model->resetBall(); model->resetCount(); model->resetMap(); model->resetStage(); selectStage(model, map); break;
			}

			x += dx;
			y += dy;

			if (model->getMap(y, x) != 0) { 
				if (model->getMap(y, x) == 7) {
					if (model->getMap(y + dy, x + dx) == 0) {
						model->setMap(y + dy, x + dx, 7);	
						model->setMap(y, x, 0);	
					}
					else if (model->getMap(y + dy, x + dx) == 6) {	
						model->setMap(y + dy, x + dx, 7);	
						model->setMap(y, x, 0);	
						drawMap(model);
						model->finishOpen();	
					}
					else {	
						x = oldx;
						y = oldy;
					}
				}
				else if (model->getMap(y, x) == 2) { 
					if (model->getMap(y + dy, x + dx) == 0) {	
						model->setMap(y + dy, x + dx, 2);	
						model->setMap(y, x, 0);	
						drawMap(model);
						if ((model->getMap(y + dy + 1, x + dx) == 2) || (model->getMap(y + dy - 1, x + dx) == 2) || (model->getMap(y + dy, x + dx + 1) == 2) || (model->getMap(y + dy, x + dx - 1) == 2)) {
							stageGameOver(model, map, stage);
							break;
						}
						else if ((model->getMap(y + dy + 1, x + dx) == 3) || (model->getMap(y + dy - 1, x + dx) == 3) || (model->getMap(y + dy, x + dx + 1) == 2) || (model->getMap(y + dy, x + dx - 1) == 3)) {
							stageGameOver(model, map, stage);
							break;
						}
					}
					else if (model->getMap(y + dy, x + dx) == 4) {	
						model->ballCount();
						model->setMap(y + dy, x + dx, 2);	
						model->setMap(y, x, 0);	
						drawMap(model);
						if (model->getBall(stage) > model->getCurBall()) {
							
						}
						else {
							model->resetMap();
							model->resetBall();
							system("cls");
							printStageSucess(model);	// stage성공 출력
							model->resetCount();
							model->resetStage();
							system("cls");
							selectStage(model, map);	// 스테이지 선택 창 출력
							break;
						}
					}
					else {	
						x = oldx;
						y = oldy;
					}
				}
				else { 
					x = oldx;
					y = oldy;
				}
			}
			if (oldx != x || oldy != y) {
				printStageNum(model);
				drawMap(model);
				printCount(model);
				printStageInfo();
			}
		} while (key != M_ESCKEY);
	}
};

