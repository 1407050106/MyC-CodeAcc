//
// Created by YonglinWang on 5/30/22.
//

#ifndef ECU_LINUXTRANS_MQTTMANAGER_H
#define ECU_LINUXTRANS_MQTTMANAGER_H
#include <string>
#include <iostream>
#include <string.h>
#include "Logger.h"
#include "MQTTClient.h"

using namespace std;

class MqttManager{

public:
    MqttManager();
    ~MqttManager();

    bool MqttBuild();
    bool MqttClientstart();
    bool MqttConnect();
    bool MqttSend();
    bool MqttDisconnect();

    bool SetAddress(const std::string& InputAddress);
    bool SetClientID(const std::string& InputClientID);
    bool SetTopic(const std::string& InputTopic);
    bool SetUserName(const std::string& InputUserName);
    bool SetPassword(const std::string& InputPassword);

    void SetQos(int InputQos);
    void SetTimeout(int InputTimeout);

private:
    std::string Address;
    std::string ClientID;
    std::string Topic;
    std::string UserName;
    std::string PassWord;
    int Qos;
    int Timeout;
    MQTTClient client;
    MQTTClient_connectOptions conn_opts;
};

extern MqttManager Mqttmanager;

#endif //ECU_LINUXTRANS_MQTTMANAGER_H
