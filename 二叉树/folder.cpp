#include <iostream>
using namespace std;

void recordfolder(int N);
void process(int i, int N, bool down);

void recordfolder(int N)
{
    process(1,N,true);
}

// 希望有一个函数，可以中序打印每一个节点的凹凸值,这棵树因为有高度值所以是已经生成固定好的,想象的!
// 当前你来了一个节点，脑海中想象的！
// 这个节点在第i层，一共有N层，N固定不变的
// 这个节点如果是凹的话，down = T
// 这个节点如果是凸的话，down = F
void process(int i, int N, bool down)
{
    // 递归的终止条件？
    if (i>N) return;
    process(i+1, N, true);  // 去递归下一层的左孩子
    string s = down?"a":"t";
    cout<<s<<" ";
    process(i+1, N, false);  // 去递归下一层的右孩子
    // 所以这题考察对二叉树的递归序的深刻理解,超级变式中序遍历!
}

int main() {
    int N = 2;
    recordfolder(N);
}