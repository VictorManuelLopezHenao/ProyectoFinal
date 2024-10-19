#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia>
#include <QFileDialog>
#include <QStyle>
#include <QAudioOutput>

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

    void on_pushButton_Next_clicked();

    void on_pushButton_Back_clicked();

    void on_pushButton_Repet_clicked();

    void on_pushButton_Mute_clicked();

    void on_progressBar_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QMediaPlayer *M_Player;
    QAudioOutput *audioOutput;
    float vol;  // Cambié qfloat16 a float
};

#endif // MAINWINDOW_H
