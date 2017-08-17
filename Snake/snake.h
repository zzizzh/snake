
#define MAX_LENGTH 50

struct SnakeBody
{
	int x;
	int y;
};

typedef struct SnakeBody SNAKE_BODY;

struct Snake
{
	int x;
	int y;
	int Dir;
	int BodyLength;
	SNAKE_BODY sBody[MAX_LENGTH];
	char* phGrap;
	char* pbGrap;
};

typedef struct Snake SNAKE;

