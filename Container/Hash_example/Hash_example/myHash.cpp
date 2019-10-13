#include <iostream>
#include <string>
#include"myHash.h"
using namespace std;

DataInfo::DataInfo() :name(""), phone(""), address(""), sign('0'){}
ostream &operator<<(ostream  & out, const DataInfo & dataInfo){
	cout << "������" << dataInfo.name << "�绰��" << dataInfo.phone << "��ַ��" << dataInfo.address << endl;
	return out;
}
HashTable::HashTable():length(0){
	for (int i = 0; i < HASHSIZE; i++){
		value[i] = new DataInfo();
	}
}
HashTable::~HashTable(){
	delete[] * value;
}
void HashTable::Hashname(DataInfo* dataInfo)//������Ϊ�ؼ��ֽ�����ϣ��
{
	int i = 0;
	int key = 0;
	for (int t = 0; dataInfo->name[t] != '\0'; t++){
		key = key + dataInfo->name[t];
	}
	key = key % 42;
	while (value[key]->sign == '1'){//����г�ͻ�������ͻ
		key = Random(key, i++);
	}
	if (key == -1)
		exit(1);
	length++;
	value[key]->name = dataInfo->name;
	value[key]->phone = dataInfo->phone;
	value[key]->address = dataInfo->address;
	value[key]->sign = '1';

}

int HashTable::Random(int key, int i)//α�����̽��ɢ�з������ͻ��
{
	int h;
	if (value[key]->sign == '1'){
		h = (key + D[i]) % HASHSIZE;
		return h;
	}
	return -1;
}
void HashTable::Hashphone(DataInfo * dateInfo)//�Ե绰Ϊ�ؼ��ִ�����ϣ��
{
	int key = 0;
	int t;
	for (t = 0; dateInfo->phone[t] != '\0'; t++){
		key = key + dateInfo->phone[t];
	}
	key = key % 42;
	while (value[key]->sign == '1')//��ʾ�г�ͻ
	{
		key = Rahash(key, dateInfo->phone);
	}
	length++;
	value[key]->name = dateInfo->name;
	value[key]->phone = dateInfo->phone;
	value[key]->address = dateInfo->address;
	value[key]->sign = '1';
}
int HashTable::Rahash(int key, string str)//�ڹ�ϣ�������ͻ��
{
	int h = 0;
	int num1 = (str[0] - '0') * 1000 + (str[1] - '0') * 100 + (str[2] - '0') * 10 + (str[3] - '0');
	int num2 = (str[4] - '0') * 1000 + (str[5] - '0') * 100 + (str[6] - '0') * 10 + (str[7] - '0');
	int num3 = (str[8] - '0') * 100 + (str[9] - '0') * 10 + (str[10] - '0');
	h = num1 + num2 + num3;
	h = (h + key) % HASHSIZE;
	return h;
}

void HashTable::Hash(char *fname, int n)//������ϣ��
{
	ifstream fin;
	int i;
	fin.open(fname);
	if (fin.fail()){
		cout << "�ļ���ʧ�ܣ�" << endl;
		exit(1);
	}

	while (!fin.eof()){//������������
		DataInfo *datainfo = new DataInfo();
		char *str = new char[100];
		fin.getline(str, 100, '\n');

		if (str[0] == '*'){
			break;
		}

		i = 0;

		while ((str[i] < 97) || (str[i]>122)){
			i++;
		}

		for (i; str[i] != '\n'; i++){
			datainfo->name += str[i];
		}

		while (str[i] == ' '){
			i++;
		}

		for (int j = 0; str[i] != ','; j++, i++){
			datainfo->address += str[i];
		}

		if (n == 1){
			Hashname(datainfo);
		}
		else{
			Hashphone(datainfo);
		}
		delete[] str;
		delete datainfo;


	}

	fin.close();
}

int HashTable::Findname(string name)//�����������ҹ�ϣ���еĶ�Ӧ�Ĺؼ��룻
{
	int i = 0;
	int j = 1;
	int t;
	int key = 0;
	for (key = 0, t = 0; name[t] != '\0'; t++){
		key = key + name[t];
	}

	key = key % 42;

	while ((value[key]->sign == '1') && (value[key]->name != name)){
		key = Random(key, i++);
		j++;
		if (j >= length)
			return -1;
	}
	return key;
}
int HashTable::Findphone(string phone)//���ݵ绰���ҹ�ϣ���м�¼��Ӧ�Ĺؼ��룻
{
	int key = 0;
	int t;
	for (t = 0; phone[t] != '\0'; t++){
		key = key + phone[t];
	}
	key = key % 42;
	int i = 1;
	while ((value[key]->sign == '1') && (value[key]->phone != phone)){
		key = Rahash(key, phone);
		i++;
		if (i >= length){
			return -1;
		}
	}
	return key;
}
void HashTable::OutHash(int key)//�����ϣ���йؼ������Ӧ��һ����¼��
{
	if ((key == -1) || (value[key]->sign == '0')){
		cout << "û���ҵ�������¼" << endl;
	}
	else{
		for (unsigned int i = 0; value[key]->name[i] != '\0'; i++){
			cout << value[key]->name[i];
		}

		for (unsigned int i = 0; i < 10; i++){
			cout << " ";
		}

		cout << value[key]->phone;
		for (unsigned int i = 0; i < 10; i++){
			cout << " ";
		}

		cout << value[key]->address << endl;

	}
}
void HashTable::Outfile(string name, int key)//û���ҵ���λΪ�ҵ��ļ�¼��
{
	ofstream fout;
	if ((key == -1) || (value[key]->sign == '0')){
		fout.open("out.txt", ios::app);
		if (fout.fail()){
			cout << "�ļ���ʧ��" << endl;
			exit(1);
		}
		fout << name << endl;
		fout.close();
	}
}
void HashTable::Rashfile()//��������ļ��������ļ�������new.txt�У�
{
	ofstream fout;
	fout.open("new.txt");
	if (fout.fail()){
		cout << "���ܴ��ļ�" << endl;
		exit(1);
	}
	for (int i = 0; i < 30; i++){
		string name = " ";
		for (int i = 0; i < 20; i++){
			name += rand() % 26 + 'a';
		}
		fout << name << " ";

		string phone = "";
		for (int i = 0; i < 11; i++){
			phone += rand() % 10 + '0';
		}
		fout << phone << "";

		string address = "";
		for (int i = 0; i < 29; i++){
			address += rand() % 26 + 'a';
		}
		address += ',';
		fout << address << endl;

	}
	fout.close();
	
}
void HashTable::WriteToOldTxt()//������ǰд�����ݣ�
{
	ofstream openfile("old.txt");
	if (openfile.fail())
	{
		cout << "�ļ��򿪴���" << endl;
		exit(1);
	}
	string oldname;
	string oldphone;
	string oldaddress;

	for (int i = 0; i < 30; i++){
		cout << "�������" << i + 1 << "����¼" << endl;
		cin >> oldname;
		cin >> oldphone;
		cin >> oldaddress;
		openfile << oldname << " " << oldphone << " " << oldaddress << "," << endl;
	}
	openfile.close();
}