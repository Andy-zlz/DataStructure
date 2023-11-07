//
// Created by 张力 on 2023/11/7.
//
#include "iostream"
using namespace std;

typedef int QElemType;

typedef struct Qnode
{
    QElemType data;
    struct Qnode *next;
}Qnode, *QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

void InitQueue(LinkQueue &Q)
{
    Q.rear = Q.front = new Qnode;
    Q.front->next = nullptr;
    cout << "初始化成功" << endl;
}


int main()
{
    LinkQueue linkQueue;
    InitQueue(linkQueue);
}