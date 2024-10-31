#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QVideoWidget>
#include <QStyle>
#include <QFileInfo>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QMessageBox>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString dir = "/";
    directorio = new QFileSystemModel(this);
    directorio->setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);
    directorio->setRootPath(dir);

    ui->treeView->setModel(directorio);

    archivo = new QFileSystemModel(this);
    archivo->setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);
    archivo->setRootPath(dir);

    ui->listView->setModel(archivo);

    // Configuración del reproductor de video
    Player = new QMediaPlayer(this);
    videoAudioOutput = new QAudioOutput(this);
    Player->setAudioOutput(videoAudioOutput);

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
    videoAudioOutput->setVolume(ui->horizontalSlider_VolumeV->value() / 100.0);

    // Inicializamos las banderas de estado
    IS_Pause = true;
    IS_Muted = false;

    // Barra y tiempo de duración de los archivos
    connect(Player, &QMediaPlayer::durationChanged, this, &MainWindow::durationChanged);
    connect(Player, &QMediaPlayer::positionChanged, this, &MainWindow::positionChanged);

    // En el constructor
    ui->horizontalSlide_DurationV->setRange(0, 0);
    Mduration = 0;

    // Configuración del QTimer para actualizar el slider
    updateTimer = new QTimer(this);
    updateTimer->setInterval(500);  // Actualiza cada medio segundo
    connect(updateTimer, &QTimer::timeout, this, &MainWindow::updateSliderPosition);
    updateTimer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Función para actualizar la posición del slider
void MainWindow::updateSliderPosition()
{
    if (!ui->horizontalSlide_DurationV->isSliderDown()) {
        ui->horizontalSlide_DurationV->blockSignals(true);
        ui->horizontalSlide_DurationV->setValue(Player->position() / 1000);
        ui->horizontalSlide_DurationV->blockSignals(false);
    }
    updateDuration(Player->position() / 1000);
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
    Mduration = duration / 1000;
    ui->horizontalSlide_DurationV->setMaximum(Mduration);
}

// Función para manejar el cambio de posición
void MainWindow::positionChanged(qint64)
{
    if (!ui->horizontalSlide_DurationV->isSliderDown()) {
        updateSliderPosition();  // Mover la lógica al QTimer
    }
}

//Mostrar el video en pantalla
void MainWindow::on_actionOpen_File_Video_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Video File"), "", tr("Video Files (*.mp4 *.avi *.mkv)"));
    if (!fileName.isEmpty()) {
        // Configurar el QVideoWidget si aún no está inicializado
        Video = new QVideoWidget();
        Video->setGeometry(5, 5, ui->groupBox_Video->width() - 10, ui->groupBox_Video->height() - 10);
        Video->setParent(ui->groupBox_Video);

        // Configurar la salida de video y el archivo de video
        Player->setVideoOutput(Video);
        Player->setSource(QUrl::fromLocalFile(fileName));

        // Mostrar el video y reproducir
        Video->setVisible(true);
        Video->show();
        Player->play();

        // Actualizar la etiqueta con el nombre del archivo
        QFileInfo fileInfo(fileName);
        ui->label_Value_File_Name->setText(fileInfo.fileName());

        // Cambiar el icono del botón de reproducción a "pausa"
        IS_Pause = false;
        ui->pushButton_Play_PauseV->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    }
}

// Control del progreso del video
void MainWindow::on_horizontalSlide_DurationV_valueChanged(int value)
{
    Player->setPosition(value * 1000);
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
    videoAudioOutput->setMuted(IS_Muted);
}

// Control del volumen del video
void MainWindow::on_horizontalSlider_VolumeV_valueChanged(int value)
{
    videoAudioOutput->setVolume(value / 100.0);
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

// Manejo del clic en treeView para actualizar listView o reproducir archivos multimedia
void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        QMessageBox::warning(this, tr("Error"), tr("No se ha seleccionado ningún archivo o directorio."));
        return;
    }

    QString filePath = directorio->fileInfo(index).absoluteFilePath();

    if (directorio->fileInfo(index).isDir()) {
        ui->listView->setRootIndex(archivo->setRootPath(filePath));
    } else {
        qDebug() << "Archivo seleccionado:" << filePath;

        if (Video) {
            delete Video;
            Video = nullptr;
        }

        Video = new QVideoWidget(ui->groupBox_Video);
        Video->setGeometry(5, 5, ui->groupBox_Video->width() - 10, ui->groupBox_Video->height() - 10);
        Video->setVisible(true);
        Video->setParent(ui->groupBox_Video);

        Player->setVideoOutput(Video);

        if (QFileInfo::exists(filePath) && QFileInfo(filePath).isFile()) {
            Player->setSource(QUrl::fromLocalFile(filePath));
            Player->play();

            IS_Pause = false;
            ui->pushButton_Play_PauseV->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        } else {
            QMessageBox::warning(this, tr("Error"), tr("El archivo seleccionado no existe o no es un archivo válido."));
        }

        Video->show();
    }
}
