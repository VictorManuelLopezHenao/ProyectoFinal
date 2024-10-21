/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_File;
    QWidget *centralwidget;
    QLabel *Ibl_Title_File_Name;
    QLabel *Lbl_Value_File_Name;
    QPushButton *pushButton_Play;
    QPushButton *pushButton_Pause;
    QSlider *horizontalSlider_Volume_Control;
    QMenuBar *menubar;
    QMenu *menuOpen;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(774, 304);
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName("actionOpen_File");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Ibl_Title_File_Name = new QLabel(centralwidget);
        Ibl_Title_File_Name->setObjectName("Ibl_Title_File_Name");
        Ibl_Title_File_Name->setGeometry(QRect(30, 20, 171, 71));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        Ibl_Title_File_Name->setFont(font);
        Lbl_Value_File_Name = new QLabel(centralwidget);
        Lbl_Value_File_Name->setObjectName("Lbl_Value_File_Name");
        Lbl_Value_File_Name->setGeometry(QRect(210, 20, 531, 71));
        Lbl_Value_File_Name->setFont(font);
        pushButton_Play = new QPushButton(centralwidget);
        pushButton_Play->setObjectName("pushButton_Play");
        pushButton_Play->setGeometry(QRect(30, 120, 121, 81));
        pushButton_Pause = new QPushButton(centralwidget);
        pushButton_Pause->setObjectName("pushButton_Pause");
        pushButton_Pause->setGeometry(QRect(160, 120, 121, 81));
        horizontalSlider_Volume_Control = new QSlider(centralwidget);
        horizontalSlider_Volume_Control->setObjectName("horizontalSlider_Volume_Control");
        horizontalSlider_Volume_Control->setGeometry(QRect(300, 120, 431, 71));
        horizontalSlider_Volume_Control->setMinimum(1);
        horizontalSlider_Volume_Control->setMaximum(100);
        horizontalSlider_Volume_Control->setValue(10);
        horizontalSlider_Volume_Control->setOrientation(Qt::Orientation::Horizontal);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 774, 25));
        menuOpen = new QMenu(menubar);
        menuOpen->setObjectName("menuOpen");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOpen->menuAction());
        menuOpen->addAction(actionOpen_File);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen_File->setText(QCoreApplication::translate("MainWindow", "Open File", nullptr));
        Ibl_Title_File_Name->setText(QCoreApplication::translate("MainWindow", "Audio File Name:", nullptr));
        Lbl_Value_File_Name->setText(QCoreApplication::translate("MainWindow", "FILE_NAME", nullptr));
        pushButton_Play->setText(QString());
        pushButton_Pause->setText(QString());
        menuOpen->setTitle(QCoreApplication::translate("MainWindow", "Open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
