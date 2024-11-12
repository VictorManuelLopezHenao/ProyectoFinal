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
    QAction *action;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *ORG1_17;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_6;
    QLabel *ORG1_15;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_Nombre;
    QLabel *ORG1_14;
    QFormLayout *formLayout_3;
    QFormLayout *formLayout_2;
    QVBoxLayout *verticalLayout_4;
    QFormLayout *formLayout;
    QTreeView *treeView;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *ORG1_10;
    QSlider *horizontalSlider_VolumeV;
    QHBoxLayout *horizontalLayout_3;
    QLabel *ORG1_11;
    QPushButton *pushButton_VolumeV;
    QLabel *ORG1_12;
    QLabel *ORG1_13;
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QGroupBox *groupBox_Video;
    QVBoxLayout *verticalLayout;
    QLabel *label_Value_File_Name;
    QLabel *ORG1_9;
    QSlider *horizontalSlide_DurationV;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Current_Time;
    QLabel *ORG1_26;
    QLabel *ORG1_21;
    QLabel *ORG1_30;
    QLabel *ORG1_18;
    QLabel *ORG1_28;
    QLabel *ORG1_19;
    QLabel *ORG1_22;
    QLabel *ORG1_20;
    QLabel *ORG1_29;
    QLabel *ORG1_7;
    QLabel *ORG1_25;
    QLabel *ORG1_27;
    QLabel *ORG1_24;
    QLabel *ORG1_23;
    QLabel *label_Total_Time;
    QLabel *ORG1_8;
    QHBoxLayout *horizontalLayout;
    QLabel *ORG1;
    QLabel *ORG1_4;
    QLabel *ORG1_3;
    QPushButton *pushButton_StopV;
    QPushButton *pushButton_Seek_BackwardV;
    QPushButton *pushButton_Play_PauseV;
    QPushButton *pushButton_Seek_ForwardV;
    QPushButton *pushButton_Fullscreen;
    QLabel *ORG1_5;
    QLabel *ORG1_6;
    QLabel *ORG1_2;
    QLabel *ORG1_16;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1095, 674);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(18, 18, 18);"));
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName("actionOpen_File");
        action = new QAction(MainWindow);
        action->setObjectName("action");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        ORG1_17 = new QLabel(centralwidget);
        ORG1_17->setObjectName("ORG1_17");

        gridLayout_2->addWidget(ORG1_17, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        ORG1_15 = new QLabel(centralwidget);
        ORG1_15->setObjectName("ORG1_15");

        verticalLayout_6->addWidget(ORG1_15);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_Nombre = new QLabel(centralwidget);
        label_Nombre->setObjectName("label_Nombre");
        label_Nombre->setStyleSheet(QString::fromUtf8("font: 14pt \"Cooper Black\";\n"
"color: rgb(255, 255, 255);\n"
""));

        verticalLayout_5->addWidget(label_Nombre);

        ORG1_14 = new QLabel(centralwidget);
        ORG1_14->setObjectName("ORG1_14");

        verticalLayout_5->addWidget(ORG1_14);


        verticalLayout_6->addLayout(verticalLayout_5);


        gridLayout->addLayout(verticalLayout_6, 0, 0, 1, 1);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        treeView = new QTreeView(centralwidget);
        treeView->setObjectName("treeView");
        treeView->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 120, 120);\n"
"background-color: rgb(0, 0, 0);"));

        formLayout->setWidget(0, QFormLayout::LabelRole, treeView);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        formLayout->setWidget(1, QFormLayout::LabelRole, listWidget);


        verticalLayout_4->addLayout(formLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        ORG1_10 = new QLabel(centralwidget);
        ORG1_10->setObjectName("ORG1_10");

        verticalLayout_3->addWidget(ORG1_10);

        horizontalSlider_VolumeV = new QSlider(centralwidget);
        horizontalSlider_VolumeV->setObjectName("horizontalSlider_VolumeV");
        horizontalSlider_VolumeV->setStyleSheet(QString::fromUtf8(""));
        horizontalSlider_VolumeV->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout_3->addWidget(horizontalSlider_VolumeV);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        ORG1_11 = new QLabel(centralwidget);
        ORG1_11->setObjectName("ORG1_11");

        horizontalLayout_3->addWidget(ORG1_11);

        pushButton_VolumeV = new QPushButton(centralwidget);
        pushButton_VolumeV->setObjectName("pushButton_VolumeV");
        pushButton_VolumeV->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(pushButton_VolumeV);

        ORG1_12 = new QLabel(centralwidget);
        ORG1_12->setObjectName("ORG1_12");

        horizontalLayout_3->addWidget(ORG1_12);


        verticalLayout_4->addLayout(horizontalLayout_3);


        formLayout_2->setLayout(0, QFormLayout::LabelRole, verticalLayout_4);

        ORG1_13 = new QLabel(centralwidget);
        ORG1_13->setObjectName("ORG1_13");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, ORG1_13);


        formLayout_3->setLayout(0, QFormLayout::LabelRole, formLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
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

        verticalLayout_2->addWidget(splitter);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_Value_File_Name = new QLabel(centralwidget);
        label_Value_File_Name->setObjectName("label_Value_File_Name");
        QFont font;
        font.setFamilies({QString::fromUtf8("Cooper Black")});
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        label_Value_File_Name->setFont(font);
        label_Value_File_Name->setStyleSheet(QString::fromUtf8("font: 11pt \"Cooper Black\";"));

        verticalLayout->addWidget(label_Value_File_Name);

        ORG1_9 = new QLabel(centralwidget);
        ORG1_9->setObjectName("ORG1_9");

        verticalLayout->addWidget(ORG1_9);

        horizontalSlide_DurationV = new QSlider(centralwidget);
        horizontalSlide_DurationV->setObjectName("horizontalSlide_DurationV");
        horizontalSlide_DurationV->setStyleSheet(QString::fromUtf8(""));
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
        label_Current_Time->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(label_Current_Time);

        ORG1_26 = new QLabel(centralwidget);
        ORG1_26->setObjectName("ORG1_26");

        horizontalLayout_2->addWidget(ORG1_26);

        ORG1_21 = new QLabel(centralwidget);
        ORG1_21->setObjectName("ORG1_21");

        horizontalLayout_2->addWidget(ORG1_21);

        ORG1_30 = new QLabel(centralwidget);
        ORG1_30->setObjectName("ORG1_30");

        horizontalLayout_2->addWidget(ORG1_30);

        ORG1_18 = new QLabel(centralwidget);
        ORG1_18->setObjectName("ORG1_18");

        horizontalLayout_2->addWidget(ORG1_18);

        ORG1_28 = new QLabel(centralwidget);
        ORG1_28->setObjectName("ORG1_28");

        horizontalLayout_2->addWidget(ORG1_28);

        ORG1_19 = new QLabel(centralwidget);
        ORG1_19->setObjectName("ORG1_19");

        horizontalLayout_2->addWidget(ORG1_19);

        ORG1_22 = new QLabel(centralwidget);
        ORG1_22->setObjectName("ORG1_22");

        horizontalLayout_2->addWidget(ORG1_22);

        ORG1_20 = new QLabel(centralwidget);
        ORG1_20->setObjectName("ORG1_20");

        horizontalLayout_2->addWidget(ORG1_20);

        ORG1_29 = new QLabel(centralwidget);
        ORG1_29->setObjectName("ORG1_29");

        horizontalLayout_2->addWidget(ORG1_29);

        ORG1_7 = new QLabel(centralwidget);
        ORG1_7->setObjectName("ORG1_7");

        horizontalLayout_2->addWidget(ORG1_7);

        ORG1_25 = new QLabel(centralwidget);
        ORG1_25->setObjectName("ORG1_25");

        horizontalLayout_2->addWidget(ORG1_25);

        ORG1_27 = new QLabel(centralwidget);
        ORG1_27->setObjectName("ORG1_27");

        horizontalLayout_2->addWidget(ORG1_27);

        ORG1_24 = new QLabel(centralwidget);
        ORG1_24->setObjectName("ORG1_24");

        horizontalLayout_2->addWidget(ORG1_24);

        ORG1_23 = new QLabel(centralwidget);
        ORG1_23->setObjectName("ORG1_23");

        horizontalLayout_2->addWidget(ORG1_23);

        label_Total_Time = new QLabel(centralwidget);
        label_Total_Time->setObjectName("label_Total_Time");
        label_Total_Time->setFont(font1);

        horizontalLayout_2->addWidget(label_Total_Time);


        verticalLayout->addLayout(horizontalLayout_2);

        ORG1_8 = new QLabel(centralwidget);
        ORG1_8->setObjectName("ORG1_8");

        verticalLayout->addWidget(ORG1_8);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        ORG1 = new QLabel(centralwidget);
        ORG1->setObjectName("ORG1");

        horizontalLayout->addWidget(ORG1);

        ORG1_4 = new QLabel(centralwidget);
        ORG1_4->setObjectName("ORG1_4");

        horizontalLayout->addWidget(ORG1_4);

        ORG1_3 = new QLabel(centralwidget);
        ORG1_3->setObjectName("ORG1_3");

        horizontalLayout->addWidget(ORG1_3);

        pushButton_StopV = new QPushButton(centralwidget);
        pushButton_StopV->setObjectName("pushButton_StopV");
        pushButton_StopV->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(pushButton_StopV);

        pushButton_Seek_BackwardV = new QPushButton(centralwidget);
        pushButton_Seek_BackwardV->setObjectName("pushButton_Seek_BackwardV");
        pushButton_Seek_BackwardV->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(pushButton_Seek_BackwardV);

        pushButton_Play_PauseV = new QPushButton(centralwidget);
        pushButton_Play_PauseV->setObjectName("pushButton_Play_PauseV");
        pushButton_Play_PauseV->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(pushButton_Play_PauseV);

        pushButton_Seek_ForwardV = new QPushButton(centralwidget);
        pushButton_Seek_ForwardV->setObjectName("pushButton_Seek_ForwardV");
        pushButton_Seek_ForwardV->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(pushButton_Seek_ForwardV);

        pushButton_Fullscreen = new QPushButton(centralwidget);
        pushButton_Fullscreen->setObjectName("pushButton_Fullscreen");
        pushButton_Fullscreen->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(pushButton_Fullscreen);

        ORG1_5 = new QLabel(centralwidget);
        ORG1_5->setObjectName("ORG1_5");

        horizontalLayout->addWidget(ORG1_5);

        ORG1_6 = new QLabel(centralwidget);
        ORG1_6->setObjectName("ORG1_6");

        horizontalLayout->addWidget(ORG1_6);

        ORG1_2 = new QLabel(centralwidget);
        ORG1_2->setObjectName("ORG1_2");

        horizontalLayout->addWidget(ORG1_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        formLayout_3->setLayout(0, QFormLayout::FieldRole, verticalLayout_2);


        gridLayout->addLayout(formLayout_3, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);

        ORG1_16 = new QLabel(centralwidget);
        ORG1_16->setObjectName("ORG1_16");

        gridLayout_2->addWidget(ORG1_16, 0, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen_File->setText(QCoreApplication::translate("MainWindow", "Abrir Archivo Audio", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "Abrir Archivo Video", nullptr));
        ORG1_17->setText(QString());
        ORG1_15->setText(QString());
        label_Nombre->setText(QCoreApplication::translate("MainWindow", " CodeVibes", nullptr));
        ORG1_14->setText(QString());
        ORG1_10->setText(QString());
        ORG1_11->setText(QString());
        pushButton_VolumeV->setText(QString());
        ORG1_12->setText(QString());
        ORG1_13->setText(QString());
        groupBox_Video->setTitle(QString());
        label_Value_File_Name->setText(QCoreApplication::translate("MainWindow", "FILE_NAME", nullptr));
        ORG1_9->setText(QString());
        label_Current_Time->setText(QCoreApplication::translate("MainWindow", "00:00:00 ", nullptr));
        ORG1_26->setText(QString());
        ORG1_21->setText(QString());
        ORG1_30->setText(QString());
        ORG1_18->setText(QString());
        ORG1_28->setText(QString());
        ORG1_19->setText(QString());
        ORG1_22->setText(QString());
        ORG1_20->setText(QString());
        ORG1_29->setText(QString());
        ORG1_7->setText(QString());
        ORG1_25->setText(QString());
        ORG1_27->setText(QString());
        ORG1_24->setText(QString());
        ORG1_23->setText(QString());
        label_Total_Time->setText(QCoreApplication::translate("MainWindow", " 00:00:00", nullptr));
        ORG1_8->setText(QString());
        ORG1->setText(QString());
        ORG1_4->setText(QString());
        ORG1_3->setText(QString());
        pushButton_StopV->setText(QString());
        pushButton_Seek_BackwardV->setText(QString());
        pushButton_Play_PauseV->setText(QString());
        pushButton_Seek_ForwardV->setText(QString());
        pushButton_Fullscreen->setText(QString());
        ORG1_5->setText(QString());
        ORG1_6->setText(QString());
        ORG1_2->setText(QString());
        ORG1_16->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
