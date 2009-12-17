#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include "reductiontolp.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;

    double **table;
    bool gamerA;

private slots:
    void changeColums(int n);
    void changeRows(int n);
    void solve();
    void getData();
};

#endif // MAINWINDOW_H
