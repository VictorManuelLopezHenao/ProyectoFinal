#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Inicializamos el reproductor sin la salida de audio
    M_Player = new QMediaPlayer(this);

    // Ajustamos los íconos de los botones
    ui->pushButton_Play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->pushButton_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));

    // Establecemos el volumen inicial basado en el valor del slider
    vol = ui->horizontalSlider_Volume_Control->value() / 100.0;  // Convertir a rango [0.0, 1.0]
    M_Player->setVolume(vol * 100);  // Ajustar el volumen inicial en un rango [0, 100]
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_File_triggered()
{
    QString FileName = QFileDialog::getOpenFileName(this, tr("Select Audio File"), "", tr("MP3 Files (*.mp3)"));

    // Asignar el archivo seleccionado al reproductor
    M_Player->setMedia(QUrl::fromLocalFile(FileName));  // Usar setMedia para versiones de Qt 5

    QFileInfo File(FileName);

    // Mostrar el nombre del archivo en la interfaz
    ui->Lbl_Value_File_Name->setText(File.fileName());
}

void MainWindow::on_pushButton_Play_clicked()
{
    // Iniciar la reproducción
    M_Player->play();
}

void MainWindow::on_pushButton_Pause_clicked()
{
    // Pausar la reproducción
    M_Player->stop();
}

void MainWindow::on_horizontalSlider_Volume_Control_valueChanged(int value)
{
    // Actualizar el volumen cuando se cambia el slider
    vol = value / 100.0;  // Convertir el valor del slider a un rango [0.0, 1.0]
    M_Player->setVolume(vol * 100);  // Ajustar el volumen en un rango [0, 100]
}



void MainWindow::on_pushButton_Next_clicked() //Boton de Next
{
}

void MainWindow::on_pushButton_Back_clicked() //Boton de Back
{
}

void MainWindow::on_pushButton_Repet_clicked()  //Boton Repet
{
}

void MainWindow::on_pushButton_Mute_clicked()   //Boton Mute
{
}



