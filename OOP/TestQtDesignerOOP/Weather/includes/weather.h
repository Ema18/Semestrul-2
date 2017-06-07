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

















/*
#ifndef TOPSCORER_H
#define TOPSCORER_H

#include <QtWidgets/QWidget>
#include "ui_topscorer.h"
#include "controller.h"

class TopScorer : public QWidget
{
	Q_OBJECT
private:
	Controller contro;

public:
	TopScorer(Controller contro, QWidget *parent = 0);
	~TopScorer();

	public slots:
	void populate_list();
	void sort_list();
	void italic();
	void show_players();

private:
	Ui::TopScorerClass ui;
	void connect_signals();
};

#endif // TOPSCORER_H
*/