#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include"MyBlock.h"
#include"MyBoard.h"
using namespace std;
int main()
{
	MyBoard game;

	int menuN;
	int randX, randY;
	int R;
	bool result;

	srand(time(NULL)); //����

	game.Set();
	game.Connect(); //ó�� ����


	cout << "[Start]" << endl;

	while (1)
	{
		while (1)
		{
			randX = rand() % 4;
			randY = rand() % 4;
			R = game.Search(randX, randY); //�������� ��ǥ�� ã��
			if (R == 1)
			{
				game.Input(randX, randY); //���� 2�� �������� ����
				break;
			}
		}
	
		if (game.checkLose() == true) //�� �̻� ������� ���� ������
		{
			cout << "Lose!!" << endl;
			break;
		}

		while (1)
		{
			game.Print();
			cout << "\n[Menu]" << endl << "1.Up 2.Down 3.Left 4.Right" << endl << "Input >> ";
			cin >> menuN;

			switch (menuN)
			{
			case 1:
				result = game.Up(); break; //���� �̵�
			case 2:
				result = game.Down(); break; //�Ʒ��� �̵�
			case 3:
				result = game.Left(); break; //�������� �̵�
			case 4:
				result = game.Right(); break; //���������� �̵�
			case -1:
				cout << "[program exit]" << endl;
				return 0; //�Է��� -1�̸� �Լ� ����
			default:
				continue;
			}

			if (result == false) //�̵��� �������� ��
				continue;

			break;
		}

		cout << endl;

		if (game.checkWin() == true) //2048�� ���� ��
		{
			cout << "Win!!" << endl;
			break;
		}
	}

	return 0;
}