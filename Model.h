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
	int stageX[STAGE] = { 5, 7, 2, 1, 5};	// 각 스테이지별 사용자의 x좌표 
	int stageY[STAGE] = { 5, 3, 1, 1, 6};	// 각 스테이지별 사용자의 y좌표
	int ball[STAGE] = { 4, 1, 2, 1, 4};		// 각 스테이지별 공의 갯수
	int curBall = 0;	// 현재 스테이지의 공 갯수 추적
	int stage = 0;	// 현재 스테이지
	int keycount = 0;	// 키보드 누르는 횟수 카운터
	int curMap[MAP_HEIGHT][MAP_WIDTH] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },	// Map클래스로부터 맵 정보를 불러들일 2차원 배열
										  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	const char* icon[10] = { "  ", "▤", "●", "▦", "※", "○", "□", "■", "▩" , "  "};
	
public:
	Model() {
	}
	
	// 카운트 관련 메소드
	void increase() {	// 키보드 카운터 증가
		keycount++;
	}
	void penalty() {	// 패널티로 키보드 카운터 3 증가
		keycount += 3;
	}
	int getCount() {	// 키보드 카운터 리턴
		return keycount;
	}
	void resetCount() {	// 키보드 카운터 초기화
		keycount = 0;
	}

	// 랭크 관련 메소드 
	int rank() {	// 키보드 카운터 크기에 따라 상응하는 랭크의 아스키코드 리턴
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

	// 공 갯수 관련 메소드
	int getBall(int stage) {	// 스테이지 별 공의 갯수 리턴
		return ball[stage];
	}
	void resetBall() {			// 현재 공 갯수 초기화
		curBall = 0;
	}
	int getCurBall() {			// 현재 공 갯수 리턴
		return curBall;
	}

	void ballCount() {			// 현재 공 갯수 추가
		curBall++;
	}

	// 비활성화 된 도착지점 활성화
	void finishOpen() {			
		for (int i = 0; i < MAP_HEIGHT; i++) {
			for (int j = 0; j < MAP_WIDTH; j++) {
				if (curMap[i][j] == 8) {
					curMap[i][j] = 4;
				}
			}
		}
	}

	// 맵 관련 메소드
	void loadMap(Map *map, int stage) {	// 맵 로드
		for (int i = 0; i < MAP_HEIGHT; i++) {
			for (int j = 0; j < MAP_WIDTH; j++) {
				curMap[i][j] = map->getMap(i, j, stage);
			}
		}
	}
	void resetMap() {	// 맵 초기화
		for (int i = 0; i < MAP_HEIGHT; i++) {
			for (int j = 0; j < MAP_WIDTH; j++) {
				curMap[i][j] = 0;
			}
		}
	}	
	int getMap(int row, int col) {	// 맵 원소 리턴
		return curMap[row][col];
	}
	void setMap(int row, int col, int val) {	// 맵 원소 교체
		curMap[row][col] = val;
	}

	// 사용자 좌표 관련
	int getX(int stage) {	// 사용자 x좌표 리턴
		return stageX[stage];
	}
	int getY(int stage) {	// 사용자 y좌표 리턴
		return stageY[stage];
	}

	// 스테이지 관련
	void nextStage() {	// 스테이지 가산
		stage++;
	}
	int getStage() {	// 현재 스테이지 리턴
		return stage;
	}
	void resetStage() {	// 스테이지 초기화
		stage = 0;
	}
	void setStage(int level) {	// 스테이지값 정의
		stage = level;
	}

	const char* getIcon(int cell) {	// 아이콘
		return icon[cell];
	}

};

