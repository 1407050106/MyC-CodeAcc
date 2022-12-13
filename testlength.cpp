#include <iostream>
#include <string.h>
using namespace std;

string w = "abcd";
char s[10];
int k[]={0,1,2,3};

int main() {
    strcpy(s, w.c_str());
    cout<<strlen(w.c_str())<<endl;
    cout<<sizeof(w)<<endl;
    cout<<w.size()<<endl;
    cout<<w.length()<<endl;

    printf("\n");

    cout<<strlen(s)<<endl;
    cout<<sizeof(s)<<endl;
    cout<<sizeof(s)/sizeof(s[1])<<endl;

    printf("\n");
    for (int i=0; i<10; i++)
    {
        cout<<s[i];
    }

    printf("\n");

    cout<<sizeof(k)<<endl;    //if k[10] =40
    cout<<sizeof(k)/sizeof(k[0])<<endl;  //if k[10] =10
}