#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include "BasicInformation.h"
#include "MqttManager.h"

int BuildDataToCloud(MqttInf& inputmqttInf){

    if(!Mqttmanager.SetAddress(inputmqttInf.Mqtt_address)){
        LogERROR("MQTT set address error !");
        return -1;
    }
    if(!Mqttmanager.SetClientID(inputmqttInf.Mqtt_cncid)){
        LogERROR("MQTT set client id error !");
        return -2;
    }
    if(!Mqttmanager.SetTopic(inputmqttInf.Mqtt_topic)){
        LogERROR("MQTT set topic error !");
        return -3;
    }
    if(!Mqttmanager.SetUserName(inputmqttInf.Mqtt_username)){
        LogERROR("MQTT set username error !");
        return -4;
    }
    if(!Mqttmanager.SetPassword(inputmqttInf.Mqtt_password)){
        LogERROR("MQTT set password error !");
        return -5;
    }

    Mqttmanager.SetQos(0);
    Mqttmanager.SetTimeout(1000L);
    if (!Mqttmanager.MqttBuild()) {
        LogERROR("Failed to create client!");
        return -6;
    }

    return 0;
}

int SendDataToCloud() {
    if (!Mqttmanager.MqttConnect())
    {
        LogERROR("Mqtt Connect Fail!");
        return -3;
    }
    if(!Mqttmanager.MqttSend())
    {
        LogERROR("Send Data String Fail!");
        return -4;
    }
    return 0;
}




