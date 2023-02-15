#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int remvfloor(stack<int>& v);
void reversestack(stack<int>& v);

void reversestack(stack<int>& v)
{
    if (v.empty())
    {
        return;
    }
    int i = remvfloor(v);
    reversestack(v);
    v.push(i);
}

// 移除栈底元素，将栈中剩余元素继续压下去, 返回栈底元素
int remvfloor(stack<int>& v)
{
    int result = v.top();
    v.pop();
    if (v.empty())
    {
        return result;
    } else {
        int last=remvfloor(v);
        // 先压入栈
        v.push(result);
        // 再返回值给上一层使用
        return last;
    }
}

int main() {
    stack<int> test;
    test.push(1);
    test.push(2);
    test.push(3);

    reversestack(test);
    while (!test.empty())
    {
        cout<<test.top()<<" ";
        test.pop();
    }
}