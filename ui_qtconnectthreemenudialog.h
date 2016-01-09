/********************************************************************************
** Form generated from reading UI file 'qtconnectthreemenudialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCONNECTTHREEMENUDIALOG_H
#define UI_QTCONNECTTHREEMENUDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtConnectThreeMenuDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *button_start;
    QPushButton *button_about;
    QPushButton *button_quit;

    void setupUi(QDialog *QtConnectThreeMenuDialog)
    {
        if (QtConnectThreeMenuDialog->objectName().isEmpty())
            QtConnectThreeMenuDialog->setObjectName(QStringLiteral("QtConnectThreeMenuDialog"));
        QtConnectThreeMenuDialog->resize(267, 171);
        QFont font;
        font.setFamily(QStringLiteral("Verdana"));
        font.setPointSize(14);
        QtConnectThreeMenuDialog->setFont(font);
        QtConnectThreeMenuDialog->setStyleSheet(QLatin1String("QDialog { \n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0  #808080, stop: 1 #ffffff);\n"
"}\n"
"QPushButton { background-color: rgb(255, 255, 255);  }\n"
"QPushButton { color: rgb(0,0,0); }\n"
"QPushButton { font: 32px, \"monospace\" }"));
        horizontalLayout = new QHBoxLayout(QtConnectThreeMenuDialog);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget = new QWidget(QtConnectThreeMenuDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(120, 16777215));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        button_start = new QPushButton(widget);
        button_start->setObjectName(QStringLiteral("button_start"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(button_start->sizePolicy().hasHeightForWidth());
        button_start->setSizePolicy(sizePolicy);
        button_start->setFlat(true);

        verticalLayout->addWidget(button_start);

        button_about = new QPushButton(widget);
        button_about->setObjectName(QStringLiteral("button_about"));
        sizePolicy.setHeightForWidth(button_about->sizePolicy().hasHeightForWidth());
        button_about->setSizePolicy(sizePolicy);
        button_about->setFlat(true);

        verticalLayout->addWidget(button_about);

        button_quit = new QPushButton(widget);
        button_quit->setObjectName(QStringLiteral("button_quit"));
        sizePolicy.setHeightForWidth(button_quit->sizePolicy().hasHeightForWidth());
        button_quit->setSizePolicy(sizePolicy);
        button_quit->setFlat(true);

        verticalLayout->addWidget(button_quit);


        horizontalLayout->addWidget(widget);


        retranslateUi(QtConnectThreeMenuDialog);

        QMetaObject::connectSlotsByName(QtConnectThreeMenuDialog);
    } // setupUi

    void retranslateUi(QDialog *QtConnectThreeMenuDialog)
    {
        QtConnectThreeMenuDialog->setWindowTitle(QApplication::translate("QtConnectThreeMenuDialog", "ConnectThree", 0));
        button_start->setText(QApplication::translate("QtConnectThreeMenuDialog", "&Start", 0));
        button_about->setText(QApplication::translate("QtConnectThreeMenuDialog", "&About", 0));
        button_quit->setText(QApplication::translate("QtConnectThreeMenuDialog", "&Quit", 0));
    } // retranslateUi

};

namespace Ui {
    class QtConnectThreeMenuDialog: public Ui_QtConnectThreeMenuDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCONNECTTHREEMENUDIALOG_H
