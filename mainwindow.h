#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia>
#include <QFileDialog>
#include <QStyle>
#include <QAudioOutput>

#include <QtMultimediaWidgets> // Nuevo
#include <QtCore>              // Nuevo
#include <QtWidgets>           // Nuevo
#include <QtGui>               // Nuevo

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
    void on_actionOpen_File_triggered();
    void on_pushButton_Play_clicked();
    void on_pushButton_Pause_clicked();
    void on_horizontalSlider_Volume_Control_valueChanged(int value);

    void on_actionOpen_File_Video_triggered();
    void on_horizontalSlide_DurationV_valueChanged(int value);

    void on_pushButton_Play_PauseV_clicked();
    void on_pushButton_StopV_clicked();
    void on_pushButton_VolumeV_clicked();
    void on_horizontalSlider_VolumeV_valueChanged(int value);
    void on_pushButton_Seek_BackwardV_clicked();
    void on_pushButton_Seek_ForwardV_clicked();

private:
    Ui::MainWindow *ui;

    // Reproductor de audio
    QMediaPlayer *M_Player;        // Reproductor de audio
    QAudioOutput *audioOutput;     // Salida de audio para el reproductor de audio
    float vol;                     // Control de volumen (float en lugar de qfloat16)

    // Reproductor de video
    QMediaPlayer *Player;          // Reproductor de video
    QVideoWidget *Video;           // Widget de video
    QAudioOutput *videoAudioOutput; // NUEVO: salida de audio separada para video
    qint64 mDuration;              // Duración del video

    // Estado del reproductor de video
    bool IS_Pause;                 // Indica si el video está pausado
    bool IS_Muted;                 // Indica si el video está silenciado
};

#endif // MAINWINDOW_H

