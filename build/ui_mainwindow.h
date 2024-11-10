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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_File;
    QAction *actionOpen_File_Video;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QTreeView *treeView;
    QListWidget *listWidget;
    QSlider *horizontalSlider_VolumeV;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_6;
    QSplitter *splitter;
    QGroupBox *groupBox_Video;
    QLabel *ORG1_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_Title_File_Name;
    QLabel *label_Value_File_Name;
    QVBoxLayout *verticalLayout;
    QSlider *horizontalSlide_DurationV;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Current_Time;
    QLabel *ORG1;
    QLabel *label_Total_Time;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_VolumeV;
    QPushButton *pushButton_Seek_BackwardV;
    QPushButton *pushButton_Seek_ForwardV;
    QPushButton *pushButton_Play_PauseV;
    QPushButton *pushButton_StopV;
    QMenuBar *menubar;
    QMenu *menuOpen;
    QMenu *menuVideo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1161, 803);
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName("actionOpen_File");
        actionOpen_File_Video = new QAction(MainWindow);
        actionOpen_File_Video->setObjectName("actionOpen_File_Video");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        treeView = new QTreeView(centralwidget);
        treeView->setObjectName("treeView");

        verticalLayout_4->addWidget(treeView);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");

        verticalLayout_4->addWidget(listWidget);


        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalSlider_VolumeV = new QSlider(centralwidget);
        horizontalSlider_VolumeV->setObjectName("horizontalSlider_VolumeV");
        horizontalSlider_VolumeV->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout_5->addWidget(horizontalSlider_VolumeV);


        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout_5);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Orientation::Vertical);
        groupBox_Video = new QGroupBox(splitter);
        groupBox_Video->setObjectName("groupBox_Video");
        groupBox_Video->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"border: 1px solid black;\n"
"}"));
        splitter->addWidget(groupBox_Video);

        verticalLayout_6->addWidget(splitter);

        ORG1_2 = new QLabel(centralwidget);
        ORG1_2->setObjectName("ORG1_2");

        verticalLayout_6->addWidget(ORG1_2);


        gridLayout->addLayout(verticalLayout_6, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_Title_File_Name = new QLabel(centralwidget);
        label_Title_File_Name->setObjectName("label_Title_File_Name");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_Title_File_Name->setFont(font);

        verticalLayout_2->addWidget(label_Title_File_Name);

        label_Value_File_Name = new QLabel(centralwidget);
        label_Value_File_Name->setObjectName("label_Value_File_Name");
        label_Value_File_Name->setFont(font);

        verticalLayout_2->addWidget(label_Value_File_Name);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalSlide_DurationV = new QSlider(centralwidget);
        horizontalSlide_DurationV->setObjectName("horizontalSlide_DurationV");
        horizontalSlide_DurationV->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout->addWidget(horizontalSlide_DurationV);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_Current_Time = new QLabel(centralwidget);
        label_Current_Time->setObjectName("label_Current_Time");
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        label_Current_Time->setFont(font1);

        horizontalLayout_2->addWidget(label_Current_Time);

        ORG1 = new QLabel(centralwidget);
        ORG1->setObjectName("ORG1");

        horizontalLayout_2->addWidget(ORG1);

        label_Total_Time = new QLabel(centralwidget);
        label_Total_Time->setObjectName("label_Total_Time");
        label_Total_Time->setFont(font1);

        horizontalLayout_2->addWidget(label_Total_Time);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_VolumeV = new QPushButton(centralwidget);
        pushButton_VolumeV->setObjectName("pushButton_VolumeV");

        horizontalLayout->addWidget(pushButton_VolumeV);

        pushButton_Seek_BackwardV = new QPushButton(centralwidget);
        pushButton_Seek_BackwardV->setObjectName("pushButton_Seek_BackwardV");

        horizontalLayout->addWidget(pushButton_Seek_BackwardV);

        pushButton_Seek_ForwardV = new QPushButton(centralwidget);
        pushButton_Seek_ForwardV->setObjectName("pushButton_Seek_ForwardV");

        horizontalLayout->addWidget(pushButton_Seek_ForwardV);

        pushButton_Play_PauseV = new QPushButton(centralwidget);
        pushButton_Play_PauseV->setObjectName("pushButton_Play_PauseV");

        horizontalLayout->addWidget(pushButton_Play_PauseV);

        pushButton_StopV = new QPushButton(centralwidget);
        pushButton_StopV->setObjectName("pushButton_StopV");

        horizontalLayout->addWidget(pushButton_StopV);


        verticalLayout_3->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_3, 1, 0, 1, 1);


        formLayout->setLayout(0, QFormLayout::FieldRole, gridLayout);


        gridLayout_2->addLayout(formLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1161, 25));
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
        ORG1_2->setText(QString());
        label_Title_File_Name->setText(QCoreApplication::translate("MainWindow", "Audio File Name: ", nullptr));
        label_Value_File_Name->setText(QCoreApplication::translate("MainWindow", "FILE_NAME", nullptr));
        label_Current_Time->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        ORG1->setText(QString());
        label_Total_Time->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        pushButton_VolumeV->setText(QString());
        pushButton_Seek_BackwardV->setText(QString());
        pushButton_Seek_ForwardV->setText(QString());
        pushButton_Play_PauseV->setText(QString());
        pushButton_StopV->setText(QString());
        menuOpen->setTitle(QCoreApplication::translate("MainWindow", "Audio", nullptr));
        menuVideo->setTitle(QCoreApplication::translate("MainWindow", "Video", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
