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
		system("cls");//cls���������Ļ�����е�����  
		cout << "��ӭʹ�ñ�ϵͳ��" << endl << endl;
		cout << "��ѡ������" << endl;
		cout << "1.ʹ�����������ļ�" << endl;
		cout << "2.������������ļ�" << endl;
		cout << "0.����" << endl;
		cout << "������Ӧ���ѡ���ܣ�";
		cin >> k;

		switch (k)
		{
		case 0:
			return;
		case 1:
			Fname = "old.txt";//�������ļ�old.txt(�Լ����н���)�ж�������¼  
			break;
		case 2:
			ht->Rashfile();
			Fname = "new.txt";//��ϵͳ�����������¼�����ҰѼ�¼���浽new.txt�ļ���  
			break;
		default:
			cout << "������������˳�����" << endl;
			return;
		}

		do
		{
			system("cls");
			cout << " ��ѡ����ҷ�ʽ" << endl;
			cout << "1.ͨ����������" << endl;
			cout << "2.ͨ���绰����" << endl;
			cout << "������Ӧ���ѡ���ܣ�";
			cin >> ch;
			if ((ch != 1) && (ch != 2))
				cout << "�����������" << endl;
		} while ((ch != 1) && (ch != 2));

		ht->Hash(Fname, ch);

		while (ch == 1)
		{
			int choice;
			cout << endl << "��ѡ����" << endl;
			cout << "1.����������������" << endl;
			cout << "2.��ʾ��ϣ��" << endl;
			cout << "0.�˳�" << endl;
			cout << "������Ӧ���ѡ���ܣ�";
			cin >> choice;
			switch (choice)
			{
			case 1:
			{//ע��˴�Ӧ�ü��ϴ�����  
				int key1;
				string name;
				cout << "������������";
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
				cout << endl << "������������" << endl;
			}

			if (choice == 0)
			{
				return;
			}
		}

		while (ch == 2)
		{
			int choice;
			cout << endl << "��ѡ����" << endl;
			cout << "1.����绰��������" << endl;
			cout << "2.��ʾ��ϣ��" << endl;
			cout << "0.�˳�" << endl;
			cout << "������Ӧ���ѡ���ܣ�";
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				int key2;
				string phone;
				cout << "������11λ�ĵ绰���룺";

				do
				{
					cin >> phone;
					if (phone.length() != 11)
					{
						cout << "�绰����ӦΪ11λ��\n���������룺";
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
				cout << endl << "������������" << endl;
			}

			if (choice == 0)
			{
				return;
			}
		}

		while ((ch != 1) && (ch != 2))
		{
			cout << "��������������������Ӧ��Ҫѡ���ܣ�";
		}
	}

	system("pause");
	
}