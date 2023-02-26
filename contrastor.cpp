#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

// +类的继承关系验证!
class Young{
    public:
        Young(){}
        Young(int input)
        {
            this->c=input;
            cout<<"c=input!"<<endl;
        }

        static bool compare(int a, int b)     //static!
        {
            return a>b;
        }

        ~Young()
        {
            c=6666;
            cout<<"c is changed!"<<endl;
        }

        //virtual int bei()=0;
    private:
        int c;
};

class wyl: public Young{
    public:
        int bei()
        {
            cout<<"Fuck!"<<endl;
            return 0;
        }

        ~wyl()
        {
            cout<<"wyl is changed!"<<endl;
        }
};

bool compare(int a, int b)       //用在容器�?己带的sort方法�?, 直接写名字就�?
{
    return a>b;     //jiang xu
}

struct myway{
    void operator()(int val){
        cout<<val<<" ";
    }
};

int main() {
    // 确实不会继承构造函数，但父类析构函数执行了两遍
    // Young young(8888);
    // wyl test;
    // test.bei();
    
    vector<int> v{7,1,2,3,4,5,6};
    //sort(v.begin(), v.end());
    //sort(v.begin(), v.end(), compare);
    //sort(v.begin(), v.end(), less<int>());
    sort(v.begin(), v.end(), compare);
    for_each(v.begin(), v.end(), myway());
    printf("\n");
    
}