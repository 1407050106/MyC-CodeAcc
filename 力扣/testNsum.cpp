#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getNsum(int n)
{
    if (n==1)
    {
        return 1;
    }
    return getNsum(n-1)+n;
}

int main() {
    //cout<<getNsum(3)<<endl;  // OK
}