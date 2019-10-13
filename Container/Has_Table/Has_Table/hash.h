#ifndef HASH_H_
#define HASH_H_

#define HASHSIZE 5
typedef struct Node{
	char *key;
	char *value;
	Node *next;

}Node;

class HashTable{
private:
	Node * node[HASHSIZE];
public:
	HashTable();
	~HashTable();
	size_t hash(const char *key);
	Node *lookup(const char *key);
	bool install(const char *key, const char*value);
	const char *get(const char *key);
	void display();
private:
	char * strdup(const char *str);//为节点分配空间；
};

#endif