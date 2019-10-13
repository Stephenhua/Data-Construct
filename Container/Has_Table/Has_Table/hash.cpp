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
//定义哈希表的Hash算法，在这里我使用time33算法
size_t HashTable::hash(const char *key){
	size_t hash = 0;
	while (*key){
		hash += (hash << 5) + (*key++);
	}
	return hash%HASHSIZE;
}
//定义一个查找根据key查找结点的方法
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

//定义一个插入结点的方法
//首先是查看该key值的结点是否存在，如果存在则更改value值就好，如果不存在，则插入新结点。
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