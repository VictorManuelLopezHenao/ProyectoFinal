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

    // Inicializamos el reproductor y la salida de audio
    M_Player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);  // Crear la salida de audio para el reproductor de audio

    // Asignamos la salida de audio al reproductor de audio
    M_Player->setAudioOutput(audioOutput);

    // Establecemos el volumen inicial basado en el valor del slider
    vol = ui->horizontalSlider_Volume_Control->value() / 100.0;  // Convertir a rango [0.0, 1.0]
    audioOutput->setVolume(vol);  // Ajustar el volumen inicial

    // Configuración del reproductor de video
    Player = new QMediaPlayer(this);
    videoAudioOutput = new QAudioOutput(this);  // Crear salida de audio separada para el video
    Player->setAudioOutput(videoAudioOutput);   // Asignar la salida de audio al reproductor de video

    // Ajustes visuales del reproductor de video
    ui->pushButton_Play_PauseV->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->pushButton_StopV->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    ui->pushButton_Seek_BackwardV->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
    ui->pushButton_Seek_ForwardV->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));
    ui->pushButton_VolumeV->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));

    // Ajustamos el slider de volumen del video
    ui->horizontalSlider_VolumeV->setMinimum(0);
    ui->horizontalSlider_VolumeV->setMaximum(100);
    ui->horizontalSlider_VolumeV->setValue(30);

    // Inicializamos el volumen en el reproductor de video
    videoAudioOutput->setVolume(ui->horizontalSlider_VolumeV->value() / 100.0);

    // Inicializamos las banderas de estado
    IS_Pause = true;
    IS_Muted = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Acción para abrir archivo de audio
void MainWindow::on_actionOpen_File_triggered()
{
    QString FileName = QFileDialog::getOpenFileName(this, tr("Select Audio File"), "", tr("MP3 Files (*.mp3)"));

    // Asignar el archivo seleccionado al reproductor de audio
    M_Player->setSource(QUrl::fromLocalFile(FileName));

    QFileInfo File(FileName);

    // Mostrar el nombre del archivo en la interfaz
    ui->Lbl_Value_File_Name->setText(File.fileName());
}

// Botón para reproducir el audio
void MainWindow::on_pushButton_Play_clicked()
{
    M_Player->play();
}

// Botón para pausar el audio
void MainWindow::on_pushButton_Pause_clicked()
{
    M_Player->stop();
}

// Control del volumen del reproductor de audio
void MainWindow::on_horizontalSlider_Volume_Control_valueChanged(int value)
{
    vol = value / 100.0;  // Convertir el valor del slider a un rango [0.0, 1.0]
    audioOutput->setVolume(vol);  // Ajustar el volumen de la salida de audio
}

// Acción para abrir archivo de video
void MainWindow::on_actionOpen_File_Video_triggered()
{
    QString FileName = QFileDialog::getOpenFileName(this, tr("Select Video File"), "", tr("MP4 Files (*.mp4)"));

    // Configuramos el reproductor de video
    Video = new QVideoWidget();
    Video->setGeometry(5, 5, ui->groupBox_Video->width() - 10, ui->groupBox_Video->height() - 10);
    Video->setParent(ui->groupBox_Video);

    Player->setVideoOutput(Video);  // Asignar el reproductor al widget de video
    Player->setSource(QUrl::fromLocalFile(FileName));  // Asignar el archivo de video

    Video->setVisible(true);
    Video->show();
}

// Control del progreso del video
void MainWindow::on_horizontalSlide_DurationV_valueChanged(int value)
{
    Player->setPosition(value * 1000);  // Establecer la posición en milisegundos
}

// Botón para reproducir o pausar el video
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

// Botón para detener el video
void MainWindow::on_pushButton_StopV_clicked()
{
    Player->stop();
}

// Botón para mutear el video
void MainWindow::on_pushButton_VolumeV_clicked()
{
    if (!IS_Muted)
    {
        IS_Muted = true;
        ui->pushButton_VolumeV->setIcon(style()->standardIcon(QStyle::SP_MediaVolumeMuted));
        videoAudioOutput->setMuted(true);  // Mutear la salida de audio del video
    }
    else
    {
        IS_Muted = false;
        ui->pushButton_VolumeV->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
        videoAudioOutput->setMuted(false);  // Desmutear la salida de audio del video
    }
}

// Control del volumen del video
void MainWindow::on_horizontalSlider_VolumeV_valueChanged(int value)
{
    videoAudioOutput->setVolume(value / 100.0);  // Ajustar el volumen del reproductor de video
}

// Botón para retroceder en el video
void MainWindow::on_pushButton_Seek_BackwardV_clicked()
{
    ui->horizontalSlide_DurationV->setValue(ui->horizontalSlide_DurationV->value() - 20);
    Player->setPosition(ui->horizontalSlide_DurationV->value() * 1000);
}

// Botón para avanzar en el video
void MainWindow::on_pushButton_Seek_ForwardV_clicked()
{
    ui->horizontalSlide_DurationV->setValue(ui->horizontalSlide_DurationV->value() + 20);
    Player->setPosition(ui->horizontalSlide_DurationV->value() * 1000);
}
