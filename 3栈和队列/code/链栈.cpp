//
// Created by 张力 on 2023/11/7.
//
#include "iostream"
using namespace std;
typedef int SElemType;

typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode, *LinkStack;

void InitStack(LinkStack &S)
{
    S = nullptr;
    cout << "初始化成功" << endl;
}

void Push(LinkStack &S, SElemType e)
{
    LinkStack p = new StackNode;
    p->data = e;
    p->next = S;
    S = p;
}

void Pop(LinkStack &S)
{
    LinkStack p = S;
    SElemType e = S->data;
    S = S->next;
    delete p;
    cout << "栈顶元素" << e << endl;
}

int main()
{
    LinkStack S;
    InitStack(S);
    // 入栈
    Push(S, 10);
    Push(S, 20);
    Push(S, 30);
    // 出栈
    Pop(S);
    Pop(S);
    Pop(S);

}