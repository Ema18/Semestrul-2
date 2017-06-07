/********************************************************************************
** Form generated from reading UI file 'ui.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI_H
#define UI_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UIClass
{
public:

    void setupUi(QWidget *UIClass)
    {
        if (UIClass->objectName().isEmpty())
            UIClass->setObjectName(QStringLiteral("UIClass"));
        UIClass->resize(600, 400);

        retranslateUi(UIClass);

        QMetaObject::connectSlotsByName(UIClass);
    } // setupUi

    void retranslateUi(QWidget *UIClass)
    {
        UIClass->setWindowTitle(QApplication::translate("UIClass", "UI", 0));
    } // retranslateUi

};

namespace Ui {
    class UIClass: public Ui_UIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_H
