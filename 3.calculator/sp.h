#ifndef SP_H
#define SP_H
#include<iostream>
#include<stdlib.h>
#include<cctype>
#include<string>
#include<queue>
using namespace std;


class Scan                                                 //����Scan��
{
public:
    string IN;
    string temp;
    queue<string> str;

    queue<string> ToStringQueue(string input);
};


class Print                                    //����Print��
{
public:
    void toprintqueue(queue<string>str)
    {
        int a=str.size();                      //ѭ������
        for (int i = 0; i < a; i++)
        {
            cout << str.front() << endl;       //���������λԪ��
            str.pop();                         //ȥ��������λԪ��
        }
    }
};

#endif

