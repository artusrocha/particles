/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Mar 8 00:45:23 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDial>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "myglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    myGLWidget *widget;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QSpinBox *particulas;
    QLabel *label;
    QSpinBox *spinBox;
    QCheckBox *checkBox;
    QFrame *line_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QSpacerItem *verticalSpacer;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QSlider *horizontalSlider;
    QLabel *label_4;
    QDial *dial;
    QLabel *label_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QFrame *line;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox;
    QSpacerItem *verticalSpacer_2;
    QPushButton *exitButton;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(724, 584);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new myGLWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(300, 300));
        widget->setMaximumSize(QSize(16777215, 16777215));
        widget->setCursor(QCursor(Qt::ArrowCursor));
        widget->setMouseTracking(false);

        horizontalLayout->addWidget(widget);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        particulas = new QSpinBox(widget_2);
        particulas->setObjectName(QString::fromUtf8("particulas"));
        particulas->setMaximum(1000000);

        verticalLayout->addWidget(particulas);

        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        spinBox = new QSpinBox(widget_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setValue(1);

        verticalLayout->addWidget(spinBox);

        checkBox = new QCheckBox(widget_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setChecked(true);

        verticalLayout->addWidget(checkBox);

        line_2 = new QFrame(widget_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(widget_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        verticalSpacer = new QSpacerItem(20, 391, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(widget_2);

        widget_4 = new QWidget(centralWidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        sizePolicy1.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        horizontalSlider = new QSlider(widget_4);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMinimum(-45);
        horizontalSlider->setMaximum(45);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider);

        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        dial = new QDial(widget_4);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setMinimum(-20);
        dial->setMaximum(20);

        verticalLayout_2->addWidget(dial);

        label_5 = new QLabel(widget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        pushButton = new QPushButton(widget_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);

        line = new QFrame(widget_4);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        label_6 = new QLabel(widget_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_2->addWidget(label_6);

        doubleSpinBox = new QDoubleSpinBox(widget_4);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setSingleStep(0.01);
        doubleSpinBox->setValue(0.5);

        verticalLayout_2->addWidget(doubleSpinBox);

        verticalSpacer_2 = new QSpacerItem(20, 226, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        exitButton = new QPushButton(widget_4);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        verticalLayout_2->addWidget(exitButton);


        horizontalLayout->addWidget(widget_4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 724, 23));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);
        QObject::connect(exitButton, SIGNAL(clicked()), MainWindow, SLOT(close()));
        QObject::connect(checkBox, SIGNAL(toggled(bool)), widget, SLOT(play(bool)));
        QObject::connect(dial, SIGNAL(valueChanged(int)), widget, SLOT(giroy(int)));
        QObject::connect(doubleSpinBox, SIGNAL(valueChanged(double)), widget, SLOT(cubesize(double)));
        QObject::connect(particulas, SIGNAL(valueChanged(int)), widget, SLOT(add(int)));
        QObject::connect(pushButton_2, SIGNAL(pressed()), widget, SLOT(giroz()));
        QObject::connect(pushButton, SIGNAL(pressed()), widget, SLOT(giroz_()));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), widget, SLOT(girox(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), widget, SLOT(faster(int)));
        QObject::connect(pushButton_3, SIGNAL(clicked()), widget, SLOT(reset()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), widget, SLOT(twoparticles()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), widget, SLOT(chain()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "N Particles", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Speed", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindow", "Run", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MainWindow", "Two Particles", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("MainWindow", "Group", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "x axis", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "y axis", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "z axis", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "<", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", ">", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "cube size", 0, QApplication::UnicodeUTF8));
        exitButton->setText(QApplication::translate("MainWindow", "Sair", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
