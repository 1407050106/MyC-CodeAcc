#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>
#include <numeric>
#include <algorithm>
#include <memory>
#include <cmath>
#include <ctime>
#include <cstring>
using namespace std;

int main() 
{
    char* split = ";/";

    string a ="a;b/cc";
    char c[10]={};
    strncpy(c, a.c_str(), a.length());
    cout<<"c="<<c<<endl;

    char* b = strtok(c, split);
    cout<<"b="<<b<<endl;

    string s = b;
    cout<<"s="<<s<<endl;
}