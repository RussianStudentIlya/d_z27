#include "Logger.h"

Logger::Logger(const string& fileName):_fileName(fileName)
{
	_fs.open(_fileName, fstream::in | fstream::out | fstream::app);

	if (_fs.is_open())
		this->_status = true;
}

Logger::~Logger()
{
	_fs.close();
}

bool Logger::setLog(const string& from, const string& to, const string& messag)
{
	string sendText = "от:_" + from + "_кому:_" + to + "_сообщение:_" + messag;

	if (this->_status == true)
	{
		_fs << sendText;
		_fs << endl;
		return true;
	}

	return false;
}

void Logger::getLog()
{
	string text = " ";

	if (this->_status == true)
	{
		while (!_fs.eof())
		{
			_fs >> text;
			cout << text << endl;
		}
	}
}

const string Logger::getFileName() const
{
	return _fileName;
}
