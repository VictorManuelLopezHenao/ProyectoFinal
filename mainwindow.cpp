#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QVideoWidget>
#include <QStyle>
#include <QFileInfo>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QMessageBox>

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

    // Inicializamos el volumen en el reproductor de video
    videoAudioOutput->setVolume(ui->horizontalSlider_VolumeV->value() / 100.0);

    // Inicializamos las banderas de estado
    IS_Pause = true;
    IS_Muted = false;

    // Barra y tiempo de duración de los archivos
    connect(Player, &QMediaPlayer::durationChanged, this, &MainWindow::durationChanged);
    connect(Player, &QMediaPlayer::positionChanged, this, &MainWindow::positionChanged);

    // En el constructor
    ui->horizontalSlide_DurationV->setRange(0, 0);
    Mduration = 0; // Que inicie en 0
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

        Player->setVideoOutput(Video);
        Player->setSource(QUrl::fromLocalFile(FileName));

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
        // Si está en pausa, iniciar la reproducción
        IS_Pause = false;
        Player->play();
        ui->pushButton_Play_PauseV->setIcon(style()->standardIcon(QStyle::SP_MediaPause));  // Mostrar ícono de pausa
    }
    else
    {
        // Si está reproduciéndose, pausar
        IS_Pause = true;
        Player->pause();
        ui->pushButton_Play_PauseV->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));  // Mostrar ícono de play
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
    // Verificar que el índice sea válido
    if (!index.isValid()) {
        QMessageBox::warning(this, tr("Error"), tr("No se ha seleccionado ningún archivo o directorio."));
        return;
    }

    QString filePath = directorio->fileInfo(index).absoluteFilePath();

    // Comprobar si es un directorio
    if (directorio->fileInfo(index).isDir()) {
        ui->listView->setRootIndex(archivo->setRootPath(filePath));
    } else {
        // Si es un archivo, reproducirlo
        qDebug() << "Archivo seleccionado:" << filePath;

        // Limpiar el widget de video si ya existe
        if (Video) {
            delete Video; // Eliminar el widget de video
            Video = nullptr; // Establecer el puntero a nullptr
        }

        // Crear un nuevo QVideoWidget para mostrar el video
        Video = new QVideoWidget(ui->groupBox_Video);
        Video->setGeometry(5, 5, ui->groupBox_Video->width() - 10, ui->groupBox_Video->height() - 10);
        Video->setVisible(true);
        Video->setParent(ui->groupBox_Video); // Establecer el padre

        // Asignar el video al reproductor
        Player->setVideoOutput(Video);

        // Comprobar si el archivo existe y es un archivo de video válido
        if (QFileInfo::exists(filePath) && QFileInfo(filePath).isFile()) {
            Player->setSource(QUrl::fromLocalFile(filePath)); // Cargar el archivo seleccionado
            Player->play(); // Reproducir automáticamente

            // Actualizar el estado y el ícono del botón play/pause
            IS_Pause = false;
            ui->pushButton_Play_PauseV->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        } else {
            QMessageBox::warning(this, tr("Error"), tr("El archivo seleccionado no existe o no es un archivo válido."));
        }

        Video->show(); // Mostrar el widget de video
    }
}
