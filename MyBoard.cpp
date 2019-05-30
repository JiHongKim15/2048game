#include "MyBoard.h"
#include<iostream>
#include<iomanip>
using namespace std;


MyBoard::MyBoard()
{
	m_pHead = NULL;
}


MyBoard::~MyBoard()
{
	MyBlock* pcur = m_pHead;
	MyBlock* pcur_;
	MyBlock* pcur_d = m_pHead;

	while (pcur)
	{
		pcur_ = pcur;
		pcur = pcur_->getRight();
		free(pcur_);
	}
	m_pHead = NULL;
	m_pTail = NULL;
}

bool MyBoard::Up()
{
	MyBlock* pcur = m_pHead;
	MyBlock* pcur_d = m_pHead;
	MyBlock* iter;
	int temp;
	bool flag = false;

	while (pcur != NULL)
	{
		pcur_d = pcur;
		iter = NULL;
		//���� ���� ã��
		while (pcur_d != NULL)
		{
			if (pcur_d->getNum() != 0) 
			{
				if (iter != NULL && iter->getNum() == pcur_d->getNum())
				{
					flag = true;

					iter->setNum(pcur_d->getNum() * 2); //������ 2�踦 ����
					pcur_d->setNum(0); 
					iter = NULL;
				}
				else
					iter = pcur_d; //iter �̵�
			}
			pcur_d = pcur_d->getDown(); //������ �̵�
		}

		pcur_d = pcur;
		iter = pcur;
		//���� ���� �̵�
		while (pcur_d != NULL)
		{
			if (pcur_d->getNum() != 0)
			{
				if (iter->getX() != pcur_d->getX() || iter->getY() != pcur_d->getY()) //iter�� ��ġ�� pucr_d�� ��ġ�� ���� ���� ��
					flag = true;

				temp = pcur_d->getNum();  //pcur_d�� iter�� ���� �ٲ�

				pcur_d->setNum(0);

				iter->setNum(temp);
				iter = iter->getDown(); //iter �̵�
			}
			pcur_d = pcur_d->getDown(); //������ �̵�
		}

		pcur = pcur->getRight(); //������ �̵�
	}

	return flag;
}

bool MyBoard::Down()
{
	MyBlock* pcur = m_pHead->getDown()->getDown()->getDown();
	MyBlock* pcur_d = m_pHead;
	MyBlock* iter;
	int temp;
	bool flag = false;

	while (pcur != NULL)
	{
		pcur_d = pcur;
		iter = NULL;
		//���� ���� ã��
		while (pcur_d != NULL)
		{
			if (pcur_d->getNum() != 0)
			{
				if (iter != NULL && iter->getNum() == pcur_d->getNum())
				{
					flag = true;

					iter->setNum(pcur_d->getNum() * 2); //2��
					pcur_d->setNum(0);
					iter = NULL;
				}
				else
					iter = pcur_d;
			}
			pcur_d = pcur_d->getUp(); //���� �̵�
		}

		pcur_d = pcur;
		iter = pcur;
		//���� �Ʒ��� �̵�
		while (pcur_d != NULL)
		{
			if (pcur_d->getNum() != 0)
			{
				if (iter->getX() != pcur_d->getX() || iter->getY() != pcur_d->getY())
					flag = true;

				temp = pcur_d->getNum();

				pcur_d->setNum(0);

				iter->setNum(temp);
				iter = iter->getUp();
			}
			pcur_d = pcur_d->getUp();
		}

		pcur = pcur->getRight();
	}

	return flag;
}

bool MyBoard::Left()
{
	MyBlock* pcur = m_pHead;
	MyBlock* pcur_d = m_pHead;
	MyBlock* iter;
	int temp;
	bool flag = false;

	while (pcur != NULL)
	{
		pcur_d = pcur;
		iter = NULL;

		//���� ���� ã��
		while (pcur_d != NULL)
		{
			if (pcur_d->getNum() != 0)
			{
				if (iter != NULL && iter->getNum() == pcur_d->getNum())
				{
					flag = true;

					iter->setNum(pcur_d->getNum() * 2);
					pcur_d->setNum(0);
					iter = NULL;
				}
				else
					iter = pcur_d;
			}
			pcur_d = pcur_d->getRight();
		}

		pcur_d = pcur;
		iter = pcur;
		//���� �������� �̵�
		while (pcur_d != NULL)
		{
			if (pcur_d->getNum() != 0)
			{
				if (iter->getX() != pcur_d->getX() || iter->getY() != pcur_d->getY())
					flag = true;

				temp = pcur_d->getNum();

				pcur_d->setNum(0);

				iter->setNum(temp);
				iter = iter->getRight();
			}
			pcur_d = pcur_d->getRight();
		}

		pcur = pcur->getDown();
	}

	return flag;
}

bool MyBoard::Right()
{
	MyBlock* pcur = m_pHead->getRight()->getRight()->getRight();
	MyBlock* pcur_d = m_pHead;
	MyBlock* iter;
	int temp;
	bool flag = false;

	while (pcur != NULL)
	{
		pcur_d = pcur;
		iter = NULL;
		//���� ���� ã��
		while (pcur_d != NULL)
		{
			if (pcur_d->getNum() != 0)
			{
				if (iter != NULL && iter->getNum() == pcur_d->getNum())
				{
					flag = true;

					iter->setNum(pcur_d->getNum() * 2);
					pcur_d->setNum(0);
					iter = NULL;
				}
				else
					iter = pcur_d;
			}
			pcur_d = pcur_d->getLeft();
		}

		pcur_d = pcur;
		iter = pcur;
		//���� ���������� �̵�
		while (pcur_d != NULL)
		{
			if (pcur_d->getNum() != 0)
			{
				if (iter->getX() != pcur_d->getX() || iter->getY() != pcur_d->getY())
					flag = true;

				temp = pcur_d->getNum();

				pcur_d->setNum(0);

				iter->setNum(temp);
				iter = iter->getLeft();
			}
			pcur_d = pcur_d->getLeft();
		}

		pcur = pcur->getDown();
	}

	return flag;
}

void MyBoard::Set()
{
	MyBlock* pcur = m_pHead;
	int pos[2] = { 0, 0 };

	for (int i = 0; i < 16; i++)
	{
		MyBlock* pnew = new MyBlock;

		pnew->setX(pos[0]);
		pnew->setY(pos[1]);

		if (m_pHead == NULL)
		{
			m_pHead = m_pTail = pnew;
		}
		else
		{
			m_pTail->setRight(pnew);
			pnew->setLeft(m_pTail);
			m_pTail = pnew;
		}

		//��ǥ �Է�
		pos[1]++;
		if ((i + 1) % 4 == 0)
		{
			pos[0]++;
			pos[1] = 0;
		}
	}
}

void MyBoard::Connect()
{
	MyBlock* pcur = m_pHead->getRight();
	MyBlock* pcur_d = m_pHead;
	MyBlock* pcur_ds = pcur_d;

	int cnt = 1;

	while (pcur != NULL)
	{
		if (cnt % 4 == 0) //�� ���� ����
		{
			pcur_ds = pcur_d;
			pcur->getLeft()->setRight(NULL);
			pcur->setLeft(NULL);

			for (int i = 0; i < 3; i++) //���Ʒ��� �̾���
			{
				pcur->setUp(pcur_d);
				pcur_d->setDown(pcur);

				pcur_d = pcur_d->getRight();
				pcur = pcur->getRight();
				cnt++;
			}
			pcur->setUp(pcur_d);
			pcur_d->setDown(pcur);

			pcur_d = pcur_ds->getDown();
		}
		pcur = pcur->getRight();
		cnt++;
	}
}
void MyBoard::Input(int x, int y)
{
	MyBlock* pcur = m_pHead;
	MyBlock* pcur_d = m_pHead;

	while (pcur_d != NULL)
	{
		pcur = pcur_d;
		while (pcur != NULL)
		{
			if (pcur->getX() == x && pcur->getY() == y) //��ǥ�� ���� ��
			{
				pcur->setNum(2); //2 ����
			}
			pcur = pcur->getRight();
		}
		pcur_d = pcur_d->getDown();
	}
}

void MyBoard::Print()
{
	MyBlock* pcur = m_pHead;
	MyBlock* pcur_d = m_pHead;

	cout << "[Board]" << endl;
	while (pcur_d != NULL)
	{
		pcur = pcur_d;
		cout << "[ ";
		while (pcur != NULL)
		{
			if (pcur->getNum() == 0)
				cout << setw(5) << "_";
			else
				cout << setw(5) << pcur->getNum();
			pcur = pcur->getRight();
		}
		cout << " ]" << endl;
		pcur_d = pcur_d->getDown();
	}
	cout << endl;
}

int MyBoard::Search(int x, int y)
{
	MyBlock* pcur = m_pHead;
	MyBlock* pcur_d = m_pHead;

	while (pcur_d != NULL)
	{
		pcur = pcur_d;
		while (pcur != NULL)
		{
			if (pcur->getX() == x && pcur->getY() == y) //��ǥ�� ã��
			{
				if (pcur->getNum() == 0) //���������
					return 1; //1 ��ȯ
			}
			pcur = pcur->getRight();
		}
		pcur_d = pcur_d->getDown();
	}
	return 0;
}

bool MyBoard::checkWin()
{
	MyBlock* pcur = m_pHead;
	MyBlock* pcur_d = m_pHead;

	while (pcur != NULL)
	{
		pcur_d = pcur;
		while (pcur_d != NULL)
		{
			if (pcur_d->getNum() == 2048) //���ڰ� 2048�� �� ��
				return true;
			pcur_d = pcur_d->getRight();
		}
		pcur = pcur->getDown();
	}
	return false;
}

bool MyBoard::checkLose()
{
	MyBlock* pcur = m_pHead;
	MyBlock* pcur_d = m_pHead;

	while (pcur != NULL)
	{
		pcur_d = pcur;
		while (pcur_d != NULL)
		{
			if (pcur_d->getNum() == 0) //���ڰ� ����ִ� ���
				return false;
			if (pcur_d->getUp() != NULL && pcur_d->getUp()->getNum() == pcur_d->getNum()) //�ٷ� ���� ���� ���ڰ� �ִ� ���
				return false;
			if (pcur_d->getDown() != NULL && pcur_d->getDown()->getNum() == pcur_d->getNum()) //�ٷ� �ؿ� ���� ���ڰ� �ִ� ���
				return false;
			if (pcur_d->getLeft() != NULL && pcur_d->getLeft()->getNum() == pcur_d->getNum()) //�ٷ� ���ʿ� ���� ���ڰ� �ִ� ���
				return false;
			if (pcur_d->getRight() != NULL && pcur_d->getRight()->getNum() == pcur_d->getNum()) //�ٷ� �����ʿ� ���� ���ڰ� �ִ� ���
				return false;

			pcur_d = pcur_d->getRight(); //������ �̵�
		}
		pcur = pcur->getDown(); //������ �̵� 
	}
	return true;
}