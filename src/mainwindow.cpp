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

        model = new QSqlRelationalTableModel(this);
        model->setTable("INSTRUMENTS");
        model->setRelation(1, QSqlRelation("TYPES", "type_key", "MI_type"));
        model->setRelation(2, QSqlRelation("CHARS", "char_type", "MI_char"));
        model->select();
        model->setHeaderData(0, Qt::Horizontal, "ID", Qt::DisplayRole);
        model->setHeaderData(1, Qt::Horizontal, "Тип", Qt::DisplayRole);
        model->setHeaderData(2, Qt::Horizontal, "Характеристика", Qt::DisplayRole);
        model->setHeaderData(3, Qt::Horizontal, "Наименование", Qt::DisplayRole);
        model->setHeaderData(4, Qt::Horizontal, "Диапазон", Qt::DisplayRole);
        model->setHeaderData(5, Qt::Horizontal, "Точность", Qt::DisplayRole);
        model->setHeaderData(6, Qt::Horizontal, "Цена деления", Qt::DisplayRole);

        ui->tableView->setModel(model);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->tableView->setColumnHidden(0, true);
        ui->tableView->setItemDelegate(new QSqlRelationalDelegate(this));

        //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
    else
    {
        ui->statusbar->showMessage("Failed to connect: " + db.lastError().databaseText());
    }
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}

void MainWindow::on_actionAdd_item_triggered()
{
  model->insertRow(model->rowCount());
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
   currentRow = index.row();
}


void MainWindow::on_actionRemove_item_triggered()
{
   model->removeRow(currentRow);
   model->select();
}

