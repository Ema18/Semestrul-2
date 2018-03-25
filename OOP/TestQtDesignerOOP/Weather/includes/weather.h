#ifndef WEATHER_H
#define WEATHER_H

#include <QtWidgets/QWidget>
#include "ui_weather.h"
#include "controller.h"

class Weather : public QWidget
{
	Q_OBJECT

private:
	Controller contro;

public:
	Weather(Controller contro, QWidget *parent = 0);
	~Weather();

	public slots:
	void populate_list(vector<Day> d);
	void filter_list();
	void show_list();
	void total_hours();

private:
	Ui::WeatherClass ui;
	void connect_signals();
};

#endif // WEATHER_H
