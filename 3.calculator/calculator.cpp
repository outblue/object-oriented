#include"sp.h"
#include<iostream>
#include<stdlib.h>
#include<cctype>
#include<string>
#include<queue>
using namespace std;


queue<string> Scan::ToStringQueue(string input)
{
    for (int i = 0; i < input.size(); i++)                 //�ӵ�һ��Ԫ�ؿ�ʼѭ��
    {
        IN = input[i];
        if (isdigit(input[i])) temp += IN;                 //��������֣����ݴ浽�ַ���temp��
        else 
        {
            if (input[i] == '.') temp += IN;               //�����С���㣬Ҳ�ݴ浽temp��
            else                                           //�����������
            {
                if (temp.empty()) str.push(IN);            //��tempΪ��ʱ��ֱ��push��������
                else
                {
                    str.push(temp);                 	   //������push temp                 
                    str.push(IN);                          //Ȼ��push����
                    temp.clear();                          //������temp
                }
            }
        }
    }
    
    if (!temp.empty()) str.push(temp);                     //ѭ����������temp��Ϊ�գ�push������
    return str;
}


bool num(string in);


int main()
{
    string INPUT;
    cin >> INPUT ;                           //��������ʽ

    bool x = num(INPUT);                     //ͨ��num�������ж��Ƿ�Ҫ��������

    if (x)                                   //��x=1
    {
        Scan scan;                           //����scan����
        queue<string> d;
        d = scan.ToStringQueue(INPUT);       //��ȡ����

        Print print;                         //����print����
        print.toprintqueue(d);               //�������
    }
    else cout << "It is wrong." << endl;     //��x=0������

    return 0;
}


bool num(string in)
{
    bool y = false;                           //����һ��boolֵ
    int n = 0;
    for (int i = 0; i < in.size(); i++)          
    {
        if (isdigit(in[i]))                   //�ж�Ԫ���Ƿ�Ϊ����
        {
            n += 1;                           //���ǣ���һ
            if (n > 10)
			{
				y = 0;
				break;
			}                                 //����������10��y=0
            else y = 1;                       //����y=1
        }
        else
        {
            if (in[i] == '.')                 //���������ֶ���С����
            {
                n += 1;                       //��һ
                if (n > 10) 
				{
					y = 0;
					break;
				}                             //����������10��y=0
                else y = 1;                   //����y=1
            }
            else 
			{
				n = 0;
				y = 1;
			}                 				  //��Ϊ�������y=1
        }
    }
    
    return y;
}
