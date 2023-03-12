#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>

using namespace std;

string getloweststring1(vector<string> snum);
set<string> process(vector<string> snum);
vector<string> removexfromv(vector<string> snum, int i);
string getloweststring2(vector<string> snum);
string generateRandomString(int strLen);
vector<string> generateRandomStringArray(int arrLen, int strLen);
vector<string> copysnum(vector<string> origin);

// method 1   baoli
string getloweststring1(vector<string> snum)
{
    if (snum.empty()) return "";
    set<string> res = process(snum);
    //if (res.size()==0) return "";
    return *res.begin();
}

// ���õݹ��������������ַ�����ȫ���У��������п��ܵĽ��?!!!!!!!
set<string> process(vector<string> snum)
{
    set<string> ans;
    if (snum.size()==0) 
    {
        ans.insert({""});
        return ans;
    }
    for (int i=0; i<snum.size(); i++)
    {
        string first = snum[i];
        vector<string> temp = removexfromv(snum, i);
        // ����ں�˼�?
        set<string> next = process(temp);
        // for (string s : next)
        // {
        //     ans.insert({first+s});
        // }
        for (auto it = next.begin(); it!=next.end(); i++)
        {
            ans.insert({first+*it});
        }
    }
    return ans;
}

vector<string> removexfromv(vector<string> snum, int i)
{
    int len = snum.size();
    vector<string> ans(len-1);
    for (int k=0; k<len; k++)
    {
        if (k=i) continue;
        ans.push_back(snum[k]); 
    }
    return ans;
}

// method 2   tanxin
bool compare1(string s1, string s2)
{
    return (s1+s2)<(s2+s1);
}

string getloweststring2(vector<string> snum)
{
    if (snum.empty()) return "";
    string ans="";
    sort(snum.begin(), snum.end(), compare1);
    for (int k=0; k<snum.size(); k++)
    {
        ans+=snum[k];
    }
    //cout<<ans<<endl;
    return ans;
} 

// for test
string generateRandomString(int strLen) {
    int randomsize = rand()%strLen+1;
    char ans[randomsize] = {};
    for (int i = 0; i < randomsize; i++) {
        int value = rand()%26;
        ans[i] = (char)(97 + value);
    }
    string res = ans;
    return res;
}

vector<string> generateRandomStringArray(int arrLen, int strLen) {
    vector<string> ans(rand()%arrLen+1);
    for (int i = 0; i < ans.size(); i++) {
        ans[i] = generateRandomString(strLen);
    }
    return ans;
}

vector<string> copysnum(vector<string> origin)
{
    vector<string> ans;
    for (int k=0; k<origin.size(); k++)
    {
        ans.push_back(origin[k]);
    }
    return ans;
}

int main() {
    // vector<string> test = {"ba", "b"};
    // getloweststring2(test);
    int arrLen = 3;
	int strLen = 2;
	int testTimes = 1;
    printf("Test begin!\n");
    for (int i=0; i<testTimes; i++)
    {
        vector<string> test1 = generateRandomStringArray(arrLen, strLen);
        vector<string> test2 = copysnum(test1);
        //string res1 = getloweststring1(test1);
        //cout<<"res1="<<res1<<endl;
        string res2 = getloweststring2(test2);
        cout<<"res2="<<res2<<endl;
        // if(res1!=res2)
        // {
        //     cout<<"Oops!"<<endl;
        // }
    }
    printf("Test ending!\n");
}