#include "MyBlock.h"
#include <iostream>



MyBlock::MyBlock()
{
	m_number = 0;
	m_x = 0;
	m_y = 0;
	m_pUp = NULL;
	m_pDown = NULL;
	m_pLeft = NULL;
	m_pRight = NULL;
}


MyBlock::~MyBlock()
{
}

void MyBlock::setNum(int n)
{
	m_number = n;
}

void MyBlock::setX(int x)
{
	m_x = x;
}

void MyBlock::setY(int y)
{
	m_y = y;
}

void MyBlock::setUp(MyBlock * u)
{
	m_pUp = u;
}

void MyBlock::setDown(MyBlock * d)
{
	m_pDown = d;
}

void MyBlock::setLeft(MyBlock * l)
{
	m_pLeft = l;
}

void MyBlock::setRight(MyBlock * r)
{
	m_pRight = r;
}

int MyBlock::getNum()
{
	return m_number;
}

int MyBlock::getX()
{
	return m_x;
}

int MyBlock::getY()
{
	return m_y;
}

MyBlock * MyBlock::getUp()
{
	return m_pUp;
}

MyBlock * MyBlock::getDown()
{
	return m_pDown;
}

MyBlock * MyBlock::getLeft()
{
	return m_pLeft;
}

MyBlock * MyBlock::getRight()
{
	return m_pRight;
}
