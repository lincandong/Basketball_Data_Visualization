/********************************************************************************
** Form generated from reading UI file 'pagePlayer.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEPLAYER_H
#define UI_PAGEPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pagePlayer
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelPlayerPix;
    QLabel *labelPlayerName;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QPushButton *buttonShoot;
    QPushButton *buttonThree;
    QPushButton *buttonBackboard;
    QPushButton *buttonPenalty;
    QPushButton *buttonTotal;
    QPushButton *buttonAssisting;
    QPushButton *buttonFalut;
    QPushButton *buttonScore;
    QPushButton *buttonVictory;
    QGridLayout *gridLayoutTable;

    void setupUi(QWidget *pagePlayer)
    {
        if (pagePlayer->objectName().isEmpty())
            pagePlayer->setObjectName(QStringLiteral("pagePlayer"));
        pagePlayer->resize(600, 600);
        verticalLayout = new QVBoxLayout(pagePlayer);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        labelPlayerPix = new QLabel(pagePlayer);
        labelPlayerPix->setObjectName(QStringLiteral("labelPlayerPix"));

        horizontalLayout->addWidget(labelPlayerPix);

        labelPlayerName = new QLabel(pagePlayer);
        labelPlayerName->setObjectName(QStringLiteral("labelPlayerName"));

        horizontalLayout->addWidget(labelPlayerName);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonShoot = new QPushButton(pagePlayer);
        buttonShoot->setObjectName(QStringLiteral("buttonShoot"));

        gridLayout->addWidget(buttonShoot, 0, 1, 1, 1);

        buttonThree = new QPushButton(pagePlayer);
        buttonThree->setObjectName(QStringLiteral("buttonThree"));

        gridLayout->addWidget(buttonThree, 0, 2, 1, 1);

        buttonBackboard = new QPushButton(pagePlayer);
        buttonBackboard->setObjectName(QStringLiteral("buttonBackboard"));

        gridLayout->addWidget(buttonBackboard, 0, 4, 1, 1);

        buttonPenalty = new QPushButton(pagePlayer);
        buttonPenalty->setObjectName(QStringLiteral("buttonPenalty"));

        gridLayout->addWidget(buttonPenalty, 0, 3, 1, 1);

        buttonTotal = new QPushButton(pagePlayer);
        buttonTotal->setObjectName(QStringLiteral("buttonTotal"));

        gridLayout->addWidget(buttonTotal, 0, 0, 1, 1);

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


        verticalLayout->addLayout(gridLayout);

        gridLayoutTable = new QGridLayout();
        gridLayoutTable->setObjectName(QStringLiteral("gridLayoutTable"));

        verticalLayout->addLayout(gridLayoutTable);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(2, 10);

        retranslateUi(pagePlayer);

        QMetaObject::connectSlotsByName(pagePlayer);
    } // setupUi

    void retranslateUi(QWidget *pagePlayer)
    {
        pagePlayer->setWindowTitle(QApplication::translate("pagePlayer", "Form", nullptr));
        labelPlayerPix->setText(QApplication::translate("pagePlayer", "\347\220\203\345\221\230\345\233\276\347\211\207", nullptr));
        labelPlayerName->setText(QApplication::translate("pagePlayer", "\347\220\203\345\221\230\345\220\215\345\255\227", nullptr));
        buttonShoot->setText(QApplication::translate("pagePlayer", "\346\212\225\347\257\256", nullptr));
        buttonThree->setText(QApplication::translate("pagePlayer", "\344\270\211\345\210\206", nullptr));
        buttonBackboard->setText(QApplication::translate("pagePlayer", "\347\257\256\346\235\277", nullptr));
        buttonPenalty->setText(QApplication::translate("pagePlayer", "\347\275\232\347\220\203", nullptr));
        buttonTotal->setText(QApplication::translate("pagePlayer", "\346\200\273\350\247\210", nullptr));
        buttonAssisting->setText(QApplication::translate("pagePlayer", "\345\212\251\346\224\273/\346\212\242\346\226\255/\347\233\226\345\270\275", nullptr));
        buttonFalut->setText(QApplication::translate("pagePlayer", "\345\244\261\350\257\257/\347\212\257\350\247\204", nullptr));
        buttonScore->setText(QApplication::translate("pagePlayer", "\345\210\206\346\225\260", nullptr));
        buttonVictory->setText(QApplication::translate("pagePlayer", "\350\203\234\350\264\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pagePlayer: public Ui_pagePlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEPLAYER_H
