#ifndef __GAME_H__
#define __GAME_H__
#include <array>
#include <iostream>
#include <list>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <vector>

using namespace std;

//$게임 화면 크기 설정
#define WIDTH 43
#define HEIGHT 20

//$스테이지의 길이(스테이지당 최대 장애물 수)
#define MAXOB 10

//장애물의 최대 길이
#define MAX_LENGTH 5

// 캐릭터 클래스
class Character {

  public:
    Character();
    void showD();
    void moveR();
    void moveL();

    int getX() { return location[1]; }
    int getY() { return location[0]; }

    //$캐릭터 ui
  private:
    array<array<char, 3>, 3> motionD = {' ',  'O', ' ', '/', 'T',
                                        '\\', '|', ' ', '|'};
    array<array<char, 3>, 3> motionR = {' ',  'O', ' ', '/', 'T',
                                        '\\', '|', ' ', '\\'};
    array<array<char, 3>, 3> motionL = {' ',  'O', ' ', '/', 'T',
                                        '\\', '/', ' ', '|'};
    array<int, 2> location = {HEIGHT - 3, (int)(WIDTH - 3) / 2};
};

//장애물 클래스
//장애물 아이콘 '@', 최대 길이 5
class Obstacle {

  public:
    static int total;

    Obstacle();
    void show();
    void moveO();

  private:
    int length;
    array<int, 2> location = {0, 0};
};

//$회피한 장애물의 갯수를 반환
int nemberOfObstacle(vector<Obstacle> &obstacle);

//$게임 시작 함수
int game(int time, Character &character, vector<Obstacle> &obstacle);

//장애물을 발생시키는 함수
void generateObstacle(vector<Obstacle> &obstacle);

//충돌 판단 함수
bool crash(int y, int x);

//컴파일용
void showBoard();
void showState(vector<Obstacle> &obstacle, int time);

#endif
