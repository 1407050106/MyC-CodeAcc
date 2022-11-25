#include <string>
#include <cstring>
#include "Logger.h"
#include "BasicInformation.h"

int GetMQTTInf(const std::string& inipath,MqttInf& inputmqttInf){
    ReadConfig readConfig;
    if(inipath.empty()){
        LogERROR("Invalid MQTT Config init path!");
        return -1;
    }
    if(!readConfig.ReadConfigInformation(inipath)){
        LogERROR("Invalid MQTT Config Information!");
        return -2;
    }

    inputmqttInf.Mqtt_address = readConfig.ReadString("mqtt", "ip", "") + ":" + readConfig.ReadString("mqtt", "port", "");
    if(inputmqttInf.Mqtt_address.empty()){
        LogERROR("Invalid MQTT Config Mqtt_address!");
        return -3;
    }

    inputmqttInf.Mqtt_cncid = readConfig.ReadString("mqtt","clientid",""); //FC_3C7B5D01089191A45E33C3897C92C461
    if(inputmqttInf.Mqtt_cncid.empty()){
        LogERROR("Invalid MQTT Config Mqtt_cncid!");
        return -4;
    }

    inputmqttInf.Mqtt_topic = readConfig.ReadString("mqtt","topic","");
    if(inputmqttInf.Mqtt_topic.empty()){
        LogERROR("Invalid MQTT Config Mqtt_topic!");
        return -5;
    }

    inputmqttInf.Mqtt_username = readConfig.ReadString("mqtt","user","");
    if(inputmqttInf.Mqtt_username.empty()){
        LogERROR("Invalid MQTT Config Mqtt_username!");
        return -6;
    }

    inputmqttInf.Mqtt_password = readConfig.ReadString("mqtt","password","");
    if(inputmqttInf.Mqtt_password.empty()){
        LogERROR("Invalid MQTT Config Mqtt_password!");
        return -7;
    }
    return 0;
}

