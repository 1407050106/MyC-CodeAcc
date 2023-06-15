#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <numeric>
#include <unistd.h>
#include <cstring>
#include <climits>
#include <memory>
#include <queue>
#include <thread>
using namespace std;

// 先写一个引用计数的类
class countobj
{
    public:
        explicit countobj():count(1) {}

        void addcount()
        {
            ++count;
        }

        long deccount()
        {
            return --count;
        }

        long get() const
        {
            return count;
        }
    private:
        long count;
};

template<class T>
class mysmartptr{
    public:
        explicit mysmartptr(T* ptr=nullptr):myptr(ptr)
        {
            //if (!myptr) myptr = new T;  //?
            if (myptr)
            {
                smartptr_count = new countobj();
            }
        }

        ~ mysmartptr()
        {
            if (myptr && !smartptr_count->deccount())
            {
                delete myptr;
                delete smartptr_count;
            }
        }

        long getcount()
        {
            if (myptr)
            {
                return smartptr_count->get();
            } else {
                return 0;
            }
            
        }

//拷贝构造函数
        mysmartptr(const mysmartptr& other)  // 注意！
        {
            this->myptr = other.myptr;
            if (myptr) // 这里判断，如果有的话(没有就是nullptr，也没事)
            {
                other.smartptr_count->addcount();
                this->smartptr_count = other.smartptr_count; //只要把类的成员都拷贝过来就行，成员函数无所谓
            }
        }
// //模板拷贝构造函数
//         template<typename U>
//         mysmartptr(const mysmartptr<U>& other)
//         {
//             myptr = other.myptr;
//             if (myptr)
//             {
//                 other.smartptr_count->addcount();
//                 smartptr_count = other.smartptr_count;
//             }
//         }
// //移动构造函数
//         template<typename U>
//         mysmartptr(const mysmartptr<U>&& other)
//         {
//             myptr = other.myptr;
//             if (myptr)
//             {
//                 smartptr_count = other.smartptr_count;
//                 other.myptr=nullptr;
//             }
//         }

        mysmartptr& operator=(const mysmartptr& other)
        {
            // if (!(&other)) 
            // {
            //     return nullptr;
            // }
            this->myptr = other.myptr;
            other.smartptr_count->addcount();
            this->smartptr_count=other.smartptr_count;
            return *this;
        }


        T& operator*() const {return *myptr;}
        T* operator->() const {return myptr;}
 
    private:
        T* myptr;
        countobj* smartptr_count;     

        // void swap(const mysmartptr& rhs)  // 为了方便实现赋值（及其他一些惯用法），我们需要一个新的 swap 成员函数, 暂时不用！
        // {
        //     using std::swap;
        //     swap(myptr, rhs.myptr);
        //     swap(smartptr_count, rhs.smartptr_count);
        // }
};


int main() {
    mysmartptr<int> testptr(new int);
    cout<<testptr.getcount()<<endl;

        mysmartptr<int> test2 = testptr;
        cout<<testptr.getcount()<<endl;
        cout<<test2.getcount()<<endl;

    mysmartptr<int> test3;
    cout<<test3.getcount()<<endl;
    test3 = test2;
    cout<<test3.getcount()<<" "<<testptr.getcount()<<endl;
}