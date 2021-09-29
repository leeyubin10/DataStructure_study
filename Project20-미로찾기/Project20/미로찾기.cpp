#include <iostream>
using namespace std;

const int MAZE_SIZE = 6;
const int MAX_SIZE = 100;

typedef struct Pos {
	short x;
	short y;
}Pos;

typedef struct Stack
{
	Pos data[MAX_SIZE];
	int top;
}Stack;

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'},
};

void init(Stack *p)
{
	p->top = -1;
}

int Is_full(Stack *p)
{
	return (p->top == MAX_SIZE - 1);
}

int Is_empty(Stack *p)
{
	return (p->top == -1);
}

void Push(Stack *p, Pos data)
{
	if (Is_full(p))
	{
		cout << "스택이 꽉찼습니다." << endl;
		return;
	}
	else
	{
		p->top++;
		p->data[p->top].x = data.x;
		p->data[p->top].y = data.y;
	}
}

Pos Pop(Stack *p)
{
	if (Is_empty(p))
	{
		cout << "스택이 비어있습니다." << endl;
		exit(1);
	}

	return p->data[(p->top)--];
}

void Push_Loc(Stack *s, int x, int y)
{
	if (x < 0 || y < 0 || x > MAZE_SIZE || y > MAZE_SIZE) return;

	if (maze[x][y] != '1' && maze[x][y] != '.') 
	{
		Pos tmp;
		tmp.x = x;
		tmp.y = y;

		Push(s, tmp);
	}
}

int main()
{
	Stack s;
	Pos here;
	int x, y;

	init(&s);

	for (int i = 0; i < MAZE_SIZE; i++)
	{
		for (int j = 0; j < MAZE_SIZE; j++)
		{
			cout << maze[i][j];
			if (maze[i][j] == 'e')
			{
				here.x = i;
				here.y = j;
			}
		}
		cout << endl;
	}

	cout << endl << "시작 점 (" << here.x << "," << here.y << ")" << endl;

	while (maze[here.x][here.y] != 'x')
	{
		x = here.x;
		y = here.y;

		maze[x][y] = '.';

		Push_Loc(&s, x + 1, y);
		Push_Loc(&s, x - 1, y);
		Push_Loc(&s, x, y + 1);
		Push_Loc(&s, x, y - 1);

		if (Is_empty(&s))
		{
			cout << "실패";
			return 0;
		}
		else
		{
			here = Pop(&s);
			cout << "(" << here.x << ", " << here.y << ")" << endl;
		}
	}

	cout << "도착 점 (" << here.x << "," << here.y << ")" << endl;
	cout << "탐색 성공" << endl;

	return 0;
}