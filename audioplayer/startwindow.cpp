#include "startwindow.h"
#include "ui_startwindow.h"
#include "mainwindow.h"
#include <QFileDialog>

StartWindow::StartWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartWindow)
{
    ui->setupUi(this);

    this->setFixedSize(this->size());

}

StartWindow::~StartWindow()
{
    delete ui;
}


//Открывается диалоговое окно с выбором папки

void StartWindow::on_pushButton_clicked()
{
    QString str;
    str = QFileDialog::getExistingDirectory(this, "Выберите папку с медиафайлами", "C://");

    if(str != nullptr)
    {
        emit folderSelected(str);
    }

}

