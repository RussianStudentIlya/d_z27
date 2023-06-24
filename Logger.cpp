#include "Logger.h"

Logger::Logger(const string& fileName):_fileName(fileName)
{
	_fs.open(_fileName, fstream::in | fstream::out | fstream::app); // открывает или создает файл для чтения и записи данных

	if (_fs.is_open()) // проверка что файл открывается
		this->_status = true;
}

Logger::~Logger()
{
	_fs.close(); /// закрываем поток
}

bool Logger::setLog(const string& from, const string& to, const string& messag)
{
	string sendText = "от:_" + from + "_кому:_" + to + "_сообщение:_" + messag;

	if (this->_status == true)
	{
		_m.lock();
		_fs << sendText;
		_fs << endl;
		_m.unlock();
		return true;
	}

	return false;
}

void Logger::getLog()
{
	string text = " ";

	if (this->_status == true)
	{
		_m.lock();
		while (!_fs.eof())
		{
			_fs >> text;
			cout << text << endl;
		}
		_m.unlock();
	}
}

const string Logger::getFileName() const
{
	return _fileName;
}
