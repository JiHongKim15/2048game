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

	srand(time(NULL)); //랜덤

	game.Set();
	game.Connect(); //처음 세팅


	cout << "[Start]" << endl;

	while (1)
	{
		while (1)
		{
			randX = rand() % 4;
			randY = rand() % 4;
			R = game.Search(randX, randY); //랜덤으로 좌표를 찾음
			if (R == 1)
			{
				game.Input(randX, randY); //숫자 2를 랜덤으로 넣음
				break;
			}
		}
	
		if (game.checkLose() == true) //더 이상 만들어질 것이 없으면
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
				result = game.Up(); break; //위로 이동
			case 2:
				result = game.Down(); break; //아래로 이동
			case 3:
				result = game.Left(); break; //왼쪽으로 이동
			case 4:
				result = game.Right(); break; //오른쪽으로 이동
			case -1:
				cout << "[program exit]" << endl;
				return 0; //입력이 -1이면 함수 종료
			default:
				continue;
			}

			if (result == false) //이동을 실패했을 때
				continue;

			break;
		}

		cout << endl;

		if (game.checkWin() == true) //2048을 만들 때
		{
			cout << "Win!!" << endl;
			break;
		}
	}

	return 0;
}