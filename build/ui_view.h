/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_view
{
public:
    QAction *actionStart;
    QAction *actionRank;
    QAction *actionData;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QToolBar *toolBar;

    void setupUi(QMainWindow *view)
    {
        if (view->objectName().isEmpty())
            view->setObjectName(QStringLiteral("view"));
        view->resize(667, 351);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(view->sizePolicy().hasHeightForWidth());
        view->setSizePolicy(sizePolicy);
        actionStart = new QAction(view);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        actionRank = new QAction(view);
        actionRank->setObjectName(QStringLiteral("actionRank"));
        actionData = new QAction(view);
        actionData->setObjectName(QStringLiteral("actionData"));
        centralWidget = new QWidget(view);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));

        horizontalLayout->addWidget(stackedWidget);

        view->setCentralWidget(centralWidget);
        toolBar = new QToolBar(view);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        toolBar->setFloatable(true);
        view->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionStart);
        toolBar->addAction(actionRank);
        toolBar->addAction(actionData);

        retranslateUi(view);

        QMetaObject::connectSlotsByName(view);
    } // setupUi

    void retranslateUi(QMainWindow *view)
    {
        view->setWindowTitle(QApplication::translate("view", "view", nullptr));
        actionStart->setText(QApplication::translate("view", "\344\270\273\351\241\265", nullptr));
        actionRank->setText(QApplication::translate("view", "\346\210\230\347\273\251\346\216\222\350\241\214", nullptr));
        actionData->setText(QApplication::translate("view", "\346\225\260\346\215\256", nullptr));
        toolBar->setWindowTitle(QApplication::translate("view", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class view: public Ui_view {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
