#include "weather.h"
#include <QtWidgets\qmessagebox.h>

Weather::Weather(Controller contro, QWidget *parent)
	: contro{ contro }, QWidget(parent)
{
	ui.setupUi(this);

	connect_signals();
	populate_list(contro.get_all());
}

void Weather::populate_list(vector<Day> d)
{
	this->ui.listWidget->clear();
	vector<Day> days = d;

	for (int i = 0; i < days.size(); i++)
	{
		Day d = days[i];
		QString line = QString::number(d.start) + "-" + QString::number(d.end) + " " + QString::number(d.temperature) + " " + QString::fromStdString(d.description);
		this->ui.listWidget->addItem(line);
	}
}

void Weather::connect_signals()
{
	connect(this->ui.filterButton, &QPushButton::clicked, this, &Weather::filter_list);
	connect(this->ui.list, &QPushButton::clicked, this, &Weather::show_list);
	connect(this->ui.computeTotalButton, &QPushButton::clicked, this, &Weather::total_hours);
}

void Weather::filter_list()
{
	QString value = this->ui.filterLineEdit->text();
	vector<Day> d = contro.filter_repo(value.toStdString());
	populate_list(d);
}

void Weather::show_list()
{
	populate_list(contro.get_all());
}

void Weather::total_hours()
{
	QString description = this->ui.totalLineEdit->text();
	int nr = contro.count_hours(description.toStdString());
	QString message = description + " total hours: " + QString::number(nr);
	QMessageBox *count = new QMessageBox;
	count->setText(message);
	count->show();
}

Weather::~Weather()
{

}