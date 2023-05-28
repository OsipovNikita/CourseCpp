#include <string>
#include "Logger.h"

int main()
{
	string file = "log.txt";
	//Logger * p = new FileLogger(file);
	Logger* p = new ConsoleLogger();
	string mes = "message";
	p->log(mes);

	delete p;
	return 0;
}
