/********************************************************************************
** Form generated from reading UI file 'pageRank.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGERANK_H
#define UI_PAGERANK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pageRank
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *buttonTeam;
    QPushButton *buttonPlayer;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QPushButton *buttonShoot;
    QPushButton *buttonFalut;
    QPushButton *buttonScore;
    QPushButton *buttonVictory;
    QPushButton *buttonBackboard;
    QPushButton *buttonThree;
    QPushButton *buttonPenalty;
    QPushButton *buttonAssisting;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *pageShoot;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *layoutShoot;
    QWidget *pageThree;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *layoutThree;
    QWidget *pagePenalty;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *layoutPenalty;
    QWidget *pageBackboard;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *layoutBackboard;
    QWidget *pageAssisting;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *layoutAssisting;
    QWidget *pageFalut;
    QVBoxLayout *verticalLayout_7;
    QGridLayout *layoutFalut;
    QWidget *pageScore;
    QVBoxLayout *verticalLayout_8;
    QGridLayout *layoutScore;
    QWidget *pageVictory;
    QVBoxLayout *verticalLayout_9;
    QGridLayout *layoutVictory;

    void setupUi(QWidget *pageRank)
    {
        if (pageRank->objectName().isEmpty())
            pageRank->setObjectName(QStringLiteral("pageRank"));
        pageRank->resize(600, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pageRank->sizePolicy().hasHeightForWidth());
        pageRank->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(pageRank);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        buttonTeam = new QPushButton(pageRank);
        buttonTeam->setObjectName(QStringLiteral("buttonTeam"));
        buttonTeam->setMinimumSize(QSize(100, 0));

        horizontalLayout_5->addWidget(buttonTeam);

        buttonPlayer = new QPushButton(pageRank);
        buttonPlayer->setObjectName(QStringLiteral("buttonPlayer"));
        buttonPlayer->setMinimumSize(QSize(100, 0));

        horizontalLayout_5->addWidget(buttonPlayer);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_5);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonShoot = new QPushButton(pageRank);
        buttonShoot->setObjectName(QStringLiteral("buttonShoot"));

        gridLayout->addWidget(buttonShoot, 0, 0, 1, 1);

        buttonFalut = new QPushButton(pageRank);
        buttonFalut->setObjectName(QStringLiteral("buttonFalut"));

        gridLayout->addWidget(buttonFalut, 1, 1, 1, 1);

        buttonScore = new QPushButton(pageRank);
        buttonScore->setObjectName(QStringLiteral("buttonScore"));

        gridLayout->addWidget(buttonScore, 1, 2, 1, 1);

        buttonVictory = new QPushButton(pageRank);
        buttonVictory->setObjectName(QStringLiteral("buttonVictory"));

        gridLayout->addWidget(buttonVictory, 1, 3, 1, 1);

        buttonBackboard = new QPushButton(pageRank);
        buttonBackboard->setObjectName(QStringLiteral("buttonBackboard"));

        gridLayout->addWidget(buttonBackboard, 0, 3, 1, 1);

        buttonThree = new QPushButton(pageRank);
        buttonThree->setObjectName(QStringLiteral("buttonThree"));

        gridLayout->addWidget(buttonThree, 0, 1, 1, 1);

        buttonPenalty = new QPushButton(pageRank);
        buttonPenalty->setObjectName(QStringLiteral("buttonPenalty"));

        gridLayout->addWidget(buttonPenalty, 0, 2, 1, 1);

        buttonAssisting = new QPushButton(pageRank);
        buttonAssisting->setObjectName(QStringLiteral("buttonAssisting"));

        gridLayout->addWidget(buttonAssisting, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        scrollArea = new QScrollArea(pageRank);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 563, 1500));
        scrollAreaWidgetContents->setMinimumSize(QSize(500, 1500));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        stackedWidget = new QStackedWidget(scrollAreaWidgetContents);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        pageShoot = new QWidget();
        pageShoot->setObjectName(QStringLiteral("pageShoot"));
        horizontalLayout_2 = new QHBoxLayout(pageShoot);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        layoutShoot = new QGridLayout();
        layoutShoot->setObjectName(QStringLiteral("layoutShoot"));

        horizontalLayout_2->addLayout(layoutShoot);

        stackedWidget->addWidget(pageShoot);
        pageThree = new QWidget();
        pageThree->setObjectName(QStringLiteral("pageThree"));
        verticalLayout_3 = new QVBoxLayout(pageThree);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        layoutThree = new QGridLayout();
        layoutThree->setObjectName(QStringLiteral("layoutThree"));

        verticalLayout_3->addLayout(layoutThree);

        stackedWidget->addWidget(pageThree);
        pagePenalty = new QWidget();
        pagePenalty->setObjectName(QStringLiteral("pagePenalty"));
        verticalLayout_4 = new QVBoxLayout(pagePenalty);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        layoutPenalty = new QGridLayout();
        layoutPenalty->setObjectName(QStringLiteral("layoutPenalty"));

        verticalLayout_4->addLayout(layoutPenalty);

        stackedWidget->addWidget(pagePenalty);
        pageBackboard = new QWidget();
        pageBackboard->setObjectName(QStringLiteral("pageBackboard"));
        verticalLayout_5 = new QVBoxLayout(pageBackboard);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        layoutBackboard = new QGridLayout();
        layoutBackboard->setObjectName(QStringLiteral("layoutBackboard"));

        verticalLayout_5->addLayout(layoutBackboard);

        stackedWidget->addWidget(pageBackboard);
        pageAssisting = new QWidget();
        pageAssisting->setObjectName(QStringLiteral("pageAssisting"));
        verticalLayout_6 = new QVBoxLayout(pageAssisting);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        layoutAssisting = new QGridLayout();
        layoutAssisting->setObjectName(QStringLiteral("layoutAssisting"));

        verticalLayout_6->addLayout(layoutAssisting);

        stackedWidget->addWidget(pageAssisting);
        pageFalut = new QWidget();
        pageFalut->setObjectName(QStringLiteral("pageFalut"));
        verticalLayout_7 = new QVBoxLayout(pageFalut);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        layoutFalut = new QGridLayout();
        layoutFalut->setObjectName(QStringLiteral("layoutFalut"));

        verticalLayout_7->addLayout(layoutFalut);

        stackedWidget->addWidget(pageFalut);
        pageScore = new QWidget();
        pageScore->setObjectName(QStringLiteral("pageScore"));
        verticalLayout_8 = new QVBoxLayout(pageScore);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        layoutScore = new QGridLayout();
        layoutScore->setObjectName(QStringLiteral("layoutScore"));

        verticalLayout_8->addLayout(layoutScore);

        stackedWidget->addWidget(pageScore);
        pageVictory = new QWidget();
        pageVictory->setObjectName(QStringLiteral("pageVictory"));
        verticalLayout_9 = new QVBoxLayout(pageVictory);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        layoutVictory = new QGridLayout();
        layoutVictory->setObjectName(QStringLiteral("layoutVictory"));

        verticalLayout_9->addLayout(layoutVictory);

        stackedWidget->addWidget(pageVictory);

        verticalLayout_2->addWidget(stackedWidget);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(2, 10);

        retranslateUi(pageRank);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(pageRank);
    } // setupUi

    void retranslateUi(QWidget *pageRank)
    {
        pageRank->setWindowTitle(QApplication::translate("pageRank", "Form", nullptr));
        buttonTeam->setText(QApplication::translate("pageRank", "\347\220\203\351\230\237", nullptr));
        buttonPlayer->setText(QApplication::translate("pageRank", "\347\220\203\345\221\230", nullptr));
        buttonShoot->setText(QApplication::translate("pageRank", "\346\212\225\347\257\256", nullptr));
        buttonFalut->setText(QApplication::translate("pageRank", "\345\244\261\350\257\257/\347\212\257\350\247\204", nullptr));
        buttonScore->setText(QApplication::translate("pageRank", "\345\210\206\346\225\260", nullptr));
        buttonVictory->setText(QApplication::translate("pageRank", "\350\203\234\350\264\237", nullptr));
        buttonBackboard->setText(QApplication::translate("pageRank", "\347\257\256\346\235\277", nullptr));
        buttonThree->setText(QApplication::translate("pageRank", "\344\270\211\345\210\206", nullptr));
        buttonPenalty->setText(QApplication::translate("pageRank", "\347\275\232\347\220\203", nullptr));
        buttonAssisting->setText(QApplication::translate("pageRank", "\345\212\251\346\224\273/\346\212\242\346\226\255/\347\233\226\345\270\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pageRank: public Ui_pageRank {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGERANK_H
