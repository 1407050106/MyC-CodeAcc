#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// 完全可以啦 不用再看卡啦

#define Maxsize 50
#define Maxnumber 100

vector<int> maopao (vector<int> v)
    {
        int scape = v.size();
        int begin = 0, temp = 0;
        for (begin; begin<(scape-1); begin++){
            int i = 0;
            while(i<(scape-1))
            {
                if(v[i]>v[i+1])
                {
                    temp = v[i+1];
                    v[i+1]=v[i];
                    v[i]=temp;
                }
                i++;
            }
        }
        return v;
    }

vector<int> xuanze (vector<int> v)
{
    int num = v.size();
    if (v.empty() || num <2)
    {
        return v;
    }

    for (int i = 0; i<num-1; i++)
    {
        int MinIndex = i;
        for (int j = i+1; j<num; j++)
        {
            MinIndex = v[j]<v[MinIndex]?j:MinIndex;
        }
        if(MinIndex!=i)                     //zheju buyao yexing 
        {
            int temp = v[MinIndex];
            v[MinIndex] = v[i];
            v[i]=temp;
        }
    }
    return v;
}

struct myway{
    public:
        void operator()(int val){
            cout<<val<<endl;
        }
};

//int b = (rand() % 100)*0.1;   //0-9
class SrandNumber{              //duishuqi
    public:
        vector<int> producenum () 
        {
            vector<int> v;
            //v.resize(Maxsize);
            for (int i=0; i<Maxsize; i++)
            {
                v.push_back((Maxnumber+10)*((rand() % 100)*0.1)-(Maxnumber)*((rand() % 100)*0.1));
            }
            return v;
        }

};

int main() {
    SrandNumber srandnumber;
    int counter = 500000;
    while(counter>=1){      
        vector<int> puzzle, res1, res2;
        puzzle=srandnumber.producenum();
        res1=xuanze(puzzle);
        res2=maopao(puzzle);
        //for_each(puzzle.begin(), puzzle.end(), myway());
        if(res1!=res2){
            cout<<"Not good!"<<endl;
        } 
        counter--;
    }
    cout<<"Nice!"<<endl;   
}

