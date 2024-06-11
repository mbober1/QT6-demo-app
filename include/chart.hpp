#pragma once

#include <QtCharts>
#include <vector>
#include <memory>

/**
  @brief Chart class
*/
class Chart : public QChart
{
  Q_OBJECT
public:
  Chart();
  ~Chart();

protected:
  static constexpr int MAX_POINTS = 100;
  std::unique_ptr<QValueAxis> axisX;
  std::unique_ptr<QValueAxis> axisY;
};