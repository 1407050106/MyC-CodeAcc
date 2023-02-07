#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

class wylniubi{
    public:
        void quanpailie(string str)
        {
            int n = str.length();
            char temp[str.length()] = {};
            strcpy(temp, str.c_str());
            dfs (n, temp, 0);
        }

        void dfs(int n, char* temp, int first)
        {
            if (first==n)
            {
                ans.push_back(temp);
                return;
            }
            // 先循环把每个值放第一位，再把每个值放第二位
            for (int i=first; i<n; i++)
            {
                swap(temp, i, first);
                dfs(n, temp, first+1);
                swap(temp, i, first);
            }
        }

        void printvec()
        {
            for (int k=0; k<ans.size(); k++)
            {
                cout<<ans[k]<<" ";
            }
            printf("\n");
        }

        void swap(char* temp, int a, int b)
        {
            char c = temp[a];
            temp[a]=temp[b];
            temp[b]=c;
        }

    private:
        vector<string> ans;
};

int main() {
    wylniubi www;
    www.quanpailie("132");
    www.printvec();
}