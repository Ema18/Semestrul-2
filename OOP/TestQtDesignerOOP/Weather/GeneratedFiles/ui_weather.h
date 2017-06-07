/********************************************************************************
** Form generated from reading UI file 'weather.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHER_H
#define UI_WEATHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeatherClass
{
public:
    QListWidget *listWidget;
    QPushButton *filterButton;
    QLineEdit *filterLineEdit;
    QPushButton *list;
    QPushButton *computeTotalButton;
    QLineEdit *totalLineEdit;

    void setupUi(QWidget *WeatherClass)
    {
        if (WeatherClass->objectName().isEmpty())
            WeatherClass->setObjectName(QStringLiteral("WeatherClass"));
        WeatherClass->resize(462, 400);
        listWidget = new QListWidget(WeatherClass);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(20, 20, 256, 261));
        filterButton = new QPushButton(WeatherClass);
        filterButton->setObjectName(QStringLiteral("filterButton"));
        filterButton->setGeometry(QRect(320, 30, 75, 23));
        filterLineEdit = new QLineEdit(WeatherClass);
        filterLineEdit->setObjectName(QStringLiteral("filterLineEdit"));
        filterLineEdit->setGeometry(QRect(300, 60, 113, 20));
        list = new QPushButton(WeatherClass);
        list->setObjectName(QStringLiteral("list"));
        list->setGeometry(QRect(320, 100, 75, 23));
        computeTotalButton = new QPushButton(WeatherClass);
        computeTotalButton->setObjectName(QStringLiteral("computeTotalButton"));
        computeTotalButton->setGeometry(QRect(310, 160, 91, 23));
        totalLineEdit = new QLineEdit(WeatherClass);
        totalLineEdit->setObjectName(QStringLiteral("totalLineEdit"));
        totalLineEdit->setGeometry(QRect(300, 190, 113, 20));

        retranslateUi(WeatherClass);

        QMetaObject::connectSlotsByName(WeatherClass);
    } // setupUi

    void retranslateUi(QWidget *WeatherClass)
    {
        WeatherClass->setWindowTitle(QApplication::translate("WeatherClass", "Weather", 0));
        filterButton->setText(QApplication::translate("WeatherClass", "filter", 0));
        filterLineEdit->setText(QString());
        list->setText(QApplication::translate("WeatherClass", "show list", 0));
        computeTotalButton->setText(QApplication::translate("WeatherClass", "compute total", 0));
    } // retranslateUi

};

namespace Ui {
    class WeatherClass: public Ui_WeatherClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHER_H
