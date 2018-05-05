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
