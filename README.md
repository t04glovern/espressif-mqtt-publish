# AWS IoT - Espressif MQTT Publisher [![Build Status](https://travis-ci.org/t04glovern/espressif-mqtt-publish.svg?branch=master)](https://travis-ci.org/t04glovern/espressif-mqtt-publish)

## Setup

Edit the `src/main.h` file with the relevant information for your project and save it.

```cpp
#ifndef MAIN_H

// Wifi Details
const char *ssid = "YourWifiSSID";
const char *password = "YourWifiPassword";

const String thing_id = "YourThingID";

// AWS MQTT Details
char *aws_mqtt_server = "YourAWSThingID.iot.ap-southeast-2.amazonaws.com";
char *aws_mqtt_client_id = "YourMQTTClientID";
char *aws_mqtt_thing_topic_pub = "YourMQTTAWSIoTThing/YourMQTTTopic";
char *aws_mqtt_thing_topic_sub = "YourMQTTAWSIoTThing/YourMQTTTopic";

#endif
```

You will also need to edit the `lib/AWS/IOT/src/aws_iot_certficates.c` file based on the certificates you get when setting up a `thing` on the AWS platform.

You can use the following command to create these arrays

```bash
xxd -i src/certs .pem | sed -e 's/unsigned char .* = {/const char certificate_pem_crt[] = {/g' -e 's/unsigned int .* = .*;//g'
```

```cpp
// Example below, change this and the other two entries to your certificates

const char certificate_pem_crt[] = {"-----BEGIN CERTIFICATE-----\n\
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\
-----END CERTIFICATE-----\n"};
```

## MQTT Providers

### AWS IoT

You can sign up for and follow along with the setup guides on [AWS IoT Setup](https://ap-southeast-2.console.aws.amazon.com/iotv2/home?region=ap-southeast-2#/connIntro)

## Platform IO

This project is build and run with PlatformIO. The library dependencies can be found in the `platformio.ini` file. Below is the current configuration targetting the FireBeetle ESP32 development board. This can be changed to any variable of the ESP32 chip.

```ini
[env:firebeetle32]
platform = espressif32
board = firebeetle32
framework = arduino
```

### lib dependencies

#### AWS_IOT

Based on the AWS_IOT Project in [ExploreEmbedded/Hornbill-Examples](https://github.com/ExploreEmbedded/Hornbill-Examples/tree/master/arduino-esp32/AWS_IOT), the AWS_IOT directory should be dropped into/maintained in the `lib` directory of this project
