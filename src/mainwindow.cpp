#include "mainwindow.hpp"
#include "./ui_mainwindow.h"
#include "list_item.hpp"

constexpr int CHART_FRAME_RATE = 60;

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  chartView.setChart(&chart);
  ui->chartLayout->addWidget(&chartView);
  ui->videoLayout->addWidget(&player);
  ui->webviewLayout->addWidget(&webview);

  for (int i = 0; i < 10; i++)
  {
    add_list_item("Item " + QString::number(i));
  }

  connect(&timer, &QTimer::timeout, this, &MainWindow::addPoint);
  connect(ui->pushButton_clean, &QPushButton::clicked, &chart, &GyroChart::clear);
  connect(ui->pushButton_rocket, &QPushButton::clicked, &player, &Player::restart);
  timer.start(1000 / CHART_FRAME_RATE);
}

MainWindow::~MainWindow() {}


void MainWindow::addPoint()
{
  static int x = 0;
  auto y_1 = sin(x / 10.0) * 10 + 10;
  auto y_2 = cos(x / 10.0) * 10 + 10;
  auto y_3 = sin(x / 10.0) * 10 + cos(x / 10.0) * 10 + 15;
  chart.addPoint(QPointF(x, y_1), QPointF(x, y_2), QPointF(x, y_3));
  x++;
}

void MainWindow::add_list_item(const QString &name)
{
  QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listLayout);
  ui->listLayout->addItem(listWidgetItem);

  ListItem *theWidgetItem = new ListItem(name);
  ui->listLayout->setItemWidget(listWidgetItem, theWidgetItem);
}