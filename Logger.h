#pragma once
#include <iostream>
#include <fstream>
#include <shared_mutex>
#include <string>
using namespace std;

class Logger
{
private:
	fstream _fs;
	string _fileName;
	shared_mutex _shMutex;
	bool _status = false;
	string _from;
	string _to;
	string _messag;
public:
	Logger(const string& fileName);
	~Logger();

	bool setLog(const string &from, const string& to, const string& messag);
	void getLog();
	const string getFileName() const;
};

