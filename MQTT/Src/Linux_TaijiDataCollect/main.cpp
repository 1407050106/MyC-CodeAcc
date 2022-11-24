#include <iostream>
#include <unistd.h>
#include "BasicInformation.h"
#include "Logger.h"

#define INIPath "/home/fanuc/conf.ini"

extern int BuildDataToCloud(MqttInf& inputmqttInf);
extern int SendDataToCloud();

int main(){
  MqttInf mqttInf;
  if(GetMQTTInf(INIPath,mqttInf) < 0){
    LogERROR("Get Basic Information Fail!");
    exit(0);
  }
  LogINFO("Get Basic Information Successful!");

  while (true) {
    if (BuildDataToCloud(mqttInf) < 0) {
      LogERROR("Build data to cloud fail!");
      exit(0);
    }
    LogINFO("Build data to cloud successful!");
    if (SendDataToCloud() < 0) {
      LogERROR("Send data to cloud fail!");
      exit(0);
    }
    LogINFO("Send data to cloud successful!");
    sleep(5);
  }
  return 0;
}