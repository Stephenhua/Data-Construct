#include <iostream>
#include <string>
#include<fstream>
#include "stdafx.h"
#include "myHash.h"
using namespace std;
void main(){
	int k;
	int ch;
	char *Fname;
	HashTable *ht = new HashTable;

	while (1)
	{
		system("cls");//cls命令清除屏幕上所有的文字  
		cout << "欢迎使用本系统！" << endl << endl;
		cout << "请选择数据" << endl;
		cout << "1.使用已有数据文件" << endl;
		cout << "2.随机生成数据文件" << endl;
		cout << "0.结束" << endl;
		cout << "输入相应序号选择功能：";
		cin >> k;

		switch (k)
		{
		case 0:
			return;
		case 1:
			Fname = "old.txt";//从数据文件old.txt(自己现行建好)中读入各项记录  
			break;
		case 2:
			ht->Rashfile();
			Fname = "new.txt";//由系统随机产生各记录，并且把记录保存到new.txt文件中  
			break;
		default:
			cout << "输入序号有误，退出程序。" << endl;
			return;
		}

		do
		{
			system("cls");
			cout << " 请选择查找方式" << endl;
			cout << "1.通过姓名查找" << endl;
			cout << "2.通过电话查找" << endl;
			cout << "输入相应序号选择功能：";
			cin >> ch;
			if ((ch != 1) && (ch != 2))
				cout << "输入序号有误！" << endl;
		} while ((ch != 1) && (ch != 2));

		ht->Hash(Fname, ch);

		while (ch == 1)
		{
			int choice;
			cout << endl << "请选择功能" << endl;
			cout << "1.输入姓名查找数据" << endl;
			cout << "2.显示哈希表" << endl;
			cout << "0.退出" << endl;
			cout << "输入相应序号选择功能：";
			cin >> choice;
			switch (choice)
			{
			case 1:
			{//注意此处应该加上大括号  
				int key1;
				string name;
				cout << "请输入姓名：";
				cin >> name;
				key1 = ht->Findname(name);
				ht->Outfile(name, key1);
				ht->OutHash(key1);
			}
			break;

			case 2:
			{
				for (int i = 0; i < HASHSIZE; i++)
				{
					if (ht->value[i]->returnSign() != '0')
					{
						ht->OutHash(i);
					}
				}
			}
			break;


			default:
				cout << endl << "您的输入有误！" << endl;
			}

			if (choice == 0)
			{
				return;
			}
		}

		while (ch == 2)
		{
			int choice;
			cout << endl << "请选择功能" << endl;
			cout << "1.输入电话查找数据" << endl;
			cout << "2.显示哈希表" << endl;
			cout << "0.退出" << endl;
			cout << "输入相应序号选择功能：";
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				int key2;
				string phone;
				cout << "请输入11位的电话号码：";

				do
				{
					cin >> phone;
					if (phone.length() != 11)
					{
						cout << "电话号码应为11位！\n请重新输入：";
					}

				} while (phone.length() != 11);

				key2 = ht->Findphone(phone);
				ht->Outfile(phone, key2);
				ht->OutHash(key2);
			}
			break;

			case 2:
			{
				for (int i = 0; i < HASHSIZE; i++)
				{
					if (ht->value[i]->returnSign() != '0')
					{
						ht->OutHash(i);
					}
				}
			}
			break;

			default:
				cout << endl << "您的输入有误！" << endl;
			}

			if (choice == 0)
			{
				return;
			}
		}

		while ((ch != 1) && (ch != 2))
		{
			cout << "您的输入有误！请输入相应需要选择功能：";
		}
	}

	system("pause");
	
}