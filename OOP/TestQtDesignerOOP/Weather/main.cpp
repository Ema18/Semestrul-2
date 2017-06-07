#include "weather.h"
#include <QtWidgets/QApplication>
#include "FileRepository.h"
#include "controller.h"
#include "Tests.h"

int main(int argc, char *argv[])
{
	Test::run_all_tests();
	QApplication a(argc, argv);
	FileRepository repo("data.txt");
	Controller contro{ repo };

	Weather w(contro);
	w.show();
	return a.exec();
}