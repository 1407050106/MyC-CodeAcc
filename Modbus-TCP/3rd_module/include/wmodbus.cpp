#include "wmodbus.h"
#include <unistd.h>
#include <sys/wait.h>

bool WModbus::ReadServoFan(char *input)
{
    char output[160]={0x00};
    modbus_t *mb;

    mb = modbus_new_tcp(IP.c_str(), PORT);
    if (modbus_connect(mb)==-1)
    {
        std::cout<<"Connection failed: "<<modbus_strerror(errno)<<std::endl;
        modbus_free(mb);
        return false;
    }
    printf("Connect successful!\n");

    for (int i=1; i<=slave_num; i++)
    { 
        uint16_t tab_reg[8]={0};
        char onceres[40]={0x00};
        if (!modbus_set_slave(mb,i))
        {
            std::cout<<"Set Slave Address "<<i<<" Successful!"<<std::endl;
        } else {
            std::cout<<"Set Slave Address "<<i<<" Failed!"<<std::endl;
            modbus_free(mb);
            return false;
        }

        struct timeval t;
        t.tv_sec=1;
        t.tv_usec=1000000;  //设置modbus超时时间为1000毫秒  
        modbus_set_response_timeout(mb,t.tv_sec,t.tv_usec);
        
        //if (modbus_read_registers(mb,3,4,tab_reg)==-1)      //03
        if (modbus_read_input_registers(mb,0,8,tab_reg)==-1)  //04
        {
            std::cout<<"Read Slave "<<i<<" Failed!"<<std::endl;
        } else {
            std::cout<<"Read Slave "<<i<<" Successful!"<<std::endl;
        }
            
        //regs=modbus_write_register(mb,0x00,94);
        printf("Slave[%d]=%d %d %d %d %d %d %d %d\n", i, tab_reg[0], tab_reg[1], tab_reg[2], tab_reg[3], tab_reg[4], tab_reg[5], tab_reg[6], tab_reg[7]);
        sprintf(onceres, "[F_SERVO%d=%d]", i, tab_reg[1]);
        strcat(output, onceres);
        usleep(300000);
    }

    strcpy(input, output);
    
    modbus_close(mb);
    modbus_free(mb);
    return true;
}
    
