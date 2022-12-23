#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "modbus.h"

using namespace std;

class WModbus{
    public:
        bool ReadServoFan(char *input);
    private:
        string IP="192.168.1.200";
        int PORT=502;
        int slave_num = 4;
};