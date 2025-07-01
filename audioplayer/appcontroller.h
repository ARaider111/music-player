#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <QObject>
#include "startwindow.h"
#include "mainwindow.h"

class AppController : public QObject
{
    Q_OBJECT
public:
    explicit AppController(QObject *parent = nullptr);
    ~AppController();

public slots:
    void onFolderSelected(const QString &path);
    void showStartWindow();
    void showMainWindow();

private:
    StartWindow *startWindow;
    MainWindow *mainWindow;
};

#endif // APPCONTROLLER_H
