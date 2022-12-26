#include <iostream>
#include <fstream>
#include <mutex>
#include <shared_mutex>
#include <condition_variable>
#include <thread>
using namespace std;

ofstream os;
off_t fileSize;
int i;
bool cap = false;
mutex lk;
condition_variable cv;

bool WriteSome()
{
    unique_lock<mutex> lock(lk);
    while (i<10)
    {
        cout<<"i+once"<<endl;
        i++; 
    }          
    cap=true;  
    lk.unlock();
    cv.notify_one();
}

int Look()
{
    {                 
        cout<<"i="<<i<<endl;
        return i;
    }
}

string data;

int main() {
    // os.open("./test.json", ios_base::out | ios_base::binary);
    // os<<"hello~"<<flush;
    // os.close();
    // fileSize = sizeof(fopen("./test.json", "rb"));
    // cout<<fileSize<<endl;
    // ifstream t("./test.json");
    // t>>data;
    // cout<<data<<endl;
    thread th1(WriteSome);
    {
        unique_lock<mutex> lck(lk);     //cv.wait bixu dengdai unique_lock()
        cv.wait(lck, []{return cap;});   
    }   
    thread th2(Look);
    th1.join();
    th2.join();
}