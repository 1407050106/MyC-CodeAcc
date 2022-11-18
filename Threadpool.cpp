/***======================================================================
====                                                                     
====    File name           :  Threadpool.cpp
====    Project name        :  NewDaqProg
====    Project number      :  001
====    Creation date       :  2022/10/10
====    Author(s)           :  Wang Yonglin, Yang Lang                            
====                                                                     
=========================================================================*/
#include "Threadpool.h"
#include <unistd.h>

int testn =100;

void fun1(int slp)
{
	printf("  hello, fun1 !  %d\n", std::this_thread::get_id());
	//std::this_thread::sleep_for(std::chrono::milliseconds(slp));    // ms
	//std::this_thread::sleep_for(std::chrono::seconds(3));           // s
}
 
struct gfun {
	int operator()(int n) {
		printf("%d  hello, gfun !  %d\n", n, std::this_thread::get_id());
		return 123;
	}
};
 
class A {
	public:   		
		static int Afun(int n = 0) {
			std::cout << n << "  hello, Afun !  " << std::this_thread::get_id() << std::endl;
			return n;
		}
	
		static std::string Bfun(int n, std::string str, char c) {
			std::cout << n << "  hello, Bfun !  " << str.c_str() << "  " << (int)c << "  " << std::this_thread::get_id() << std::endl;
			return str;
		}

		static void Cfun () {
			while (testn>0) {
				--testn;
				cout<<testn<<endl;
			}
			// B b; 
			// b.fun2(1);
		}

		static void Dfun () {
			while (testn>0) {
				--testn;
				cout<<testn<<endl;
			}
		}
};

class B {
public:
	static void fun2(int q){
		cout<<"5555555555555555555"<<endl;
	}
};
 
int main()
{
	try {
		threadpool executor{ 6 };
		A a;
		executor.commit(a.Cfun);
		executor.commit(a.Dfun);
		// std::future<void> ff = executor.commit(fun1, 0);
		// std::future<int> fg = executor.commit(gfun{}, 0);
		// std::future<int> gg = executor.commit(a.Afun, 456);
		// std::future<std::string> gh = executor.commit(A::Bfun, 789, "hello wyl", 111);
		// std::future<std::string> fh = executor.commit([]()->std::string { std::cout << "hello, fh !  " << std::this_thread::get_id() << std::endl; return "hello,fh ret !"; });
		
 
		//ff.get(); 
		//std::cout << fg.get() << " gfunsreturn " << fh.get().c_str() << " gfunsreturn2 " << std::this_thread::get_id() << std::endl;
 
		// executor.commit(fun1, 55).get();    
		int num = thread::hardware_concurrency();//获坖cpu核心�?�?  
    	cout << "CPUs is:" << num << endl;
		std::cout << "end... " << std::this_thread::get_id() << std::endl;
		 
		while (1) {
        	sleep(10000);
    	}

		// threadpool pool(4);
		// std::vector< std::future<int> > results;
 
		// for (int i = 0; i < 8; ++i) {
		// 	results.emplace_back(
		// 		pool.commit([i] {
		// 			std::cout << "hello " << i << std::endl;
		// 			std::this_thread::sleep_for(std::chrono::seconds(1));
		// 			std::cout << "world " << i << std::endl;
		// 			return i * i;
		// 			})
		// 	);
		// }
		// std::cout << " =======  commit all2 ========= " << std::this_thread::get_id() << std::endl;
 
		// for (auto&& result : results)
		// 	std::cout << result.get() << ' ';
		return 0;
	}
	catch (std::exception & e) {
		std::cout << "some unhappy happened...  " << std::this_thread::get_id() << e.what() << std::endl;
	}
 
}