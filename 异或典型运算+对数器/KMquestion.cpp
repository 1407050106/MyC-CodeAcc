#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <stdlib.h>
#include <time.h>
using namespace std;

int Rangdom(int range)
{
    return (rand()%range+1)-(rand()%range+1);   //[1-range]
}

//duidhuqi
vector<int> generator(int maxkind, int range, int kk, int mm)   //set shuzu (how to kepp 1<=kk<mm?)
{
    vector<int> arry;
    int kn = Rangdom(range);
    for (int i=0; i<kk; i++)
    {
        arry.push_back(kn);
    }
    unordered_map<int, int> mp;
    mp[kn]=1;
    maxkind--;
    while(maxkind!=0)
    {
        int mn = Rangdom(range);
        while(mp.count(mn)>0)
        {
            mn = Rangdom(range);
        } 
        mp[mn]=1;
        for (int i=0; i<mm; i++)
        {
            arry.push_back(mn);
        }
        maxkind--;
    }
    //arry tian hao le
    for (int j=0; j<arry.size(); j++)
    {
        int c = (rand()%arry.size());    //0-N-1
        int temp = arry[j];
        arry[j]=arry[c];
        arry[c]=temp;
    }
    return arry;
}


int hashmethod(vector<int> v, int k)
{
    map<int, int> hashmap;
    int res = 0;
    for (int value : v)
    {
        if (hashmap.count(value)>0)
        {
            hashmap[value]++;
        } else {
            hashmap[value]=1;
        }
    }

    // for (auto i = hashmap.cbegin(); i != hashmap.cend(); ++i) {
    //     std::cout << i->first << " " << i->second << std::endl;
    // }

    for (auto i = hashmap.begin(); i!=hashmap.end(); i++)
    {
        if (i->second == k)
        {
            res = i->first;
        }
    }
    return res;
}

//m>1, k<m
int findanswer(vector<int> v, int m)
{
    int acc[32]={0};
    int res=0;
    //bianli v zhong shuzi, tongji meiyiwei de geshu
    for(int i : v)
    {
        for (int j=0; j<32; j++)
        {
            // gooder
            // 右移1位与上1，就是要依次获取低位的二进制值
            acc[j] += (i>>j)&1; 
            // if((i>>j)&1 == 1)
            // {
            //     cout<<i<<j<<endl;
            //     acc[j]++;
            // }
        }
    }

    for (int i=0; i<32; i++)
    {
        if (acc[i]%m==0){
            continue;
        } else {
            res |= 1<<i;
        }
    }

    return res;
    
}

int main()
{
    // vector<int> v={1,4,4,4,1,5,5,1};
    // int ans = findanswer(v, 3);   //tell other's num(m)
    // cout<<ans<<endl;
    // int ans2 = hashmethod(v, 2);  //tell aim's num(k)
    // cout<<ans2<<endl;

    //int a = 1+(rand() % 100)*0.1;    1~10
    
    int maxkind = 6;
    int range = 100;
    int testnum = 100000;

    time_t start = clock();
    for (int i=0; i<testnum; i++)
    {
        cout<<"Test Start"<<endl;
        int aa = (rand()%10)+1;  //[1-10]
        int bb = (rand()%10)+1;

        int kk=min(aa, bb);
        int mm=max(aa, bb);

        if (kk==mm)
        {
            mm=kk+1;
        }

        vector<int> test = generator(maxkind, range, kk, mm);
        int ans1 = findanswer(test, mm);
        int ans2 = hashmethod(test, kk);
        if (ans1!=ans2)
        {
            cout<<"Some Wrong!"<<endl;
        }
        cout<<"Test Finish"<<endl;
    }
    time_t end = clock();

    cout<<"Time consume is : "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;

    cout<<"Yes!!!"<<endl;

}