#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QFileDialog>
#include <QStyle>
#include <QAudioOutput>
#include <QtCore>
#include <QtWidgets>
#include <QtGui>
#include <QTimer>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateSliderPosition(); // Declaración de la función
    // Barra y tiempo de duración del archivo multimedia
    void durationChanged(qint64 duration);
    void positionChanged(qint64 position);

    // Acciones relacionadas con archivos de video
    void on_actionOpen_File_Video_triggered();
    void on_horizontalSlide_DurationV_valueChanged(int value);

    // Controles del reproductor de video
    void on_pushButton_Play_PauseV_clicked();
    void on_pushButton_StopV_clicked();
    void on_pushButton_VolumeV_clicked();
    void on_horizontalSlider_VolumeV_valueChanged(int value);
    void on_pushButton_Seek_BackwardV_clicked();
    void on_pushButton_Seek_ForwardV_clicked();

    void on_treeView_clicked(const QModelIndex &index);

    // Manejo de selección en el QListWidget (selección de archivo para reproducir)
    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;

    QTimer *updateTimer; // Declaración del QTimer

    // Reproductor de video
    QMediaPlayer *Player;           // Reproductor de video
    QVideoWidget *Video;            // Widget de video
    QAudioOutput *videoAudioOutput; // Salida de audio para el reproductor de video
    qint64 Mduration;               // Duración del video

    // Reproductor de audio para MP3
    QMediaPlayer *audioPlayer;      // Reproductor de audio
    QAudioOutput *audioOutput;     // Salida de audio para el MP3

    // Estado del reproductor de video
    bool IS_Pause;                  // Indica si el video está pausado
    bool IS_Muted;                  // Indica si el video está silenciado

    QFileSystemModel *directorio;
    QFileSystemModel *archivo;

    QListWidget *listWidget;       // Puntero al QListWidget para mostrar los archivos

    void updateDuration(qint64 duration);  // Función para la duración del archivo multimedia
    void createVideoWidget();
};

#endif // MAINWINDOW_H
