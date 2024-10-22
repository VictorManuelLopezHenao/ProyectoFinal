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

private:
    Ui::MainWindow *ui;

    // Reproductor de video
    QMediaPlayer *Player;           // Reproductor de video
    QVideoWidget *Video;            // Widget de video
    QAudioOutput *videoAudioOutput; // Salida de audio para el reproductor de video
    qint64 mDuration;               // Duración del video

    // Estado del reproductor de video
    bool IS_Pause;                  // Indica si el video está pausado
    bool IS_Muted;                  // Indica si el video está silenciado
};

#endif // MAINWINDOW_H
