#include <iostream>
#include <vector>
using namespace std;

vector<string> findallsubseq(string str);
void process(vector<char> s, int index, vector<string>& ans, string path);
void printvec(vector<string> ins);

vector<string> findallsubseq(string str)
{
    vector<char> s;
    for (char c : str)
    {
        s.push_back(c);
    }
    vector<string> ans;
    process(s, 0, ans, "");
    return ans;
}

// 该递归函数需要不断在每一位上做选择并记录结果, 需要去重的话，就用set保存结果
// s 固定参数
// 来到了s[index]字符，index是位置
// s[0..index-1]已经走过了！之前的决定，都在path上
// 之前的决定已经不能改变了，就是path
// 把所有生成的子序列，放入到ans里去
void process(vector<char> s, int index, vector<string>& ans, string path)
{   
    if (index==s.size())
    {
        ans.push_back(path);
        return;
    }
    // 没有要index位置的字符
    process(s, index+1, ans, path);
    // 要了index位置的字符
    process(s, index+1, ans, path+s[index]);
}

void printvec(vector<string> ins)
{
    auto it=ins.begin(); 
    while (it!=ins.end())
    {
        cout<<*it<<" ";
        it++;
    }
}

int main() {
    string test = "123";
    vector<string> res=findallsubseq(test);
    printvec(res);
}