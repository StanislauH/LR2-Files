#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    direc = new QFileSystemModel(this);
    direc->setRootPath("D:/");
    ui->treeView->setModel(direc);
    img = new QImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
     ui->image->setText(direc->fileInfo(index).absoluteFilePath());
     img->load(direc->fileInfo(index).absoluteFilePath());
     if(img->width()!=0&&img->height()!=0){
        ui->image->setText("Image is open: " + direc->fileInfo(index).absoluteFilePath());
        ui->size->setText("Image size: " + QString::number(img->width()) + " x " + QString::number(img->height()));
        int xdpi;
        int ydpi;
        int ddpi;
        xdpi = img->dotsPerMeterX() / 39.37;
        ydpi = img->dotsPerMeterY() / 39.37;
        ddpi = sqrt(xdpi * xdpi + ydpi * ydpi);
        ui->resolution->setText("Resolution: " + QString::number(ddpi));
        ui->depth->setText("Image depth: " + QString::number(img->depth()));
    }
    else{
        ui->size->setText("");
        ui->resolution->setText("");
        ui->depth->setText("");
    }
}







