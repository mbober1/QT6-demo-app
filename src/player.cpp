#include "player.hpp"

Player::Player()
{
  player = std::make_unique<QMediaPlayer>();
  player->setSource(QUrl("http://commondatastorage.googleapis.com/gtv-videos-bucket/sample/BigBuckBunny.mp4"));
  player->setVideoOutput(this);
  player->play();
}

void Player::restart()
{
  player->setPosition(0);
  player->play();
}