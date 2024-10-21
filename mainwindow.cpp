#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QVideoWidget>
#include <QStyle>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Inicializamos el reproductor y la salida de audio para el audio
    M_Player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    M_Player->setAudioOutput(audioOutput);

    // Inicializamos el reproductor y la salida de audio para el video
    Player = new QMediaPlayer(this);
    videoAudioOutput = new QAudioOutput(this);
    Player->setAudioOutput(videoAudioOutput);

    // Configuración de botones
    ui->pushButton_Play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->pushButton_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    ui->pushButton_Play_PauseV->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->pushButton_StopV->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    ui->pushButton_Seek_BackwardV->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
    ui->pushButton_Seek_ForwardV->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));
    ui->pushButton_VolumeV->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));

    // Ajustamos el slider de volumen del video
    ui->horizontalSlider_VolumeV->setMinimum(0);
    ui->horizontalSlider_VolumeV->setMaximum(100);
    ui->horizontalSlider_VolumeV->setValue(30);
    videoAudioOutput->setVolume(ui->horizontalSlider_VolumeV->value() / 100.0);

    // Inicializamos las banderas de estado
    IS_Pause = true;
    IS_Muted = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_File_triggered()
{
    QString FileName = QFileDialog::getOpenFileName(this, tr("Select Audio File"), "", tr("MP3 Files (*.mp3)"));
    M_Player->setSource(QUrl::fromLocalFile(FileName));

    QFileInfo File(FileName);
    ui->Lbl_Value_File_Name->setText(File.fileName());
}


void MainWindow::on_actionOpen_File_Video_triggered()
{
    QString FileName = QFileDialog::getOpenFileName(this, tr("Select Video File"), "", tr("MP4 Files (*.mp4)"));

    Video = new QVideoWidget();
    Video->setGeometry(5, 5, ui->groupBox_Video->width() - 10, ui->groupBox_Video->height() - 10);
    Video->setParent(ui->groupBox_Video);
    
    Player->setVideoOutput(Video);
    Player->setSource(QUrl::fromLocalFile(FileName));
    
    Video->setVisible(true);
    Video->show();
}

void MainWindow::on_horizontalSlide_DurationV_valueChanged(int value)
{
    Player->setPosition(value * 1000);
}

void MainWindow::on_pushButton_Play_PauseV_clicked()
{
    if (IS_Pause)
    {
        IS_Pause = false;
        Player->play();
        ui->pushButton_Play_PauseV->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    }
    else
    {
        IS_Pause = true;
        Player->pause();
        ui->pushButton_Play_PauseV->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    }
}

void MainWindow::on_pushButton_StopV_clicked()
{
    Player->stop();
}

void MainWindow::on_pushButton_VolumeV_clicked()
{
    IS_Muted = !IS_Muted;
    ui->pushButton_VolumeV->setIcon(IS_Muted ? style()->standardIcon(QStyle::SP_MediaVolumeMuted) : style()->standardIcon(QStyle::SP_MediaVolume));
    videoAudioOutput->setMuted(IS_Muted);
}

void MainWindow::on_horizontalSlider_VolumeV_valueChanged(int value)
{
    videoAudioOutput->setVolume(value / 100.0);
}

void MainWindow::on_pushButton_Seek_BackwardV_clicked()
{
    ui->horizontalSlide_DurationV->setValue(ui->horizontalSlide_DurationV->value() - 20);
    Player->setPosition(ui->horizontalSlide_DurationV->value() * 1000);
}

void MainWindow::on_pushButton_Seek_ForwardV_clicked()
{
    ui->horizontalSlide_DurationV->setValue(ui->horizontalSlide_DurationV->value() + 20);
    Player->setPosition(ui->horizontalSlide_DurationV->value() * 1000);
}



