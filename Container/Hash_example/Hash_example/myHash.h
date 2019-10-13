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
	int Random(int key, int i);//伪随机数探测散列法处理冲突；
	int Rahash(int key, string str);//在哈希法处理冲突；
	void Hashname(DataInfo* dataInfo);//以名字为关键字建立哈希表；
	void Hashphone(DataInfo * dateInfo);//以电话为关键字创建哈希表；
	void Hash(char *fname, int n);//建立哈希表；

	int Findname(string name);//根据姓名查找哈希表中的对应的关键码；
	int Findphone(string phone);//根据电话查找哈希表中记录相应的关键码；
	void OutHash(int key);//输出哈希表中关键字码对应的一条记录；
	void Outfile(string name, int key);//没有找到数位为找到的记录；
	void Rashfile();//随机生成文件，并将文件保存在new.txt中；
	void WriteToOldTxt();//在运行前写入数据；

};
#endif