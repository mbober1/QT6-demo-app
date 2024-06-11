#include "gyro_chart.hpp"


GyroChart::GyroChart()
: Chart(),
  accXSeries(new QLineSeries),
  accYSeries(new QLineSeries),
  accZSeries(new QLineSeries)
{
  addSeries(accXSeries.get());
  addSeries(accYSeries.get());
  addSeries(accZSeries.get());

  accXSeries->setName("AccX");
  accYSeries->setName("AccY");
  accZSeries->setName("AccZ");

  accXSeries->attachAxis(axisY.get());
  accXSeries->attachAxis(axisX.get());
  accYSeries->attachAxis(axisY.get());
  accYSeries->attachAxis(axisX.get());
  accZSeries->attachAxis(axisY.get());
  accZSeries->attachAxis(axisX.get());
}

void GyroChart::addPoint(const QPointF& accX, const QPointF& accY, const QPointF& accZ)
{
  accXSeries->append(accX);
  accYSeries->append(accY);
  accZSeries->append(accZ);

  if (accXSeries->points().size() > MAX_POINTS)
  {
    accXSeries->remove(0);
    accYSeries->remove(0);
    accZSeries->remove(0);
    axisX->setRange(accXSeries->points().first().x(), accXSeries->points().last().x());
  }
}

void GyroChart::clear()
{
  accXSeries->clear();
  accYSeries->clear();
  accZSeries->clear();
  axisX->setRange(0, MAX_POINTS);
}