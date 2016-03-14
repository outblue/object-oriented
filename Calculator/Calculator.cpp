#include<iostream>
#include<stdlib.h>
#include<cctype>
#include<string>
#include<queue>
using namespace std;


class Scan                                     //定义Scan类
{
public:
	string IN;
	string temp;
	queue<string> str;

	queue<string> ToStringQueue(string input);
};


queue<string> Scan::ToStringQueue(string input)
{
	for(int i=0;i<input.size();i++)                 //从第一个元素开始循环
	{
		IN=input[i];
		if(isdigit(input[i])) temp+=IN;             //如果是数字，就暂存到字符串temp中
		else 
		{
			if(input[i]=='.') temp+=IN;             //如果是小数点，也暂存到temp中
			else                                    //若是其余符号
			{
				if(temp.empty()) str.push(IN);      //当temp为空时，直接push到队列中
				else
				{
					str.push(temp);                 //否则，先push temp                 
					str.push(IN);                   //然后push符号
					temp.clear();                   //最后清空temp
				}
			}
		}
	}
	if(!temp.empty()) str.push(temp);               //循环结束后，若temp不为空，push进队列
	return str;
}



		
class Print                                    //定义Print类
{
public:
	void toprintqueue(queue<string>str)
	{
		int a=str.size();                      //循环次数
		for(int i=0;i<a;i++)
		{
			cout << str.front() << endl;       //输出队列首位元素
			str.pop();                         //去除队列首位元素
		}
	}
};


bool num(string in);


int main()
{
	string INPUT;
	cin >> INPUT ;                          //输入运算式
	
	bool x=num(INPUT);                      //通过num函数来判断是否要继续运行

	if(x)                                   //若x=1
	{
	    Scan scan;                          //创建scan对象
	    queue<string> d;
	    d=scan.ToStringQueue(INPUT);        //获取队列

	    Print print;                        //创建print对象
	    print.toprintqueue(d);              //输出队列
	}
	else cout << "It is wrong." << endl;    //若x=0，报错

	system("pause");
	return 0;
}


bool num(string in)
{
	bool y=false;                            //定义一个bool值
	int n=0;
	for(int i=0;i<in.size();i++)          
	{
		if(isdigit(in[i]))                   //判断元素是否为数字
		{
			n+=1;                            //若是，加一
			if(n>10) {y=0; break;}           //若总数大于10，y=0
			else y=1;                        //否则y=1
		}
		else
		{
			if(in[i]=='.')                   //若不是数字而是小数点
			{
				n+=1;                        //加一
				if(n>10) {y=0; break;}       //若总数大于10，y=0
				else y=1;                    //否则y=1
			}
			else {n=0; y=1;}                 //若为运算符，y=1
		}
	}

	return y;
}

