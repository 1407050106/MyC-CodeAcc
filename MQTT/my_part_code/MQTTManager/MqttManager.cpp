//
// Created by longyaowei on 7/30/20.
//
#include "MqttManager.h"

MqttManager Mqttmanager;

MqttManager::MqttManager() {

}

bool MqttManager::SetAddress(const std::string& InputAddress) {
    if(!InputAddress.empty()){
        this->Address =  InputAddress;
        return true;
    } else {
        return false;
    }
}

bool MqttManager::SetClientID(const std::string& InputClientID) {
    if(!InputClientID.empty()){
        this->ClientID = InputClientID;
        return true;
    }else{
        return false;
    }
}

bool MqttManager::SetTopic(const std::string& InputTopic) {
    if(!InputTopic.empty()){
        this->Topic = InputTopic;
        return true;
    } else{
        return false;
    }
}

bool MqttManager::SetUserName(const std::string& InputUserName) {
    if(!InputUserName.empty()){
        this->UserName = InputUserName;
        return true;
    } else{
        return false;
    }
}

bool MqttManager::SetPassword(const std::string& InputPassword) {
    if(!InputPassword.empty()){
        this->PassWord = InputPassword;
        return true;
    } else{
        return false;
    }
}

void MqttManager::SetQos(const int InputQos) {
    this->Qos = InputQos;
}

void MqttManager::SetTimeout(const int InputTimeout) {
    this->Timeout = InputTimeout;
}

bool MqttManager::MqttBuild() {

    int rc = MQTTClient_create(&client,Address.c_str(),ClientID.c_str(),MQTTCLIENT_PERSISTENCE_NONE, NULL);
    //int rc=MQTTClient_createWithOptions(&client, "tcp://114.251.54.124:2883", "FC_3C7B5D01089191A45E33C3897C92C461",  MQTTCLIENT_PERSISTENCE_NONE, NULL, NULL);
    printf("Client create reason code: %d\n", rc);
    if ( rc != MQTTCLIENT_SUCCESS)
    {
        LogERROR("Failed to create client, return code "+ std::to_string(rc));
        //LogERROR("Failed to create client!");
        return false;
    }
    return true;
}

void trace_callback(enum MQTTCLIENT_TRACE_LEVELS level, char* message)
{
	printf("%s(): Trace : %d, %s\n", __func__ ,level, message);
}

bool MqttManager::MqttClientstart() {

}

bool MqttManager::MqttConnect() {
    conn_opts = MQTTClient_connectOptions_initializer;
    conn_opts.username = UserName.c_str();
    conn_opts.password = PassWord.c_str();
    conn_opts.keepAliveInterval = 60;  //SERVER LISTEN XINTIAO
    conn_opts.cleansession = true;
    // int rcc = MQTTClient_createWithOptions(&client, "tcp://114.251.54.124:2883", "FC_3C7B5D01089191A45E33C3897C92C461",  MQTTCLIENT_PERSISTENCE_NONE, NULL, NULL);
    // printf("Client create reason code: %d\n", rcc); 
    MQTTClient_connectionLost* connlost;
	MQTTClient_messageArrived* msgarrvd;
    MQTTClient_deliveryComplete* delivered;
    MQTTClient_setCallbacks(client, NULL, connlost, msgarrvd, delivered);
    MQTTClient_setTraceCallback(trace_callback);
    MQTTClient_setTraceLevel(MQTTCLIENT_TRACE_PROTOCOL);
    int rc = MQTTClient_connect(client, &conn_opts);
    if ( rc != MQTTCLIENT_SUCCESS)
    {
        LogERROR("Failed to connect, return code  "+ std::to_string(rc));
        return false;
    }
    return true;
}

bool MqttManager::MqttSend() {
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;
    pubmsg.payload = "HiTMT";
    pubmsg.payloadlen = strlen(pubmsg.payload);
    pubmsg.qos = Qos;
    pubmsg.retained = false;

    /*
    int rc = MQTTClient_publishMessage(client, Topic.c_str(), &pubmsg, &token);
    printf("Waiting for up to %d seconds for publication of %s\n",(int)(Timeout/1000));

    rc = MQTTClient_waitForCompletion(client, token, Timeout);

    */
    int rc = MQTTClient_publishMessage(client, Topic.c_str(), &pubmsg, &token);
    if (rc != MQTTCLIENT_SUCCESS)
    {
        LogERROR("Failed to publish message, return code "+ std::to_string(rc));
        //std::cout<<"Failed to publish message, return code "+ std::to_string(rc)<<std::endl;
        return false;
        //exit(EXIT_FAILURE);
    }
    //printf("Waiting for up to %d seconds for publication of %s\n"
    //       "on topic %s for client with ClientID: %s\n",
    //       (int)(TIMEOUT/1000), PAYLOAD, TOPIC, ID);

    if ((rc = MQTTClient_waitForCompletion(client, token, Timeout)) != MQTTCLIENT_SUCCESS)
    {
        LogERROR("Failed to publish message, return code "+ std::to_string(rc));
        //std::cout<<"Failed to publish message, return code "+ std::to_string(rc)<<std::endl;
        return false;
        //exit(EXIT_FAILURE);
    }
    //LogINFO("Message with delivery token delivered "+std::to_string(token));
    return true;
}

bool MqttManager::MqttDisconnect() {
    int rc = MQTTClient_disconnect(client, 10000);
    if(rc != MQTTCLIENT_SUCCESS)
    {
        LogERROR("Failed to disconnect, return code "+ std::to_string(rc));
        //LogERROR("Failed to disconnect!");
        return false;
    }
    return true;
}

MqttManager::~MqttManager() {
    MqttDisconnect();
    MQTTClient_destroy(&client);
}
