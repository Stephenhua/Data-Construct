#ifndef MYHASH_H_
#define MYHASH_H_

#include <iostream>
#include <string>
#include <fstream>
using std::string;
using std::ostream;
class DataInfo{
private:
	string name;
	string phone;
	string address;
	char sign;
public:
	DataInfo();
	friend ostream& operator <<(ostream &out, const DataInfo& dataInfo);
	friend class HashTable;
	string returnName(){ return name; }
	string returnPhone(){ return phone; }
	string returnAddress(){ return address; }
	char returnSign(){ return sign; }
};
const int HASHSIZE=50;
const int D[] = { 3, 5, 8, 11, 13, 14, 19, 21 };
class  HashTable{
private:
	
	int length;
public:
	DataInfo *value[HASHSIZE];
	//DataInfo reTuren(){ return value };
	HashTable();
	~HashTable();
	int Random(int key, int i);//α�����̽��ɢ�з������ͻ��
	int Rahash(int key, string str);//�ڹ�ϣ�������ͻ��
	void Hashname(DataInfo* dataInfo);//������Ϊ�ؼ��ֽ�����ϣ��
	void Hashphone(DataInfo * dateInfo);//�Ե绰Ϊ�ؼ��ִ�����ϣ��
	void Hash(char *fname, int n);//������ϣ��

	int Findname(string name);//�����������ҹ�ϣ���еĶ�Ӧ�Ĺؼ��룻
	int Findphone(string phone);//���ݵ绰���ҹ�ϣ���м�¼��Ӧ�Ĺؼ��룻
	void OutHash(int key);//�����ϣ���йؼ������Ӧ��һ����¼��
	void Outfile(string name, int key);//û���ҵ���λΪ�ҵ��ļ�¼��
	void Rashfile();//��������ļ��������ļ�������new.txt�У�
	void WriteToOldTxt();//������ǰд�����ݣ�

};
#endif