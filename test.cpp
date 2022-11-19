#include <iostream>
#include <string.h>
using namespace std;

string a = "1213";
char b[] = {};

int main(){
    strcpy(b, a.c_str());
    cout<<b;
}
