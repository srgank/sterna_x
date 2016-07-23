#include "xx.h"
#include <QIODevice>
#include <QFile>




Singleton* Singleton::_instance = 0;

Singleton* Singleton::Instance() 
{
	if (_instance == 0) 
	{
		_instance = new Singleton;
	}
	return _instance;
}


