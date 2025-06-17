#include "appcontroller.h"

AppController::AppController(QObject *parent)
    : QObject(parent)
{
    startWindow = new StartWindow();
    mainWindow = new MainWindow("");

    connect(startWindow, &StartWindow::folderSelected, this, &AppController::onFolderSelected);

    connect(mainWindow, &MainWindow::requestGoToStartWindow, this, &AppController::showStartWindow);

    startWindow->show();
}

AppController::~AppController()
{
    delete startWindow;
    delete mainWindow;
}

void AppController::onFolderSelected(const QString &path)
{
    mainWindow->setMusicDirectory(path);
    mainWindow->refreshPlaylist(path);
    mainWindow->updatePlayListUI();

    showMainWindow();
}

void AppController::showStartWindow()
{
    mainWindow->hide();
    startWindow->show();
}

void AppController::showMainWindow()
{
    startWindow->hide();
    mainWindow->show();
}

