#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include </usr/include/qt5/QtSql/qsqldatabase.h>
#include </usr/include/qt5/QtSql/qsqlerror.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private:
        Ui::MainWindow *ui;
        QSqlDatabase db;
};

#endif // MAINWINDOW_H
