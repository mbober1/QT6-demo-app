#pragma once

#include "chart.hpp"

/**
  @brief GyroChart class
*/
class GyroChart : public Chart
{
  Q_OBJECT
public:
  GyroChart();

public slots:
  void addPoint(const QPointF& accX, const QPointF& accY, const QPointF& accZ);
  void clear();

private:
  std::unique_ptr<QLineSeries> accXSeries;
  std::unique_ptr<QLineSeries> accYSeries;
  std::unique_ptr<QLineSeries> accZSeries;
};