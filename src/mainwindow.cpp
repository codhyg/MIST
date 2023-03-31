#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./../../db/m_instruments.db");

    if (db.open())
    {
        ui->statusbar->showMessage("Connected to database");
    }
    else
    {
        ui->statusbar->showMessage("Failed to connect: " + db.lastError().databaseText());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
