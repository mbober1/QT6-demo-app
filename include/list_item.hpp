#pragma once
#include <QWidget>

namespace Ui
{
  class Form;
}

class ListItem : public QWidget
{
  Q_OBJECT

public:
  explicit ListItem(const QString &name, QWidget *parent = nullptr);
  ~ListItem();

private:
  Ui::Form *ui;
};