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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_File;
    QAction *actionOpen_File_Video;
    QWidget *centralwidget;
    QGroupBox *groupBox_Video;
    QSlider *horizontalSlide_DurationV;
    QLabel *label_Current_Time;
    QLabel *label_Total_Time;
    QPushButton *pushButton_Play_PauseV;
    QPushButton *pushButton_Seek_BackwardV;
    QPushButton *pushButton_StopV;
    QPushButton *pushButton_Seek_ForwardV;
    QPushButton *pushButton_VolumeV;
    QSlider *horizontalSlider_VolumeV;
    QTreeView *treeView;
    QListView *listView;
    QLabel *label_Title_File_Name;
    QLabel *label_Value_File_Name;
    QMenuBar *menubar;
    QMenu *menuOpen;
    QMenu *menuVideo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(920, 630);
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName("actionOpen_File");
        actionOpen_File_Video = new QAction(MainWindow);
        actionOpen_File_Video->setObjectName("actionOpen_File_Video");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox_Video = new QGroupBox(centralwidget);
        groupBox_Video->setObjectName("groupBox_Video");
        groupBox_Video->setGeometry(QRect(290, 30, 571, 331));
        groupBox_Video->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"border: 1px solid black;\n"
"}"));
        horizontalSlide_DurationV = new QSlider(centralwidget);
        horizontalSlide_DurationV->setObjectName("horizontalSlide_DurationV");
        horizontalSlide_DurationV->setGeometry(QRect(290, 440, 571, 20));
        horizontalSlide_DurationV->setOrientation(Qt::Orientation::Horizontal);
        label_Current_Time = new QLabel(centralwidget);
        label_Current_Time->setObjectName("label_Current_Time");
        label_Current_Time->setGeometry(QRect(290, 460, 71, 20));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        label_Current_Time->setFont(font);
        label_Total_Time = new QLabel(centralwidget);
        label_Total_Time->setObjectName("label_Total_Time");
        label_Total_Time->setGeometry(QRect(800, 460, 71, 20));
        label_Total_Time->setFont(font);
        pushButton_Play_PauseV = new QPushButton(centralwidget);
        pushButton_Play_PauseV->setObjectName("pushButton_Play_PauseV");
        pushButton_Play_PauseV->setGeometry(QRect(550, 490, 51, 41));
        pushButton_Seek_BackwardV = new QPushButton(centralwidget);
        pushButton_Seek_BackwardV->setObjectName("pushButton_Seek_BackwardV");
        pushButton_Seek_BackwardV->setGeometry(QRect(430, 490, 51, 41));
        pushButton_StopV = new QPushButton(centralwidget);
        pushButton_StopV->setObjectName("pushButton_StopV");
        pushButton_StopV->setGeometry(QRect(790, 490, 51, 41));
        pushButton_Seek_ForwardV = new QPushButton(centralwidget);
        pushButton_Seek_ForwardV->setObjectName("pushButton_Seek_ForwardV");
        pushButton_Seek_ForwardV->setGeometry(QRect(670, 490, 51, 41));
        pushButton_VolumeV = new QPushButton(centralwidget);
        pushButton_VolumeV->setObjectName("pushButton_VolumeV");
        pushButton_VolumeV->setGeometry(QRect(310, 490, 51, 41));
        horizontalSlider_VolumeV = new QSlider(centralwidget);
        horizontalSlider_VolumeV->setObjectName("horizontalSlider_VolumeV");
        horizontalSlider_VolumeV->setGeometry(QRect(50, 440, 181, 20));
        horizontalSlider_VolumeV->setOrientation(Qt::Orientation::Horizontal);
        treeView = new QTreeView(centralwidget);
        treeView->setObjectName("treeView");
        treeView->setGeometry(QRect(30, 30, 221, 281));
        listView = new QListView(centralwidget);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(30, 320, 221, 91));
        label_Title_File_Name = new QLabel(centralwidget);
        label_Title_File_Name->setObjectName("label_Title_File_Name");
        label_Title_File_Name->setGeometry(QRect(290, 370, 201, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label_Title_File_Name->setFont(font1);
        label_Value_File_Name = new QLabel(centralwidget);
        label_Value_File_Name->setObjectName("label_Value_File_Name");
        label_Value_File_Name->setGeometry(QRect(290, 400, 561, 31));
        label_Value_File_Name->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 920, 25));
        menuOpen = new QMenu(menubar);
        menuOpen->setObjectName("menuOpen");
        menuVideo = new QMenu(menubar);
        menuVideo->setObjectName("menuVideo");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOpen->menuAction());
        menubar->addAction(menuVideo->menuAction());
        menuOpen->addAction(actionOpen_File);
        menuVideo->addAction(actionOpen_File_Video);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen_File->setText(QCoreApplication::translate("MainWindow", "Abrir Archivo Audio", nullptr));
        actionOpen_File_Video->setText(QCoreApplication::translate("MainWindow", "Abrir Archivo Video", nullptr));
        groupBox_Video->setTitle(QString());
        label_Current_Time->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        label_Total_Time->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        pushButton_Play_PauseV->setText(QString());
        pushButton_Seek_BackwardV->setText(QString());
        pushButton_StopV->setText(QString());
        pushButton_Seek_ForwardV->setText(QString());
        pushButton_VolumeV->setText(QString());
        label_Title_File_Name->setText(QCoreApplication::translate("MainWindow", "Audio File Name: ", nullptr));
        label_Value_File_Name->setText(QCoreApplication::translate("MainWindow", "FILE_NAME", nullptr));
        menuOpen->setTitle(QCoreApplication::translate("MainWindow", "Audio", nullptr));
        menuVideo->setTitle(QCoreApplication::translate("MainWindow", "Video", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
