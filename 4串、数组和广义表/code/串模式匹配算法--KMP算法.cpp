//
// Created by 张力 on 2023/11/13.
//
#include "iostream"
using namespace std;

#define MAXLEN 255
typedef struct
{
    char ch[MAXLEN+1];
    int length; // 串当前长度
}SString;

void InitSString(SString &S, string s)
{
    for(int i = 1; i <= s.size(); i++)
    {
        S.ch[i] = s[i-1];
    }
    S.length = s.size();
}

int Index_KMP(SString &S, SString &T, int (&next)[4])
{
    int i, j;
    for(i = 1, j = 1; i <= S.length;)
    {
        if(S.ch[i] == T.ch[j])
        {
            i++; j++;
            // 只有完全匹配j才会大于模式串的长度
            if(j > T.length)
                return i-T.length;
        }
        else
        {
            j = next[j];  // i不回退，j回退到最大位置
        }
    }
    // 主串扫描完都没有匹配到子串
    return 0;
}

void GetNext(char (&ch)[256], int length, int (&next)[4])
{
    next[1] = 0;
    int i = 1, j = 0; // i当前主串正在匹配的字符位置，也就是next数组的索引
    while(i <= length)
    {
        if(j == 0 || ch[i] == ch[j])
            next[++i] = ++j;
        else
            j = next[j];
    }

}

int main()
{
    SString S;
    SString T;
    int next[4];

    cout << endl;
    InitSString(S, "aaabaab");
    InitSString(T, "aab");

    GetNext(T.ch, T.length, next);
    for(int num : next)
    {
        cout << num << " ";
    }

    cout << Index_KMP(S, T, next) << endl;
}