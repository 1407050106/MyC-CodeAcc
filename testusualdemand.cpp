#include <iostream>
#include <typeinfo>
#include <string.h>
#include <stdio.h>
#include <vector>
using namespace std;

string a;
char c[]={};
pair<string, int> b;
int d;

int main () 
{
    // int i = 12;
    // string j = to_string(i);
    // cout << j << endl;
    // cout << typeid(i).name();
    cout<<"Please Input a string:"<<endl;
    cin>>a; //getline
    //cout<<a<<endl;
    strcpy(c, a.c_str());
    cout<<c<<endl;
    cout<<c[0]<<endl;

    b.first=a;
    b.second=d;
    cout<<b.first<<endl;

}
