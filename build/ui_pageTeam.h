/********************************************************************************
** Form generated from reading UI file 'pageTeam.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGETEAM_H
#define UI_PAGETEAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
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
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *layoutTeamData;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_12;
    QGridLayout *layoutPlayers;

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
        labelTeamPix->setMinimumSize(QSize(150, 100));

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
        scrollArea_2 = new QScrollArea(tab);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 554, 425));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        layoutTeamData = new QGridLayout();
        layoutTeamData->setObjectName(QStringLiteral("layoutTeamData"));

        verticalLayout_4->addLayout(layoutTeamData);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_2->addWidget(scrollArea_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        scrollArea = new QScrollArea(tab_2);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 537, 2000));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 2000));
        verticalLayout_12 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        layoutPlayers = new QGridLayout();
        layoutPlayers->setObjectName(QStringLiteral("layoutPlayers"));

        verticalLayout_12->addLayout(layoutPlayers);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 10);

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
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("pageTeam", "\347\220\203\351\230\237\346\225\260\346\215\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("pageTeam", "\347\220\203\351\230\237\346\210\220\345\221\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pageTeam: public Ui_pageTeam {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGETEAM_H
