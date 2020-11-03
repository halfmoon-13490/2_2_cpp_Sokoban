#pragma once
#define MAP_HEIGHT 10
#define MAP_WIDTH 10
#define MAP_X1  4
#define MAP_Y1  4
#define STAGE 5
#include "Consola.h"
#include <conio.h>
#include <iostream>
#include "Map.h"

class Model
{
	int stageX[STAGE] = { 5, 7, 2, 1, 5};	// �� ���������� ������� x��ǥ 
	int stageY[STAGE] = { 5, 3, 1, 1, 6};	// �� ���������� ������� y��ǥ
	int ball[STAGE] = { 4, 1, 2, 1, 4};		// �� ���������� ���� ����
	int curBall = 0;	// ���� ���������� �� ���� ����
	int stage = 0;	// ���� ��������
	int keycount = 0;	// Ű���� ������ Ƚ�� ī����
	int curMap[MAP_HEIGHT][MAP_WIDTH] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },	// MapŬ�����κ��� �� ������ �ҷ����� 2���� �迭
										  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	const char* icon[10] = { "  ", "��", "��", "��", "��", "��", "��", "��", "��" , "  "};
	
public:
	Model() {
	}
	
	// ī��Ʈ ���� �޼ҵ�
	void increase() {	// Ű���� ī���� ����
		keycount++;
	}
	void penalty() {	// �г�Ƽ�� Ű���� ī���� 3 ����
		keycount += 3;
	}
	int getCount() {	// Ű���� ī���� ����
		return keycount;
	}
	void resetCount() {	// Ű���� ī���� �ʱ�ȭ
		keycount = 0;
	}

	// ��ũ ���� �޼ҵ� 
	int rank() {	// Ű���� ī���� ũ�⿡ ���� �����ϴ� ��ũ�� �ƽ�Ű�ڵ� ����
		if (keycount > 0 && keycount < 213) {
			return 83;
		}
		else if (keycount >= 213 && keycount < 240) {
			return 65;
		}
		else if (keycount >= 241 && keycount < 277) {
			return 66;
		}
		else if (keycount >= 278 && keycount < 350) {
			return 67;
		}
		else {
			return 70;
		}
	}

	// �� ���� ���� �޼ҵ�
	int getBall(int stage) {	// �������� �� ���� ���� ����
		return ball[stage];
	}
	void resetBall() {			// ���� �� ���� �ʱ�ȭ
		curBall = 0;
	}
	int getCurBall() {			// ���� �� ���� ����
		return curBall;
	}

	void ballCount() {			// ���� �� ���� �߰�
		curBall++;
	}

	// ��Ȱ��ȭ �� �������� Ȱ��ȭ
	void finishOpen() {			
		for (int i = 0; i < MAP_HEIGHT; i++) {
			for (int j = 0; j < MAP_WIDTH; j++) {
				if (curMap[i][j] == 8) {
					curMap[i][j] = 4;
				}
			}
		}
	}

	// �� ���� �޼ҵ�
	void loadMap(Map *map, int stage) {	// �� �ε�
		for (int i = 0; i < MAP_HEIGHT; i++) {
			for (int j = 0; j < MAP_WIDTH; j++) {
				curMap[i][j] = map->getMap(i, j, stage);
			}
		}
	}
	void resetMap() {	// �� �ʱ�ȭ
		for (int i = 0; i < MAP_HEIGHT; i++) {
			for (int j = 0; j < MAP_WIDTH; j++) {
				curMap[i][j] = 0;
			}
		}
	}	
	int getMap(int row, int col) {	// �� ���� ����
		return curMap[row][col];
	}
	void setMap(int row, int col, int val) {	// �� ���� ��ü
		curMap[row][col] = val;
	}

	// ����� ��ǥ ����
	int getX(int stage) {	// ����� x��ǥ ����
		return stageX[stage];
	}
	int getY(int stage) {	// ����� y��ǥ ����
		return stageY[stage];
	}

	// �������� ����
	void nextStage() {	// �������� ����
		stage++;
	}
	int getStage() {	// ���� �������� ����
		return stage;
	}
	void resetStage() {	// �������� �ʱ�ȭ
		stage = 0;
	}
	void setStage(int level) {	// ���������� ����
		stage = level;
	}

	const char* getIcon(int cell) {	// ������
		return icon[cell];
	}

};

