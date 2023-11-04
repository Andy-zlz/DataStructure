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

int main()
{
    SqStack sqStack;
    InitStack(sqStack);
    cout << "ok" << endl;
}