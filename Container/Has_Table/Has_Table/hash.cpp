#include <iostream>
#include "hash.h"

HashTable::HashTable(){
	for (int i = 0; i < HASHSIZE; i++){
		node[i] = NULL;
	}
}

HashTable::~HashTable(){
	for (int i = 0; i < HASHSIZE; i++){
		Node *next = node[i];
		while (next){
			Node *temp = next->next;
			free(next->key);
			free(next->next);
			free(next->value);
			next = temp;
		}
	}
}

char * HashTable::strdup(const char *str){
	int len = strlen(str) + 1;
	char *ns = (char*)malloc(len*sizeof(char));
	strcpy(ns, str);
	if (ns == nullptr){
		return nullptr;
	}
	else{
		return ns;
	}
}
//�����ϣ���Hash�㷨����������ʹ��time33�㷨
size_t HashTable::hash(const char *key){
	size_t hash = 0;
	while (*key){
		hash += (hash << 5) + (*key++);
	}
	return hash%HASHSIZE;
}
//����һ�����Ҹ���key���ҽ��ķ���
Node * HashTable::lookup(const char *key){
	Node *np;
	size_t index;
	index = hash(key);
	for (np = node[index]; np; np = np->next){
		if (!strcmp(key, np->key)){
			return np;
		}
	}
	return NULL;
}

//����һ��������ķ���
//�����ǲ鿴��keyֵ�Ľ���Ƿ���ڣ�������������valueֵ�ͺã���������ڣ�������½�㡣
bool HashTable::install(const char *key, const char*value){
	size_t index;
	Node *np;
	if (!(np = lookup(key))){
		index = hash(key);
		np = (Node*)malloc(sizeof(Node));
		if (!np)
			return false;
		if (np->key == nullptr)
			return false;
		np->next = node[index];
		node[index] = np;
	}
	else{
		free(np->value);	
		np->value = strdup(value);
		if (np->key == nullptr)
			return false;

	}

	return true;

}
void HashTable::display(){
		Node* temp;
		for (int i = 0; i < HASHSIZE; ++i)
		{
			if (!node[i]){
				printf("[]\n");
			}
			else{
				printf("[");
				for (temp = node[i]; temp; temp = temp->next)
				{
					printf("[%s][%s] ", temp->key, temp->value);
				}
				printf("]\n");
			}
		}
}