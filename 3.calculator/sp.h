#ifndef SP_H
#define SP_H
#include<iostream>
#include<stdlib.h>
#include<cctype>
#include<string>
#include<queue>
using namespace std;


class Scan                                                 //定义Scan类
{
public:
    string IN;
    string temp;
    queue<string> str;

    queue<string> ToStringQueue(string input);
};


class Print                                    //定义Print类
{
public:
    void toprintqueue(queue<string>str)
    {
        int a=str.size();                      //循环次数
        for (int i = 0; i < a; i++)
        {
            cout << str.front() << endl;       //输出队列首位元素
            str.pop();                         //去除队列首位元素
        }
    }
};

#endif

