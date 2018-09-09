/********************************************************************************
** Form generated from reading UI file 'pageData.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEDATA_H
#define UI_PAGEDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pageData
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_8;
    QLabel *label;
    QLabel *label_2;
    QGridLayout *gridLayoutTeam;

    void setupUi(QWidget *pageData)
    {
        if (pageData->objectName().isEmpty())
            pageData->setObjectName(QStringLiteral("pageData"));
        pageData->resize(600, 600);
        verticalLayout = new QVBoxLayout(pageData);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_5 = new QLabel(pageData);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(10, 18));
        label_5->setMaximumSize(QSize(16777215, 18));
        label_5->setFrameShape(QFrame::WinPanel);
        label_5->setFrameShadow(QFrame::Raised);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 1, 2, 1, 1);

        label_4 = new QLabel(pageData);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(10, 18));
        label_4->setMaximumSize(QSize(16777215, 18));
        label_4->setFrameShape(QFrame::WinPanel);
        label_4->setFrameShadow(QFrame::Raised);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 1, 1, 1, 1);

        label_7 = new QLabel(pageData);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(10, 18));
        label_7->setMaximumSize(QSize(16777215, 18));
        label_7->setFrameShape(QFrame::WinPanel);
        label_7->setFrameShadow(QFrame::Raised);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 1, 4, 1, 1);

        label_6 = new QLabel(pageData);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(10, 18));
        label_6->setMaximumSize(QSize(16777215, 18));
        label_6->setFrameShape(QFrame::WinPanel);
        label_6->setFrameShadow(QFrame::Raised);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 1, 3, 1, 1);

        label_3 = new QLabel(pageData);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(10, 18));
        label_3->setMaximumSize(QSize(16777215, 18));
        label_3->setFrameShape(QFrame::WinPanel);
        label_3->setFrameShadow(QFrame::Raised);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_8 = new QLabel(pageData);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(10, 18));
        label_8->setMaximumSize(QSize(16777215, 18));
        label_8->setFrameShape(QFrame::WinPanel);
        label_8->setFrameShadow(QFrame::Raised);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 1, 5, 1, 1);

        label = new QLabel(pageData);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(30, 18));
        label->setMaximumSize(QSize(16777215, 18));
        label->setFrameShape(QFrame::WinPanel);
        label->setFrameShadow(QFrame::Raised);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 3);

        label_2 = new QLabel(pageData);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(30, 18));
        label_2->setMaximumSize(QSize(16777215, 18));
        label_2->setFrameShape(QFrame::WinPanel);
        label_2->setFrameShadow(QFrame::Raised);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 3, 1, 3);


        verticalLayout->addLayout(gridLayout);

        gridLayoutTeam = new QGridLayout();
        gridLayoutTeam->setObjectName(QStringLiteral("gridLayoutTeam"));

        verticalLayout->addLayout(gridLayoutTeam);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 16);

        retranslateUi(pageData);

        QMetaObject::connectSlotsByName(pageData);
    } // setupUi

    void retranslateUi(QWidget *pageData)
    {
        pageData->setWindowTitle(QApplication::translate("pageData", "Form", nullptr));
        label_5->setText(QApplication::translate("pageData", "\345\244\247\350\245\277\346\264\213\345\214\272", nullptr));
        label_4->setText(QApplication::translate("pageData", "\344\270\255\345\214\272", nullptr));
        label_7->setText(QApplication::translate("pageData", "\350\245\277\345\214\227\345\214\272", nullptr));
        label_6->setText(QApplication::translate("pageData", "\345\244\252\345\271\263\346\264\213\345\214\272", nullptr));
        label_3->setText(QApplication::translate("pageData", "\344\270\234\345\215\227\345\214\272", nullptr));
        label_8->setText(QApplication::translate("pageData", "\350\245\277\345\215\227\345\214\272", nullptr));
        label->setText(QApplication::translate("pageData", "\344\270\234\351\203\250", nullptr));
        label_2->setText(QApplication::translate("pageData", "\350\245\277\351\203\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pageData: public Ui_pageData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEDATA_H
