
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "config.h"
#include "snake.h"
#include "map.h"

HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);

void MoveSnakeBody(SNAKE *g_Snake, int x, int y, int cur);
void MoveSnake(SNAKE *g_Snake);
void drawSnake(SNAKE *g_Snake);
void eraseSnake(Snake *g_Snake);

enum { MAP_EMPTY, MAP_WALL, MAP_APPLE, MAP_SBODY };

struct _GAME_BOARD
{
	int sx;
	int sy;
	int **ppBoard;
};

typedef struct _GAME_BOARD GAME_BOARD;

int** CreatMap(int sx, int sy)
{
	int **ppMap = (int**)malloc(sizeof(int*)*sy);

	for(int i=0; i<sx; i++)
		ppMap[i]=(int*)malloc(sizeof(int)*sx);

	return ppMap;
}

 GAME_BOARD* InitGmaeBoard(int sx, int sy)
{
	GAME_BOARD *pBoard=(GAME_BOARD*)malloc(sizeof(GAME_BOARD));
	pBoard->sx=sx;
	pBoard->sy=sy;

	pBoard->ppBoard=CreatMap(sx, sy);
}

void SetupBoard(GAME_BOARD *pBoard)
{
	for(int y=0; y<pBoard->sy; y++)
	{
			for(int x=0; x<pBoard->sx; x++)
		{
			pBoard->ppBoard[y][x]=MAP_EMPTY;
		}
	}

	for(int y=0; y<pBoard->sy; y++)
	{
		pBoard->ppBoard[y][0]=MAP_WALL;
		pBoard->ppBoard[y][pBoard->sx]=MAP_WALL;
	}

	for(int x=0; x<pBoard->sx; x++)
	{
		pBoard->ppBoard[0][x]=MAP_WALL;
		pBoard->ppBoard[pBoard->sy][x]=MAP_WALL;
	}

}

void DrawMap(GAME_BOARD *pBoard)
{
	for(int y=0; y<pBoard->sy; y++)
		for(int x=0; x<pBoard->sx; x++)
		{
			if(pBoard->ppBoard[y][x]==MAP_WALL)
				drawChar(x, y, "в╞");
		}
}

void drawChar(int x, int y, char* p)
{
	COORD cPos = { x*2 , y };
	
	::SetConsoleCursorPosition(hConsole, cPos);

	printf("%s", p);
}

void BoundCheck(int *x, int *y, int SX, int SY)
{
	if(*x<0)
		*x=0;
	if(*x>SX-1)
		*x=SX-1;

	if(*y<0)
		*y=0;
	if(*y>SY-1)
		*y=SY-1;
}

void KeyProc(SNAKE *g_Snake)
{
	for(int i=0; i<100; i++)
	{
		int kPress=_kbhit();
		if(kPress)
		{
			int kVal=_getch();

			switch(kVal)
			{
			case K_LEFT : 
				g_Snake->Dir = g_Snake->Dir-1 < 0 ? D_NOD-1 : g_Snake->Dir-1;
				break;

			case K_RIGHT :
				g_Snake->Dir = ( g_Snake->Dir+1 ) % D_NOD;
			}
		}

		if(i%20==0)
			Sleep(10);
	}
}

void Render(SNAKE *g_Snake)
{
	eraseSnake(g_Snake);

	MoveSnake(g_Snake);

	BoundCheck(&g_Snake->x, &g_Snake->y, BOARD_SIZE_X, BOARD_SIZE_Y);
		
	drawSnake(g_Snake);
}

int main()
{
	SNAKE g_Snake;

	g_Snake.x=0;
	g_Snake.y=0;
	g_Snake.BodyLength=5;
	g_Snake.Dir=1;
	g_Snake.pbGrap="бр";
	g_Snake.phGrap="бс";
	
	GAME_BOARD *g_Board;

	g_Board=InitBoard(

	while(1)
	{
		Render(&g_Snake);
		
		KeyProc(&g_Snake);
	}

	return 0;
}
