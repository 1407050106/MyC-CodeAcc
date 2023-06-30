#include <thread>
#include <vector>
#include <queue>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <future>
#include <iostream>
#include <stdexcept>
#include <functional>
#include <unistd.h>
using namespace std;


#define MAX_NUMS 6
using task = function<void()>;

class pool{
    private:
       queue<task> _tasks;
       vector<thread> _pool;
       condition_variable cv;
       mutex _lock;
       atomic<bool> _is_run{true};
        atomic<int> _free_num{0};

    public:
        explicit pool(int sum=3)
        {
            if (sum>MAX_NUMS) sum=MAX_NUMS;
            addThread(sum);
        }

        inline ~pool()
        {
            _is_run=false;
            cv.notify_all();
            // 这里不用判断�?否在运�?�！
                for (thread& thd : _pool)
                {
                    if (thd.joinable()) thd.join();
                } 
        }

        template<class F, class... Args>
        auto commit(F f, Args... args) ->future<decltype(f(args...))>
        {
            if (!_is_run) __throw_runtime_error("No Working");
            using RecType = decltype(f(args...));
            auto Task = make_shared<packaged_task<RecType()>>(bind(forward<F>(f), forward<Args>(args)...));
            future<RecType> fres = Task->get_future();
            {
                lock_guard<mutex> lock(_lock);
                _tasks.emplace([Task](){(*Task)();});
            }
            cv.notify_one();
            return fres;
        }

        void addThread(int sum)
        {
            for ( ; _pool.size()<MAX_NUMS && sum>0; --sum)
            {
                _pool.emplace_back(
                    [this]()
                    {
                        while (_is_run)
                        {
                            task aimtask;
                            {
                                unique_lock<mutex> lock(_lock);

                                cv.wait(lock, [this]{return !_tasks.empty();}); //如果没在运�?�了或者任务队列不为空，都�?以继�?
                                
                                if (!_is_run || _tasks.empty()) // 注意这里的防止虚假唤�?
                                {
                                    return;
                                }
                                aimtask = move(_tasks.front()); // ע�������ƶ�����
                                _tasks.pop();
                            }
                            _free_num--;
                            aimtask();
                            _free_num++;
                        }
                    }
                );
                _free_num++;
            }
        }

        int get_free()
        {
            return _free_num;
        }

        int get_size()
        {
            return _pool.size();
        }
        
};

void printcode(int a)
{
    cout<<"a=="<<a<<endl;
    while (1)
    {
        cout<<"love"<<" ";
        this_thread::sleep_for(chrono::seconds(2));
    }
}

class test{
    public:
        static int fucked()
        {
            int c = rand()%10+1;
            sleep(2);
            return 9;
        }
};

int main()
{

    pool mypool(7);
    cout<<"线程池的数量为："<<mypool.get_size()<<endl;
    cout<<"线程池的空闲数量为："<<mypool.get_free()<<endl;

    mypool.commit(printcode,666);
    test st;
    future<int> ret = mypool.commit(st.fucked);
    sleep(1); // 让主线程等一�?
    cout<<"线程池的数量为："<<mypool.get_size()<<endl;
    cout<<"线程池的空闲数量为："<<mypool.get_free()<<endl;
    sleep(1);
    cout<<"ret=="<<ret.get()<<endl;
    cout<<"线程池的数量为："<<mypool.get_size()<<endl;
    cout<<"线程池的空闲数量为："<<mypool.get_free()<<endl;

    while (1)
    {
        sleep(60);
    }

//     while (1)
//     {
//         printf("wScanning dependencies of target THREAD_DAQ w  7ww Building C object CMakeFiles/THREAD_DAQ.dir/CommonMethod/cjson/include/cJSON.c.o \
// 15ww Building CXX object CMakeFiles/THREAD_DAQ.dir/CommonMethod/libiconv/include/CodeConvert.cpp.o\
// /home/wyl/study/NewDaqProg/CommonMethod/libiconv/include/CodeConvert.cpp: In member function wchar* code_convert::strtrim(char*)w:\
// /home/wyl/study/NewDaqProg/CommonMethod/libiconv/include/CodeConvert.cpp:22:21: warning: suggest parentheses around assignment used as truth value w-Wparenthesesw\
// w 23ww Building CXX object CMakeFiles/THREAD_DAQ.dir/CommonMethod/log4cpp/include/Logger.cpp.o\
// In file included from /opt/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/arm-linux-gnueabihf/include/c++/4.8.3/backward/strstream:51:0,\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/log4cpp/include/Portability.hh:58,\n\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/log4cpp/include/Category.hh:13,\n\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/log4cpp/include/Logger.h:4,\n\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/log4cpp/include/Logger.cpp:2:\n\
// /opt/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/arm-linux-gnueabihf/include/c++/4.8.3/backward/backward_warning.h:32:2: warning: wwarning This file includes at least one deprecated or antiquated header which may be removed without further notice at a future date. Please use a non-deprecated interface with equivalent functionality instead. For a listing of replacement headers and interfaces, consult the file backward_warning.h. To disable this warning use -Wno-deprecated. w-Wcppw\
// w 30ww Building CXX object CMakeFiles/THREAD_DAQ.dir/CommunicationMeans/mqtt/include/MqttManager.cpp.o\n\
// In file included from /opt/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/arm-linux-gnueabihf/include/c++/4.8.3/backward/strstream:51:0,\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/log4cpp/include/Portability.hh:58,\n\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/log4cpp/include/Category.hh:13,\n\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/log4cpp/include/Logger.h:4,\n\
//                  from /home/wyl/study/NewDaqProg/CommunicationMeans/mqtt/include/MqttManager.h:6,\n\
//                  from /home/wyl/study/NewDaqProg/CommunicationMeans/mqtt/include/MqttManager.cpp:1:\n\
// /opt/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/arm-linux-gnueabihf/include/c++/4.8.3/backward/backward_warning.h:32:2: warning: wwarning This file includes at least one deprecated or antiquated header which may be removed without further notice at a future date. Please use a non-deprecated interface with equivalent functionality instead. For a listing of replacement headers and interfaces, consult the file backward_warning.h. To disable this warning use -Wno-deprecated. w-Wcppw\
//  wwarning \
//   ^\n \
// w 38ww Building CXX object CMakeFiles/THREAD_DAQ.dir/CommonMethod/getconfig/ReadConfig.cpp.o\n\
// /home/wyl/study/NewDaqProg/CommonMethod/getconfig/ReadConfig.cpp: In member function wvoid ReadConfig::Trim(std::string&)w:\n\
// /home/wyl/study/NewDaqProg/CommonMethod/getconfig/ReadConfig.cpp:28:30: warning: comparison between signed and unsigned integer expressions w-Wsign-comparew\
//      for (i = 0; i < str.size(); ++i) {\
//                               ^\
// /home/wyl/study/NewDaqProg/CommonMethod/getconfig/ReadConfig.cpp:33:23: warning: comparison between signed and unsigned integer expressions w-Wsign-comparew\
//      if (i == str.size())\
//                        ^\
// w 46ww Building CXX object CMakeFiles/THREAD_DAQ.dir/CommonMethod/getconfig/BasicInformation.cpp.o\
// In file included from /opt/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/arm-linux-gnueabihf/include/c++/4.8.3/backward/strstream:51:0,\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/log4cpp/include/Category.hh:13,\n\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/log4cpp/include/Logger.h:4,\n\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/getconfig/BasicInformation.h:11,\n\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/getconfig/BasicInformation.cpp:3:\n\
// /opt/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/arm-linux-gnueabihf/include/c++/4.8.3/backward/backward_warning.h:32:2: warning: wwarning This file includes at least one deprecated or antiquated header which may be removed without further notice at a future date. Please use a non-deprecated interface with equivalent functionality instead. For a listing of replacement headers and interfaces, consult the file backward_warning.h. To disable this warning use -Wno-deprecated. w-Wcppw\
//  wwarning \
//   ^\
// w 53ww Building CXX object CMakeFiles/THREAD_DAQ.dir/CommonMethod/getresult/metandresofget.cpp.o\n\
// In file included from /opt/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/arm-linux-gnueabihf/include/c++/4.8.3/backward/strstream:51:0,\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/log4cpp/include/Portability.hh:58,\n\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/log4cpp/include/Category.hh:13,\n\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/log4cpp/include/Logger.h:4,\n\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/getconfig/BasicInformation.h:11,\n\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/getresult/metandresofget.h:6,\n\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/getresult/metandresofget.cpp:1:\n\
// /opt/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/arm-linux-gnueabihf/include/c++/4.8.3/backward/backward_warning.h:32:2: warning: wwarning This file includes at least one deprecated or antiquated header which may be removed without further notice at a future date. Please use a non-deprecated interface with equivalent functionality instead. For a listing of replacement headers and interfaces, consult the file backward_warning.h. To disable this warning use -Wno-deprecated. w-Wcppw\
//  wwarning \
//   ^\
// w 61ww Building CXX object CMakeFiles/THREAD_DAQ.dir/CommonMethod/platsysfunc/syswatch.cpp.o\
// In file included from /opt/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/arm-linux-gnueabihf/include/c++/4.8.3/backward/strstream:51:0,\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/log4cpp/include/Portability.hh:58,\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/log4cpp/include/Category.hh:13,\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/log4cpp/include/Logger.h:4,\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/getconfig/BasicInformation.h:11,\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/platsysfunc/syswatch.h:6,\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/platsysfunc/syswatch.cpp:1:\
// /opt/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/arm-linux-gnueabihf/include/c++/4.8.3/backward/backward_warning.h:32:2: warning: wwarning This file includes at least one deprecated or antiquated header which may be removed without further notice at a future date. Please use a non-deprecated interface with equivalent functionality instead. For a listing of replacement headers and interfaces, consult the file backward_warning.h. To disable this warning use -Wno-deprecated. w-Wcppw\
//  wwarning \
//   ^\n \
// In file included from /home/wyl/study/NewDaqProg/CommonMethod/platsysfunc/syswatch.cpp:1:0:\
// /home/wyl/study/NewDaqProg/CommonMethod/platsysfunc/syswatch.h: In member function wsystemwatch& systemwatch::operator=(const systemwatch&)w:\
// /home/wyl/study/NewDaqProg/CommonMethod/platsysfunc/syswatch.h:41:52: warning: no return statement in function returning non-void w-Wreturn-typew\
//          systemwatch& operator=(const systemwatch&){};\
//                                                     ^\
// w 69ww Building CXX object CMakeFiles/THREAD_DAQ.dir/DeviceProtocol/focas/include/FanucCncInfo.cpp.o\n\
// In file included from /opt/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/arm-linux-gnueabihf/include/c++/4.8.3/backward/strstream:51:0,\n\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/log4cpp/include/Portability.hh:58,\n\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/log4cpp/include/Category.hh:13,\n\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/log4cpp/include/Logger.h:4,\n\
//                  from /home/wyl/study/NewDaqProg/DeviceProtocol/focas/include/FanucCncInfo.cpp:8:\n\
// /opt/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/arm-linux-gnueabihf/include/c++/4.8.3/backward/backward_warning.h:32:2: warning: wwarning This file includes at least one deprecated or antiquated header which may be removed without further notice at a future date. Please use a non-deprecated interface with equivalent functionality instead. For a listing of replacement headers and interfaces, consult the file backward_warning.h. To disable this warning use -Wno-deprecated. w-Wcppw\
//  wwarning \
//   ^\
// /home/wyl/study/NewDaqProg/DeviceProtocol/focas/include/FanucCncInfo.cpp: In function wchar* strtrim(char*)w:\
// /home/wyl/study/NewDaqProg/DeviceProtocol/focas/include/FanucCncInfo.cpp:48:21: warning: suggest parentheses around assignment used as truth value w-Wparenthesesw\
//      while (*q++ = *p++)\
//                      ^\
// /home/wyl/study/NewDaqProg/DeviceProtocol/focas/include/FanucCncInfo.cpp: In member function wlong int FanucCncInfo::ReadPartsNum() constw:\
// /home/wyl/study/NewDaqProg/DeviceProtocol/focas/include/FanucCncInfo.cpp:207:12: warning: unused variable winfow w-Wunused-variablew\
//    ODBSYS   info;\n\
//             ^\n \n\
// /home/wyl/study/NewDaqProg/DeviceProtocol/focas/include/FanucCncInfo.cpp:207:12: warning: unused variable winfow w-Wunused-variablew\
//    ODBSYS   info;\n\
//             ^\/home/wyl/study/NewDaqProg/DeviceProtocol/focas/include/FanucCncInfo.cpp:207:12: warning: unused variable winfow w-Wunused-variablew\
//    ODBSYS   info;\n\
//             ^\/home/wyl/study/NewDaqProg/DeviceProtocol/focas/include/FanucCncInfo.cpp:207:12: warning: unused variable winfow w-Wunused-variablew\
//    ODBSYS   info;\n\
//             ^\/home/wyl/study/NewDaqProg/DeviceProtocol/focas/include/FanucCncInfo.cpp:207:12: warning: unused variable winfow w-Wunused-variablew\
//    ODBSYS   info;\n\
//             ^\/home/wyl/study/NewDaqProg/DeviceProtocol/focas/include/FanucCncInfo.cpp:207:12: warning: unused variable winfow w-Wunused-variablew\
//    ODBSYS   info;\n\
//             ^\/home/wyl/study/NewDaqProg/DeviceProtocol/focas/include/FanucCncInfo.cpp:207:12: warning: unused variable winfow w-Wunused-variablew\
//    ODBSYS   info;\n\
//             ^\/home/wyl/study/NewDaqProg/DeviceProtocol/focas/include/FanucCncInfo.cpp:207:12: warning: unused variable winfow w-Wunused-variablew\
//    ODBSYS   info;\n\
//             ^\/home/wyl/study/NewDaqProg/DeviceProtocol/focas/include/FanucCncInfo.cpp:207:12: warning: unused variable winfow w-Wunused-variablew\
//    ODBSYS   info;\n\
//             ^\/home/wyl/study/NewDaqProg/DeviceProtocol/focas/include/FanucCncInfo.cpp:207:12: warning: unused variable winfow w-Wunused-variablew\
//    ODBSYS   info;\n\
//             ^\n \
// w 76ww Building CXX object CMakeFiles/THREAD_DAQ.dir/DataCollect/FanucCnc/FanucCncCollect.cpp.o\
// In file included from /opt/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/arm-linux-gnueabihf/include/c++/4.8.3/backward/strstream:51:0,\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/log4cpp/include/Portability.hh:58,\n\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/log4cpp/include/Category.hh:13,\n\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/log4cpp/include/Logger.h:4,\n\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/getconfig/BasicInformation.h:11,\n\
//                  from /home/wyl/study/NewDaqProg/DataCollect/FanucCnc/FanucCncCollect.h:4,\n\
//                  from /home/wyl/study/NewDaqProg/DataCollect/FanucCnc/FanucCncCollect.cpp:10:\n\
// /opt/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/arm-linux-gnueabihf/include/c++/4.8.3/backward/backward_warning.h:32:2: warning: wwarning This file includes at least one deprecated or antiquated header which may be removed without further notice at a future date. Please use a non-deprecated interface with equivalent functionality instead. For a listing of replacement headers and interfaces, consult the file backward_warning.h. To disable this warning use -Wno-deprecated. w-Wcppw\
//  wwarning \
//   ^\
// In file included from /home/wyl/study/NewDaqProg/DataCollect/FanucCnc/FanucCncCollect.h:17:0,\
//                  from /home/wyl/study/NewDaqProg/DataCollect/FanucCnc/FanucCncCollect.cpp:10:\
// /home/wyl/study/NewDaqProg/CommonMethod/platsysfunc/syswatch.h: In member function wsystemwatch& systemwatch::operator=(const systemwatch&)w:\
// /home/wyl/study/NewDaqProg/CommonMethod/platsysfunc/syswatch.h:41:52: warning: no return statement in function returning non-void w-Wreturn-typew\
//          systemwatch& operator=(const systemwatch&){};\
//                                                     ^\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/log4cpp/include/Category.hh:13,\n\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/log4cpp/include/Logger.h:4,\n\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/getconfig/BasicInformation.h:11,\n\
//                  from /home/wyl/study/NewDaqProg/CommonMethod/getresult/metandresofget.h:6,\n\
//                  from /home/wyl/study/NewDaqProg/Src/main.cpp:14:\n\
// /opt/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/arm-linux-gnueabihf/include/c++/4.8.3/backward/backward_warning.h:32:2: warning: wwarning This file includes at least one deprecated or antiquated header which may be removed without further notice at a future date. Please use a non-deprecated interface with equivalent functionality instead. For a listing of replacement headers and interfaces, consult the file backward_warning.h. To disable this warning use -Wno-deprecated. w-Wcppw\
//  wwarning \
//   ^\n \
// In file included from /home/wyl/study/NewDaqProg/DataCollect/FanucCnc/FanucCncCollect.h:17:0,\
//                  from /home/wyl/study/NewDaqProg/Src/main.cpp:17:\
// /home/wyl/study/NewDaqProg/CommonMethod/platsysfunc/syswatch.h: In member function wsystemwatch& systemwatch::operator=(const systemwatch&)w:\
// /home/wyl/study/NewDaqProg/CommonMethod/platsysfunc/syswatch.h:41:52: warning: no return statement in function returning non-void w-Wreturn-typew\
//          systemwatch& operator=(const systemwatch&){};\
//                                                     ^\
// /home/wyl/study/NewDaqProg/Src/main.cpp: In function wint main()w:\
// /home/wyl/study/NewDaqProg/Src/main.cpp:272:42: warning: comparison between signed and unsigned integer expressions w-Wsign-comparew\
//          for (int j=0; j<(*SendInfs).size(); j++) \
//                                           ^\
// /home/wyl/study/NewDaqProg/Src/main.cpp:31:33: warning: variable wactsendnumw set but not used w-Wunused-but-set-variablew\
//      int actdevnum=0, acttags=0, actsendnum=0;\
//                                  ^\
// /home/wyl/study/NewDaqProg/Src/main.cpp:179:9: warning: unused variable wrangesizew w-Wunused-variablew\
//      int rangesize = unidwithresmp->size();\
//          ^\
// w100ww Linking CXX executable THREAD_DAQ\
// w100ww Built target THREAD_DAQw\n");

//         //usleep(500000);
//     }

}
