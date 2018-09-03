/********************************************************************************
** Form generated from reading UI file 'pageTeam.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGETEAM_H
#define UI_PAGETEAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pageTeam
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QLabel *labelTeamPix;
    QLabel *labelTeamEn;
    QSpacerItem *horizontalSpacer_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_4;
    QPushButton *buttonPenalty;
    QPushButton *buttonVictory;
    QPushButton *buttonShoot;
    QPushButton *buttonScore;
    QPushButton *buttonBackboard;
    QPushButton *buttonFalut;
    QPushButton *buttonAssisting;
    QPushButton *buttonThree;
    QGridLayout *gridLayoutTable;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayoutPlayer;

    void setupUi(QWidget *pageTeam)
    {
        if (pageTeam->objectName().isEmpty())
            pageTeam->setObjectName(QStringLiteral("pageTeam"));
        pageTeam->resize(600, 600);
        horizontalLayout_2 = new QHBoxLayout(pageTeam);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelTeamPix = new QLabel(pageTeam);
        labelTeamPix->setObjectName(QStringLiteral("labelTeamPix"));
        labelTeamPix->setMinimumSize(QSize(66, 44));

        gridLayout->addWidget(labelTeamPix, 0, 0, 2, 1);


        horizontalLayout->addLayout(gridLayout);

        labelTeamEn = new QLabel(pageTeam);
        labelTeamEn->setObjectName(QStringLiteral("labelTeamEn"));
        labelTeamEn->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(labelTeamEn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        tabWidget = new QTabWidget(pageTeam);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        buttonPenalty = new QPushButton(tab);
        buttonPenalty->setObjectName(QStringLiteral("buttonPenalty"));

        gridLayout_4->addWidget(buttonPenalty, 0, 2, 1, 1);

        buttonVictory = new QPushButton(tab);
        buttonVictory->setObjectName(QStringLiteral("buttonVictory"));

        gridLayout_4->addWidget(buttonVictory, 1, 3, 1, 1);

        buttonShoot = new QPushButton(tab);
        buttonShoot->setObjectName(QStringLiteral("buttonShoot"));

        gridLayout_4->addWidget(buttonShoot, 0, 0, 1, 1);

        buttonScore = new QPushButton(tab);
        buttonScore->setObjectName(QStringLiteral("buttonScore"));

        gridLayout_4->addWidget(buttonScore, 1, 2, 1, 1);

        buttonBackboard = new QPushButton(tab);
        buttonBackboard->setObjectName(QStringLiteral("buttonBackboard"));

        gridLayout_4->addWidget(buttonBackboard, 0, 3, 1, 1);

        buttonFalut = new QPushButton(tab);
        buttonFalut->setObjectName(QStringLiteral("buttonFalut"));

        gridLayout_4->addWidget(buttonFalut, 1, 1, 1, 1);

        buttonAssisting = new QPushButton(tab);
        buttonAssisting->setObjectName(QStringLiteral("buttonAssisting"));

        gridLayout_4->addWidget(buttonAssisting, 1, 0, 1, 1);

        buttonThree = new QPushButton(tab);
        buttonThree->setObjectName(QStringLiteral("buttonThree"));

        gridLayout_4->addWidget(buttonThree, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_4);

        gridLayoutTable = new QGridLayout();
        gridLayoutTable->setObjectName(QStringLiteral("gridLayoutTable"));

        verticalLayout_2->addLayout(gridLayoutTable);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 6);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayoutPlayer = new QVBoxLayout();
        verticalLayoutPlayer->setObjectName(QStringLiteral("verticalLayoutPlayer"));

        verticalLayout_3->addLayout(verticalLayoutPlayer);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(pageTeam);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(pageTeam);
    } // setupUi

    void retranslateUi(QWidget *pageTeam)
    {
        pageTeam->setWindowTitle(QApplication::translate("pageTeam", "Form", nullptr));
        labelTeamPix->setText(QApplication::translate("pageTeam", "\351\230\237\344\274\215\345\233\276\347\211\207", nullptr));
        labelTeamEn->setText(QApplication::translate("pageTeam", "\351\230\237\344\274\215\345\220\215", nullptr));
        buttonPenalty->setText(QApplication::translate("pageTeam", "\347\275\232\347\220\203", nullptr));
        buttonVictory->setText(QApplication::translate("pageTeam", "\350\203\234\350\264\237", nullptr));
        buttonShoot->setText(QApplication::translate("pageTeam", "\346\212\225\347\257\256", nullptr));
        buttonScore->setText(QApplication::translate("pageTeam", "\345\210\206\346\225\260", nullptr));
        buttonBackboard->setText(QApplication::translate("pageTeam", "\347\257\256\346\235\277", nullptr));
        buttonFalut->setText(QApplication::translate("pageTeam", "\345\244\261\350\257\257/\347\212\257\350\247\204", nullptr));
        buttonAssisting->setText(QApplication::translate("pageTeam", "\345\212\251\346\224\273/\346\212\242\346\226\255/\347\233\226\345\270\275", nullptr));
        buttonThree->setText(QApplication::translate("pageTeam", "\344\270\211\345\210\206", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("pageTeam", "\347\220\203\351\230\237\346\225\260\346\215\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("pageTeam", "\347\220\203\351\230\237\346\210\220\345\221\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pageTeam: public Ui_pageTeam {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGETEAM_H
