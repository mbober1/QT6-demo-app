#include "chart.hpp"


Chart::Chart()
: QChart(),
  axisX(new QValueAxis),
  axisY(new QValueAxis)
{
  axisY->setRange(0, 30);
  axisX->setRange(0, MAX_POINTS);
  addAxis(axisY.get(), Qt::AlignLeft);
  addAxis(axisX.get(), Qt::AlignBottom);
}

Chart::~Chart()
{
}