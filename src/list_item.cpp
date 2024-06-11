#include "list_item.hpp"
#include "ui_list_item.h"

  
/*!
 * \brief Constructor ListItem Class
 */
ListItem::ListItem(const QString &name, QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Form)
{
  ui->setupUi(this);
  ui->radioButton_name->setText(name);
}


/*!
 * \brief Destructor ListItem Class
 */
ListItem::~ListItem()
{
    delete ui;
}