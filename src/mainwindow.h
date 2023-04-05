#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include </usr/include/qt5/QtSql/qsqldatabase.h>
#include </usr/include/qt5/QtSql/qsqlerror.h>
#include </usr/include/qt5/QtSql/qsqltablemodel.h>
#include </usr/include/qt5/QtSql/qsqlrelationaldelegate.h>
#include </usr/include/qt5/QtSql/qsqlrelationaltablemodel.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

private slots:
    void on_actionRemove_item_triggered();

private slots:
    void on_tableView_clicked(const QModelIndex &index);

private slots:
    void on_actionAdd_item_triggered();

private:
        Ui::MainWindow *ui;
        QSqlDatabase db;
        QSqlRelationalTableModel *model;
        int currentRow;
};

#endif // MAINWINDOW_H
