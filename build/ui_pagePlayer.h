/********************************************************************************
** Form generated from reading UI file 'pagePlayer.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEPLAYER_H
#define UI_PAGEPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pagePlayer
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_10;
    QLabel *labelPlayerPix;
    QLabel *labelPlayerName;
    QGridLayout *gridLayout;
    QPushButton *buttonAssisting;
    QPushButton *buttonFalut;
    QPushButton *buttonScore;
    QPushButton *buttonVictory;
    QPushButton *buttonShoot;
    QPushButton *buttonThree;
    QPushButton *buttonPenalty;
    QPushButton *buttonBackboard;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_11;
    QStackedWidget *stackedWidget;
    QWidget *pageShoot;
    QVBoxLayout *verticalLayout_2;
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

    void setupUi(QWidget *pagePlayer)
    {
        if (pagePlayer->objectName().isEmpty())
            pagePlayer->setObjectName(QStringLiteral("pagePlayer"));
        pagePlayer->resize(600, 600);
        verticalLayout = new QVBoxLayout(pagePlayer);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        labelPlayerPix = new QLabel(pagePlayer);
        labelPlayerPix->setObjectName(QStringLiteral("labelPlayerPix"));
        labelPlayerPix->setMinimumSize(QSize(220, 275));
        labelPlayerPix->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(labelPlayerPix);

        labelPlayerName = new QLabel(pagePlayer);
        labelPlayerName->setObjectName(QStringLiteral("labelPlayerName"));
        labelPlayerName->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(labelPlayerName);


        horizontalLayout->addLayout(verticalLayout_10);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonAssisting = new QPushButton(pagePlayer);
        buttonAssisting->setObjectName(QStringLiteral("buttonAssisting"));

        gridLayout->addWidget(buttonAssisting, 1, 0, 1, 1);

        buttonFalut = new QPushButton(pagePlayer);
        buttonFalut->setObjectName(QStringLiteral("buttonFalut"));

        gridLayout->addWidget(buttonFalut, 1, 1, 1, 1);

        buttonScore = new QPushButton(pagePlayer);
        buttonScore->setObjectName(QStringLiteral("buttonScore"));

        gridLayout->addWidget(buttonScore, 1, 2, 1, 1);

        buttonVictory = new QPushButton(pagePlayer);
        buttonVictory->setObjectName(QStringLiteral("buttonVictory"));

        gridLayout->addWidget(buttonVictory, 1, 3, 1, 1);

        buttonShoot = new QPushButton(pagePlayer);
        buttonShoot->setObjectName(QStringLiteral("buttonShoot"));

        gridLayout->addWidget(buttonShoot, 0, 0, 1, 1);

        buttonThree = new QPushButton(pagePlayer);
        buttonThree->setObjectName(QStringLiteral("buttonThree"));

        gridLayout->addWidget(buttonThree, 0, 1, 1, 1);

        buttonPenalty = new QPushButton(pagePlayer);
        buttonPenalty->setObjectName(QStringLiteral("buttonPenalty"));

        gridLayout->addWidget(buttonPenalty, 0, 2, 1, 1);

        buttonBackboard = new QPushButton(pagePlayer);
        buttonBackboard->setObjectName(QStringLiteral("buttonBackboard"));

        gridLayout->addWidget(buttonBackboard, 0, 3, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        verticalLayout->addLayout(horizontalLayout);

        scrollArea = new QScrollArea(pagePlayer);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 580, 69));
        verticalLayout_11 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        stackedWidget = new QStackedWidget(scrollAreaWidgetContents);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        pageShoot = new QWidget();
        pageShoot->setObjectName(QStringLiteral("pageShoot"));
        verticalLayout_2 = new QVBoxLayout(pageShoot);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        layoutShoot = new QGridLayout();
        layoutShoot->setObjectName(QStringLiteral("layoutShoot"));

        verticalLayout_2->addLayout(layoutShoot);

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

        verticalLayout_11->addWidget(stackedWidget);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        verticalLayout->setStretch(0, 1);

        retranslateUi(pagePlayer);

        QMetaObject::connectSlotsByName(pagePlayer);
    } // setupUi

    void retranslateUi(QWidget *pagePlayer)
    {
        pagePlayer->setWindowTitle(QApplication::translate("pagePlayer", "Form", nullptr));
        labelPlayerPix->setText(QApplication::translate("pagePlayer", "\347\220\203\345\221\230\345\233\276\347\211\207", nullptr));
        labelPlayerName->setText(QApplication::translate("pagePlayer", "\347\220\203\345\221\230\345\220\215\345\255\227", nullptr));
        buttonAssisting->setText(QApplication::translate("pagePlayer", "\345\212\251\346\224\273/\346\212\242\346\226\255/\347\233\226\345\270\275", nullptr));
        buttonFalut->setText(QApplication::translate("pagePlayer", "\345\244\261\350\257\257/\347\212\257\350\247\204", nullptr));
        buttonScore->setText(QApplication::translate("pagePlayer", "\345\210\206\346\225\260", nullptr));
        buttonVictory->setText(QApplication::translate("pagePlayer", "\350\203\234\350\264\237", nullptr));
        buttonShoot->setText(QApplication::translate("pagePlayer", "\346\212\225\347\257\256", nullptr));
        buttonThree->setText(QApplication::translate("pagePlayer", "\344\270\211\345\210\206", nullptr));
        buttonPenalty->setText(QApplication::translate("pagePlayer", "\347\275\232\347\220\203", nullptr));
        buttonBackboard->setText(QApplication::translate("pagePlayer", "\347\257\256\346\235\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pagePlayer: public Ui_pagePlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEPLAYER_H
