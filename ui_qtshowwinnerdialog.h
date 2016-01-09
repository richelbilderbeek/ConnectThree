/********************************************************************************
** Form generated from reading UI file 'qtshowwinnerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTSHOWWINNERDIALOG_H
#define UI_QTSHOWWINNERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QtShowWinnerDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_title;
    QLabel *label_image;
    QLabel *label_footer;

    void setupUi(QDialog *QtShowWinnerDialog)
    {
        if (QtShowWinnerDialog->objectName().isEmpty())
            QtShowWinnerDialog->setObjectName(QStringLiteral("QtShowWinnerDialog"));
        QtShowWinnerDialog->resize(116, 144);
        QFont font;
        font.setFamily(QStringLiteral("Courier New"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        QtShowWinnerDialog->setFont(font);
        verticalLayout = new QVBoxLayout(QtShowWinnerDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_title = new QLabel(QtShowWinnerDialog);
        label_title->setObjectName(QStringLiteral("label_title"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_title->sizePolicy().hasHeightForWidth());
        label_title->setSizePolicy(sizePolicy);
        label_title->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_title);

        label_image = new QLabel(QtShowWinnerDialog);
        label_image->setObjectName(QStringLiteral("label_image"));
        sizePolicy.setHeightForWidth(label_image->sizePolicy().hasHeightForWidth());
        label_image->setSizePolicy(sizePolicy);
        label_image->setPixmap(QPixmap(QString::fromUtf8(":/images/ConnectThreePlayer1.png")));
        label_image->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_image);

        label_footer = new QLabel(QtShowWinnerDialog);
        label_footer->setObjectName(QStringLiteral("label_footer"));
        sizePolicy.setHeightForWidth(label_footer->sizePolicy().hasHeightForWidth());
        label_footer->setSizePolicy(sizePolicy);
        label_footer->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_footer);


        retranslateUi(QtShowWinnerDialog);

        QMetaObject::connectSlotsByName(QtShowWinnerDialog);
    } // setupUi

    void retranslateUi(QDialog *QtShowWinnerDialog)
    {
        QtShowWinnerDialog->setWindowTitle(QApplication::translate("QtShowWinnerDialog", "Winner", 0));
        label_title->setText(QApplication::translate("QtShowWinnerDialog", "Winner", 0));
        label_image->setText(QString());
        label_footer->setText(QApplication::translate("QtShowWinnerDialog", "Winner", 0));
    } // retranslateUi

};

namespace Ui {
    class QtShowWinnerDialog: public Ui_QtShowWinnerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSHOWWINNERDIALOG_H
