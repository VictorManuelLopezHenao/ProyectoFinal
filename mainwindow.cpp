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
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow),
    audioPlayer(nullptr), Player(nullptr), videoAudioOutput(nullptr)  // Inicialización de punteros
{
    ui->setupUi(this);  // Setup de la UI

    // Inicialización del VideoWidget
    Video = new QVideoWidget(this);
    Video->setParent(ui->groupBox_Video);

    //NUEVO
    QVBoxLayout *videoLayout = new QVBoxLayout(ui->groupBox_Video);
    videoLayout->addWidget(Video);
    videoLayout->setContentsMargins(0, 0, 0, 0);  // Sin márgenes para un ajuste completo
    ui->groupBox_Video->setLayout(videoLayout);
    //


    audioPlayer = new QMediaPlayer(this);
    videoAudioOutput = new QAudioOutput(this);  // Asegúrate de que el QAudioOutput esté configurado
    audioPlayer->setAudioOutput(videoAudioOutput);  // Asocia audioPlayer con videoAudioOutput
 // Si deseas configurar una salida de audio para audioPlayer
    // Configuración del QFileSystemModel para el treeView
    directorio = new QFileSystemModel(this);
    directorio->setRootPath(QDir::rootPath());
    ui->treeView->setModel(directorio);
    ui->treeView->setRootIndex(directorio->index(QDir::rootPath())); // Muestra el root por defecto

    // Inicializar el QListWidget
    listWidget = ui->listWidget; // Asumiendo que tienes un QListWidget en tu UI
    listWidget->clear();  // Limpiar el QListWidget al inicio
    listWidget->setSelectionMode(QAbstractItemView::SingleSelection); // Permitir selección de un solo item

    // Conectar la señal de selección de carpeta
    connect(ui->treeView, &QTreeView::clicked, this, &MainWindow::on_treeView_clicked);

    // Conectar la selección de archivos en el QListWidget
    connect(listWidget, &QListWidget::itemClicked, this, &MainWindow::on_listWidget_itemClicked);

    // Configuración del reproductor de video
    Player = new QMediaPlayer(this);
    videoAudioOutput = new QAudioOutput(this);
    Player->setAudioOutput(videoAudioOutput);
    Player->setVideoOutput(Video); // Asegúrate de que el reproductor
    connect(Player, &QMediaPlayer::playbackStateChanged, this, &MainWindow::onVideoStateChanged);

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

void MainWindow::onVideoStateChanged(QMediaPlayer::PlaybackState state) {
    if (state == QMediaPlayer::StoppedState) {
        // Si el video se detuvo, reiniciarlo para que esté listo para la próxima reproducción
        Player->setPosition(0); // Reiniciar el video
        Player->play(); // Reproducir el video en bucle
    }
}

// Función para actualizar la posición del slider
void MainWindow::updateSliderPosition() {
    if (!ui->horizontalSlide_DurationV->isSliderDown()) {
        ui->horizontalSlide_DurationV->blockSignals(true);

        // Verificar si el audio o el video están reproduciéndose
        if (audioPlayer->playbackState() == QMediaPlayer::PlayingState) {
            qint64 position = audioPlayer->position();
            ui->horizontalSlide_DurationV->setValue(position / 1000);
            updateDuration(position / 1000);
        } else if (Player->playbackState() == QMediaPlayer::PlayingState) {
            qint64 position = Player->position();
            ui->horizontalSlide_DurationV->setValue(position / 1000);
            updateDuration(position / 1000);
        }

        ui->horizontalSlide_DurationV->blockSignals(false);
    }
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
void MainWindow::durationChanged(qint64 duration) {
    Mduration = duration / 1000;
    ui->horizontalSlide_DurationV->setMaximum(Mduration);

    QTime TotalTime((Mduration / 3600) % 60, (Mduration / 60) % 60, Mduration % 60);
    QString format = "mm:ss";
    if (Mduration > 3600) {
        format = "hh:mm:ss";
    }
    ui->label_Total_Time->setText(TotalTime.toString(format));
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
void MainWindow::on_pushButton_Play_PauseV_clicked() {
    if (IS_Pause) {
        // Reanudar reproducción solo del reproductor activo (audio o video)
        if (audioPlayer->playbackState() == QMediaPlayer::PausedState) {
            audioPlayer->play();
        }
        if (Player->playbackState() == QMediaPlayer::PausedState) {
            Player->play();
        }

        // Cambiar el icono a "Pausar"
        ui->pushButton_Play_PauseV->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    } else {
        // Pausar ambos reproductores
        Player->pause();
        audioPlayer->pause();

        // Cambiar icono a "Reproducir"
        ui->pushButton_Play_PauseV->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    }
    IS_Pause = !IS_Pause;

}


// Botón para detener el video
void MainWindow::on_pushButton_StopV_clicked()
{
    Player->stop();

    // Regresar al inicio del video (en el tiempo 0)
    Player->setPosition(0);  // Regresa al principio

    // Reproducir el video nuevamente
    Player->play();
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

// Botón para volver a la cancion anterior
void MainWindow::on_pushButton_Seek_BackwardV_clicked() {
    int currentIndex = listWidget->currentRow();
    if (currentIndex > 0) {
        listWidget->setCurrentRow(currentIndex - 1);
        on_listWidget_itemClicked(listWidget->currentItem()); // Reproducir archivo seleccionado
    }
}



// Botón para avanzar a la siguinete cancion
void MainWindow::on_pushButton_Seek_ForwardV_clicked() {
    int currentIndex = listWidget->currentRow();
    if (currentIndex < listWidget->count() - 1) {
        listWidget->setCurrentRow(currentIndex + 1);
        on_listWidget_itemClicked(listWidget->currentItem()); // Reproducir archivo seleccionado
    }
}

///////////////////// NUEVO

// Variable para verificar el estado de pantalla completa
bool isFullscreen = false;
QWidget *fullscreenOverlay = nullptr;

void MainWindow::on_pushButton_Fullscreen_clicked()
{
    if (!Video) {
        qDebug() << "Error: El widget de video no está inicializado.";
        return;
    }

    if (isFullscreen) {
        // Salir de pantalla completa
        Video->setWindowFlags(Qt::Widget);    // Restaurar como widget normal
        Video->showNormal();  // Restaurar la apariencia normal del widget

        // Asegurarse de que el widget de video se ajuste al tamaño de su contenedor
        Video->resize(ui->groupBox_Video->size()); // Ajustar el tamaño al groupBox
        Video->setGeometry(5, 5, ui->groupBox_Video->width() - 10, ui->groupBox_Video->height() - 10);
        isFullscreen = false;

        // Ocultar y eliminar el overlay
        if (fullscreenOverlay) {
            fullscreenOverlay->close();
            delete fullscreenOverlay;
            fullscreenOverlay = nullptr;
        }

        ui->pushButton_Fullscreen->setText("[ ]");
    } else {
        // Ir a pantalla completa
        Video->setWindowFlags(Qt::Window);  // Convertir el widget de video en una ventana independiente
        Video->showFullScreen(); // Mostrar en pantalla completa

        isFullscreen = true;
        ui->pushButton_Fullscreen->setText("[ ]");

        // Crear una ventana flotante (overlay) para el botón en pantalla completa
        fullscreenOverlay = new QWidget(Video);
        fullscreenOverlay->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
        fullscreenOverlay->setAttribute(Qt::WA_TranslucentBackground, true);
        fullscreenOverlay->resize(50, 50); // Tamaño del botón de overlay
        fullscreenOverlay->move(Video->frameGeometry().width() - fullscreenOverlay->width() - 10, 700);

        // Crear el botón en la ventana flotante
        QPushButton *fullscreenButton = new QPushButton("[ ]", fullscreenOverlay);
        fullscreenButton->resize(fullscreenOverlay->size());

        // Conectar el botón al mismo slot para alternar entre los modos
        connect(fullscreenButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_Fullscreen_clicked);

        fullscreenOverlay->show();
    }
}


////////////////////////////////////////


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

//Funcion para manejar el click en las carpetas
void MainWindow::on_treeView_clicked(const QModelIndex &index) {
    // Obtener la ruta completa del archivo o directorio
    QString filePath = directorio->filePath(index);
    QFileInfo fileInfo(filePath);

    // Verificar si se ha seleccionado un directorio
    if (fileInfo.isDir()) {
        // Si es un directorio, actualizar el QListWidget con los archivos contenidos en esa carpeta
        listWidget->clear();  // Limpiar el QListWidget antes de agregar nuevos archivos

        // Cargar los archivos de video y audio en el QListWidget
        QDir dir(filePath);
        QStringList audioFiles = dir.entryList(QStringList() << "*.mp3" << "*.wav" << "*.flac", QDir::Files);
        QStringList videoFiles = dir.entryList(QStringList() << "*.mp4" << "*.avi" << "*.mkv", QDir::Files);

        // Añadir los archivos al QListWidget
        listWidget->addItems(audioFiles);
        listWidget->addItems(videoFiles);

        // Si no hay archivos en la carpeta, mostrar un mensaje
        if (audioFiles.isEmpty() && videoFiles.isEmpty()) {
            QMessageBox::information(this, tr("Sin archivos"), tr("No hay archivos de audio o video en esta carpeta."));
        }
    } else if (fileInfo.isFile()) {
        // Si se selecciona un archivo, verificar si es válido
        if (fileInfo.suffix() == "mp4" || fileInfo.suffix() == "avi" || fileInfo.suffix() == "mkv") {
            // Es un archivo de video
            qDebug() << "Archivo de video seleccionado: " << filePath;

            // Detener cualquier reproducción anterior y cargar el nuevo archivo
            Player->stop();
            Player->setSource(QUrl::fromLocalFile(filePath));
            Player->play();

            // Cambiar el icono del botón de reproducción a "Pausar"
            IS_Pause = false;
            ui->pushButton_Play_PauseV->setIcon(style()->standardIcon(QStyle::SP_MediaPause));

            // Asegurarse de que el VideoWidget esté visible
            if (Video) {
                Video->setVisible(true);
                Video->show();
            }
        } else if (fileInfo.suffix() == "mp3" || fileInfo.suffix() == "wav" || fileInfo.suffix() == "flac") {
            // Es un archivo de audio
            qDebug() << "Archivo de audio seleccionado: " << filePath;

            // Detener cualquier reproducción anterior y cargar el nuevo archivo
            Player->stop();
            Player->setSource(QUrl::fromLocalFile(filePath));
            Player->play();

            // Cambiar el icono del botón de reproducción a "Pausar"
            IS_Pause = false;
            ui->pushButton_Play_PauseV->setIcon(style()->standardIcon(QStyle::SP_MediaPause));

            // Mostrar el video predefinido
            Player->setSource(QUrl("qrc:/new/prefix1/VideoFondoMP3.mp4")); // Establecer el video de fondo
            Player->play(); // Reproducir el video

            // Asegurarse de que el VideoWidget esté visible
            if (Video) {
                Video->setVisible(true);
                Video->show();
            }
        } else {
            // Si el archivo no es válido (ni video ni audio), mostrar un mensaje de advertencia
            QMessageBox::warning(this, tr("Formato no soportado"), tr("Por favor selecciona un archivo de video o audio válido."));
        }
    } else {
        // Si no es un archivo ni un directorio, mostrar un mensaje de error
        QMessageBox::warning(this, tr("Error"), tr("Selecciona una carpeta o un archivo válido."));
    }
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item) {
    QString fileName = item->text();
    QString dirPath = directorio->filePath(ui->treeView->currentIndex());
    QString filePath = QDir(dirPath).filePath(fileName);
    QFileInfo fileInfo(filePath);

    // Parar cualquier reproducción actual (audio y video)
    audioPlayer->stop();  // Detener el audio
    Player->stop();  // Detener el video

    // Limpiar las fuentes de los reproductores antes de asignar nuevas
    audioPlayer->setSource(QUrl());
    Player->setSource(QUrl());

    // Mostrar el nombre del archivo en la etiqueta label_FileName
    ui->label_Value_File_Name->setText(fileInfo.fileName());

    if (fileInfo.suffix() == "mp4" || fileInfo.suffix() == "avi" || fileInfo.suffix() == "mkv") {
        // Reproducción de video
        Player->setSource(QUrl::fromLocalFile(filePath));
        Player->play();

        // Cambiar el icono de "Pausar"
        IS_Pause = false;
        ui->pushButton_Play_PauseV->setIcon(style()->standardIcon(QStyle::SP_MediaPause));

        // Asegurarse de que el VideoWidget esté visible
        if (Video) {
            Video->setVisible(true);
            Video->show();
        }

    } else if (fileInfo.suffix() == "mp3" || fileInfo.suffix() == "wav" || fileInfo.suffix() == "flac") {
        // Reproducción de audio
        audioPlayer->setSource(QUrl::fromLocalFile(filePath));
        audioPlayer->play();

        // Mostrar el video de fondo mientras se reproduce el audio
        Player->setSource(QUrl("qrc:/new/prefix1/VideoFondoMP3.mp4")); // Establecer el video de fondo
        Player->play(); // Reproducir el video de fondo

        // Cambiar el icono de "Pausar"
        IS_Pause = false;
        ui->pushButton_Play_PauseV->setIcon(style()->standardIcon(QStyle::SP_MediaPause));

        // Asegurarse de que el VideoWidget esté visible
        if (Video) {
            Video->setVisible(true);
            Video->show();
        }
    } else {
        // Si el archivo no es válido (ni video ni audio), mostrar un mensaje de advertencia
        QMessageBox::warning(this, tr("Formato no soportado"), tr("Por favor selecciona un archivo de video o audio válido."));
    }
}
