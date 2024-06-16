#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gyro_chart.hpp"
#include "player.hpp"
#include "webview.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void add_list_item(const QString &name);

private:
    std::unique_ptr<Ui::MainWindow> ui;
    QChartView chartView;
    GyroChart chart;
    QTimer timer;
    // Player player;
    // Webview webview;

private slots:
    void addPoint();
};
#endif // MAINWINDOW_H
