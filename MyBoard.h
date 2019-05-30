#pragma once
#include"MyBlock.h"
class MyBoard
{
private:
	MyBlock* m_pHead;
	MyBlock* m_pTail;
public:
	MyBoard();
	~MyBoard();

	bool Up();
	bool Down();
	bool Left();
	bool Right();
	void Set();
	void Connect();
	void Input(int x, int y);
	void Print();
	int Search(int x, int y);
	bool checkWin();
	bool checkLose();
};

