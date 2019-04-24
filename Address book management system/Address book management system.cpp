// Address book management system.cpp : Defines the entry point for the console application.
/*
	通讯录管理系统
	1.增加联系人
	2.删除联系人
	3.修改联系人
	4.查询联系人
	5.清空联系人
	6.退出

*/

#include "stdafx.h"
#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

void showMenu()   //显示菜单
{
	cout<<"================================"<<endl;
	cout<<"	1.添加联系人		   "<<endl;
	cout<<"	2.删除联系人		   "<<endl;
	cout<<"	3.更新联系人		   "<<endl;
	cout<<"	4.查询联系人		   "<<endl;
	cout<<"	5.清空联系人		   "<<endl;
	cout<<"	6.显示联系人		   "<<endl;
	cout<<"	0.退出系统			   "<<endl;
	cout<<"================================"<<endl;
}
//创建联系人结构体
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Address;
};
//创建通讯录结构体
struct Addressbooks
{
	int m_Size;
	//定义一个person类型的联系人数组

	struct Person personArray[MAX];
};
void addPerson(Addressbooks *abs)
{
	if(abs->m_Size==MAX)
	{
		cout<<"通讯录已满!"<<endl;
		return;
	}
	else
	{
		//添加姓名
		string name;
		cout<<"请输入姓名:";
		cin>>name;
		abs->personArray[abs->m_Size].m_Name=name;
		
		//性别
		cout<<"请输入性别: "<<endl;
		cout<<"1 --- 男"<<endl;
		cout<<"2 --- 女"<<endl;
		int sex=0;
		while(true)
		{
			cin>>sex;
			if(sex==1||sex==2)
			{
				abs->personArray[abs->m_Size].m_Sex=sex;
				break;
			}
			cout<<"数据不合法,请重新输入"<<endl;
			
		}

		//年龄
		cout<<"请输入年龄(0-180):"<<endl;
		int age=0;
		cin>>age;
		abs->personArray[abs->m_Size].m_Age=age;		
		
		//电话
		cout<<"请输入电话号码:"<<endl;
		string phone;
		cin>>phone;
		abs->personArray[abs->m_Size].m_Phone=phone;
		//地址
		cout<<"请输入地址:"<<endl;
		string address;
		cin>>address;
		abs->personArray[abs->m_Size].m_Address=address;

		//更新通讯录
		abs->m_Size++;
		cout<<"添加成功"<<endl;

	}
	
}
//显示联系人
void showPerson(Addressbooks *abs)
{
	if(abs->m_Size==0)
	{
		cout<<"当前记录为空"<<endl;
		
	}
	else
	{
		for(int i=0;i<abs->m_Size;i++)
		{
			cout<<"姓名: "<<abs->personArray[i].m_Name<<"\t";
			cout<<"性别: "<<((abs->personArray[i].m_Sex)==1?"男":"女")<<"\t";
			cout<<"年龄: "<<abs->personArray[i].m_Age<<"\t";
			cout<<"电话: "<<abs->personArray[i].m_Phone<<"\t";
			cout<<"地址: "<<abs->personArray[i].m_Address<<"\n";	
							
		}
		
	
	}
}
//检测联系人是否存在,存在返回下标位,不存在返回-1
int isExist(Addressbooks *abs,string name)
{
	for(int i=0;i<abs->m_Size;i++)
	{
		if(abs->personArray[i].m_Name==name)
		{
			return i;
		}
		
	}
	return -1;
}
//删除联系人
void deletePerson(Addressbooks *abs)
{
	cout<<"请输入你要删除的联系人:";
	string name;
	cin>>name;
	if(isExist(abs,name)!=-1)
	{		
		for(int i=0;i<abs->m_Size;i++)
		{
			abs->personArray[i]=abs->personArray[i+1];   //数据前移
		}
		abs->m_Size--;
		cout<<"删除成功"<<endl;
	}
	else
	{
	
		cout<<"查无此人"<<endl;
	}
}
//查询联系人
void queryPerson(Addressbooks *abs)
{
	cout<<"请输入要查询的联系人:";
	string name;
	cin>>name;
	int rect =isExist(abs,name);
	if(rect!=-1)
	{		
			cout<<"姓名: "<<abs->personArray[rect].m_Name<<"\t";
			cout<<"性别: "<<((abs->personArray[rect].m_Sex)==1?"男":"女")<<"\t";
			cout<<"年龄: "<<abs->personArray[rect].m_Age<<"\t";
			cout<<"电话: "<<abs->personArray[rect].m_Phone<<"\t";
			cout<<"地址: "<<abs->personArray[rect].m_Address<<"\n";	
	}
	else
	{
	
		cout<<"查无此人"<<endl;
	}

}
//修改联系人
void updatePerson(Addressbooks *abs)
{
	cout<<"请输入要修改的联系人:";
	string name;
	cin>>name;
	int rect =isExist(abs,name);
	if(rect!=-1)
	{		
			cout<<"姓名: "<<abs->personArray[rect].m_Name<<"\n";
				string name;
				cout<<"请输入姓名:";
				cin>>name;
				abs->personArray[rect].m_Name=name;
			cout<<"性别: "<<((abs->personArray[rect].m_Sex)==1?"男":"女")<<"\n";
				cout<<"请输入性别: "<<endl;
				cout<<"1 --- 男"<<endl;
				cout<<"2 --- 女"<<endl;
				int sex=0;
				while(true)
				{
					cin>>sex;
					if(sex==1||sex==2)
					{
						abs->personArray[rect].m_Sex=sex;
						break;
					}
					cout<<"数据不合法,请重新输入"<<endl;
					
				}

			cout<<"年龄: "<<abs->personArray[rect].m_Age<<"\n";
				cout<<"请输入年龄(0-180):"<<endl;
				int age=0;
				cin>>age;
				abs->personArray[rect].m_Age=age;	
			cout<<"电话: "<<abs->personArray[rect].m_Phone<<"\n";
					cout<<"请输入电话号码:"<<endl;
					string phone;
					cin>>phone;
					abs->personArray[rect].m_Phone=phone;
			cout<<"地址: "<<abs->personArray[rect].m_Address<<"\n";	
			cout<<"请输入地址:"<<endl;
			string address;
			cin>>address;
			abs->personArray[rect].m_Address=address;

			cout<<"更新完成"<<endl;
			system("pause");
			system("cls");
	}
	else
	{
	
		cout<<"查无此人"<<endl;
	}
}
//清空联系人
void emptyPerson(Addressbooks *abs)
{
	abs->m_Size=0;
	cout<<"清空完成"<<endl;
}
int main(int argc, char* argv[])
{
		//创建通讯录结构体变量
		Addressbooks abs;
		//初始化通讯录当前人员个数
		abs.m_Size=0;
		
		while(true)
		{
			showMenu();  //调用显示菜单
			cout<<"请选择:(1-6)"<<" ";
			int select;
			cin>>select;
			switch(select)
			{
				case 1:  //添加联系人
					addPerson(&abs);
						break;
				case 2:  //删除
					deletePerson(&abs);
						break;
				case 3:  //更新
					updatePerson(&abs);
					break;
				case 4:  //查询
					queryPerson(&abs);
					break;
				case 5:	//清空
					emptyPerson(&abs);
					break;
				case 6:  //显示联系人
					showPerson(&abs);
					break;
				case 0:  
					{
					cout<<"88,欢迎下次光临!"<<endl;
					return 0;
					}
					break;

			}
		}

	system("pause");

}

