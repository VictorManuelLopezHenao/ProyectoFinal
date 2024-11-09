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


///////////////////////////////////////////////////////////////////////////// NUEVO

    // Inicialización del VideoWidget
    Video = new QVideoWidget(this); // Crea una nueva instancia de QVideoWidget
    Video->setGeometry(5, 5, ui->groupBox_Video->width() - 10, ui->groupBox_Video->height() - 10);
    Video->setParent(ui->groupBox_Video); // Establece el padre del VideoWidget

    // Configuración del QFileSystemModel para el treeView
    directorio = new QFileSystemModel(this);
    directorio->setRootPath(QDir::rootPath());
    ui->treeView->setModel(directorio);
    ui->treeView->setRootIndex(directorio->index(QDir::rootPath())); // Muestra el root por defecto

    // Conectar la señal de selección
    connect(ui->treeView, &QTreeView::clicked, this, &MainWindow::on_treeView_clicked);

    // Configuración del reproductor de video
    Player = new QMediaPlayer(this);
    videoAudioOutput = new QAudioOutput(this);
    Player->setAudioOutput(videoAudioOutput);
    Player->setVideoOutput(Video); // Asegúrate de que el reproductor
/////////////////////////////////////////////////////////////////////////////


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
    delete Player;
    delete videoAudioOutput;
    delete Video; // Eliminar el VideoWidget
    delete ui;
}


//Mostrar el video en pantalla
void MainWindow::on_actionOpen_File_Video_triggered()
{
    // No hacer nada aquí. La inicialización del video se manejará desde el treeView.
    QMessageBox::information(this, tr("Información"), tr("Por favor selecciona un archivo de video desde el árbol de archivos."));
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


/////////////////////////////////////////////////////////////////////////////// NUEVO
/////////////////////////////////////////////////////////////////////////////// NUEVO



void MainWindow::createVideoWidget() {
    // Solo crear el widget si no existe uno ya
    if (!Video) {
        // Verificar que Player no es nulo antes de configurarlo
        if (!Player) {
            qDebug() << "Error: El reproductor de video no está inicializado.";
            return; // No continuar si Player no está inicializado
        }

        Video = new QVideoWidget(this);  // Crear una nueva instancia si no existe
        Video->setGeometry(5, 5, ui->groupBox_Video->width() - 10, ui->groupBox_Video->height() - 10);
        Video->setParent(ui->groupBox_Video);  // Colocar el widget en el groupBox

        // Configurar el reproductor de video
        Player->setVideoOutput(Video);
        Video->setVisible(true);
        Video->show();
        qDebug() << "VideoWidget creado y configurado correctamente.";
    }
}

// Función para manejar el clic en el treeView
void MainWindow::on_treeView_clicked(const QModelIndex &index) {
    // Verifica si el índice es válido
    if (!index.isValid()) {
        qDebug() << "Error: Índice no válido.";
        return;  // No hacer nada si el índice no es válido
    }

    QString filePath = directorio->filePath(index);
    QFileInfo fileInfo(filePath);

    // Verifica que el archivo sea de un tipo específico (video o audio)
    if (fileInfo.isFile() && (fileInfo.suffix() == "mp4" || fileInfo.suffix() == "avi" || fileInfo.suffix() == "mkv" || fileInfo.suffix() == "mp3")) {

        qDebug() << "Archivo seleccionado: " << filePath;

        // Si ya hay un reproductor de video, detenerlo antes de cargar el nuevo archivo
        if (Player) {
            Player->stop();  // Detener el reproductor si ya está reproduciendo
            qDebug() << "Reproductor detenido.";
        }



        // Verifica si la URL es válida antes de configurar el reproductor
        if (QFile::exists(filePath)) {
            qDebug() << "Archivo encontrado. Cargando en el reproductor.";
            Player->setSource(QUrl::fromLocalFile(filePath));

            // Reiniciar la reproducción desde el inicio
            Player->play();  // Iniciar la reproducción del archivo seleccionado
            qDebug() << "Reproducción iniciada.";

            // Cambiar el icono de reproducción a "pausa"
            IS_Pause = false;
            ui->pushButton_Play_PauseV->setIcon(style()->standardIcon(QStyle::SP_MediaPause));

            // Actualizar la etiqueta con el nombre del archivo
            ui->label_Value_File_Name->setText(fileInfo.fileName());

            // Asegurarse de que el video se muestra correctamente
            if (Video) {
                Video->setVisible(true);  // Mostrar el VideoWidget si es un archivo de video
                Video->show();
                qDebug() << "VideoWidget visible.";
            }

        } else {
            qDebug() << "Error: El archivo no existe.";
            QMessageBox::warning(this, tr("Error de archivo"), tr("El archivo seleccionado no se puede encontrar."));
        }

    } else {
        // Si el archivo no es un archivo de video, mostrar mensaje y ocultar el video
        if (Video) {
            Video->hide();  // Esconder el VideoWidget si no es un archivo de video
        }
        QMessageBox::warning(this, tr("Formato no soportado"), tr("Por favor selecciona un archivo de video o audio válido."));
    }
}


/////////////////////////////////////////////////////////////////////////////////
