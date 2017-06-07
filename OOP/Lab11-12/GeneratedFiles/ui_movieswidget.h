/********************************************************************************
** Form generated from reading UI file 'movieswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVIESWIDGET_H
#define UI_MOVIESWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_movieswidget
{
public:
    QTableView *moviesTableView;

    void setupUi(QWidget *movieswidget)
    {
        if (movieswidget->objectName().isEmpty())
            movieswidget->setObjectName(QStringLiteral("movieswidget"));
        movieswidget->resize(400, 300);
        moviesTableView = new QTableView(movieswidget);
        moviesTableView->setObjectName(QStringLiteral("moviesTableView"));
        moviesTableView->setGeometry(QRect(10, 10, 381, 281));

        retranslateUi(movieswidget);

        QMetaObject::connectSlotsByName(movieswidget);
    } // setupUi

    void retranslateUi(QWidget *movieswidget)
    {
        movieswidget->setWindowTitle(QApplication::translate("movieswidget", "movieswidget", 0));
    } // retranslateUi

};

namespace Ui {
    class movieswidget: public Ui_movieswidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVIESWIDGET_H
