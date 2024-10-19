/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
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
    QPushButton *pushButton_Play;
    QPushButton *pushButton_Pause;
    QSlider *horizontalSlider_Volume_Control;
    QFrame *frame_Pantalla_Video;
    QLabel *Ibl_Title_File_Name;
    QLabel *Lbl_Value_File_Name;
    QFrame *frame_Biblioteca;
    QPushButton *pushButton_Next;
    QPushButton *pushButton_Repet;
    QPushButton *pushButton_Mute;
    QPushButton *pushButton_Back;
    QProgressBar *progressBar;
    QMenuBar *menubar;
    QMenu *menuOpen;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(704, 468);
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName("actionOpen_File");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton_Play = new QPushButton(centralwidget);
        pushButton_Play->setObjectName("pushButton_Play");
        pushButton_Play->setGeometry(QRect(440, 330, 71, 41));
        pushButton_Pause = new QPushButton(centralwidget);
        pushButton_Pause->setObjectName("pushButton_Pause");
        pushButton_Pause->setGeometry(QRect(440, 380, 71, 41));
        horizontalSlider_Volume_Control = new QSlider(centralwidget);
        horizontalSlider_Volume_Control->setObjectName("horizontalSlider_Volume_Control");
        horizontalSlider_Volume_Control->setGeometry(QRect(30, 360, 171, 41));
        horizontalSlider_Volume_Control->setStyleSheet(QString::fromUtf8(""));
        horizontalSlider_Volume_Control->setMinimum(1);
        horizontalSlider_Volume_Control->setMaximum(100);
        horizontalSlider_Volume_Control->setValue(10);
        horizontalSlider_Volume_Control->setOrientation(Qt::Orientation::Horizontal);
        frame_Pantalla_Video = new QFrame(centralwidget);
        frame_Pantalla_Video->setObjectName("frame_Pantalla_Video");
        frame_Pantalla_Video->setGeometry(QRect(210, 20, 451, 271));
        frame_Pantalla_Video->setFrameShape(QFrame::Shape::StyledPanel);
        frame_Pantalla_Video->setFrameShadow(QFrame::Shadow::Raised);
        Ibl_Title_File_Name = new QLabel(frame_Pantalla_Video);
        Ibl_Title_File_Name->setObjectName("Ibl_Title_File_Name");
        Ibl_Title_File_Name->setGeometry(QRect(10, 200, 261, 41));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        Ibl_Title_File_Name->setFont(font);
        Lbl_Value_File_Name = new QLabel(frame_Pantalla_Video);
        Lbl_Value_File_Name->setObjectName("Lbl_Value_File_Name");
        Lbl_Value_File_Name->setGeometry(QRect(10, 230, 441, 31));
        Lbl_Value_File_Name->setFont(font);
        frame_Biblioteca = new QFrame(centralwidget);
        frame_Biblioteca->setObjectName("frame_Biblioteca");
        frame_Biblioteca->setGeometry(QRect(40, 20, 141, 271));
        frame_Biblioteca->setFrameShape(QFrame::Shape::StyledPanel);
        frame_Biblioteca->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_Next = new QPushButton(centralwidget);
        pushButton_Next->setObjectName("pushButton_Next");
        pushButton_Next->setGeometry(QRect(540, 350, 71, 41));
        pushButton_Repet = new QPushButton(centralwidget);
        pushButton_Repet->setObjectName("pushButton_Repet");
        pushButton_Repet->setGeometry(QRect(240, 350, 71, 41));
        pushButton_Mute = new QPushButton(centralwidget);
        pushButton_Mute->setObjectName("pushButton_Mute");
        pushButton_Mute->setGeometry(QRect(80, 310, 71, 41));
        pushButton_Back = new QPushButton(centralwidget);
        pushButton_Back->setObjectName("pushButton_Back");
        pushButton_Back->setGeometry(QRect(340, 350, 71, 41));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(210, 300, 481, 16));
        progressBar->setValue(24);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 704, 18));
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
        pushButton_Play->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        pushButton_Pause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        Ibl_Title_File_Name->setText(QCoreApplication::translate("MainWindow", "Audio File Name:", nullptr));
        Lbl_Value_File_Name->setText(QCoreApplication::translate("MainWindow", "FILE_NAME", nullptr));
        pushButton_Next->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        pushButton_Repet->setText(QCoreApplication::translate("MainWindow", "Repet", nullptr));
        pushButton_Mute->setText(QCoreApplication::translate("MainWindow", "Mute", nullptr));
        pushButton_Back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        menuOpen->setTitle(QCoreApplication::translate("MainWindow", "Open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
