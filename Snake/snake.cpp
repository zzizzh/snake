
#include <stdio.h>
#include "snake.h"

int cur=0;

void drawChar(int x, int y, char* p);

void MoveSnakeBody(SNAKE *g_Snake, int x, int y, int cur)
{
	if(x==0&&y==0)
	{
		for(int i=0; i<g_Snake->BodyLength; i++)
		{
			g_Snake->sBody[i].x=0;
			g_Snake->sBody[i].y=0;
		}
	}
	else
	{	
		if(cur<g_Snake->BodyLength)
		{
			MoveSnakeBody(g_Snake, g_Snake->sBody[cur].x,  g_Snake->sBody[cur].y, cur+1);

			g_Snake->sBody[cur].x=x;	
			g_Snake->sBody[cur].y=y;	
		}
	}
}

void MoveSnake(SNAKE *g_Snake)
{
	int prevX=g_Snake->x;
	int prevY=g_Snake->y;

	int dx[]={0, 1, 0, -1};
	int dy[]={-1, 0, 1, 0};

	g_Snake->x += dx[g_Snake->Dir];
	g_Snake->y += dy[g_Snake->Dir];

	MoveSnakeBody(g_Snake, prevX, prevY, cur);
}

void drawSnake(SNAKE *g_Snake)
{
	drawChar(g_Snake->x, g_Snake->y, g_Snake->phGrap);

	for(int i=0; i<g_Snake->BodyLength; i++)
		drawChar(g_Snake->sBody[i].x, g_Snake->sBody[i].y, g_Snake->pbGrap);
}

void eraseSnake(Snake *g_Snake)
{
	drawChar(g_Snake->x, g_Snake->y, "  ");

	for(int i=0; i<g_Snake->BodyLength; i++)
		drawChar(g_Snake->sBody[i].x, g_Snake->sBody[i].y, "  ");
}
