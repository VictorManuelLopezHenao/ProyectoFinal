#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QVideoWidget>
#include <QStyle>
#include <QFileInfo>
#include <QMediaPlayer>
#include <QAudioOutput>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Configuración del reproductor de video
    Player = new QMediaPlayer(this);
    videoAudioOutput = new QAudioOutput(this);  // Crear salida de audio para el video
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
    ui->horizontalSlider_VolumeV->setValue(30); // Volumen inicial

    // Inicializamos el volumen en el reproductor de video
    videoAudioOutput->setVolume(ui->horizontalSlider_VolumeV->value() / 100.0);

    // Inicializamos las banderas de estado
    IS_Pause = true;
    IS_Muted = false;

    //Barra y tiempo de duracion de los archivos
    connect(Player, &QMediaPlayer::durationChanged, this, &MainWindow::durationChanged);
    connect(Player, &QMediaPlayer::positionChanged, this, &MainWindow::positionChanged);
    // En el constructor
    ui->horizontalSlide_DurationV->setRange(0, 0);
    Mduration = 0; //Que inicie en 0
}

MainWindow::~MainWindow()
{
    delete ui;
}


// Función para actualizar la duración mostrada
void MainWindow::updateDuration(qint64 duration)
{
    if (duration > 0 && Mduration > 0) {
        QTime CurrentTime((duration / 3600) % 60, (duration / 60) % 60, duration % 60);
        QTime TotalTime((Mduration / 3600) % 60, (Mduration / 60) % 60, Mduration % 60);

        QString format = "mm:ss";
        if (Mduration > 3600) {
            format = "hh:mm:ss";
        }

        ui->label_Current_Time->setText(CurrentTime.toString(format));
        ui->label_Total_Time->setText(TotalTime.toString(format));
    }
}

// Función para manejar el cambio de duración
void MainWindow::durationChanged(qint64 duration)
{
    Mduration = duration / 1000; // Convertir a segundos
    ui->horizontalSlide_DurationV->setMaximum(Mduration); // Establecer el rango máximo
}

// Función para manejar el cambio de posición
void MainWindow::positionChanged(qint64 position)
{
    if (!ui->horizontalSlide_DurationV->isSliderDown()) {
        updateDuration(position / 1000); // Actualiza el tiempo mostrado
        ui->horizontalSlide_DurationV->setValue(position / 1000); // Actualiza la barra de progreso
    }
}

// Acción para abrir archivo de video
void MainWindow::on_actionOpen_File_Video_triggered()
{
    QString FileName = QFileDialog::getOpenFileName(this, tr("Select Video File"), "", tr("MP4 Files (*.mp4)"));
    if (!FileName.isEmpty()) {
        Video = new QVideoWidget();
        Video->setGeometry(5, 5, ui->groupBox_Video->width() - 10, ui->groupBox_Video->height() - 10);
        Video->setParent(ui->groupBox_Video);

        Player->setVideoOutput(Video);  // Asignar el reproductor al widget de video
        Player->setSource(QUrl::fromLocalFile(FileName));  // Asignar el archivo de video

        Video->setVisible(true);
        Video->show();
    }
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
    IS_Muted = !IS_Muted;
    ui->pushButton_VolumeV->setIcon(IS_Muted ? style()->standardIcon(QStyle::SP_MediaVolumeMuted) : style()->standardIcon(QStyle::SP_MediaVolume));
    videoAudioOutput->setMuted(IS_Muted);  // Mutear o desmutear la salida de audio del video
}

// Control del volumen del video
void MainWindow::on_horizontalSlider_VolumeV_valueChanged(int value)
{
    videoAudioOutput->setVolume(value / 100.0);  // Ajustar el volumen del reproductor de video
}

// Botón para retroceder en el video
void MainWindow::on_pushButton_Seek_BackwardV_clicked()
{
    int newValue = ui->horizontalSlide_DurationV->value() - 20;
    ui->horizontalSlide_DurationV->setValue(qMax(0, newValue));
    Player->setPosition(ui->horizontalSlide_DurationV->value() * 1000);
}

// Botón para avanzar en el video
void MainWindow::on_pushButton_Seek_ForwardV_clicked()
{
    int newValue = ui->horizontalSlide_DurationV->value() + 20;
    ui->horizontalSlide_DurationV->setValue(newValue);
    Player->setPosition(ui->horizontalSlide_DurationV->value() * 1000);
}
