#pragma once

#include <QMediaPlayer>
#include <QVideoWidget>

/**
  @brief Chart class
*/
class Player : public QVideoWidget
{
  Q_OBJECT
public:
  Player();

public slots:
  void restart();

private:
  std::unique_ptr<QMediaPlayer> player;
};