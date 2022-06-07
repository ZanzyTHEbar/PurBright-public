/*
 basicmqtt.hpp - ESP32GreenHouseDIY MQTT library
 Copyright (c) 2021 ZanzyTHEbar
 */
#pragma once
#ifndef BASEMQTT_HPP
#define BASEMQTT_HPP
#include <defines.hpp>
#include <PubSubClient.h>

class BASEMQTT : public IPAddress
{
public:
    // Constructor
    BASEMQTT();
    virtual ~BASEMQTT();

    void loadMQTTConfig();
    bool Setup();
    void mqttLoop();
    void Publish(const char *topic, const char *payload);
    void mqttReconnect();

    // Friends
    friend class LDR;
    friend void callback(char *topic, byte *payload, unsigned int length);

private:
    // Private functions

    // Private variables
    char *_pumpTopic;
    char *_pumpInTopic;
    char *_menuTopic;
    char *_ledTopic;
    char *_speakerTopic;
    const long _interval;
    unsigned long _previousMillis;
    uint8_t _user_bytes_received;
    char _user_data[100];
    bool _publishState;
};

extern BASEMQTT basemqtt;
#endif // BASEMQTT_HPP