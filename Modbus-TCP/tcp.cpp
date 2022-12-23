#include "wmodbus.h"
 
int main(void)
{
    WModbus newmdtcp;
    char res[160]={0x00};
    if (newmdtcp.ReadServoFan(res))
    {
        for (int i=0; i<160; i++)
        {
          cout<<res[i];
        }
        printf("\n");
    } else {
        cout<<"Read ServoFan Failed!"<<endl;
    }
}