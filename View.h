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

	// ����ڷκ��� Ű ���� ���� 
	int getkey() {
		int ch = _getch();
		return (ch != 0xe0) ? ch : (0xe000 | _getch());
	}

	// ����� ������ �׸���
	void drawCharacter(int mx, int my) {
		textbackground(YELLOW);
		gotoxy((MAP_X1 + mx + 1) * 2, MAP_Y1 + my + 1);
		puts("��");
	}

	// �� �׸���
	void drawCell(Model* model, int row, int col) {
		int cell = model->getMap(row, col);
		// �� ���� �� �ٸ� ����
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

	// �� �׸��� �޼ҵ�
	void drawMap(Model *model) {
		for (int row = 0; row < MAP_HEIGHT; ++row)
			for (int col = 0; col < MAP_WIDTH; ++col)
				drawCell(model, row, col);
	}

	// ����ȭ�� �޼ҵ�
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
		case M_1: system("cls"); generalGame(model, model->getX(0), model->getY(0), map); break;	// Ŀ������ ����
		case M_2: system("cls"); selectStage(model, map); break;	// �������� ��� ����
		case M_3: system("cls"); howto(model, map); break;	// ���� ����
		case M_4: exit(0);	// ����
		}
	}

	// �������� ���� ȭ�� �޼ҵ�
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
			// ���� ������ ���������� �Ķ���ͷ� �ϴ� stageGame�޼ҵ� ����
		case M_1: system("cls"); stage = 0; x = model->getX(stage), y = model->getY(stage); stageGame(model, x, y, stage, map); break;
		case M_2: system("cls"); stage = 1; x = model->getX(stage), y = model->getY(stage); stageGame(model, x, y, stage, map); break;
		case M_3: system("cls"); stage = 2; x = model->getX(stage), y = model->getY(stage); stageGame(model, x, y, stage, map); break;
		case M_4: system("cls"); stage = 3; x = model->getX(stage), y = model->getY(stage); stageGame(model, x, y, stage, map); break;
		case M_5: system("cls"); stage = 4; x = model->getX(stage), y = model->getY(stage); stageGame(model, x, y, stage, map); break;
		case M_Q: system("cls"); start(model, map); break;
		}

	}

	// ����
	void howto(Model *model, Map* map) {
		_setcursortype(_NOCURSOR);
		cout << "<How to play>" << endl;
		cout << "1. ��� ����" << endl;
		cout << "��(��): ���� ����, �׸��� ����ڴ� ���� ������ �� �� �����ϴ�." << endl;
		cout << "��(��): ����ڴ� ���� ���������� �־�� ���ӿ� �¸� �� �� �ֽ��ϴ�. ���� ���� ���� ���� ���� �´����� ���ӿ����� �˴ϴ�." << endl;
		cout << "��(��������): ����ڴ� �̰��� ���� �־�� �¸� �� �� �ֽ��ϴ�." << endl;
		cout << "��(��Ȱ��ȭ�� ��������): ��Ȱ��ȭ�� ������������ ���� �� �� �����ϴ�. ����ڴ� ���ڸ� �����Կ� �־�� ���������� Ȱ��ȭ �� �� �ֽ��ϴ�." << endl;
		cout << "��(����): ����ڴ� ���ڸ� �����Կ� �־�� ���������� Ȱ��ȭ �� �� �ֽ��ϴ�." << endl;
		cout << "��(������): ����ڴ� �̰��� ���ڸ� �־�� ���������� Ȱ��ȭ �� �� �ֽ��ϴ�." << endl;
		cout << "��(��Ÿ�� ��): ���� �̰��� ������ ���ӿ����� �˴ϴ�." << endl;
		cout << endl;
		cout << "2. ���� ���" << endl;
		cout << "������ Ŀ���� ���� �������� ��尡 �ֽ��ϴ�." << endl;
		cout << "Ŀ���� ���� ���޾� 5���� ���������� Ŭ�����ϰ� ���� ���� ���� ���� �˸��� ��ũ�� �ο��޽��ϴ�." << endl;
		cout << "�������� ���� �������ν�, ������ ���������� �����Ӱ� �����Ͽ� ���� �� �� �ֽ��ϴ�." << endl;
		cout << "Ŀ���� ��忡�� ���� ��ư�� ������ �� ����� ��ġ�� �ʱ�ȭ ������, �г�Ƽ�� 3���� ���갡 �߰��˴ϴ�." << endl;
		cout << endl;
		cout << "3. ����" << endl;
		cout << "S��ũ => �� ��� ����� < 213" << endl;
		cout << "A��ũ => �� ��� ����� < 240 " << endl;
		cout << "B��ũ => �� ��� ����� < 277 " << endl;
		cout << "C��ũ => �� ��� ����� < 350 " << endl;
		cout << "F��ũ => �̿� " << endl;
		cout << endl;
		cout << "q: ���� �޴�" << endl;
		
		int ch = getkey();
		if (ch == M_Q) {
			system("cls");
			start(model, map);
		}
		
	}

	// ���� ���൵�� Ű���� ī��Ʈ ���� ����ϴ� �޼ҵ�
	void printCount(Model *model) {
		gotoxy(38, 5);
		textbackground(WHITE);
		int count = model->getCount(); // model�� getCount  ȣ��
		printf("count: %d", count);
	}

	// Ŀ���� ��� ���� ���൵�� ������ ��Ÿ���� �޼ҵ�
	void printInfo() {
		gotoxy(38, 7);
		textbackground(WHITE);
		printf("r: ����");
		gotoxy(38, 9);
		printf("q: ���θ޴�");
		gotoxy(38, 11);
		printf("esc: ����");
	}

	// �������� ��� ���� ���൵�� ������ ��Ÿ���� �޼ҵ�
	void printStageInfo() {
		gotoxy(38, 7);
		textbackground(WHITE);
		printf("r: ����");
		gotoxy(38, 9);
		printf("q: ���θ޴�");
		gotoxy(38, 11);
		printf("1: ���� ��");
		gotoxy(50, 11);
		printf("2: ���� ��");
		gotoxy(38, 13);
		printf("m: �������� ����");
		gotoxy(38, 15);
		printf("esc: ����");
	}

	// �������� ������ �˸��� �޼ҵ�
	void printStageSucess(Model* model) {
		gotoxy(38, 13);
		printf("%d �������� ����! ���� ���� ��: %d", (model->getStage()+1), model->getCount());
		delay(3000);
	}

	// ���� ���� �������� ��ȣ�� ����ϴ� �޼ҵ�
	void printStageNum(Model* model) {
		gotoxy(10, 3);
		printf("<%d stage>", (model->getStage() + 1));
	}

	// Ŀ���� ��� ���� �� ���������� ��� Ŭ���� ���� �� ����Ǵ� �޼ҵ� / ����� �� ��ũ ���
	void printGameSucess(Model* model) {
		gotoxy(38, 13);
		printf("��� �������� ����! ���� ���� ��: %d", model->getCount());
		delay(3000);
		system("cls");
		gotoxy(18, 7);
		printf("���� ���� ��: %d =>  %c Ŭ���� �Դϴ�!", model->getCount(), model->rank());
		delay(4000);
	}

	// Ŀ������ ���ӿ����� �˸��� �޼ҵ�
	int gameOver(Model* model, Map *map) {
		// model�� ��Ҹ� �ʱ�ȭ
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
		case M_1: system("cls"); start(model, map); break;	// ����ȭ��
		case M_2: system("cls"); return 0;	// ���� ����
		}
	}

	// ����������� ���ӿ����� �˸��� �޼ҵ�
	int stageGameOver(Model* model, Map* map, int stage) {	// ���� ���������� �Ķ���ͷ� ����
		// ���� ��� �ʱ�ȭ
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
		case M_1: system("cls"); start(model, map); break;	// ����ȭ��
		case M_2: system("cls"); stageGame(model, model->getX(stage), model->getY(stage), stage, map); break;	// �Ķ���� ���������� �������� ���� �������� �����
		case M_3: system("cls"); return 0;
		}
	}

	// Ŀ������ �ڵ�
	void generalGame(Model* model, int x, int y, Map* map) {
		int key, oldx, oldy;
		int stage = model->getStage();
		model->loadMap(map, stage); // model�� map���� ���������� �´� ���� �ҷ���
		// ��ǥ�� �ʱ갪 ����
		int resetX = x; 
		int resetY = y;

		do {
			// ������� ���� ������ ����Ű�� �ϴ� �ε��� ���� �ʱ�ȭ
			int dx = 0;
			int dy = 0;

			// ���� ȭ�� ���
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
				// ����Ű�� ���� �� ���� Űī��Ʈ ���� �� �߰� ��ǥ�� ����
			case M_UPKEY: if (y > 0) dy -= 1; model->increase(); break;
			case M_DOWNKEY: if (y < MAP_HEIGHT - 1) dy += 1; model->increase();  break;
			case M_LEFTKEY: if (x > 0) dx -= 1; model->increase();  break;
			case M_RIGHTKEY: if (x < MAP_WIDTH - 1) dx += 1; model->increase(); break;
			case M_R: model->loadMap(map, stage); printStageNum(model); drawMap(model); x = resetX; y = resetY; drawCharacter(x, y); model->penalty(); /* �г�Ƽ �߻�*/  printCount(model); printInfo(); break;
			case M_Q: model->resetCount(); model->resetStage(); model->resetMap(); system("cls"); start(model, map); break;
			}

			// x�� y�� ���ο� ��ǥ�� ��
			x += dx; 
			y += dy;

			if (model->getMap(y, x) != 0) { // ������ �ϴ� ������ ������� �ƴ� ���
				if (model->getMap(y, x) == 7) {	// ������ ���
					if (model->getMap(y + dy, x + dx) == 0) {	// ���� �ʸӰ� ������� �̶��
						model->setMap(y + dy, x + dx, 7);	// �ʸӰ� ���ڰ� �ǰ�
						model->setMap(y, x, 0);	// ������ ��ġ�� �� ������ �ȴ�
					}
					else if (model->getMap(y + dy, x + dx) == 6) {	// �� �ʸӰ� �������̶��
						model->setMap(y + dy, x + dx, 7);	// �ʸӰ� ���ڰ� �ǰ�
						model->setMap(y, x, 0);	// ������ ��ġ�� �� ������ �ȴ�
						model->finishOpen();	// �������� ��Ȱ��ȭ 
					}
					else {	// ���� �ʸӰ� ������ Ȥ�� ������� �ƴ� ��� ���
						x = oldx;
						y = oldy;
					}
				}
				else if (model->getMap(y, x) == 2) { // ���� �ִ� ���
					if (model->getMap(y + dy, x + dx) == 0) {	// �� �ʸӰ� ������� �̶��
						model->setMap(y + dy, x + dx, 2);	// �ʸӰ� ���� �ǰ�
						model->setMap(y, x, 0);	// ���� ��ġ�� �� ������ �ȴ�
						drawMap(model);
						// ���� ���� ��ġ 4�������� ���� �ִٸ�
						if ((model->getMap(y + dy + 1, x + dx) == 2) || (model->getMap(y + dy - 1, x + dx) == 2) || (model->getMap(y + dy, x + dx + 1) == 2) || (model->getMap(y + dy, x + dx - 1) == 2)) {
							// ���� ����
							gameOver(model, map);
							break;
						}
						// ���� ���� ��ġ 4�������� ������ ���� �ִٸ�
						else if ((model->getMap(y + dy + 1, x + dx) == 3) || (model->getMap(y + dy - 1, x + dx) == 3) || (model->getMap(y + dy, x + dx + 1) == 2) || (model->getMap(y + dy, x + dx - 1) == 3)) {
							// ���� ����
							gameOver(model, map);
							break;
						}
					}
					else if (model->getMap(y + dy, x + dx) == 4) {	// �� �ʸӰ� �����̶��
						model->ballCount();	// �� ���� ����
						model->setMap(y + dy, x + dx, 2);	// �ʸӰ� ���� �ǰ�
						model->setMap(y, x, 0);	// ���� ��ġ�� �� ������ �ȴ�
						drawMap(model);
						if (model->getBall(stage) > model->getCurBall()) {	// �������� �� �������� ���� �� ������ ���ٸ�
						}
						else {	// ���ٸ�
							if (model->getStage() < 4) {	// ���������� 5�������� �̸��� ���
								printStageSucess(model);	// �������� ���� ���
								// model�� ���� �������� �غ�
								model->nextStage();			
								model->resetMap();
								model->resetBall();
								system("cls");				// ȭ�� �����
								// ���� ������������ ���ȣ��
								generalGame(model, model->getX(model->getStage()), model->getY(model->getStage()), map);
							}
							else { // 5�����̸� Ŭ������ ���
								// model �ʱ�ȭ
								model->resetStage();
								model->resetMap();
								model->resetBall();
								printGameSucess(model);	// ���� ���� ���
								system("cls");
								start(model, map);	// ����ȭ��
							}
							break;
						}
					}
					else {	// �� �ʸӰ� ������ �� ������ ������ ��� ���̶��
						x = oldx;
						y = oldy;
					}
				}
				else { // �÷��̾� ���� ��ġ�� �� ����, ����, ���� �ƴ϶��
					x = oldx;
					y = oldy;
				}
			}
			// ���ΰ�ħ
			if (oldx != x || oldy != y) {
				printStageNum(model);
				drawMap(model);
				printCount(model);
				printInfo();
			}
		} while (key != M_ESCKEY);
	}

	// �������� ��� �ڵ�(Ŀ���� ��� �ڵ�� �ߺ��� ����)
	void stageGame(Model *model, int x, int y, int level, Map* map) {	// �Ķ���ͷ� ���������� �޴´�
		int key, oldx, oldy;
		int stage = level;	// ���� �������� ����
		model->setStage(level);	// model�������� ���� ����
		model->loadMap(map, stage);	// ���������� �´� �� �ҷ�����
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
			// 1���� ������ ���� �������� �ҷ�����(���������� 1�̸� �ڵ����� 5�������� ��� / �ݴ��� ����)
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
							printStageSucess(model);	// stage���� ���
							model->resetCount();
							model->resetStage();
							system("cls");
							selectStage(model, map);	// �������� ���� â ���
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

