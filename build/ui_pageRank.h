/********************************************************************************
** Form generated from reading UI file 'pageRank.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGERANK_H
#define UI_PAGERANK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
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
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *boxSeason;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayoutTable;

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

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(pageRank);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(70, 0));
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        boxSeason = new QSpinBox(pageRank);
        boxSeason->setObjectName(QStringLiteral("boxSeason"));
        boxSeason->setMinimumSize(QSize(100, 0));
        boxSeason->setMinimum(2012);
        boxSeason->setMaximum(2017);
        boxSeason->setValue(2017);

        horizontalLayout->addWidget(boxSeason);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        gridLayoutTable = new QGridLayout();
        gridLayoutTable->setObjectName(QStringLiteral("gridLayoutTable"));

        verticalLayout->addLayout(gridLayoutTable);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 10);

        retranslateUi(pageRank);

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
        label->setText(QApplication::translate("pageRank", "<html><head/><body><p><span style=\" font-size:12pt;\">\350\265\233\345\255\243\357\274\232</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pageRank: public Ui_pageRank {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGERANK_H
