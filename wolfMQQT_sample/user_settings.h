#include <stdlib.h>
#include <applibs/log.h>
#include <errno.h>

#ifdef AZURE_SPHERE

//#define WOLFMQTT_MULTITHREAD
#define WOLFMQTT_DISCONNECT_CB
#define WOLFMQTT_NONBLOCK
#define WOLFMQTT_NO_STDIO
//#define WOLFMQTT_V5
//#define ENABLE_MQTT_TLS

#define NO_MAIN_DRIVER
#define WOLFMQTT_CUSTOM_PRINTF
#define PRINTF(x, ...) Log_Debug(x"\n", ##__VA_ARGS__)

/* The host must also be added app_manifest.json */
//#define DEFAULT_MQTT_HOST "mosquitto.australiaeast.cloudapp.azure.com"
//#define DEFAULT_MQTT_SECURE_PORT 8884
//#define DEFAULT_MQTT_HOST "192.168.86.45"
#define DEFAULT_MQTT_HOST "test.mosquitto.org"
#define DEFAULT_MQTT_SECURE_PORT 8883

/* These files must also be loaded in CMakeLists.txt */
#define MQTT_CA_CERTIFICATE "certs/ca-cert.pem"
#define MQTT_CLIENT_PRIVATE_KEY "certs/client-key.pem"
#define MQTT_CLIENT_CERTIFICATE "certs/client-cert.pem"

typedef unsigned short word16;

#endif	// AZURE_SPHERE
