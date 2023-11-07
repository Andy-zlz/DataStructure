//
// Created by 张力 on 2023/11/7.
//
#include "iostream"
using namespace std;

#define MAXQSIZE 11
typedef int QElemType;

typedef struct
{
    QElemType *base;
    int front; // 队头指针
    int rear; // 队尾指针
}SqQueue;

void InitQueue(SqQueue &Q)
{
    Q.base = new QElemType[MAXQSIZE];
    Q.front = 0;
    Q.rear = 0;
    cout << "初始化完成" << endl;
}

int QueueLength(SqQueue &Q)
{
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

void EnQueue(SqQueue &Q, QElemType e)
{
    // 判断队列是否已满
    if((Q.rear + 1) % MAXQSIZE == Q.front) // 采用空一个空间方法
    {
        cout << "队列已满" << endl;
        return;
    }
    // 入队
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
}

QElemType DeQueue(SqQueue &Q, QElemType &e)
{
    if(Q.rear == Q.front)
    {
        cout << "队列为空" << endl;
    }
    else
    {
        e = Q.base[Q.front];
        Q.front = (Q.front + 1) % MAXQSIZE;
        return e;
    }
}

int main()
{
    SqQueue sqQueue;
    // 初始化
    InitQueue(sqQueue);
    // 求队列长度
//    cout << "队列长度为：" << QueueLength(sqQueue) << endl;
    // 入队
    int i = 1;
    while(i <= 11)
    {
        EnQueue(sqQueue, i*10);
        cout << "队列长度为：" << QueueLength(sqQueue) << endl;
        cout << "队列长度为：" << QueueLength(sqQueue) << endl;
        ++i;
    }

    // 出队
    int e;
    i = 1;
    while(i <= 11)
    {
        DeQueue(sqQueue, e);
        cout << e << endl;
        ++i;
    }

}