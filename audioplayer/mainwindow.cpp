#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QtMultimedia>
#include <QAudioOutput>
#include <QListWidgetItem>
#include <QIcon>
#include <QPixmap>
#include <QStyle>
#include "startwindow.h"
#include "appcontroller.h"

MainWindow::MainWindow(QString str, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
    , musicDirectory(str)
{

    ui->setupUi(this);

    QIcon repeatIcon(":/svg-icon/svg pictures/media-player-ui-button-repeat-loop-svgrepo-com.svg");
    ui->repeat_btn->setIcon(repeatIcon);
    ui->repeat_btn->setIconSize(QSize(25, 25));

    ui->pushButton->hide();
    ui->currentTime_label->hide();
    ui->time_of_track->hide();
    ui->timeSlider->hide();
    ui->next_btn->hide();
    ui->previous_btn->hide();
    ui->repeat_btn->hide();

    ui->repeat_btn->setCheckable(true);
    ui->repeat_btn->setFlat(true);


    currentPlaylist = inputMediaFiles(musicDirectory);
    ui->listWidget->clear();

    QStringList fileNames;
    for (int i = 0; i < currentPlaylist.size(); ++i)
    {
        fileNames << QFileInfo(currentPlaylist.at(i)).fileName();
    }

    ui->listWidget->addItems(fileNames);

    m_player = new QMediaPlayer(this);
    m_audioOutput = new QAudioOutput(this);

    fileSystemWatcher = new QFileSystemWatcher(this);
    fileSystemWatcher->addPath(musicDirectory);

    checkDirTimer = new QTimer(this);
    connect(checkDirTimer, &QTimer::timeout, this, &MainWindow::checkMusicDirectoryExists);
    checkDirTimer->start(2000);


    connect(ui->listWidget, &QListWidget::itemDoubleClicked, this, &MainWindow::onItemDoubleClicked);
    connect(m_player, &QMediaPlayer::durationChanged, this, &MainWindow::durationChanged);
    connect(m_player, &QMediaPlayer::positionChanged, this, &MainWindow::positionChanged);
    connect(m_player, &QMediaPlayer::playbackStateChanged, this, &MainWindow::autoPlayTrack);
    connect(fileSystemWatcher, &QFileSystemWatcher::directoryChanged,this, &MainWindow::onMusicDirectoryChanged);

    ui->timeSlider->setRange(0,m_player->duration() / 1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setWhiteStandardIcon(QPushButton* button, QStyle::StandardPixmap sp, const QSize& size)
{
    QIcon icon = button->style()->standardIcon(sp);
    QPixmap pixmap = icon.pixmap(size);

    QImage img = pixmap.toImage().convertToFormat(QImage::Format_ARGB32);
    for (int y = 0; y < img.height(); ++y)
    {
        QRgb *line = reinterpret_cast<QRgb*>(img.scanLine(y));
        for (int x = 0; x < img.width(); ++x)
        {
            int alpha = qAlpha(line[x]);
            line[x] = qRgba(255, 255, 255, alpha); // белый цвет с сохранением прозрачности
        }
    }
    QPixmap whitePixmap = QPixmap::fromImage(img);
    QIcon whiteIcon(whitePixmap);

    button->setIcon(whiteIcon);
    button->setIconSize(size);
}



//Отображает текущее время и общее время трека

void MainWindow::updateDuration(qint64 duration)
{
    QString timestr;
    if(duration || m_duration)
    {
        QTime CurrentTime((duration / 3600) % 60, (duration / 60) % 60, duration % 60, (duration * 1000) % 1000);
        QTime totalTime((m_duration / 3600) % 60, (m_duration / 60) % 60, m_duration % 60, (m_duration * 1000) % 1000);

        QString format = "mm:ss";
        if(m_duration > 3600)
        {
            format = "hh:mm:ss";
        }
        ui->currentTime_label->setText(CurrentTime.toString(format));
        ui->time_of_track->setText(totalTime.toString(format));
    }
}

//Обрабатывает изменение общей продолжительности трека

void MainWindow::durationChanged(qint64 duration)
{
    m_duration = duration / 1000;
    ui->timeSlider->setMaximum(m_duration);
}

//Обрабатывает изменение прогресс бара

void MainWindow::positionChanged(qint64 progress)
{
    if(!ui->timeSlider->isSliderDown())
    {
        ui->timeSlider->setValue(progress / 1000);
    }
    updateDuration(progress / 1000);
}

//Позволяет пользователю манипулировать прогресс баром

void MainWindow::on_timeSlider_valueChanged(int value)
{
    m_player->setPosition(value * 1000);
}

//Выводит музыки в интерфейс из выбранной папки

QStringList MainWindow::inputMediaFiles(QString str)
{
    QDir dir(str);
    QStringList filter = {"*.mp3","*.wav", "*.flac"};
    dir.setNameFilters(filter);

    QStringList fileNames = dir.entryList(QDir::Files);
    QStringList fullFilePaths;

    for (int i = 0; i < fileNames.size(); ++i)
    {
        fullFilePaths << dir.absoluteFilePath(fileNames.at(i));
    }
    return fullFilePaths;
}

//Проверяет индекс текущего трека на корректность

bool MainWindow::isValidIndex(int index)
{
    return index >= 0 && index < currentPlaylist.size();
}

//Проверка на сузествование файла

bool MainWindow::fileExists(const QString &filePath)
{
    return QFile::exists(filePath);
}

//Удаляет ненайденный файл из плейлиста

bool MainWindow::removeMissingFile(int &index)
{
    QString trackPath = currentPlaylist.at(index);
    if(!fileExists(trackPath))
    {
        currentPlaylist.removeAt(index);

        if(currentPlaylist.isEmpty())
        {
            m_player->stop();
            return false;
        }
        index = index % currentPlaylist.size();
        return true;
    }
    return true;
}

//Настройка плеера для воспроизведения трека по указанному пути

void MainWindow::setupPlayer(const QString &trackPath)
{
    currentTrackPath = trackPath;
    m_player->setSource(QUrl::fromLocalFile(currentTrackPath));

    m_player->setAudioOutput(m_audioOutput);
    m_audioOutput->setVolume(0.5);
}

//Запуск трека

bool MainWindow::playTrackAtIndex(int index)
{
    if(!isValidIndex(index))
    {
        return false;
    }

    if(!removeMissingFile(index))
    {
        return false;
    }

    m_player->stop();

    currentTrackIndex = index;
    QString trackPath = currentPlaylist.at(index);
    currentTrackPath = trackPath;
    setupPlayer(trackPath);

    m_player->play();

    ui->pushButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    setWhiteStandardIcon(ui->pushButton, QStyle::SP_MediaPause, QSize(25, 25));

    return true;
}

void MainWindow::playTrackAtIndexUI(int index)
{
    bool success = playTrackAtIndex(index);
    if(!success)
    {
        ui->pushButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        ui->name_track_label->setText("Плейлист пуст");
    }
    QString fileName = QFileInfo(currentTrackPath).fileName();
    ui->name_track_label->setText(fileName);
}

//При клике на трек из списка отображает UI штуки

void MainWindow::onItemDoubleClicked(QListWidgetItem *item)
{
    int row = ui->listWidget->row(item);
    playTrackAtIndex(row);

    QString fileName = QFileInfo(currentTrackPath).fileName();
    ui->name_track_label->setText(fileName);

    ui->pushButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    setWhiteStandardIcon(ui->pushButton, QStyle::SP_MediaPause, QSize(25, 25));
    ui->pushButton->show();

    ui->currentTime_label->show();

    ui->time_of_track->show();

    ui->timeSlider->show();

    ui->next_btn->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));
    setWhiteStandardIcon(ui->next_btn, QStyle::SP_MediaSkipForward, QSize(25, 25));
    ui->next_btn->show();

    ui->previous_btn->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));
    setWhiteStandardIcon(ui->previous_btn, QStyle::SP_MediaSkipBackward, QSize(25, 25));
    ui->previous_btn->show();

    ui->repeat_btn->show();

}

//Обработчик кнопки воспроизведения/стопа в интерфейсе
void MainWindow::on_pushButton_clicked()
{
    if(m_player->playbackState() == QMediaPlayer::PlayingState)
    {
        m_player->pause();
        ui->pushButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        setWhiteStandardIcon(ui->pushButton, QStyle::SP_MediaPlay, QSize(25, 25));
    }
    else
    {
        m_player->play();
        ui->pushButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        setWhiteStandardIcon(ui->pushButton, QStyle::SP_MediaPause, QSize(25, 25));
    }
}


//Обновление плейлиста
void MainWindow::refreshPlaylist(const QString &path)
{
    currentPlaylist.clear();
    musicDirectory = path;
    currentPlaylist = inputMediaFiles(musicDirectory);
}
//Устанавливает новую директорию для музыки и обновляет наблюдатель за файловой системой.
void MainWindow::setMusicDirectory(const QString &path)
{
    if (fileSystemWatcher->directories().contains(musicDirectory))
    {
        fileSystemWatcher->removePath(musicDirectory);
    }

    musicDirectory = path;
    fileSystemWatcher->addPath(musicDirectory);
}

//Обработчик события изменения содержимого музыкальной директории.
void MainWindow::onMusicDirectoryChanged(const QString &path)
{
    if (!QDir(path).exists())
    {
        emit requestGoToStartWindow();
        return;
    }
    refreshPlaylist(path);
    updatePlayListUI();

}

//Проверяет, существует ли текущая музыкальная директория.
void MainWindow::checkMusicDirectoryExists()
{
    if (!QDir(musicDirectory).exists())
    {
        emit requestGoToStartWindow();
    }
}

//Обновляет ui
void MainWindow::updatePlayListUI()
{
    ui->listWidget->clear();
    for (int i = 0; i < currentPlaylist.size(); ++i)
    {
        QString trackPath = currentPlaylist.at(i);
        QFileInfo fileInfo(trackPath);
        ui->listWidget->addItem(fileInfo.fileName());
    }
}

//Проигрывание следующего трека
void MainWindow::playNextTrack()
{
    int nextIndex = (currentTrackIndex + 1) % currentPlaylist.size();
    playTrackAtIndex(nextIndex);
}

//Проигрывание предыдущего трека
void MainWindow::playPreviousTrack()
{
    int prevIndex = (currentTrackIndex - 1 + currentPlaylist.size()) % currentPlaylist.size();
    playTrackAtIndex(prevIndex);

}

//Обработчик кнопки
void MainWindow::on_next_btn_clicked()
{
    playNextTrack();
    ui->pushButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    setWhiteStandardIcon(ui->pushButton, QStyle::SP_MediaPause, QSize(25, 25));

//    QString fileName = QFileInfo(currentTrackPath).fileName();
//    ui->name_track_label->setText(fileName);
    updateTrackNameUI();

}

//Обработчик кнопки
void MainWindow::on_previous_btn_clicked()
{
    playPreviousTrack();

    ui->pushButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    setWhiteStandardIcon(ui->pushButton, QStyle::SP_MediaPause, QSize(25, 25));

//    QString fileName = QFileInfo(currentTrackPath).fileName();
//    ui->name_track_label->setText(fileName);
    updateTrackNameUI();
}


void MainWindow::on_repeat_btn_clicked()
{
    repeatmode = static_cast<RepeatMode>((repeatmode + 1) % RepeatModeCount);

    switch(repeatmode)
    {
    case RepeatOff:
    {
        isReapeted = false;
        autoplayEnable = false;
        qDebug() << "Repeat mode: Off";
        QIcon repeatIcon(":/svg-icon/svg pictures/media-player-ui-button-repeat-loop-svgrepo-com.svg");
        ui->repeat_btn->setIcon(repeatIcon);
        ui->repeat_btn->setIconSize(QSize(25, 25));
        break;
    }
    case RepeatTrack:
    {
        QIcon autolayPlaylist(":/svg-icon/svg pictures/Музыка by iconSvg.co.svg");
        ui->repeat_btn->setIcon(autolayPlaylist);
        ui->repeat_btn->setIconSize(QSize(25, 25));
        isReapeted = true;
        autoplayEnable = false;
        qDebug() << "Repeat mode: Repeat Track";

        break;
    }
    case RepeatPlaylist:
    {
        isReapeted = false;
        autoplayEnable = true;
        qDebug() << "Repeat mode: Repeat Playlist";
        QIcon musicModeOff(":/svg-icon/svg pictures/Music Player by iconSvg.co.svg");
        ui->repeat_btn->setIcon(musicModeOff);
        ui->repeat_btn->setIconSize(QSize(25, 25));
        break;
    }
    }
}

//автопроигрывание следующего трека

void MainWindow::autoPlayNextTrack()
{
    int nextIndex = (currentTrackIndex + 1) % currentPlaylist.size();
    playTrackAtIndex(nextIndex);

    updateTrackNameUI();
}

//повторное проигрывание трека
void MainWindow::repeatCurrentTrack()
{
    m_player->setPosition(0);
    m_player->play();
}

//обновление дизайна кнопки
void MainWindow::updatePlayButtonToPlayIcon()
{
    ui->pushButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    setWhiteStandardIcon(ui->pushButton, QStyle::SP_MediaPlay, QSize(25, 25));
}

void MainWindow::autoPlayTrack(QMediaPlayer::PlaybackState state)
{
    if(state == QMediaPlayer::StoppedState)
    {
        if(isReapeted)
        {
            repeatCurrentTrack();
        }
        else if(autoplayEnable)
        {
            autoPlayNextTrack();
        }
        else
        {
            updatePlayButtonToPlayIcon();
        }
    }
}

void MainWindow::updateTrackNameUI()
{
    QString fileName = QFileInfo(currentTrackPath).fileName();
    ui->name_track_label->setText(fileName);

    if(currentTrackIndex >= 0 && currentTrackIndex < ui->listWidget->count())
    {
        ui->listWidget->setCurrentRow(currentTrackIndex);
    }
}



