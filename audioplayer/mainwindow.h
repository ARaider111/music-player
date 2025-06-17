#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QtMultimedia>
#include <QListWidgetItem>
#include "startwindow.h"
#include <QAudioOutput>
#include <QPushButton>


namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QString str ,QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void durationChanged(qint64 duration);
    void positionChanged(qint64 progress);

    void on_pushButton_clicked();
    void onItemDoubleClicked(QListWidgetItem *item);

    void on_next_btn_clicked();

    void on_previous_btn_clicked();

    void on_timeSlider_valueChanged(int value);

    void on_autoplay_btn_clicked();

    void on_repeat_btn_clicked();

signals:
    void requestGoToStartWindow();

private:
    QStringList inputMediaFiles(QString str);

private:
    void updateDuration(qint64 duration);

    bool fileExists(const QString &filePath);
    bool isValidIndex(int index);
    bool removeMissingFile(int &index);
    void setupPlayer(const QString &trackPath);

    bool playTrackAtIndex(int index);
    void playTrackAtIndexUI(int index);

    void playNextTrack();
    void playPreviousTrack();

    void autoPlayNextTrack();
    void repeatCurrentTrack();
    void updatePlayButtonToPlayIcon();

    void toggleAutoplay();
    void toggleRepeat();
    void autoPlayTrack(QMediaPlayer::PlaybackState state);
    void updateTrackNameUI();

    void onMusicDirectoryChanged(const QString &path);
    void checkMusicDirectoryExists();

    void repeatTrack(QMediaPlayer::PlaybackState state);

    void setWhiteStandardIcon(QPushButton* button, QStyle::StandardPixmap sp, const QSize& size = QSize(25, 25));

    Ui::MainWindow *ui;
    QString musicDirectory;
    QFileSystemWatcher *fileSystemWatcher;
    QTimer *checkDirTimer;
    QStringList currentPlaylist;
    QMediaPlayer *m_player;
    QAudioOutput *m_audioOutput;
    qint64 m_duration;
    QString currentTrackPath;
    bool autoplayEnable = false;
    bool isReapeted = false;
    int currentTrackIndex = -1;


public:
    void setMusicDirectory(const QString &path);
    void refreshPlaylist(const QString &path);
    void updatePlayListUI();
};

#endif // MAINWINDOW_H
