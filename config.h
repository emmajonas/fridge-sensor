
//connect to adafruit io using wifi

#define IO_USERNAME    "emmajonas"
#define IO_KEY         "1c4f73af05b0429b8082109389a1632d"

#define WIFI_SSID       "maker"
#define WIFI_PASS       "ubcmaker"

#include "AdafruitIO_WiFi.h"
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
