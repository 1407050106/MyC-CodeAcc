/***======================================================================
====                                                                     
====    File name           :  testthreads.cpp
====    Project name        :  NewDaqProg
====    Project number      :  001
====    Creation date       :  2022/10/10
====    Author(s)           :  Wang Yonglin, Yang Lang                            
====                                                                     
=========================================================================*/
#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

void foo(int Z)
{
    for (int i = 0; i < Z; i++) {
        cout << "线程使用函数指针作为�?调用参数\n";
    }
}

class thread_obj {
public:
    void operator()(int x)
    {
        for (int i = 0; i < x; i++)
            cout << "线程使用函数对象作为�?调用参数\n";
    }
};
 
int main()
{
    cout << "Thread�?立运�?" << endl;
 
    // 函数指针
    thread th1(foo, 3);
 
    // 函数对象
    thread th2(thread_obj(), 3);
 
    // 定义 Lambda 表达�?1�?7
    auto f = [](int x) {
        for (int i = 0; i < x; i++)
            cout << "线程使用 lambda 表达式作为可调用参数\n";
    };
 
    // lambda 表达�?
    thread th3(f, 3);
 
    // 等待线程完成
    // 等待线程 t1 完成
    th1.join();
 
    // 等待线程 t2 完成
    th2.join();
 
    // 等待线程 t3 完成
    th3.join();

    while (1) {
        sleep(10);
    }
 
    return 0;
}


