#include <AWS_IOT.h>
#include <WiFi.h>

#include "main.h"

AWS_IOT hornbill;

int status = WL_IDLE_STATUS;
int tick=0,msgCount=0,msgReceived = 0;
char payload[512];
char rcvdPayload[512];

void awsSubCallBackHandler (char *topicName, int payloadLen, char *payLoad)
{
    strncpy(rcvdPayload,payLoad,payloadLen);
    rcvdPayload[payloadLen] = 0;
    msgReceived = 1;
}

void setup() {
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

    if(hornbill.connect(aws_mqtt_server,aws_mqtt_client_id)== 0)
    {
        Serial.println("Connected to AWS");
        delay(1000);

        if(0==hornbill.subscribe(aws_mqtt_thing_topic_sub,awsSubCallBackHandler))
        {
            Serial.println("Subscribe Successfull");
        }
        else
        {
            Serial.println("Subscribe Failed, Check the Thing Name and Certificates");
            while(1);
        }
    }
    else
    {
        Serial.println("AWS connection failed, Check the HOST Address");
        while(1);
    }

    delay(2000);
}

void loop() {

    if(msgReceived == 1)
    {
        msgReceived = 0;
        Serial.print("Received Message:");
        Serial.println(rcvdPayload);
    }
    if(tick >= 5)   // publish to topic every 5seconds
    {
        tick=0;
        sprintf(payload,"Hello from hornbill ESP32 : %d",msgCount++);
        if(hornbill.publish(aws_mqtt_thing_topic_pub,payload) == 0)
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
