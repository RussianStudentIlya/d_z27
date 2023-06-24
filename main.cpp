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



		cout << " Выберете режим работы программы: w - запись, r - чтение, q - выход " << endl;
		cin >> oper;
		cout << endl;

		if (oper == 'q')
			break;

		switch (oper)
		{
		case 'w':
			SetConsoleCP(1251);
			cout << "От: ";
			cin >> from;
			cout << "Кому: ";
			cin >> to;
			cout << "Текст сообщения: ";
			cin >> mess;
			cout << endl;
			if (log.setLog(from, to, mess))
				cout << "Запись добавлена!" << endl;
			SetConsoleCP(866);
			cout << " ----------- " << endl;
			break;
		case 'r':
			cout << "Чтение данных файла " << log.getFileName() << ": " << endl;
			log.getLog();
			break;
		}
	}

	return 0;
}