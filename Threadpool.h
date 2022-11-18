/***======================================================================
====                                                                     
====    File name           :  Threadpool.h
====    Project name        :  NewDaqProg
====    Project number      :  001
====    Creation date       :  2022/10/10
====    Author(s)           :  Wang Yonglin, Yang Lang                            
====                                                                     
=========================================================================*/
#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#pragma  once    

#include <vector>
#include <queue>
#include <memory>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <unordered_map>
#include <thread>
#include <iostream>
#include <future>
#include <stdexcept>
using namespace std;

#define  THREADPOOL_MAX_NUM 6
//#define  THREADPOOL_AUTO_GROW

class threadpool
{
    using Task = function<void()>;	
    vector<thread> _pool;          //threads store
    queue<Task> _tasks;            //tasks store
    mutex _lock;                   //lock class for safe
    condition_variable _task_cv;   //condition class decided on the status of thread
    atomic<bool> _run{ true };     //is pool run or not
    atomic<int>  _idlThrNum{ 0 };  //number of nonuse-thread
 
	public:
		inline threadpool(unsigned short size = 4) { addThread(size); }    //1.set the num of threads in pool 2.inline for faster speed
		inline ~threadpool()
		{
			_run = false;
			_task_cv.notify_all(); 
			for (thread& thread : _pool) {
				//thread.detach(); 
				if (thread.joinable())
					thread.join(); 
			}
		}
 
	public:
		template<class F, class... Args>
		auto commit(F&& f, Args&&... args) ->future<decltype(f(args...))>     //define template func to get any type input args and infer their returns
		{
			if (!_run)    
				throw runtime_error("ThreadPool is stopped!");
 
			using RetType = decltype(f(args...)); 
			auto task = make_shared<packaged_task<RetType()>>(
				bind(forward<F>(f), forward<Args>(args)...)
				); 
			future<RetType> future = task->get_future();
			{   //add func to the queue of tasks 
				lock_guard<mutex> lock{ _lock };
				//push task to the end of queue
				_tasks.emplace([task]() {  
					(*task)();
					});
			}
// #ifdef THREADPOOL_AUTO_GROW
// 			if (_idlThrNum < 1 && _pool.size() < THREADPOOL_MAX_NUM)
// 				addThread(1);
// #endif // !THREADPOOL_AUTO_GROW
			_task_cv.notify_one();     //notice one thread
 
			return future;     //get the result of return of func
		}
 
		//空闲线程数量
		int idlCount() { return _idlThrNum; }

		//线程数量
		int thrCount() { return _pool.size(); }
		
		void addThread(unsigned short size)
		{
			for (; _pool.size() < THREADPOOL_MAX_NUM && size > 0; --size)
			{   
				_pool.emplace_back([this] { //工作线程
					while (_run)
					{
						Task task; // get one new task
						{
							unique_lock<mutex> lock{ _lock };
							_task_cv.wait(lock, [this] {
								return !_run || !_tasks.empty();
								}); // wait until there is a task in queue
							if (!_run && _tasks.empty())
								return;
							task = move(_tasks.front()); // strach a task from queue
							_tasks.pop();
						}
						_idlThrNum--;
						task(); //执行任务
						_idlThrNum++;
					}
					});
				_idlThrNum++;
			}
		}
};

#endif
