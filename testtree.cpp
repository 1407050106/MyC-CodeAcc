#include <iostream>
#include<array>
#include<queue>
using namespace std;
//数据结构
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;
 
//先序遍历的顺序建立二叉链表
void CreateBiTree(BiTree &T) {//二叉树的构造，用递归
    char ch;
    cin >> ch;
    //当前结点为空
    if (ch == '#') T = NULL;
    else {
        //当前结点不空
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild);//构造左子树
        CreateBiTree(T->rchild);//构造右子树
    }
}
 
//递归先序遍历
void PreOrder(BiTree T){
    if(T){
        cout<<T->data<<" ";
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
 
//中序遍历
void InOrder(BiTree T){
    if(T){
        InOrder(T->lchild);
        cout<<T->data<<" ";
        InOrder(T->rchild);
    }
}
 
//后序遍历
void SubOrder(BiTree T){
    if(T){
        SubOrder(T->lchild);
        SubOrder(T->rchild);
        cout<<T->data<<" ";
    }
}
 
//复制二叉树
bool Copy(BiTree T, BiTree &NewT){
    if(T == NULL){
        NewT = NULL;
        return false;
    } else{
        NewT = new BiTNode;
        NewT->data = T->data;
        Copy(T->lchild, NewT->lchild);
        Copy(T->rchild,NewT->rchild);
    }
    return true;
}
 
//计算二叉树深度
int Depth(BiTree T){
    if(T == NULL)
        return 0;
    else{
        int m = Depth(T->lchild);
        int n = Depth(T->rchild);
        if(m>n)
            return (m+1);
        else
            return (n+1);
    }
}
 
//计算结点总数
int NodeCount(BiTree T){
    if(T == NULL)
        return 0;
    else
        return (NodeCount(T->lchild) + NodeCount(T->rchild) + 1);
}
 
//计算叶子节点数
int LeafCount(BiTree T){
    if(T == NULL)
        return 0;
    if(T->lchild == NULL && T->rchild == NULL)
        return 1;
    else
        return (LeafCount(T->lchild) + LeafCount(T->rchild));
}
 
int main() {
    BiTree T,NewT;
    cout<<"请按先序遍历顺序依次输入,空元素用#表示"<<endl;
    CreateBiTree(T);
    cout<<"先序遍历:";
    PreOrder(T);
    cout<<endl;
    cout<<"中序遍历";
    InOrder(T);
    cout<<endl;
    cout<<"后序遍历";
    SubOrder(T);
    cout<<endl;
    cout<<"复制二叉树"<<endl;
    if(Copy(T,NewT)) cout<<"复制成功"<<endl;
    cout<<"二叉树的深度为:"<<Depth(T)<<endl;
    cout<<"结点数："<<NodeCount(T)<<endl;
    cout<<"叶子节点数："<<LeafCount(T)<<endl;
    return 0;
}
