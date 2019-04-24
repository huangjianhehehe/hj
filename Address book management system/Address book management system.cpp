// Address book management system.cpp : Defines the entry point for the console application.
/*
	ͨѶ¼����ϵͳ
	1.������ϵ��
	2.ɾ����ϵ��
	3.�޸���ϵ��
	4.��ѯ��ϵ��
	5.�����ϵ��
	6.�˳�

*/

#include "stdafx.h"
#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

void showMenu()   //��ʾ�˵�
{
	cout<<"================================"<<endl;
	cout<<"	1.�����ϵ��		   "<<endl;
	cout<<"	2.ɾ����ϵ��		   "<<endl;
	cout<<"	3.������ϵ��		   "<<endl;
	cout<<"	4.��ѯ��ϵ��		   "<<endl;
	cout<<"	5.�����ϵ��		   "<<endl;
	cout<<"	6.��ʾ��ϵ��		   "<<endl;
	cout<<"	0.�˳�ϵͳ			   "<<endl;
	cout<<"================================"<<endl;
}
//������ϵ�˽ṹ��
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Address;
};
//����ͨѶ¼�ṹ��
struct Addressbooks
{
	int m_Size;
	//����һ��person���͵���ϵ������

	struct Person personArray[MAX];
};
void addPerson(Addressbooks *abs)
{
	if(abs->m_Size==MAX)
	{
		cout<<"ͨѶ¼����!"<<endl;
		return;
	}
	else
	{
		//�������
		string name;
		cout<<"����������:";
		cin>>name;
		abs->personArray[abs->m_Size].m_Name=name;
		
		//�Ա�
		cout<<"�������Ա�: "<<endl;
		cout<<"1 --- ��"<<endl;
		cout<<"2 --- Ů"<<endl;
		int sex=0;
		while(true)
		{
			cin>>sex;
			if(sex==1||sex==2)
			{
				abs->personArray[abs->m_Size].m_Sex=sex;
				break;
			}
			cout<<"���ݲ��Ϸ�,����������"<<endl;
			
		}

		//����
		cout<<"����������(0-180):"<<endl;
		int age=0;
		cin>>age;
		abs->personArray[abs->m_Size].m_Age=age;		
		
		//�绰
		cout<<"������绰����:"<<endl;
		string phone;
		cin>>phone;
		abs->personArray[abs->m_Size].m_Phone=phone;
		//��ַ
		cout<<"�������ַ:"<<endl;
		string address;
		cin>>address;
		abs->personArray[abs->m_Size].m_Address=address;

		//����ͨѶ¼
		abs->m_Size++;
		cout<<"��ӳɹ�"<<endl;

	}
	
}
//��ʾ��ϵ��
void showPerson(Addressbooks *abs)
{
	if(abs->m_Size==0)
	{
		cout<<"��ǰ��¼Ϊ��"<<endl;
		
	}
	else
	{
		for(int i=0;i<abs->m_Size;i++)
		{
			cout<<"����: "<<abs->personArray[i].m_Name<<"\t";
			cout<<"�Ա�: "<<((abs->personArray[i].m_Sex)==1?"��":"Ů")<<"\t";
			cout<<"����: "<<abs->personArray[i].m_Age<<"\t";
			cout<<"�绰: "<<abs->personArray[i].m_Phone<<"\t";
			cout<<"��ַ: "<<abs->personArray[i].m_Address<<"\n";	
							
		}
		
	
	}
}
//�����ϵ���Ƿ����,���ڷ����±�λ,�����ڷ���-1
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
//ɾ����ϵ��
void deletePerson(Addressbooks *abs)
{
	cout<<"��������Ҫɾ������ϵ��:";
	string name;
	cin>>name;
	if(isExist(abs,name)!=-1)
	{		
		for(int i=0;i<abs->m_Size;i++)
		{
			abs->personArray[i]=abs->personArray[i+1];   //����ǰ��
		}
		abs->m_Size--;
		cout<<"ɾ���ɹ�"<<endl;
	}
	else
	{
	
		cout<<"���޴���"<<endl;
	}
}
//��ѯ��ϵ��
void queryPerson(Addressbooks *abs)
{
	cout<<"������Ҫ��ѯ����ϵ��:";
	string name;
	cin>>name;
	int rect =isExist(abs,name);
	if(rect!=-1)
	{		
			cout<<"����: "<<abs->personArray[rect].m_Name<<"\t";
			cout<<"�Ա�: "<<((abs->personArray[rect].m_Sex)==1?"��":"Ů")<<"\t";
			cout<<"����: "<<abs->personArray[rect].m_Age<<"\t";
			cout<<"�绰: "<<abs->personArray[rect].m_Phone<<"\t";
			cout<<"��ַ: "<<abs->personArray[rect].m_Address<<"\n";	
	}
	else
	{
	
		cout<<"���޴���"<<endl;
	}

}
//�޸���ϵ��
void updatePerson(Addressbooks *abs)
{
	cout<<"������Ҫ�޸ĵ���ϵ��:";
	string name;
	cin>>name;
	int rect =isExist(abs,name);
	if(rect!=-1)
	{		
			cout<<"����: "<<abs->personArray[rect].m_Name<<"\n";
				string name;
				cout<<"����������:";
				cin>>name;
				abs->personArray[rect].m_Name=name;
			cout<<"�Ա�: "<<((abs->personArray[rect].m_Sex)==1?"��":"Ů")<<"\n";
				cout<<"�������Ա�: "<<endl;
				cout<<"1 --- ��"<<endl;
				cout<<"2 --- Ů"<<endl;
				int sex=0;
				while(true)
				{
					cin>>sex;
					if(sex==1||sex==2)
					{
						abs->personArray[rect].m_Sex=sex;
						break;
					}
					cout<<"���ݲ��Ϸ�,����������"<<endl;
					
				}

			cout<<"����: "<<abs->personArray[rect].m_Age<<"\n";
				cout<<"����������(0-180):"<<endl;
				int age=0;
				cin>>age;
				abs->personArray[rect].m_Age=age;	
			cout<<"�绰: "<<abs->personArray[rect].m_Phone<<"\n";
					cout<<"������绰����:"<<endl;
					string phone;
					cin>>phone;
					abs->personArray[rect].m_Phone=phone;
			cout<<"��ַ: "<<abs->personArray[rect].m_Address<<"\n";	
			cout<<"�������ַ:"<<endl;
			string address;
			cin>>address;
			abs->personArray[rect].m_Address=address;

			cout<<"�������"<<endl;
			system("pause");
			system("cls");
	}
	else
	{
	
		cout<<"���޴���"<<endl;
	}
}
//�����ϵ��
void emptyPerson(Addressbooks *abs)
{
	abs->m_Size=0;
	cout<<"������"<<endl;
}
int main(int argc, char* argv[])
{
		//����ͨѶ¼�ṹ�����
		Addressbooks abs;
		//��ʼ��ͨѶ¼��ǰ��Ա����
		abs.m_Size=0;
		
		while(true)
		{
			showMenu();  //������ʾ�˵�
			cout<<"��ѡ��:(1-6)"<<" ";
			int select;
			cin>>select;
			switch(select)
			{
				case 1:  //�����ϵ��
					addPerson(&abs);
						break;
				case 2:  //ɾ��
					deletePerson(&abs);
						break;
				case 3:  //����
					updatePerson(&abs);
					break;
				case 4:  //��ѯ
					queryPerson(&abs);
					break;
				case 5:	//���
					emptyPerson(&abs);
					break;
				case 6:  //��ʾ��ϵ��
					showPerson(&abs);
					break;
				case 0:  
					{
					cout<<"88,��ӭ�´ι���!"<<endl;
					return 0;
					}
					break;

			}
		}

	system("pause");

}

