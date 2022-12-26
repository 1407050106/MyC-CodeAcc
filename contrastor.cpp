#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

class Young{
    public:
        Young(){}
        Young(int input)
        {
            this->c=input;
            cout<<"c=input!"<<endl;
        }

        static bool compare(int a, int b)
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
};

bool compare(int a, int b)       //用在容器自己带的sort方法上, 直接写名字就行
{
    return a>b;     //jiang xu
}

struct myway{
    void operator()(int val){
        cout<<val<<" ";
    }
};

int main() {
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