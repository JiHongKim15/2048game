#pragma once
class MyBlock
{
private:
	int m_number, m_x, m_y;
	MyBlock* m_pUp;
	MyBlock* m_pDown;
	MyBlock* m_pLeft;
	MyBlock* m_pRight;
public:
	MyBlock();
	~MyBlock();

	void setNum(int n);
	void setX(int x);
	void setY(int y);

	void setUp(MyBlock* u);
	void setDown(MyBlock* d);
	void setLeft(MyBlock* l);
	void setRight(MyBlock* r);

	int getNum();
	int getX();
	int getY();

	MyBlock* getUp();
	MyBlock* getDown();
	MyBlock* getLeft();
	MyBlock* getRight();
};

