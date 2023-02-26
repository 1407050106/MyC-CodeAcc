#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

// xuanze paixu
// 选择排序的两个步骤就是：依次选择最小的值+交换!
void xuanze (vector<int>& v)
{
    int num = v.size();
    if (v.empty() || num <2)
    {
        return;
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
    
}

void swap2(vector<int>& v, int j, int MinIndex)
{
    int temp = v[MinIndex];
    v[MinIndex] = v[j];
    v[j]=temp;
}

// maopao paixu
//  冒泡排序一共要进行N-1轮，每轮都从0开始!
bool maopao (vector<int>& v)
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
        return true;
    }
        

struct myway{
    public:
        void operator()(int val){
            cout<<val<<endl;
        }
};

//More notes in OneNote
int main() {
    vector<int> shuzu;
    shuzu.push_back(1);
    shuzu.push_back(12);
    shuzu.push_back(5);
    shuzu.push_back(7);
    shuzu.push_back(2);
    shuzu.push_back(3);
    shuzu.push_back(6);
    shuzu.push_back(2);
    
    // if (maopao(shuzu)) {
    //     for_each(shuzu.begin(), shuzu.end(), myway());
    // }

    xuanze(shuzu);
    for_each(shuzu.begin(), shuzu.end(), myway());
    
}