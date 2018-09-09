/********************************************************************************
** Form generated from reading UI file 'pageStart.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGESTART_H
#define UI_PAGESTART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pageStart
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonRank;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonData;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *pageStart)
    {
        if (pageStart->objectName().isEmpty())
            pageStart->setObjectName(QStringLiteral("pageStart"));
        pageStart->resize(600, 600);
        verticalLayout = new QVBoxLayout(pageStart);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        buttonRank = new QPushButton(pageStart);
        buttonRank->setObjectName(QStringLiteral("buttonRank"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonRank->sizePolicy().hasHeightForWidth());
        buttonRank->setSizePolicy(sizePolicy);
        buttonRank->setMinimumSize(QSize(200, 200));
        buttonRank->setStyleSheet(QStringLiteral("font: 25 48pt \"Microsoft YaHei\";"));

        horizontalLayout->addWidget(buttonRank);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonData = new QPushButton(pageStart);
        buttonData->setObjectName(QStringLiteral("buttonData"));
        sizePolicy.setHeightForWidth(buttonData->sizePolicy().hasHeightForWidth());
        buttonData->setSizePolicy(sizePolicy);
        buttonData->setMinimumSize(QSize(200, 200));
        buttonData->setStyleSheet(QLatin1String("font: 72pt \"Arial\";\n"
"font: 25 48pt \"Microsoft YaHei\";"));

        horizontalLayout->addWidget(buttonData);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(pageStart);

        QMetaObject::connectSlotsByName(pageStart);
    } // setupUi

    void retranslateUi(QWidget *pageStart)
    {
        pageStart->setWindowTitle(QApplication::translate("pageStart", "Form", nullptr));
        buttonRank->setText(QApplication::translate("pageStart", "\346\216\222\350\241\214", nullptr));
        buttonData->setText(QApplication::translate("pageStart", "\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pageStart: public Ui_pageStart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGESTART_H
