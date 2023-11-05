//
// Created by 张力 on 2023/11/4.
//
#include "iostream"
using namespace std;

#define MAXSIZE 100
typedef int SElemType;
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

void InitStack(SqStack &sqStack)
{
    sqStack.base = new SElemType[MAXSIZE];
    sqStack.top = sqStack.base;
    sqStack.stacksize = MAXSIZE;
}

void Push(SqStack &sqStack, SElemType e)
{
    if(sqStack.top - sqStack.base == sqStack.stacksize)
    {
        cout << "栈满" <<endl;
    }
    // 入栈
    *sqStack.top++ = e;
}

void Pop(SqStack &sqStack, SElemType &e)
{
    if(sqStack.top == sqStack.base)
    {
        cout << " 栈空" << endl;
    }
    e = *--sqStack.top;
}

int main()
{
    SqStack sqStack;
    InitStack(sqStack);
    Push(sqStack, 10);
    int e;
    Pop(sqStack, e);
    cout << e << endl;
}