#include <AWS_IOT.h>
#include <WiFi.h>
#include <ArduinoJson.h>

#include "main.h"

AWS_IOT aws_iot;

int status = WL_IDLE_STATUS;
int tick = 0;
int msgCount = 0;

void setup()
{
    Serial.begin(115200);
    delay(2000);

    while (status != WL_CONNECTED)
    {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(ssid);
        // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
        status = WiFi.begin(ssid, password);

        // wait 5 seconds for connection:
        delay(5000);
    }

    Serial.println("Connected to wifi");

    if (aws_iot.connect(aws_mqtt_server, aws_mqtt_client_id) == 0)
    {
        Serial.println("Connected to AWS");
        delay(1000);
    }
    else
    {
        Serial.println("AWS connection failed, Check the HOST Address");
        while (1)
            ;
    }

    delay(2000);
}

void loop()
{
    if (tick >= 5) // publish to topic every 5seconds
    {
        tick = 0;

        const size_t bufferSize = JSON_OBJECT_SIZE(2) + 20;
        DynamicJsonBuffer jsonBuffer(bufferSize);

        JsonObject &root = jsonBuffer.createObject();
        root["payload"] = msgCount++;
        root["thing_id"] = thing_id;
        String json_output;

        root.printTo(json_output);
        char payload[bufferSize];

        json_output.toCharArray(payload, bufferSize);
        sprintf(payload, json_output.c_str());

        if (aws_iot.publish(aws_mqtt_thing_topic_pub, payload) == 0)
        {
            Serial.print("Publish Message:");
            Serial.println(payload);
        }
        else
        {
            Serial.println("Publish failed");
        }
    }
    vTaskDelay(1000 / portTICK_RATE_MS);
    tick++;
}
