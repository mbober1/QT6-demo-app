#include "webview.hpp"

Webview::Webview()
{
  this->load(QUrl("http://www.youtube.com/"));
}