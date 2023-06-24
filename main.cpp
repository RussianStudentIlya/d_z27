#include <iostream>
#include <Windows.h>
#include "Logger.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	while (true)
	{
		Logger log = Logger("Log.txt");
		char oper;
		string from = " ", to = " ", mess = " ";



		cout << " �������� ����� ������ ���������: w - ������, r - ������, q - ����� " << endl;
		cin >> oper;
		cout << endl;

		if (oper == 'q')
			break;

		switch (oper)
		{
		case 'w':
			SetConsoleCP(1251);
			cout << "��: ";
			cin >> from;
			cout << "����: ";
			cin >> to;
			cout << "����� ���������: ";
			cin >> mess;
			cout << endl;
			if (log.setLog(from, to, mess))
				cout << "������ ���������!" << endl;
			SetConsoleCP(866);
			cout << " ----------- " << endl;
			break;
		case 'r':
			cout << "������ ������ ����� " << log.getFileName() << ": " << endl;
			log.getLog();
			break;
		}
	}

	return 0;
}