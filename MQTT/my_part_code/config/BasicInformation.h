//
// Created by bfm on 7/5/20.
//

#ifndef BFM_TCPCLIENT_BASICINFORMATION_H
#define BFM_TCPCLIENT_BASICINFORMATION_H

#include<string>
#include<vector>
#include<ctime>
#include<string>
#include<cstring>
#include<iostream>
#include"Logger.h"
#include"ReadConfig.h"

using namespace std;

struct MainFunction{
    std::string DataCollect;
    std::string DataSend;
    std::string DTUConfig;
    std::string ReverseContral;
};

struct MqttInf {
    std::string Mqtt_address;
    std::string Mqtt_cncid;
    std::string Mqtt_topic;
    std::string Mqtt_username;
    std::string Mqtt_password;
};

struct BasicInf{
    std::string CNC_IP;
    std::string DTU_SIM_ICCID;
    std::string DTU_ID;
    std::string DTU_4G_IP;
};

struct LteInf{
    std::string ltemodel;
    std::string ltetelecom;
    std::string ltepath;
};

struct SiemensPLCInf{
    std::string CNC_IP;
    int SiemensPLCRack;
    int SiemensPLCSlot;
};

struct RabbitmqInf{
    std::string rabbitip;
    int rabbitport;
    std::string rabbitusername;
    std::string rabbitpassword;
    std::string rabbitexchange;
    std::string rabbitsendqueue;
};

int GetMQTTInf(const std::string& inipath,MqttInf& inputmqttInf);

#endif //BFM_TCPCLIENT_BASICINFORMATION_H
