#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class StartWindow;
}
QT_END_NAMESPACE

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    StartWindow(QWidget *parent = nullptr);
    ~StartWindow();
signals:
    void folderSelected(const QString &path);
private slots:
    void on_pushButton_clicked();

private:
    Ui::StartWindow *ui;
};
#endif // STARTWINDOW_H
