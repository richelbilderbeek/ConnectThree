/********************************************************************************
** Form generated from reading UI file 'qtconnectthreegamedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCONNECTTHREEGAMEDIALOG_H
#define UI_QTCONNECTTHREEGAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtConnectThreeGameDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_player2;
    QPushButton *button_quit;
    QLabel *label_player3;
    QWidget *widget;
    QLabel *label_player1;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *QtConnectThreeGameDialog)
    {
        if (QtConnectThreeGameDialog->objectName().isEmpty())
            QtConnectThreeGameDialog->setObjectName(QStringLiteral("QtConnectThreeGameDialog"));
        QtConnectThreeGameDialog->resize(724, 486);
        gridLayout = new QGridLayout(QtConnectThreeGameDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_player2 = new QLabel(QtConnectThreeGameDialog);
        label_player2->setObjectName(QStringLiteral("label_player2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_player2->sizePolicy().hasHeightForWidth());
        label_player2->setSizePolicy(sizePolicy);
        label_player2->setPixmap(QPixmap(QString::fromUtf8(":/images/ConnectThreePlayer2Grey.png")));
        label_player2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_player2, 1, 1, 1, 1);

        button_quit = new QPushButton(QtConnectThreeGameDialog);
        button_quit->setObjectName(QStringLiteral("button_quit"));
        sizePolicy.setHeightForWidth(button_quit->sizePolicy().hasHeightForWidth());
        button_quit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(button_quit, 1, 4, 1, 1);

        label_player3 = new QLabel(QtConnectThreeGameDialog);
        label_player3->setObjectName(QStringLiteral("label_player3"));
        sizePolicy.setHeightForWidth(label_player3->sizePolicy().hasHeightForWidth());
        label_player3->setSizePolicy(sizePolicy);
        label_player3->setPixmap(QPixmap(QString::fromUtf8(":/images/ConnectThreePlayer3Grey.png")));
        label_player3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_player3, 1, 2, 1, 1);

        widget = new QWidget(QtConnectThreeGameDialog);
        widget->setObjectName(QStringLiteral("widget"));

        gridLayout->addWidget(widget, 0, 0, 1, 6);

        label_player1 = new QLabel(QtConnectThreeGameDialog);
        label_player1->setObjectName(QStringLiteral("label_player1"));
        sizePolicy.setHeightForWidth(label_player1->sizePolicy().hasHeightForWidth());
        label_player1->setSizePolicy(sizePolicy);
        label_player1->setPixmap(QPixmap(QString::fromUtf8(":/images/ConnectThreePlayer1.png")));
        label_player1->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_player1, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 3, 1, 1);


        retranslateUi(QtConnectThreeGameDialog);

        QMetaObject::connectSlotsByName(QtConnectThreeGameDialog);
    } // setupUi

    void retranslateUi(QDialog *QtConnectThreeGameDialog)
    {
        QtConnectThreeGameDialog->setWindowTitle(QApplication::translate("QtConnectThreeGameDialog", "ConnectThree", 0));
        label_player2->setText(QString());
        button_quit->setText(QApplication::translate("QtConnectThreeGameDialog", "&Quit", 0));
        label_player3->setText(QString());
        label_player1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QtConnectThreeGameDialog: public Ui_QtConnectThreeGameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCONNECTTHREEGAMEDIALOG_H
