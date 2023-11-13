//
// Created by 张力 on 2023/11/8.
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

int Index_BF(SString &S, SString &T)
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
            i = i - j + 2;
            j = 1;
        }
    }
    // 主串扫描完都没有匹配到子串
    return 0;
}


int main()
{
    SString S;
    SString T;
    InitSString(S, "aaabaab");
    InitSString(T, "aab");
    cout << Index_BF(S, T) << endl;
}
