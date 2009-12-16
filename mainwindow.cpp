#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete[] table;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::changeColums(int n){
    ui->tableWidget->setColumnCount(n);
}

void MainWindow::changeRows(int n){
    ui->tableWidget->setRowCount(n);
}

void MainWindow::solve()
{
    getData();
}

void MainWindow::getData()
{
    table=new double*[ui->tableWidget->columnCount()];
    for (int i=0; i<ui->tableWidget->columnCount(); ++i)
        table[i] = new double[ui->tableWidget->rowCount()];

    for(int i; i<ui->tableWidget->columnCount(); ++i)
    for(int j; j<ui->tableWidget->rowCount(); ++j)
        table[i][j]=ui->tableWidget->item(i,j)->text().toDouble();

    if( ui->radioButton->isChecked() )
        gamerA=true;
    else gamerA=false;

    qDebug()<<table;
    qDebug()<<gamerA;
}
